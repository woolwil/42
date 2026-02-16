
### /etc/vim/vimrc
```
syntax on
set showcmd
set incsearch
set showmatch
set mouse=a
set number
set tabstop=4
set shiftwidth=4
```

### /etc/sudoers
```#
# This file MUST be edited with the 'visudo' command as root.
#
# Please consider adding local content in /etc/sudoers.d/ instead of
# directly modifying this file.
#
# See the man page for details on how to write a sudoers file.
#
Defaults	env_reset
Defaults	mail_badpass
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
Defaults	requiretty
Defaults	logfile="/var/log/sudo/sudo.log"
Defaults	iolog_dir="/var/log/sudo/"
Defaults	log_input
Defaults	log_output
Defaults	badpass_message="wrong pw buddy, try again :)"
Defaults	passwd_tries=3

# This fixes CVE-2005-4890 and possibly breaks some versions of kdesu
# (#1011624, https://bugs.kde.org/show_bug.cgi?id=452532)
Defaults	use_pty

# This preserves proxy settings from user environments of root
# equivalent users (group sudo)
#Defaults:%sudo env_keep += "http_proxy https_proxy ftp_proxy all_proxy no_proxy"

# This allows running arbitrary commands, but so does ALL, and it means
# different sudoers have their choice of editor respected.
#Defaults:%sudo env_keep += "EDITOR"

# Completely harmless preservation of a user preference.
#Defaults:%sudo env_keep += "GREP_COLOR"

# While you shouldn't normally run git as root, you need to with etckeeper
#Defaults:%sudo env_keep += "GIT_AUTHOR_* GIT_COMMITTER_*"

# Per-user preferences; root won't have sensible values for them.
#Defaults:%sudo env_keep += "EMAIL DEBEMAIL DEBFULLNAME"

# "sudo scp" or "sudo rsync" should be able to use your SSH agent.
#Defaults:%sudo env_keep += "SSH_AGENT_PID SSH_AUTH_SOCK"

# Ditto for GPG agent
#Defaults:%sudo env_keep += "GPG_AGENT_INFO"

# Host alias specification

# User alias specification

# Cmnd alias specification

# User privilege specification
root	ALL=(ALL:ALL) ALL

# Allow members of group sudo to execute any command
%sudo	ALL=(ALL:ALL) ALL

# See sudoers(5) for more information on "@include" directives:

@includedir /etc/sudoers.d
```

### /etc/pam.d/common-password
```
#
# /etc/pam.d/common-password - password-related modules common to all services
#
# This file is included from other service-specific PAM config files,
# and should contain a list of modules that define the services to be
# used to change user passwords.  The default is pam_unix.

# Explanation of pam_unix options:
# The "yescrypt" option enables
#hashed passwords using the yescrypt algorithm, introduced in Debian
#11.  Without this option, the default is Unix crypt.  Prior releases
#used the option "sha512"; if a shadow password hash will be shared
#between Debian 11 and older releases replace "yescrypt" with "sha512"
#for compatibility .  The "obscure" option replaces the old
#`OBSCURE_CHECKS_ENAB' option in login.defs.  See the pam_unix manpage
#for other options.

# As of pam 1.0.1-6, this file is managed by pam-auth-update by default.
# To take advantage of this, it is recommended that you configure any
# local modules either before or after the default block, and use
# pam-auth-update to manage selection of other modules.  See
# pam-auth-update(8) for details.

# here are the per-package modules (the "Primary" block)
password	requisite			pam_pwquality.so retry=3 minlen=10 difok=7 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username enforce_for_root
password	[success=1 default=ignore]	pam_unix.so obscure use_authtok try_first_pass yescrypt
# here's the fallback if no module succeeds
password	requisite			pam_deny.so
# prime the stack with a positive return value if there isn't one already;
# this avoids us returning an error just because nothing sets a success code
# since the modules above will each just jump around
password	required			pam_permit.so
# and here are more per-package modules (the "Additional" block)
# end of pam-auth-update config
```

### cron
`*/10 * * * * /usr/local/bin/monitoring.sh`

### /usr/local/bin/monitoring.sh
```bash
#!/bin/bash
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

