#!/usr/bin/env python3


def secure_archive(
    filename: str, action: str = "read", content: str = ""
) -> tuple[bool, str]:
    try:
        if action == "read":
            with open(filename, "r") as file:
                data = file.read()
                return True, data
        elif action == "write":
            with open(filename, "w") as file:
                file.write(content)
            return True, "Content successfully written to file"
        else:
            return False, f"Invalid action: {action}"
    except OSError as e:
        return False, str(e)


def main() -> None:
    nonexistent = "/not/existing/file"
    inaccessible = "/etc/shadow"
    sample_file = "ancient_fragment.txt"
    sample_text = (
        "[FRAGMENT 001] Digital preservation protocols established 2087\n"
        "[FRAGMENT 002] Knowledge must survive the entropy wars\n"
        "[FRAGMENT 003] Every byte saved is a victory against oblivion\n"
    )

    try:
        with open(sample_file, "w") as f:
            f.write(sample_text)
    except OSError:
        pass

    print("=== Cyber Archives Security ===")
    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive(nonexistent))
    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive(inaccessible))
    print("Using 'secure_archive' to read from a regular file:")
    success, retrieved = secure_archive(sample_file)
    print((success, retrieved))
    print("Using 'secure_archive' to write previous content to a new file:")
    if success:
        print(secure_archive("new_vault.txt", "write", retrieved))


if __name__ == "__main__":
    main()
