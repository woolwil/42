import sys

def check():
    # Load initial stack from arguments
    try:
        a = list(map(int, sys.argv[1:]))
    except ValueError:
        print("Error: Arguments must be integers")
        return

    b = []
    # Read moves from stdin (piped from push_swap)
    input_data = sys.stdin.read().strip()
    if not input_data:
        moves = []
    else:
        moves = input_data.split()
    
    for m in moves:
        if m == 'sa' and len(a) > 1: a[0], a[1] = a[1], a[0]
        elif m == 'sb' and len(b) > 1: b[0], b[1] = b[1], b[0]
        elif m == 'ss':
            if len(a) > 1: a[0], a[1] = a[1], a[0]
            if len(b) > 1: b[0], b[1] = b[1], b[0]
        elif m == 'pa' and b: a.insert(0, b.pop(0))
        elif m == 'pb' and a: b.insert(0, a.pop(0))
        elif m == 'ra' and a: a = a[1:] + [a[0]]
        elif m == 'rb' and b: b = b[1:] + [b[0]]
        elif m == 'rr':
            if a: a = a[1:] + [a[0]]
            if b: b = b[1:] + [b[0]]
        elif m == 'rra' and a: a = [a[-1]] + a[:-1]
        elif m == 'rrb' and b: b = [b[-1]] + b[:-1]
        elif m == 'rrr':
            if a: a = [a[-1]] + a[:-1]
            if b: b = [b[-1]] + b[:-1]
        else:
            # Catch typos like "ra " or invalid instructions
            print(f"Error: Invalid instruction '{m}'")
            return

    # Winning conditions: Stack B is empty AND Stack A is sorted
    if not b and a == sorted(a):
        print("OK")
    else:
        print("KO")
        print(f"Final Stack A: {a}")
        print(f"Final Stack B: {b}")

if __name__ == "__main__":
    check()