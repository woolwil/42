# Born2beroot

*This file serves as a reference guide for the author of this project (ngvo), this is **NOT** _README.md_.*

## Temporary Credentials
<details>

**Root**:

Velkemale123?

**ngvo**:

Nevimcodelat123!

**Encryption**:

SuperMegaDlouheHeslo!123
</details>

## Configuration
https://baigal.medium.com/born2beroot-e6e26dfb50ac

### 0. Installing Vim, Git, Oh my Zsh
<details>

**0.1 Vim**
- `apt-get update -y`
- `apt-get upgrade -y`
- `apt-get install vim -y`

**0.1.1. Configure VIM**
- `vim ~/.vimrc
	- `syntax on`
	- `set showcmd`
	- `set incsearch`
	- `set showmatch`
	- `set mouse=a`
	- `set number`
	- `set tabstop=4`
	- `set shiftwidth=4`

**0.2. Git**
- update and upgrade like usual
- `apt-get install git -y`
- `git --version`

**0.3. Oh my zsh**
- first install zsh
- `apt install zsh`
` $ sh -c "$(wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"`
</details>

### 1. Creating/Deleting users
<details>

**1.1. Creating a new user:**
- `adduser "name"`

**1.2. Deleting a user and all files, dirs associated with the user:**
- `deluser "name" --remove-home`

**1.3. Check userlist:**
- `cat /etc/passwd`

**1.4. Check specific user:**
- `cat /etc/passwd | grep "keyword"`

**1.5. Adding user in sudo group**
- `su -`
- `usermod -aG sudo username`
- more details in section 4.

**1.6 Creating Groups**
- `$ sudo groupadd user42`
- `$ sudo groupadd evaluating`

**1.7. Double-check creation**
- `$ getent group`

</details>

### 2. Firewall
<details>

https://wiki.debian.org/Uncomplicated%20Firewall%20(ufw)

**2.0 Install UFW**
- `apt-get install ufw`
**2.1 Enable Firewall:**

- `ufw enable`

**2.2 Firewall status:**

- `ufw status verbose`
- `ufw status numbered`

**2.3 Allowing new rules:**

- `ufw allow "X"`
- `sudo ufw allow ssh`
- `sudo ufw allow 4242`

**2.4 Deleting already existing rules:**

- `ufw delete "allow 'X'"`
- `ufw delete "number"`

**2.5 Allowing a port example (allow a range by typing X:Y):**

- `ufw allow 4242/tcp` 

**2.6 Allowing from an IP:**

- `ufw allow from XX:XX:XX:XX`
</details>

### 3. SSH Config
<details>
https://wiki.debian.org/SSH#SSH_Server

**3.0 Install SSH**
- `apt-get update -y`
- `apt-get install openssh-server` 

**3.1 Check status of SSH**
- Via **systemd**
	- `systemctl status ssh` 

**3.2. Reset SSH service through systemd command**
- Via **systemd**
	- `systemctl restart ssh`
- Via **service** (a wrapper, essentially script that redirects to systemd)
	- `service ssh restart`

**3.3 Deny root ssh login and set only allow one port:**
- within the file `/etc/ssh/sshd_config`
- `PermitRootLogin no`
- `Port 4242`
- double check port with `sudo grep Port /etc/ssh/sshd_config`
- MAKE SURE TO DELETE '#'

**3.4 Setting up Port Forward within VM**
- VM Settings -> Network -> Port Forwarding
	- Protocol: `TCP`
	- Host Port: `4242`
	- Guest Port: `4242`

**3.5 Connecting to VM through host machine**
- In Host Machine Terminal
	- `ssh ngvo@localhost -p 4242`
- Troubleshooting: 
- `@ WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED! @
IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!
Someone could be eavesdropping on you right now (man-in-the-middle attack)!
It is also possible that a host key has just been changed.`

- to fix just: `ssh-keygen -f "/home/ngvo/.ssh/known_hosts" -R "[localhost]:4242"`
</details>

### 4. SUDO Security and Access Config
<details>
https://www.sudo.ws/docs/man/sudoers.man/

**4.0. Install sudo**
- `apt-get update -y`
- `apt-get upgrade -y`
- `apt install sudo`

**4.1 Change Visudo Editor**
- `sudo update-alternatives --config editor`

**4.2 Tightening Security**

**4.2.0. Password Quality Checking Library (libpam-pwquality)**
- `$ sudo apt-get install libpam-pwquality`
- length: 
	- `$ sudo vim /etc/pam.d/common-password`
	- find this line: `password [success=2 default=ignore] pam_unix.so obscure sha512`
	- And add an extra word: `minlen=10` at the end.
		- `password [success=1 default=ignore] pam_unix.so obscure use_authtok try_first_pass yescrypt minlen=10`
- min 1 lowcase, min 1 upcase, min 1 digit, max same letter repetition 3
	- find `password    requisite         pam_pwquality.so retry=3`
	- `password    requisite         pam_pwquality.so retry=3 lcredit =-1 ucredit=-1 dcredit=-1 maxrepeat=3 usercheck=0 difok=7 enforce_for_root`

**4.2.1 Sudo Password Config**

- **Visudo (editing sudoers)**
	- add this into last line:
		- `your_username    ALL=(ALL) ALL`
	- `Defaults	passwd_tries=3`
	- `Defaults badpass_message="Incorrect password, try again."`

- `/etc/login.defs` (THIS ONLY OVERRIDES FOR FUTURE NEW USERS)
	- `PASS_MAX_DAYS	30`
	- `PASS_MIN_DAYS	2`
	- `PASS_WARN_AGE	7`
- TO MANUALLY EDIT EXISTING USERS
	- `chage -M/W/m [days] [user]`
	- To doublecheck after the change
		- `chage -l [user]`

**4.3 I/O Logging**

https://www.sudo.ws/docs/man/sudoers.man/#I/O_LOGGING

- **Visudo**
	- `Defaults log_input`
	- `Defaults log_output`
	- `Defaults iolog_dir="/var/log/sudo"`
	- `Defaults logfile="/var/log/sudo/sudo.log`