#1. Architecture
arc=$(uname -a)
#2. Physical CPU Count
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
#3. vCPU Count
vcpu=$(grep "processor" /proc/cpuinfo | wc -l)
#4. Total Memory and Memory Usage in Percentage
tram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free -m | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
#5. Disk Usage
udis=$(df -m / | awk 'NR==2 {print $3}')
tdis=$(df -m / | awk 'NR==2 {print $2}')
pdis=$(df -m / | awk 'NR==2 {print $5}')
#6. CPU Load
cpul=$(top -bn1 | grep "^%Cpu" | awk -F '[ ,]+' '{printf("%.1f%%"), 100 - $8}')
#7. Last Boot
lb=$(who -b | awk '{print $3, $4}')
#8. LVM Use
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
#9. Connections TCP
ctcp=$(ss -ta | grep "ESTAB" | wc -l)
#10. User Log
ulog=$(users | wc -w)
#11. Network IP, MAC
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')
#12. Sudo
sudoc=$(grep "COMMAND" /var/log/sudo/sudo.log 2>/dev/null | wc -l)

# Construct the message in a variable
msg="
        #Architecture: $arc
        #CPU physical: $pcpu
        #vCPU: $vcpu
        #Memory Usage: $uram/${tram}MB ($pram%)
        #Disk Usage: $udis/${tdis}MB ($pdis)
        #CPU Load: $cpul
        #Last Boot: $lb
        #LVM Use: $lvmu
        #TCP Connections: $ctcp ESTABLISHED
        #User Log: $ulog
        #Network: IP $ip ($mac)
        #Sudo cmds: $sudoc"

# Broadcast to all terminals
echo "$msg"	
echo "$msg" | /usr/bin/wall
```

### /usr/local/bin/audit.sh
```bash
#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo -e "${YELLOW}=== BORN2BEROOT COMPREHENSIVE AUDIT ===${NC}"

# 1. OS & GUI Check (Looking for Xorg binary or active display manager)
echo -ne "Check: No GUI... "
if [ ! -f "/usr/bin/Xorg" ] && [ ! -f "/usr/bin/X" ] && ! systemctl is-active --quiet gdm && ! systemctl is-active --quiet lightdm; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} GUI components detected."
fi

# 2. Hostname Check
echo -ne "Check: Hostname (ngvo42)... "
if [ "$(hostname)" = "ngvo42" ]; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} Hostname is $(hostname)"
fi

# 3. Partitioning (LVM, Crypt, & Mountpoint matching)
echo -ne "Check: LVM Structure & Mountpoints... "
# 1. Check for basic LVM and Encryption
if ! lsblk | grep -q "lvm" || ! lsblk | grep -q "crypt"; then
    echo -e "${RED}[FAIL]${NC} Missing LVM or Crypt tags."
# 2. Check if LV names match their mountpoints (root, home, var, etc.)
elif lsblk -n -o NAME,MOUNTPOINT | grep "LVMGroup" | awk '{
    if ($2 == "/" && $1 !~ /root/) exit 1;
    if ($2 == "/home" && $1 !~ /home/) exit 1;
    if ($2 == "/var" && $1 !~ /var/) exit 1;
    if ($2 == "/tmp" && $1 !~ /tmp/) exit 1;
    if ($2 == "/srv" && $1 !~ /srv/) exit 1;
    if ($2 == "/var/log" && $1 !~ /var--log/) exit 1;
} END { if (NR == 0) exit 1; }'; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} Mountpoint/Name mismatch detected."
fi

# 4. AppArmor
echo -ne "Check: AppArmor... "
if aa-status --enabled 2>/dev/null; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} AppArmor not enabled."
fi

# 5. UFW & Port 4242
echo -ne "Check: Firewall (Port 4242)... "
if sudo ufw status | grep -q "4242/tcp" && sudo ufw status | grep -q "ALLOW"; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} Port 4242 not allowed in UFW."
fi

# 6. SSH Config (Port & Root)
echo -ne "Check: SSH Security... "
PORT=$(grep "^Port " /etc/ssh/sshd_config | awk '{print $2}')
ROOT_LOGIN=$(grep "^PermitRootLogin " /etc/ssh/sshd_config | awk '{print $2}')
if [ "$PORT" = "4242" ] && [ "$ROOT_LOGIN" = "no" ]; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} Port: $PORT, PermitRootLogin: $ROOT_LOGIN"
fi

# 7. Sudoers Policy
echo -ne "Check: Sudo Policies... "
if sudo grep -q "passwd_tries=3" /etc/sudoers && \
   sudo grep -q "requiretty" /etc/sudoers && \
   sudo grep -q "iolog_dir" /etc/sudoers; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} Check tries, requiretty, or iolog_dir in visudo."
fi

