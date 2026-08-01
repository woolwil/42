#!/usr/bin/env python3

import sys
import os
import site

venv_success = r"""SUCCESS: You're in an isolated environment!
Safe to install packages without affecting
the global system."""

instructions = r"""To enter the construct, run:
python -m venv matrix_env
source matrix_env/bin/activate # On Unix
matrix_env\Scripts\activate # On Windows

Then run this program again.
"""

in_venv = (sys.prefix != sys.base_exec_prefix) or ("VIRTUAL_ENV" in os.environ)

cur_py = sys.executable
venv_name = os.path.basename(sys.prefix)
env_path = sys.prefix
pkg_install_path = site.getsitepackages()[0]
if in_venv:
    print("MATRIX STATUS: Welcome to the construct\n")
    print(f"Current Python: {cur_py}")
    print(f'Virtual Environment: {venv_name}')
    print(f"Environment Path: {env_path}\n")
    print(venv_success + '\n')
    print("Package installation path:")
    print(pkg_install_path)
else:
    print("MATRIX STATUS: You're still plugged in\n")
    print(f"Current Python: {cur_py}")
    print('Virtual Environment: "None Detected"\n')
    print("WARNING: You're in the global environment!\n"
          "The machines can see everything you install.\n")
    print(instructions)
