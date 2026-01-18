# born2beRoot: Methodical Implementation Guide

This guide follows a logical progression for setting up your Debian server according to the 42 subject requirements.

## Table of Contents

1. [Temporary Credentials](#temporary-credentials)
2. [Configuration](#configuration)
3. [Initial Tooling & Prerequisites](#1-initial-tooling--prerequisites)
4. [User & Group Management](#2-user--group-management)
5. [Sudo Security Configuration](#3-sudo-security-configuration)
   - [Configure Visudo](#31-configure-visudo)
   - [Password Policy (PAM & Aging)](#32-password-policy-pam--aging)
6. [Network & SSH Hardening](#4-network--ssh-hardening)
7. [Hostname & OS Identity & AppArmor](#5-hostname--os-identity--apparmor)
8. [Monitoring Script](#6-monitoring-script-monitoringsh-usrlocalbinmonitoringsh)
9. [Verification Checklist](#7-verification-checklist)
10. [Evaluation](#8-evaluation)

## Temporary Credentials
<details>

**Root**:  
rootpw  
Velkemale123  
Upperlower123

**ngvo**:  
ngvopw  
Nevimcodelat123  
Whatdoido123

**Encryption**:  
encryptionpw  
SuperMegaDlouheHeslo!123
</details>

## Configuration
https://baigal.medium.com/born2beroot-e6e26dfb50ac

## 1. Initial Tooling & Prerequisites

Before configuring security, we need the necessary tools. Log in as root.

**1.1 Update System**

- `apt-get update -y && apt-get upgrade -y`


**1.2 Install Required Packages**

- `apt-get install vim git sudo ufw openssh-server libpam-pwquality net-tools zsh wget -y`

**1.3 Set Zsh as default**
- `sh -c "$(wget -O- https://install.ohmyz.sh/)"`  

**1. 3. 1. OPTIONAL - Syntax Highlighting and Sudo shortcuts**
-	green if command exists, red if not
- `git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting`
- `vim ~/.zshrc`
- change `plugins=(git)` to `plugins=(git zsh-syntax-highlighting sudo)`
- `source ~/.zshrc`

**1.4 Configure Vim**
- `u` undo
- `ctrl + r` re-do
- `/` search
	- pressing `n` will go to next 
- deleting entire line by positioning cursor at desired line and type `dd`

- `vim ~/.vimrc` for user-bound settings
- `vim /etc/vim/vimrc` for global

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

## 2. User & Group Management

Set up the required account structure.

**2.1 Create Groups**
- `groupadd user42`
- `groupdel`

**2.2 Create User & Assign Groups**

Replace your_login with your actual 42 username.
- `adduser your_login`
- `usermod -aG sudo,user42 your_login`

Deleting a user and all files, dirs associated with the user
- `userdel "name" --remove`

Check userlist
- `cat /etc/passwd`

**2.3 Verification**
- `getent group user42`
- `getent group sudo`
- `getent group` gets all groups available

**2.4 Bugfix**
- if someone were to create a new user but did not add password
	- `sudo passwd -S [username] # | awk '$2 {print $2}'`
		- 2nd column
			- P (has password)
			- N (no password) **security risk**
			- L (locked) cannot be logged into

## 3. Sudo Security Configuration

Tighten sudo access as per the "Mandatory Part" requirements.

**Change Visudo Editor**
- `sudo update-alternatives --config editor`

### 3.1 Configure Visudo

Run `visudo` or `visudo -f /etc/sudoers.d/ngvo` and add these configuration lines:

**Password attempt limit**

- `Defaults passwd_tries=3`

**Custom error message**

- `Defaults badpass_message="Incorrect password, try again."`

**Initialize Log Directory**

- `mkdir -p /var/log/sudo`

**I/O Logging**

- `Defaults logfile="/var/log/sudo/sudo.log"`
- `Defaults iolog_dir="/var/log/sudo"`
- `Defaults log_input`
- `Defaults log_output`

**Security Requirements**

- `Defaults requiretty`
- `Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"`


### 3.2 Password Policy (PAM & Aging)

Enforce the strong password policy requirements.

**Password Aging (/etc/login.defs)**

Set defaults for future users:

- `PASS_MAX_DAYS   30`
- `PASS_MIN_DAYS   2`
- `PASS_WARN_AGE   7`

Apply to existing accounts (root and your login):

- `chage -M 30 -m 2 -W 7 your_login`
- `chage -M 30 -m 2 -W 7 root`
- `passwd your_username` to set new password under new rules
To doublecheck the changes:
- `chage -l "user"`

**Complexity Rules (/etc/pam.d/common-password)**

Find the pam_pwquality.so line and modify it:

- `password requisite pam_pwquality.so retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 difok=7 reject_username enforce_for_root`

- Minimum Length (10): `minlen=10`
- Minimum Lowercase Char (1): `lcredit=-1`
- Minimum Uppercase Char (1): `ucredit=-1`
- Minimum Digit Chars (1): `dcredit=-1`
- Max Repeating Chars (3): `maxrepeat=3`
- No Identity Contained: `reject_username` 
- Difference: 7 chars diff from old password: `difok=7`
- Enforce for Root: `enforce_for_root`

## 4. Network & SSH Hardening
Secure remote access and the local firewall.

- Status: 
`systemctl status ssh`

### Configure SSH
Edit /etc/ssh/sshd_config:

- `Port 4242` (Uncomment and change)
- `PermitRootLogin no`
- `PasswordAuthentication yes` (Verify this is set)

Restart service:
- `systemctl restart ssh`

### UFW Firewall

- `ufw default deny incoming`
- `ufw default allow outgoing`
- `ufw allow 4242`
- `ufw enable`
- `ufw status verbose/numbered`

### Setting up Port Forward within VM
- VM Settings -> Network -> Port Forwarding
	- Protocol: `TCP`
	- Host Port: `4242`
	- Guest Port: `4242`

**Connecting to VM through host machine**
- In Host Machine Terminal
	- `ssh ngvo@localhost -p 4242`
- Troubleshooting: 
```
@ WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED! @
IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!
Someone could be eavesdropping on you right now (man-in-the-middle attack)!
It is also possible that a host key has just been changed.
...
```

- Fix: `ssh-keygen -f "/home/ngvo/.ssh/known_hosts" -R "[localhost]:4242"`

## 5. Hostname & OS Identity & AppArmor

- Set the hostname as required by the subject (login42).

**Set Hostname**

- `hostnamectl set-hostname your_login42`

**Update Hosts File (/etc/hosts)**

- Replace the old name with your_login42 next to 127.0.1.1.
- Reboot to apply changes

**AppArmor**

- `aa-status` to check AA status

## 6. Monitoring Script monitoring.sh (usr/local/bin/monitoring.sh)

Create the script to display system info every 10 minutes.
Why **/usr/local/bin/**?
Standardization: It follows the Filesystem Hierarchy Standard (FHS).

System Admin Territory: /usr/bin/ is for the OS (managed by apt). /usr/local/bin/ is for you (the administrator).

Safe from Updates: Files here won't be overwritten or deleted during a system update.

Global Access: It's in your $PATH, so you can run `monitoring.sh` from any folder without typing the full path.

<details>

### REDUNDANT IGNORE THIS PART: 
### Create a systemd service 
I REPEAT **DO NOT DO THE SYSTEMD IT IS REDUNDANT!**
- essentially tells the system to wait until env is ready to run this ...
- `sudo vim /etc/systemd/system/monitoring.service`

```
[Unit]
Description=Monitoring script for Born2beroot
After=multi-user.target

[Service]
Type=simple
ExecStart=/usr/bin/zsh /usr/local/bin/monitoring.sh

[Install]
WantedBy=multi-user.target
```
- `sudo systemctl daemon-reload` (Refreshes list of services)
- `sudo systemctl enable monitoring.service` (Ensures it runs at boot)
- `sudo systemctl start monitoring.service` (Runs it right now to test)

### Making sure it runs on PTS running on Zsh (pseudo-terminals)
- `sudo vim /etc/zsh/zprofile`
	- on bottom line: `/usr/local/bin/monitoring.sh`
</details>

### monitoring.sh script
- **line 1**: define interpreter: `#!/bin/bash`
- **Architecture:** `arc=$(uname -a)`
- **CPU**
	- **Physical CPU:** `/proc/cpuinfo`
	- count of pCPUs -> look for `physical id`
	-	`pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)`
		- **logic:**
			- `sort` Groups all identical IDs together so uniq can "see" them.
			- `uniq` Squashes those adjacent duplicates into a single line.
			- `wc -l` count lines
				- In this case, it counts that final, unique list (1) to give you the number of physical chips.
	- **vCPU (Threads):**  count `processor`
		- **logic:** processor is a core, on a 2 core system, there will be '2' processor lines
			- we count the number of "processor" lines, which means 2 cores.
- **Memory**
	- `free` shows information about RAM usage
	- `-m` flag displays values in MiB (mebibytes)
	-  **Memory Usage: [Used]/[Total]MB ([Percentage]%)**
		- `tram=$(free -m | awk '$1 == "Mem:" {print $2}')`
		- `uram=$(free -m | awk '$1 == "Mem:" {print $3}')`
		- `pram=$(free -m | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')`
- **Disk Usage Explanation**
	- `udis` gets the used disk space (in MB) for the root filesystem by extracting the 3rd column from the second line of `df -m /` output.
	- `tdis` gets the total disk space (in MB) for the root filesystem by extracting the 2nd column from the same output.
	- `pdis` gets the percentage of disk space used (e.g., 42%) by extracting the 5th column.
	- Use:
		- `udis=$(df -m / | awk 'NR==2 {print $3}')`
		- `tdis=$(df -m / | awk 'NR==2 {print $2}')`
		- `pdis=$(df -m / | awk 'NR==2 {print $5}')`
		- **NR==2** selects second line
	- This logic ensures you report both the absolute and relative disk usage for the root partition, which is required for the monitoring script output.
- **CPU Load**
	- `top` interactive dashboard (scripts cannot interact)
		`-b` batch mode -> output is in plain text
		- `n1` number of iterations (1), takes just one snapshot and stops
	- `grep "^%Cpu"`
		- `grep` for row
		- `^` grabs the line that **starts** with `%Cpu`
			- prevents accidental grab of other lines that mention "cpu"
	- `awk` prints selected column
		- `-F '[ ,]+'` treat **spaces** and **commas** as a separator, cut them into columns
		- `100 - $8` 
			- $8 is the location of idle %  
			- math to calculate total % usage
		- `printf("%.1f%%")` 
			- formats the result to one decimal place and adds a literal % sign at the end.
- **Last Boot**
	- `who` shows who is logged on
		- `-b, --boot` time of last system boot
- **LVM Use**
	- `if` + `-gt 0`, `lsblk`, `grep`, `wc -l`
	- `lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0]; then echo yes, else echo no; fi)
	- `if` Everything inside the square brackets is the condition we are checking.
	- `-gt 0` This stands for "Greater Than 0." 
		- It checks if the number of LVM lines found by wc -l is at least 1.
	- `; then` "If the condition above is true, do the following..."
	- `echo yes` `else echo no`
	- `fi` if but backwards, `if` statement is finished
- **TCP Connections**
	- `ss`
		- `-t` displays TCP sockets
		- `-a` displays both listening and non listening
			- for **TCP** -> established connoections sockets
- **Users Log**
	- `users`
	- `wc -w` returns counted words
	- `users | wc -w` 
- **IP & MAC**
	- `hostname -I`
		- `-I` gives IP
	- `ip` show/manipulate routing, network devices...
		- requires an option -> `link` -> network device
			- this prints out MAC Address
	- `ip link | grep "link/ether" | awk '{print $2}'
- **Sudo**
	- `sudo.log` was configured to be in `/var/log/sudo`
		- `sudoc=$(cat /var/log/sudo/sudo.log | grep "COMMAND" | wc -l)`
			- no `sudo` needed because it will be ran by the system as root (cron)

```
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

**6.1 Schedule Task (Cron)**

- `chown root:root /usr/local/bin/monitoring.sh`
	- for extra safety, makes `root` the **owner**
- `chmod +x /usr/local/bin/monitoring.sh`
- `crontab -u root -e`
- `/etc/crontab`

Add at the bottom: `*/10 * * * * /usr/local/bin/monitoring.sh`

- **daemon**
	- A background process (daemon) that performs automated tasks without user interaction.
	- Status Check: `systemctl status cron`
	- Stop Scheduler (Interrupt): `sudo systemctl stop cron`
	- Restart: `sudo systemctl start cron`
	- `$ sudo crontab -u root -e`

## 7. Verification Checklist

- AppArmor: `aa-status` (Should be enabled)

- Firewall: `ufw status` (Only 4242 open)

- SSH: Root login forbidden? `ssh root@localhost -p 4242` (Should fail)

- LVM: `lsblk` (Check encrypted partitions)

## 8. Evaluation

### README.md
-  description section must explain 
	- the choice of operating system (Debian or Rocky), with their respective pros and cons
	- It must indicate the main design choices made during the setup 
		- partitioning
		- security policies
		- user management
		- services installed

### Rocky vs Debian

### Zsh > Bash?
- Zsh is much more customizable. It’s what gives you that nice ➜ prompt, better tab-completion, and plugin support (like Oh My Zsh).
	- **Oh my Zsh!**
		- `gst` instead of `git status`
		- type command but forgot `sudo` -> `esc` twice
		- Menu Selection: `Tab` opens a menu you can navigate with arrow keys
		- Case Insensitivity: `cd desk` and hit Tab, it knows you meant `cd Desktop`
		- Smart Completion: If you type `kill` and hit Tab, a list opens up to choose from

### SELinux vs AppArmor
- **SELinux**
	- Model
		- Label-based: Security depends on labels attached to files/processes.
	- Complexity
		- High; very detailed, lots of elements and powerful but harder to learn.
	- Control: 
		- Can restrict users, roles, and types (very detailed).
- **AppArmor**
	- Model: 
		- Path-based: Security is tied to the file's location on the disk.
	- Complexity: 
		- Lower; easier to write and manage profiles.
	- Control: 
		- Focuses on restricting specific applications.

### aptitude vs apt

### UFW vs firewalld

### LVM
- adds a layer of abstraction between the physical disk and the file system 
	- allowing us to combine multiple disks into a single Volume Group 
	- this makes the system flexible because we can resize logical volumes on the fly without needing to unmount disks or worry about contiguous space

In this project, I used it to create a specific encrypted partition structure that can be easily scaled if the server's storage needs grow.

- **PV (Physical Volume)**: The raw partition on your actual disk.

- **VG (Volume Group)**: The "pool" where you combine all your PVs.

- **LV (Logical Volume)**: The "virtual partition" you actually use and format (like your /home or /var).

### New user and SSH test
- `adduser evaluator`
	- attempt bad password
- `groupadd evaluator user42`
- `ssh evaluator@localhost -p 4242`
- more details in [Users...](#2-user--group-management)

### Monitoring Script

### Final Double-Check (/usr/local/bin/full_audit.sh)

`sudo chown root:root /usr/local/bin/full_audit.sh`

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
# Simplified to check for 4242 generally, without forcing /tcp
if sudo ufw status | grep -q "4242" && sudo ufw status | grep -q "ALLOW"; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} Port 4242 not open in UFW."
fi

# 10. Password Aging Policy (Defaults)
echo -ne "Check: Password Aging Defaults (30/2/7)... "
MAX=$(grep "^PASS_MAX_DAYS" /etc/login.defs | awk '{print $2}')
MIN=$(grep "^PASS_MIN_DAYS" /etc/login.defs | awk '{print $2}')
WARN=$(grep "^PASS_WARN_AGE" /etc/login.defs | awk '{print $2}')
if [ "$MAX" = "30" ] && [ "$MIN" = "2" ] && [ "$WARN" = "7" ]; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} login.defs: Max:$MAX Min:$MIN Warn:$WARN"
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

# 10. Password Aging Policy (Defaults)
echo -ne "Check: Password Aging Defaults (30/2/7)... "
MAX=$(grep "^PASS_MAX_DAYS" /etc/login.defs | awk '{print $2}')
MIN=$(grep "^PASS_MIN_DAYS" /etc/login.defs | awk '{print $2}')
WARN=$(grep "^PASS_WARN_AGE" /etc/login.defs | awk '{print $2}')
if [ "$MAX" = "30" ] && [ "$MIN" = "2" ] && [ "$WARN" = "7" ]; then
    echo -e "${GREEN}[PASS]${NC}"
else
    echo -e "${RED}[FAIL]${NC} login.defs: Max:$MAX Min:$MIN Warn:$WARN"
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