# 7.1. Sudo Secure Path (Strict Subject Requirement)
EXPECTED_PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
ACTUAL_PATH=$(sudo grep "secure_path" /etc/sudoers | cut -d'=' -f2 | sed 's/[" ]//g')

echo -ne "Check: Sudo Secure Path... "
if [ "$ACTUAL_PATH" = "$EXPECTED_PATH" ]; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC}"
    echo -e "   Expected: $EXPECTED_PATH"
    echo -e "   Detected: $ACTUAL_PATH"
fi

# 8. User Groups
echo -ne "Check: User ngvo Groups... "
if groups ngvo | grep -q "sudo" && groups ngvo | grep -q "user42"; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} ngvo must be in 'sudo' and 'user42'."
fi

# 9. Cron Job
echo -ne "Check: Monitoring Cron... "
if sudo crontab -u root -l 2>/dev/null | grep -q "monitoring.sh"; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} No cron job found for root."
fi

# 10. Password Aging Policy
echo -ne "Check: Password Aging (30/2/7)... "
MAX=$(grep "^PASS_MAX_DAYS" /etc/login.defs | awk '{print $2}')
MIN=$(grep "^PASS_MIN_DAYS" /etc/login.defs | awk '{print $2}')
WARN=$(grep "^PASS_WARN_AGE" /etc/login.defs | awk '{print $2}')
if [ "$MAX" = "30" ] && [ "$MIN" = "2" ] && [ "$WARN" = "7" ]; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} Max: $MAX, Min: $MIN, Warn: $WARN"
fi

# 10.1. User-Specific Aging (chage check)
echo -ne "Check: Individual User Aging (root & ngvo)... "
ROOT_CHAGE=$(sudo chage -l root | grep "Maximum number of days" | awk -F: '{print $2}' | tr -d ' ')
NGVO_CHAGE=$(sudo chage -l ngvo | grep "Maximum number of days" | awk -F: '{print $2}' | tr -d ' ')

if [ "$ROOT_CHAGE" = "30" ] && [ "$NGVO_CHAGE" = "30" ]; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} root:$ROOT_CHAGE days, ngvo:$NGVO_CHAGE days (Expected 30)"
fi

# 11. Password Complexity (PAM)
echo -ne "Check: Password Complexity (PAM)... "
PAM_FILE="/etc/pam.d/common-password"
if grep -q "minlen=10" $PAM_FILE && \
   grep -q "ucredit=-1" $PAM_FILE && \
   grep -q "lcredit=-1" $PAM_FILE && \
   grep -q "dcredit=-1" $PAM_FILE && \
   grep -q "reject_username" $PAM_FILE; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} Check minlen, credits, or usercheck in $PAM_FILE"
fi

# 12. Ghost User Check (UIDs 1000 and above)
echo -ne "Check: No Unauthorized Users... "
# Lists all users with UID >= 1000, excluding 'nobody'
EXTRA_USERS=$(awk -F: '$3 >= 1000 && $1 != "nobody" {print $1}' /etc/passwd | grep -v "ngvo" | xargs)

if [ -z "$EXTRA_USERS" ]; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} Found extra users: $EXTRA_USERS"
fi

# 13. Extra Group Audit (Detects custom-created groups)
echo -ne "Check: No Unauthorized Groups... "

# These are the standard Debian groups + the mandatory user42 group
# We use a regex pattern to filter them out
STANDARD_GROUPS="^(root|daemon|bin|sys|adm|tty|disk|lp|mail|news|uucp|man|proxy|kmem|dialout|fax|voice|cdrom|floppy|tape|sudo|audio|dip|www-data|backup|operator|list|irc|src|gnats|shadow|utmp|video|sasl|plugdev|staff|games|users|nogroup|systemd-journal|systemd-network|systemd-resolve|systemd-timesync|messagebus|_apt|systemd-coresump|netdev|ssh|user42|ngvo|crontab|input|sgx|clock|kvm|render|_ssh)$"
# Get all groups from /etc/group, extract names, and filter out the standards
EXTRA_GROUPS=$(cut -d: -f1 /etc/group | grep -Ev "$STANDARD_GROUPS" | xargs)

if [ -z "$EXTRA_GROUPS" ]; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} Found extra custom groups: $EXTRA_GROUPS"
fi

echo -e "${YELLOW}MAKE SURE TO RUN WITH ${GREEN}SUDO ${YELLOW}IF SOME ${RED}[FAILED]"

echo -e "${YELLOW}========================================${NC}"
```