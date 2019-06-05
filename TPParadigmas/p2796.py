EMPTY = '.'
FILLED = '#'

def quad(map, r0, r1, c0, c1):
    rm = (r1 - r0) / 2
    cm = (c1 - c0) / 2
    # if r1 is r0 and c0 is c1:
    #     return (1, 1) if map[r0][c0] is EMPTY else (0, 0)
    # elif r1 is not r0 and c0 is c1:
    #     a = quad(map, r0, r0 + rm, c0, c1)
    #     b = quad(map, r0 + rm + 1, r1, c0, c1)
    #     return (max(a[0], b[0]) - min(a[0], b[0]), r0)
    # elif r1 is r0 and c0 is not c1:
    #     a = quad(map, r0, r1, c0, c0 + cm)
    #     b = quad(map, r0, r1, c0 + cm + 1, c1)
    #     return (r0, max(a[1], b[1]) - min(a[1], b[1]))

    # if (r1 -  < )
    print(rm, cm)
    print('a', r0, r0 + rm, c0, c0 + cm)
    print('b', r0, r0 + rm, c0 + cm + 1, c1)

    print('c', r0 + rm + 1, r1, c0, c0 + cm)
    print('d', r0 + rm + 1, r1, c0 + cm + 1, c1)

    # a = quad(map, r0, r0 + rm, c0, c0 + cm)
    # b = quad(map, r0, r0 + rm, c0 + cm + 1, c1)
    # c = quad(map, r0 + rm + 1, r1, c0, c0 + cm)
    # d = quad(map, r0 + rm + 1, r1, c0 + cm + 1, c1)
    # return (max(a[0], b[0]) - min(a[0], b[0]), r0, max(a[1], b[1]) - min(a[1], b[1]))

def main():
    entry = raw_input().split()
    N = int(entry[0])
    M = int(entry[1])

    map = []
    for i in range(N):
        map.append(raw_input())

    K = int(raw_input())
    tables = []
    for i in range(K):
        entry = raw_input().split()
        tables.append((int(entry[0]), int(entry[1])))

    quad(map, 0, N-1, 0, M - 1)


if __name__ == '__main__':
    main()
