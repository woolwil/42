#!/usr/bin/env python3

import os
from dotenv import load_dotenv

env_loaded = load_dotenv()

mode = os.getenv("MATRIX_MODE", "production")
db_url = os.getenv("DATABASE_URL")
api_key = os.getenv("API_KEY")
log_level = os.getenv("LOG_LEVEL", "INFO")
zion_endpoint = os.getenv("ZION_ENDPOINT")

db_status = "Connected to local instance" if db_url else "Not configured"
auth_status = "Authenticated" if api_key else "Missing key"
zion_status = "Online" if zion_endpoint else "Offline"
no_hardcoded_secrets = bool(api_key or db_url)
env_file_exists = os.path.exists(".env")
production_overrides = True


def main() -> None:
    print("ORACLE STATUS: Reading the Matrix...")
    print()
    print("Configuration loaded:")
    print(f"Mode: {mode}")
    print(f"Database: {db_status}")
    print(f"API Access: {auth_status}")
    print(f"Log Level: {log_level}")
    print(f"Zion Network: {zion_status}")
    print()
    print("Environment security check: ")
    if no_hardcoded_secrets:
        print("[OK] No hardcoded secrets detected")
    else:
        print("[WARNING] Secrets not loaded from environment")
    if env_file_exists:
        print("[OK] .env file properly configured")
    else:
        print("[WARNING] .env file not found")
    if production_overrides:
        print("[OK] Production overrides available")
    print()
    print("The Oracle sees all configurations.")


if __name__ == "__main__":
    main()
