
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
### /etc/ssh/sshd_config
```
# This is the sshd server system-wide configuration file.  See
# sshd_config(5) for more information.

# This sshd was compiled with PATH=/usr/local/bin:/usr/bin:/bin:/usr/games

# The strategy used for options in the default sshd_config shipped with
# OpenSSH is to specify options with their default value where
# possible, but leave them commented.  Uncommented options override the
# default value.

Include /etc/ssh/sshd_config.d/*.conf

Port 4242
#AddressFamily any
#ListenAddress 0.0.0.0
#ListenAddress ::

#HostKey /etc/ssh/ssh_host_rsa_key
#HostKey /etc/ssh/ssh_host_ecdsa_key
#HostKey /etc/ssh/ssh_host_ed25519_key

# Ciphers and keying
#RekeyLimit default none

# Logging
#SyslogFacility AUTH
#LogLevel INFO

# Authentication:

#LoginGraceTime 2m
PermitRootLogin no
#StrictModes yes
#MaxAuthTries 6
#MaxSessions 10

#PubkeyAuthentication yes

# Expect .ssh/authorized_keys2 to be disregarded by default in future.
#AuthorizedKeysFile	.ssh/authorized_keys .ssh/authorized_keys2

#AuthorizedPrincipalsFile none

#AuthorizedKeysCommand none
#AuthorizedKeysCommandUser nobody

# For this to work you will also need host keys in /etc/ssh/ssh_known_hosts
#HostbasedAuthentication no
# Change to yes if you don't trust ~/.ssh/known_hosts for
# HostbasedAuthentication
#IgnoreUserKnownHosts no
# Don't read the user's ~/.rhosts and ~/.shosts files
#IgnoreRhosts yes

# To disable tunneled clear text passwords, change to "no" here!
PasswordAuthentication yes
#PermitEmptyPasswords no

# Change to "yes" to enable keyboard-interactive authentication.  Depending on
# the system's configuration, this may involve passwords, challenge-response,
# one-time passwords or some combination of these and other methods.
# Beware issues with some PAM modules and threads.
KbdInteractiveAuthentication no

# Kerberos options
#KerberosAuthentication no
#KerberosOrLocalPasswd yes
#KerberosTicketCleanup yes
#KerberosGetAFSToken no

# GSSAPI options
#GSSAPIAuthentication no
#GSSAPICleanupCredentials yes
#GSSAPIStrictAcceptorCheck yes
#GSSAPIKeyExchange no

# Set this to 'yes' to enable PAM authentication, account processing,
# and session processing. If this is enabled, PAM authentication will
# be allowed through the KbdInteractiveAuthentication and
# PasswordAuthentication.  Depending on your PAM configuration,
# PAM authentication via KbdInteractiveAuthentication may bypass
# the setting of "PermitRootLogin prohibit-password".
# If you just want the PAM account and session checks to run without
# PAM authentication, then enable this but set PasswordAuthentication
# and KbdInteractiveAuthentication to 'no'.
UsePAM yes

#AllowAgentForwarding yes
#AllowTcpForwarding yes
#GatewayPorts no
X11Forwarding yes
#X11DisplayOffset 10
#X11UseLocalhost yes
#PermitTTY yes
PrintMotd no
#PrintLastLog yes
#TCPKeepAlive yes
#PermitUserEnvironment no
#Compression delayed
#ClientAliveInterval 0
#ClientAliveCountMax 3
#UseDNS no
#PidFile /run/sshd.pid
#MaxStartups 10:30:100
#PermitTunnel no
#ChrootDirectory none
#VersionAddendum none

# no default banner path
#Banner none

# Allow client to pass locale and color environment variables
AcceptEnv LANG LC_* COLORTERM NO_COLOR

# override default of no subsystems
Subsystem	sftp	/usr/lib/openssh/sftp-server

# Example of overriding settings on a per-user basis
#Match User anoncvs
#	X11Forwarding no
#	AllowTcpForwarding no
#	PermitTTY no
#	ForceCommand cvs server
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

### /etc/Login.defs
```
#
# /etc/login.defs - Configuration control definitions for the shadow package.
#

# REQUIRED for useradd/userdel/usermod
#   Directory where mailboxes reside, _or_ name of file, relative to the
#   home directory.  If you _do_ define MAIL_DIR and MAIL_FILE,
#   MAIL_DIR takes precedence.
#
#   Essentially:
#      - MAIL_DIR defines the location of users mail spool files
#        (for mbox use) by appending the username to MAIL_DIR as defined
#        below.
#      - MAIL_FILE defines the location of the users mail spool files as the
#        fully-qualified filename obtained by prepending the user home
#        directory before $MAIL_FILE
#
# NOTE: This is no more used for setting up users MAIL environment variable
#       which is, starting from shadow 4.0.12-1 in Debian, entirely the
#       job of the pam_mail PAM modules
#       See default PAM configuration files provided for
#       login, su, etc.
#
# This is a temporary situation: setting these variables will soon
# move to /etc/default/useradd and the variables will then be
# no more supported
MAIL_DIR        /var/mail
#MAIL_FILE      .mail

#
# Enable display of unknown usernames when login(1) failures are recorded.
#
# WARNING: Unknown usernames may become world readable.
# See #290803 and #298773 for details about how this could become a security
# concern
LOG_UNKFAIL_ENAB	no

#
# Enable logging of successful logins
#
LOG_OK_LOGINS		no

