#!/usr/bin/env python3


def secure_archive(filename: str, action: str = 'read',
                   content: str = '') -> tuple[bool, str]:
    try:
        if action == 'read':
            with open(filename, 'r') as file:
                data = file.read()
                return True, data
        elif action == 'write':
            with open(filename, 'w') as file:
                file.write(content)
            return True, "Content successfully written to file"
        else:
            return False, f"Unknown action: {action}"
    except OSError as e:
        return False, str(e)


def main() -> None:
    file1 = '/not/existing/file'
    file2 = '/etc/master.passwd'
    file3 = '../ex0/ancient_fragment.txt'

    print("=== Cyber Archives Security ===")
    print()
    print("Using 'secure_archive' to read from a nonexistent file:")
    print(f"{secure_archive(file1)}\n")
    print("Using 'secure_archive' to read from a inaccessible file:")
    print(f"{secure_archive(file2)}\n")
    print("Using 'secure_archive' to read from a regular file:")
    success, retrieved_content = secure_archive(file3)
    print(f"{(success, retrieved_content)}\n")
    print("Using 'secure_archive' to write previous content to a new file:")
    if success:
        print(f"{secure_archive('new_vault.txt', 'write', retrieved_content)}")


if __name__ == "__main__":
    main()
