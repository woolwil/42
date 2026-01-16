*This project has been created as part of the 42 curriculum by ngvo.*

## Summary

This document serves as both a design specification and operational audit guide for a hardened Debian server implementation. The system has been configured according to industry security standards and 42 project requirements, with emphasis on privilege management, encryption, network security, and automated monitoring.

## Tools and Environment

| Component | Version/Name | Purpose |
|-----------|--------------|---------|
| **Operating System** | Debian 13.3.0 | Base system |
| **Virtualization** | Oracle VM VirtualBox | VM platform |
| **Security Framework** | AppArmor | Mandatory access control |
| **Firewall** | UFW (Uncomplicated Firewall) | Network filtering |
| **Shell** | Zsh with Oh My Zsh | Enhanced administration interface |

## Table of Contents

1. [Architecture and Design Decisions](#architecture-and-design-decisions)
   - [Operating System Selection](#operating-system-selection)
   - [Storage Architecture](#storage-architecture)
   - [Security Framework](#security-framework)
2. [Security Configuration Standards](#security-configuration-standards)
   - [Password Policy Compliance](#password-policy-compliance)
   - [Sudo Privilege Management](#sudo-privilege-management)
   - [Network Security](#network-security)
3. [System Verification Procedures](#system-verification-procedures)
   - [Partition and Encryption Audit](#partition-and-encryption-audit)
   - [User and Group Compliance](#user-and-group-compliance)
   - [Security Policy Verification](#security-policy-verification)
   - [Network Service Audit](#network-service-audit)
4. [Monitoring and Automation](#monitoring-and-automation)
5. [Evaluation Guidance](#evaluation-guidance)
6. [Technical Reference](#technical-reference)

---

## Architecture and Design Decisions

### Operating System Selection

**Selected Platform: Debian 13.3.0**

**Rationale:**
- **Stability**: Debian stable releases are renowned for reliability in production environments
- **Package Ecosystem**: APT package manager provides robust dependency resolution and security updates
- **Security Integration**: Native AppArmor support for mandatory access control
- **Documentation**: Extensive community resources and official documentation
- **Industry Adoption**: Widely deployed in enterprise server environments

**Alternative Considered: Rocky Linux**
- Provides enterprise-grade SELinux integration
- RHEL-compatible ecosystem
- More complex configuration overhead
- Better suited for environments requiring fine-grained security contexts

### Storage Architecture

**Logical Volume Manager (LVM) with Full Disk Encryption**

The system implements a three-layer storage abstraction:

```
Physical Disk → Physical Volume (PV) → Volume Group (VG) → Logical Volumes (LV) → Filesystems
                      ↓
                 [Encryption Layer]
```

**Architecture Components:**

| Layer | Purpose | Benefits |
|-------|---------|----------|
| **Physical Volume (PV)** | Raw disk partition prepared for LVM | Hardware abstraction |
| **Volume Group (VG)** | Pool aggregating multiple PVs | Flexible storage pooling |
| **Logical Volumes (LV)** | Virtual partitions carved from VG | Dynamic resizing, snapshots |
| **Encryption** | LUKS full-disk encryption | Data-at-rest protection |

**Strategic Advantages:**
- **Scalability**: Volumes can be resized without downtime
- **Flexibility**: Storage can span multiple physical disks
- **Security**: Full-disk encryption protects against physical theft
- **Maintenance**: Snapshot capabilities for safe system updates

### Security Framework

**AppArmor vs SELinux Analysis**

| Feature | AppArmor (Implemented) | SELinux (Alternative) |
|---------|------------------------|----------------------|
| **Model** | Path-based profiles | Label-based contexts |
| **Complexity** | Lower learning curve | Steeper learning curve |
| **Granularity** | Application-focused | Process/user/role contexts |
| **Management** | Profile-based configuration | Policy-based configuration |
| **Debian Integration** | Native, enabled by default | Requires additional setup |

**Implementation Decision**: AppArmor was selected for its balance of security and manageability, aligning with Debian's default security posture.

---

## Security Configuration Standards

### Password Policy Compliance

The system enforces enterprise-grade password standards through PAM (Pluggable Authentication Modules) and aging policies.

**Complexity Requirements** (`/etc/pam.d/common-password`):

| Parameter | Value | Enforcement |
|-----------|-------|-------------|
| Minimum Length | 10 characters | `minlen=10` |
| Uppercase Required | At least 1 | `ucredit=-1` |
| Lowercase Required | At least 1 | `lcredit=-1` |
| Digit Required | At least 1 | `dcredit=-1` |
| Max Repeating Chars | 3 consecutive | `maxrepeat=3` |
| Difference from Previous | 7 characters | `difok=7` |
| Username Exclusion | Enforced | `usercheck=1` |
| Root Enforcement | Yes | `enforce_for_root` |

**Password Aging Policy** (`/etc/login.defs`):

| Policy | Value | Purpose |
|--------|-------|---------|
| Maximum Age | 30 days | Force regular password rotation |
| Minimum Age | 2 days | Prevent rapid password cycling |
| Warning Period | 7 days | Advance notification before expiry |

### Sudo Privilege Management

**Configuration Location**: `/etc/sudoers` (edited via `visudo`)

**Security Directives Implemented**:

| Directive | Value | Security Purpose |
|-----------|-------|------------------|
| `passwd_tries` | 3 | Limit brute-force attempts |
| `badpass_message` | Custom error | Security through obscurity (limited feedback) |
| `logfile` | `/var/log/sudo/sudo.log` | Centralized audit trail |
| `log_input` | Enabled | Record all commands typed |
| `log_output` | Enabled | Record all command output |
| `iolog_dir` | `/var/log/sudo/` | I/O log storage location |
| `requiretty` | Enforced | Prevent automated/backgrounded sudo |
| `secure_path` | Restricted PATH | Prevent PATH hijacking |

### Network Security

**SSH Hardening** (`/etc/ssh/sshd_config`):

| Parameter | Value | Security Impact |
|-----------|-------|-----------------|
| `Port` | 4242 | Non-standard port reduces automated attacks |
| `PermitRootLogin` | no | Prevents direct root access |
| `PasswordAuthentication` | yes | Password auth enabled per requirements |

**Firewall Configuration (UFW)**:

| Rule | Policy | Justification |
|------|--------|---------------|
| Default Incoming | DENY | Whitelist approach |
| Default Outgoing | ALLOW | Permit system updates |
| Port 4242/TCP | ALLOW | SSH access only |

**VM Network Configuration**:
- Port Forwarding: Host `4242` → Guest `4242`
- Connection from host: `ssh ngvo@localhost -p 4242`

---

## System Verification Procedures

### Partition and Encryption Audit

**Procedure: Verify LVM and Encryption Implementation**

```bash
# Display complete block device structure
lsblk

# Expected output should show:
# - 'crypt' type for encrypted volumes
# - 'lvm' type for logical volumes

# Verify physical volumes
sudo pvs
sudo pvdisplay

# Verify volume groups
sudo vgs
sudo vgdisplay

# Verify logical volumes
sudo lvs
sudo lvdisplay
```

### User and Group Compliance

**Procedure: Audit User Accounts and Group Memberships**

```bash
# List all users with UID >= 1000 (human users)
awk -F: '$3 >= 1000 {print $1, $3}' /etc/passwd

# Verify specific user's group memberships
groups ngvo

# Expected: ngvo sudo user42

# Verify group membership lists
getent group sudo
getent group user42

# Check for unauthorized users
awk -F: '$3 >= 1000 && $1 != "nobody" {print $1}' /etc/passwd
```

**Password Status Verification**:

```bash
# Check password status for all users
sudo passwd -S username

# Status codes:
# P = Password set
# N = No password (SECURITY RISK)
# L = Locked (cannot login)
```

**Adding Users During Evaluation**:

```bash
# Create new user
sudo adduser evaluator

# Add to required groups
sudo usermod -aG user42 evaluator

# Set password
sudo passwd evaluator
```

### Security Policy Verification

**Procedure: Password Aging Compliance Check**

```bash
# Verify aging settings in configuration
grep "^PASS_MAX_DAYS\|^PASS_MIN_DAYS\|^PASS_WARN_AGE" /etc/login.defs

# Expected output:
# PASS_MAX_DAYS   30
# PASS_MIN_DAYS   2
# PASS_WARN_AGE   7

# Check specific user's aging settings
sudo chage -l ngvo
sudo chage -l root
```

**Procedure: Password Complexity Verification**

```bash
# Review PAM password quality settings
grep "pam_pwquality.so" /etc/pam.d/common-password

# Expected parameters:
# retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 
# maxrepeat=3 difok=7 usercheck=1 enforce_for_root
```

**Procedure: Sudo Configuration Audit**

```bash
# Display sudo configuration (requires sudo)
sudo cat /etc/sudoers | grep "Defaults"

# Verify sudo log directory exists and has correct permissions
ls -ld /var/log/sudo
sudo ls -l /var/log/sudo/

# Review recent sudo activity
sudo tail -n 20 /var/log/sudo/sudo.log

# Count total sudo commands executed
sudo grep -c "COMMAND" /var/log/sudo/sudo.log
```

### Network Service Audit

**Procedure: SSH Service Verification**

```bash
# Check SSH service status
sudo systemctl status ssh

# Verify SSH configuration
grep "^Port\|^PermitRootLogin\|^PasswordAuthentication" /etc/ssh/sshd_config

# Expected:
# Port 4242
# PermitRootLogin no
# PasswordAuthentication yes

# Test that root login is disabled (should fail)
ssh root@localhost -p 4242
```

**Procedure: Firewall Status Check**

```bash
# Display firewall status and rules
sudo ufw status verbose

# List numbered rules
sudo ufw status numbered

# Verify only port 4242 is open
sudo ufw status | grep "4242"
```

**Procedure: Active Network Connections**

```bash
# Show all TCP listening ports
ss -tuln

# Show only established connections
ss -tun | grep ESTAB

# Count active TCP connections (monitoring script logic)
ss -ta | grep ESTAB | wc -l
```

**Procedure: AppArmor Status**

```bash
# Check if AppArmor is enabled
sudo aa-status --enabled
echo $?  # Should return 0

# Display AppArmor profile status
sudo aa-status
```

---

## Monitoring and Automation

### System Monitoring Script

**Location**: `/usr/local/bin/monitoring.sh`

**Purpose**: Automated system metrics collection and broadcast, executed every 10 minutes via cron.

**Why `/usr/local/bin/`?**
- Follows Filesystem Hierarchy Standard (FHS)
- Administrator-managed scripts (vs. `/usr/bin/` for OS packages)
- Protected from package manager overwrites
- Included in system `$PATH`

**Metrics Collected**:

| Metric | Data Source | Extraction Method |
|--------|-------------|-------------------|
| Architecture | `uname -a` | Full system information |
| Physical CPUs | `/proc/cpuinfo` | Count unique `physical id` entries |
| Virtual CPUs | `/proc/cpuinfo` | Count `processor` entries |
| Memory Usage | `free -m` | Parse `Mem:` line for used/total/percentage |
| Disk Usage | `df -m /` | Extract used/total/percentage for root filesystem |
| CPU Load | `top -bn1` | Calculate 100 - idle% from `%Cpu` line |
| Last Boot | `who -b` | System boot timestamp |
| LVM Active | `lsblk` | Check for "lvm" in output |
| TCP Connections | `ss -ta` | Count ESTABLISHED connections |
| Logged Users | `users` | Count words (each user is one word) |
| Network Info | `hostname -I`, `ip link` | IP address and MAC address |
| Sudo Commands | `/var/log/sudo/sudo.log` | Count "COMMAND" entries |

**Script Logic Examples**:

```bash
# Physical CPU count (unique physical processors)
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)

# Memory usage percentage
pram=$(free -m | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# Disk usage extraction (NR==2 selects second line)
udis=$(df -m / | awk 'NR==2 {print $3}')  # Used
tdis=$(df -m / | awk 'NR==2 {print $2}')  # Total
pdis=$(df -m / | awk 'NR==2 {print $5}')  # Percentage

# CPU load (100 - idle%)
cpul=$(top -bn1 | grep "^%Cpu" | awk -F '[ ,]+' '{printf("%.1f%%"), 100 - $8}')

# LVM detection
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
```

**Automation via Cron**:

```bash
# View root's crontab
sudo crontab -u root -l

# Expected entry:
*/10 * * * * /usr/local/bin/monitoring.sh

# Cron daemon management
sudo systemctl status cron        # Check status
sudo systemctl stop cron          # Stop scheduler (for evaluation)
sudo systemctl start cron         # Restart scheduler
```

**Script Permissions**:
```bash
# Verify ownership and permissions
ls -l /usr/local/bin/monitoring.sh

# Expected: -rwxr-xr-x root root
sudo chown root:root /usr/local/bin/monitoring.sh
sudo chmod +x /usr/local/bin/monitoring.sh
```

---

## Evaluation Guidance

### Comparison Topics

**Debian vs Rocky Linux**

**RHEL** (Red Hat Enterprise Linux): The corporate, paid, "bank-grade" version of Linux. Focuses on stability and support.  
**Rocky Linux**: The free, 1:1 copy of **RHEL** used in this project as an alternative to Debian.
| Aspect | Debian | Rocky Linux |
|--------|--------|-------------|
| **Base** | Independent distribution | RHEL-compatible (Enterprise) |
| **Release Cycle** | Stable, Testing, Unstable | Point releases (8.x, 9.x) |
| **Package Manager** | APT (dpkg) | DNF (RPM) |
| **Security Module** | AppArmor (default) | SELinux (default) |
| **Support Model** | Community-driven | Enterprise-focused |
| **Use Case** | General purpose, servers | Enterprise, RHEL migration |

**APT vs Aptitude**

| Feature | apt | aptitude |
|---------|-----|----------|
| **Interface** | Command-line only | CLI + ncurses TUI |
| **Dependency Resolution** | Standard | Advanced (suggests solutions) |
| **User Level** | Modern, simplified | Power users, complex scenarios |
| **Speed** | Faster | Slightly slower |
| **Automation** | Better for scripts | Better for interactive problem-solving |

**UFW vs firewalld**

| Aspect | UFW | firewalld |
|--------|-----|-----------|
| **Default Platform** | Debian/Ubuntu | RHEL/CentOS/Rocky |
| **Complexity** | Simple, straightforward | More complex, more features |
| **Configuration Model** | Profile-based | Zone-based (Home, Public, Drop Zone) |
| **Rule Management** | Static (requires reload) | Dynamic (runtime changes) |
| **Syntax** | `ufw allow 4242` | `firewall-cmd --add-port=4242/tcp` |
| **Backend** | iptables/nftables | iptables/nftables |

**AppArmor vs SELinux**

| Feature | AppArmor | SELinux |
|---------|----------|---------|
| **Security Model** | Path-based profiles | Label-based contexts |
| **Complexity** | Lower, easier to learn | Higher, more powerful |
| **Scope** | Application-centric | Process/file/user/role contexts |
| **Configuration** | Text-based profiles | Policy modules |
| **Enforcement Modes** | Complain, Enforce | Permissive, Enforcing, Disabled |
| **Best For** | Application containment | Multi-level security, fine-grained control |

### Virtualization: VirtualBox vs. UTM
**QEMU**: Open-source emulator/virtualizer used by UTM for cross-platform virtualization.

| Feature | VirtualBox | UTM |
|---------|------------|-----|
| **Platform Support** | Windows, macOS (Intel), Linux | macOS only |
| **Apple Silicon Support** | ❌ Not supported | ✅ Native ARM support |
| **Technology** | Native hypervisor | QEMU-based emulation |
| **Best For** | Cross-platform, Intel Macs | Apple Silicon Macs |

### Hostname Verification

```bash
# Display current hostname
hostname

# Expected: ngvo42 (or your_login42)

# Display detailed hostname info
hostnamectl

# Verify hostname resolution
cat /etc/hosts | grep 127.0.1.1
```

### Quick Audit Script

The system includes a comprehensive audit script at `/usr/local/bin/full_audit.sh` that performs automated compliance checks:

```bash
# Run comprehensive audit (requires sudo)
sudo /usr/local/bin/full_audit.sh
```

**Checks Performed**:
- GUI absence verification
- Hostname compliance
- LVM and encryption presence
- AppArmor status
- Firewall configuration
- SSH security settings
- Sudo policy compliance
- User group memberships
- Cron job presence
- Password aging policy
- Password complexity (PAM)
- Unauthorized user detection
- Unauthorized group detection

---

## Technical Reference

### Essential Command Reference

**User Management**:

| Command | Purpose |
|---------|---------|
| `sudo adduser username` | Create new user interactively |
| `sudo usermod -aG group username` | Add user to group |
| `sudo userdel --remove username` | Delete user and home directory |
| `groups username` | Show user's group memberships |
| `getent group groupname` | Show group members |
| `sudo passwd -S username` | Check password status |
| `sudo chage -l username` | View password aging settings |

**System Information**:

| Command | Purpose |
|---------|---------|
| `uname -a` | Complete system information |
| `lsblk` | Block device tree view |
| `df -h` | Filesystem disk usage |
| `free -h` | Memory usage |
| `ss -tuln` | Network socket statistics |
| `who -b` | Last system boot time |

**Service Management**:

| Command | Purpose |
|---------|---------|
| `sudo systemctl status service` | Check service status |
| `sudo systemctl start service` | Start service |
| `sudo systemctl stop service` | Stop service |
| `sudo systemctl restart service` | Restart service |
| `sudo systemctl enable service` | Enable at boot |

**Security Auditing**:

| Command | Purpose |
|---------|---------|
| `sudo aa-status` | AppArmor status and profiles |
| `sudo ufw status verbose` | Detailed firewall status |
| `sudo tail -f /var/log/sudo/sudo.log` | Monitor sudo activity |
| `sudo cat /etc/sudoers` | View sudo configuration |
| `grep "^PASS" /etc/login.defs` | Password aging defaults |

### Configuration File Locations

| File/Directory | Purpose |
|---------------|---------|
| `/etc/ssh/sshd_config` | SSH server configuration |
| `/etc/sudoers` | Sudo privilege rules |
| `/etc/login.defs` | Password aging defaults |
| `/etc/pam.d/common-password` | Password complexity rules (PAM) |
| `/etc/hosts` | Hostname resolution |
| `/var/log/sudo/` | Sudo logging directory |
| `/usr/local/bin/` | Administrator custom scripts |

### Cron Schedule Format

```
* * * * * command_to_execute
│ │ │ │ │
│ │ │ │ └─── Day of week (0-7, Sunday = 0 or 7)
│ │ │ └───── Month (1-12)
│ │ └─────── Day of month (1-31)
│ └───────── Hour (0-23)
└─────────── Minute (0-59)

Examples:
*/10 * * * *    Every 10 minutes
0 */2 * * *     Every 2 hours
0 0 * * *       Daily at midnight
```

---

## Resources

**Official Documentation**:
- [Debian Administrator's Handbook](https://debian-handbook.info/)
- [Filesystem Hierarchy Standard](https://refspecs.linuxfoundation.org/FHS_3.0/fhs-3.0.pdf)
- [PAM System Administrator's Guide](http://www.linux-pam.org/Linux-PAM-html/Linux-PAM_SAG.html)
- [SSH Best Practices](https://www.ssh.com/academy/ssh/config)

**Project Resources**:
- Born2beRoot Subject PDF (42 Intranet)
- [Medium Implementation Guide](https://baigal.medium.com/born2beroot-e6e26dfb50ac)
- [gemartin99's Born2BeRoot guide](https://noreply.gitbook.io/born2beroot/installing-debian/configure-the-package-manager)
- [Born2BeRoot Progress Tracker](https://born2beroot-tracking.pages.dev/)

---

[![Helped by Gemini](https://img.shields.io/badge/Logic%20Audit%20by-Google%20Gemini-4285F4?logo=googlegemini&logoColor=white)](https://gemini.google.com/)

**Google Gemini**: Provided technical logic auditing, security hardening recommendations, and script optimization to ensure compliance with project mandatory requirements.

[![AI-Assisted](https://img.shields.io/badge/Maintained%20with-GitHub%20Copilot-blue?logo=githubcopilot)](https://github.com/features/copilot)

**GitHub Copilot**: Assisted with documentation structure, Markdown formatting, and technical writing enhancements.

---

**Document Version**: 2.0  
**Last Updated**: January 2026  