#
# If defined, file which maps tty line to TERM environment parameter.
# Each line of the file is in a format similar to "vt100  tty01".
#
#TTYTYPE_FILE	/etc/ttytype

#
# If defined, file which inhibits all the usual chatter during the login
# sequence.  If a full pathname, then hushed mode will be enabled if the
# user's name or shell are found in the file.  If not a full pathname, then
# hushed mode will be enabled if the file exists in the user's home directory.
#
HUSHLOGIN_FILE	.hushlogin
#HUSHLOGIN_FILE	/etc/hushlogins

#
# *REQUIRED*  The default PATH settings, for superuser and normal users.
#
# (they are minimal, add the rest in the shell startup files)
ENV_SUPATH	PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
ENV_PATH	PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games

#
# Terminal permissions for terminals after login(1).
# These settings are ignored for remote and other logins.
#
#	TTYGROUP	Login tty will be assigned this group ownership.
#	TTYPERM		Login tty will be set to this permission.
#
#TTYGROUP	tty
TTYPERM		0600

#
# Login configuration initializations:
#
#	ERASECHAR	Terminal ERASE character ('\010' = backspace).
#	KILLCHAR	Terminal KILL character ('\025' = CTRL/U).
#
# The ERASECHAR and KILLCHAR are used only on System V machines.
#
ERASECHAR	0177
KILLCHAR	025

# HOME_MODE is used by useradd(8) and newusers(8) to set the mode for new
# home directories.
HOME_MODE	0700

#
# Password aging controls:
#
#	PASS_MAX_DAYS	Maximum number of days a password may be used.
#	PASS_MIN_DAYS	Minimum number of days allowed between password changes.
#	PASS_WARN_AGE	Number of days warning given before a password expires.
#
PASS_MAX_DAYS	30
PASS_MIN_DAYS	2
PASS_WARN_AGE	7

#
# Min/max values for automatic uid selection in useradd(8)
#
UID_MIN			 1000
UID_MAX			60000
# System accounts
#SYS_UID_MIN		  101
#SYS_UID_MAX		  999
# Extra per user uids
SUB_UID_MIN		   100000
SUB_UID_MAX		600100000
SUB_UID_COUNT		    65536

#
# Min/max values for automatic gid selection in groupadd(8)
#
GID_MIN			 1000
GID_MAX			60000
# System accounts
#SYS_GID_MIN		  101
#SYS_GID_MAX		  999
# Extra per user group ids
SUB_GID_MIN		   100000
SUB_GID_MAX		600100000
SUB_GID_COUNT		    65536

#
# Max number of login(1) retries if password is bad
# This will most likely be overriden by PAM, since the default pam_unix module
# has it's own built in of 3 retries. However, this is a safe fallback in case
# you are using an authentication module that does not enforce PAM_MAXTRIES.
#
LOGIN_RETRIES		5

#
# Max time in seconds for login(1)
#
LOGIN_TIMEOUT		60

#
# Which fields may be changed by regular users using chfn(1) - use
# any combination of letters "frwh" (full name, room number, work
# phone, home phone).  If not defined, no changes are allowed.
# For backward compatibility, "yes" = "rwh" and "no" = "frwh".
#
CHFN_RESTRICT		rwh

#
# If set to MD5, MD5-based algorithm will be used for encrypting password
# If set to SHA256, SHA256-based algorithm will be used for encrypting password
# If set to SHA512, SHA512-based algorithm will be used for encrypting password
# If set to BCRYPT, BCRYPT-based algorithm will be used for encrypting password
# If set to YESCRYPT, YESCRYPT-based algorithm will be used for encrypting password
# If set to DES, DES-based algorithm will be used for encrypting password (default)
# MD5 and DES should not be used for new hashes, see crypt(5) for recommendations.
# Overrides the MD5_CRYPT_ENAB option
#
# Note: It is recommended to use a value consistent with
# the PAM modules configuration.
#
ENCRYPT_METHOD YESCRYPT

#
# Should login be allowed if we can't cd to the home directory?
# Default is no.
#
DEFAULT_HOME	yes

#
# The pwck(8) utility emits a warning for any system account with a home
# directory that does not exist.  Some system accounts intentionally do
# not have a home directory.  Such accounts may have this string as
# their home directory in /etc/passwd to avoid a spurious warning.
#
NONEXISTENT	/nonexistent

#
# If defined, this command is run when removing a user.
# It should remove any at/cron/print jobs etc. owned by
# the user to be removed (passed as the first argument).
#
#USERDEL_CMD	/usr/sbin/userdel_local

#
# If set to yes, userdel(8) will remove the user's group if it contains no more
# members, and useradd(8) will create by default a group with the name of the
# user.
#
# Other former uses of this variable are not used in PAM environments, such as
# Debian.
#
USERGROUPS_ENAB yes
➜  ~ sudo cat /etc/sudoers    
➜  ~ sudo cat /etc/pam.d/common-password 
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
password	requisite			pam_pwquality.so retry=3 ucredit=-1 lcredit=-1 dcredit=-1 reject_username maxrepeat=3 minlen=10 difok=7 enforce_for_root
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

# 3. Partitioning (LVM & Crypt)
echo -ne "Check: LVM & Encryption... "
if lsblk | grep -q "lvm" && lsblk | grep -q "crypt"; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} Missing LVM or Crypt tags in lsblk."
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