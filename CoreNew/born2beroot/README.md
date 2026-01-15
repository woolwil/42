# Born2beRoot Project

*This project has been created as part of the 42 curriculum by ngvo.*

## Description

An in-depth guide to provisioning, securing, and configuring a Debian (or Rocky Linux) server following the specifications of the Born2beRoot project. This project emphasizes:
- Security and privilege management.
- Strong scripting skills and automation.
- Compliance with industry-standard server setups.

## Table of Contents

1. [Instructions](#instructions)
2. [Design Choices](#design-choices)
3. [Setup Guide](#setup-guide)
4. [Evaluation Checklist](#evaluation-checklist)
5. [References](#references)

## Instructions

This project requires the implementation of:
1. Partitioning and disk encryption using LVM.
2. Security practices (e.g., sudo policies, AppArmor, SSH configuration).
3. Account and user group management.
4. Monitoring and logging functionalities.

## Design Choices

### Operating System
**Choice: Debian**

Debian was selected for this project due to:
- **Stability**: Known for its rock-solid stable releases, ideal for server environments.
- **Package Management**: APT package manager is straightforward and well-documented.
- **Community Support**: Extensive documentation and large community.
- **AppArmor**: Native integration with AppArmor for mandatory access control.

*Comparison: Rocky Linux would provide SELinux and enterprise-grade security, but Debian's simplicity and widespread adoption make it more accessible for learning foundational server administration.*

### Partitioning
**LVM with Encryption**

The project uses Logical Volume Manager (LVM) with full disk encryption:
- **Physical Volume (PV)**: Raw partition on the disk.
- **Volume Group (VG)**: Pool combining all physical volumes.
- **Logical Volumes (LV)**: Virtual partitions (e.g., `/home`, `/var`) that can be resized on-the-fly.

This approach adds abstraction between physical disks and the file system, enabling:
- Easy resizing of partitions without downtime.
- Combining multiple disks into a single volume group.
- Encrypted partitions for enhanced security.
- Scalability for future storage needs.

### Security Policies
**Password Requirements:**
- Minimum length: 10 characters
- Must contain: uppercase, lowercase, and digit
- Maximum 3 consecutive repeating characters
- Must differ by at least 7 characters from previous password
- Username cannot be contained in password
- Enforced for root as well

**Password Aging:**
- Maximum age: 30 days
- Minimum age: 2 days
- Warning period: 7 days before expiration

**Sudo Hardening:**
- Maximum 3 password attempts
- Custom error messages
- Full I/O logging to `/var/log/sudo/`
- TTY requirement for sudo execution
- Restricted secure_path

### Networking and Remote Access
**SSH Configuration:**
- Custom port: 4242 (instead of default 22)
- Root login: Disabled (`PermitRootLogin no`)
- Password authentication: Enabled for project requirements

**Firewall (UFW):**
- Default policy: Deny incoming, allow outgoing
- Only port 4242 allowed for SSH
- Active and enabled on boot

**Port Forwarding:**
- VM configured with port forwarding: Host 4242 → Guest 4242
- Allows SSH from host machine: `ssh ngvo@localhost -p 4242`

### Tools and Customizations
**Zsh with Oh My Zsh:**
- Enhanced shell with better auto-completion and customization
- Syntax highlighting: Commands turn green if valid, red if invalid
- Sudo plugin: Press `Esc` twice to prepend `sudo` to previous command
- Git shortcuts: `gst` instead of `git status`
- Improved navigation with arrow keys through file menus

**AppArmor vs SELinux:**
- **AppArmor** (chosen for Debian):
  - Path-based security model
  - Lower complexity, easier to manage
  - Focuses on restricting specific applications
- **SELinux** (Rocky/RHEL alternative):
  - Label-based security model
  - More complex but more granular control
  - Can restrict users, roles, and types

**Additional Tools:**
- Vim with custom configuration for better usability
- libpam-pwquality for password complexity enforcement

## Setup Guide

Key implementation highlights:
1. **System Initialization**:
   - Update system packages
   - Install required tools: `vim`, `git`, `sudo`, `ufw`, `openssh-server`, `libpam-pwquality`, `net-tools`, `zsh`

2. **User & Group Management**:
   - Create `user42` group
   - Add user to `sudo` and `user42` groups

3. **Security Configuration**:
   - Configure sudo policies via `visudo`
   - Set password complexity in `/etc/pam.d/common-password`
   - Configure password aging in `/etc/login.defs`

4. **Network & SSH**:
   - Configure SSH on port 4242
   - Set up UFW firewall rules

5. **Monitoring Script**:
   - Create `/usr/local/bin/monitoring.sh` to display system metrics
   - Schedule with cron to run every 10 minutes
   - Broadcasts to all terminals using `wall`

## Evaluation Checklist

- Basic functionality tests such as SSH access and monitoring script outputs.
- Security compliance checks:
  - Firewall and port configurations.
  - LVM and encryption verification.
  - Correct user permissions.
- Key configurations:
  - Sudo access policies.
  - Password complexity rules.

## References

- **Project instructions**: Born2beRoot Subject PDF
- **Tutorials and blogs**: 
  - [Medium guide](https://baigal.medium.com/born2beroot-e6e26dfb50ac).