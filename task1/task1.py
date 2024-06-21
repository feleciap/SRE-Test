import sys

def circular_array_path(n, m):
    path = []
    current_index = 0

    for _ in range(n):
        path.append((current_index % n) + 1)
        current_index = (current_index + m -1) % n
    
    return ''.join(map(str, path))

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 task1.py <n> <m>")
        sys.exit(1)

    n = int(sys.argv[1])
    m = int(sys.argv[2])

    result = circular_array_path(n, m)
    print(result)

