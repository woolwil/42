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

For detailed commands and steps, refer to [`NOTES2.md`](./NOTES2.md).

## Design Choices

### Operating System
- Choices: Debian vs. Rocky Linux.
- Justification for the selected OS, including pros and cons.

### Partitioning
- Usage of LVM for encrypted partitions.
- Flexibility and scalability of logical volumes.

### Security Policies
- Password strength and aging settings.
- Hardened sudo configuration and logging.

### Networking and Remote Access
- SSH hardening, including port changes and key-based authentication.
- Firewall setup with UFW (or alternative).

### Tools and Customizations
- Zsh as the default shell (pros and cons vs. Bash).
- AppArmor (vs. SELinux).

## Setup Guide

Refer to the step-by-step instructions in:
- [`NOTES2.md`](./NOTES2.md) for setup.
- Highlights include:
  - Installing required packages.
  - Configuring the sudoers file.
  - Adding monitoring scripts as a systemd service.

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

- Project instructions: [Born2beRoot Subject PDF](#)
- Tutorials and blogs: 
  - [Medium guide](https://baigal.medium.com/born2beroot-e6e26dfb50ac).