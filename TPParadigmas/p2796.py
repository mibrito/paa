def divide (map, r0, r1, c0, c1):
    cm = ((c1 - c0) / 2)
    rm = ((r1 - r0) / 2)

    res = []

    # print "\t".join([str(r0), str(r1), str(c0), str(c1), str(rm), str(cm)])

    if rm < 0 or cm < 0:
        return None

    if (r1 <= r0 and c1 <= c0):
        return ((r0, r1, c0, c1), '.') if map[r0][c0] is '.' else None

    if r1 <= r0:
        a = divide(map, r0, r1, c0, c0 + cm)
        b = divide(map, r0, r1, c0 + cm + 1, c1)
        if a is b and a is None:
            return None
        else:
            return ((r0, r1, c0, c1), [a, b, None, None])

    if c1 <= c0:
        a = divide(map, r0, r0 + rm, c0, c1)
        c = divide(map, r0 + rm + 1, r1, c0, c1)
        if a is b and a is None:
            return None
        else:
            return ((r0, r1, c0, c1), [a, None, c, None])

    res = (
        (r0, r1, c0, c1),
        [
            divide(map, r0, r0 + rm, c0, c0 + cm),
            divide(map, r0, r0 + rm, c0 + cm + 1, c1),
            divide(map, r0 + rm + 1, r1, c0, c0 + cm),
            divide(map, r0 + cm + 1, r1, c0 + cm + 1, c1)
        ]
    )

    return res

def  main ():
    linha = raw_input().split()
    N =  int (linha[ 0 ])
    M =  int (linha[ 1 ])

    map = []
    for i in range(N):
        line = raw_input()
        map.append(line)

    tables = []
    K = int(raw_input())
    for i in range(K):
        line = raw_input().split()
        tables.append((int(line[0]), int(line[1])))

    print divide(map, 0, N-1, 0, M-1)


if __name__ == '__main__':
    main()