**4.4 Terminal Requirement (Teletypewriter TTY)**

- `Defaults requiretty`
	- only allows sudo being executed within terminal, restricts scripts for example

</details>

### 5. Secure User Access (PAM)
<details>
https://www.debian.org/doc/manuals/securing-debian-manual/ch04s11.en.html
https://manpages.debian.org/testing/libpam-pwquality/pam_pwquality.8.en.html

- **5.1 Setting Password Complexity**
	- Edited within: `/etc/pam.d/common-password`
	- Minimum Length (10): `minlen = 10`
	- Minimum Lowercase Char (1): `lcredit=-1`
	- Minimum Uppercase Char (1): `ucredit=-1`
	- Minimum Digit Chars (1): `dcredit=-1`
	- Max Repeating Chars (3): `maxrepeat=3`
	- No Identity Contained: `usercheck=0` 
	- Difference: 7 chars diff from old password: `difok=7`
	- Enforce for Root: `enforce_for_root`
</details>

### 6. Hostname
<details>

**6.1 Current Hostname**
- `hostnamectl`

**6.2. Change Hostname**
- `hostnamectl set-hostname new_hostname`
- edit `/etc/hosts file`
	- change old_hostname with new_hostname
- `sudo reboot`

</details>

### 7. AppArmor
<details>
https://wiki.debian.org/AppArmor/HowToUse

**7.1. Installation**
- Debian 10 or newer already has AppArmor up and running
- check status through `sudo aa-status`

</details>

### 8. monitoring.sh

<details>

**8.1 Necessary Tools**
- `apt-get update -y`
- `apt-get install net-tools -y`

**8.2 Writing Information**
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
- **Final Result**
<details>

```#!/bin/bash

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
sudoc=$(cat /var/log/sudo/sudo.log | grep "COMMAND" | wc -l)

/usr/bin/wall << EOF
		#Architecture: $arc
		#CPU physical: $pcpu
		#vCPU: $vcpu
		#Memory Usage: $uram/${tram}MB ($pram%)
		#Disk Usage: $udis/${tdis}b ($pdis)
		#CPU Load: $cpul
		#Last Boot: $lb
		#LVM Use: $lvmu
		#TCP Connections: $ctcp ESTABLISHED
		#User Log: $ulog
		#Network: IP $ip ($mac)
		#Sudo: $sudoc cmd
EOF
```
</details>

- **CRON**
	- **daemon**
		- program that runs as a background process, independent of direct user interaction, designed to perform specific tasks or services when triggered by certain events or conditions
	- Status Check: `systemctl status cron`
	- Stop Scheduler (Interrupt): `sudo systemctl stop cron`
	- Restart: `sudo systemctl start cron`
	- `$ sudo crontab -u root -e`
			- `*/10 * * * * sh /usr/local/bin/monitoring.sh`
</details>

### For Evaluation

**1. Debian vs Rocky Linux**

**2. AppArmor vs SELinux**

**3. UFW vs firewalld**

**VirtualBox vs UTM**