import sys

t = int(input())

for _i in range(t):
    r, c = [int(x) for x in input().split()]
    
    colors = []

    for _j in range(r):
        for _k in range(c):
            colors.append('B' if sys.stdin.read(1) == 'B' else ' ')
        sys.stdin.readline()

    input() # for blank space

    for _j in range(r):
        for _k in range(c):
            chx = sys.stdin.read(1)
            idx = _j * c + _k
            if colors[idx] == 'B':
                continue
            colors[idx] = 'R' if chx in ['R', 'B'] else 'G'
        sys.stdin.readline()

    for _j in range(r):
        for _k in range(c):
            print(colors[_j * c + _k], end="")
        print()

    print(end='\n' if _i != t - 1 else '')
