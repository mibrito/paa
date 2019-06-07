import math

def dim(r):
    return ((r[1] - r[0] + 1), (r[3] - r[2] + 1))

def adj(a, b):
    merge = False
    for i in range(len(a)):
        for j in range(len(b)):
            if (max(a[i], b[j]) - min(a[i], b[j]) <= 1):
                return True

def merge(a, b):
    if (a[:2] == b[:2]) and adj(a[2:], b[2:]):
        return [a[:2] + (min(a[2:] + b[2:]), max(a[2:] + b[2:]))]
    elif (a[2:] == b[2:]) and adj(a[:2], b[:2]):
        return [(min(a[:2] + b[:2]), max(a[:2] + b[:2])) + a[2:]]
    else:
        return [a, b]

def mergeAll(l):
    merged = [False] * len(l)
    res = []
    for i in range(len(l)):
        for j in range(i+1, len(l)):
            m = merge(l[i], l[j])
            print l[i], l[j], m
            if len(m) is 1:
                merged[i] = True
                merged[j] = True
                res = res + m
        if not merged[i]:
            res = res + [l[i]]
            print l[i]
    return res

def divide (map, r0, r1, c0, c1):
    cm = ((c1 - c0) / 2)
    rm = ((r1 - r0) / 2)

    res = []

    print 'divide', (r0, r1, c0, c1), rm, cm

    if rm < 0 or cm < 0:
        print 'A'
        return []

    if (r1 == r0 and c1 == c0):
        print 'B'
        if map[r0][c0] is '.':
            print (r0, r1, c0, c1)
        return [(r0, r1, c0, c1)] if map[r0][c0] is '.' else []

    elif r1 <= r0 and c1 == c0:
        a = divide(map, r0, r1, c0, c0 + cm)
        b = divide(map, r0, r1, c0 + cm + 1, c1)
        m = mergeAll(a + b)
        print 'C'
        print 'a', a, 'b', b, 'm', m
        return m

    elif c1 <= c0 and r1 == r0:
        a = divide(map, r0, r0 + rm, c0, c1)
        c = divide(map, r0 + rm + 1, r1, c0, c1)
        m = mergeAll(a + b)
        print 'D'
        print 'a', a, 'c', c, 'm', m
        return m

    res = mergeAll(
        divide(map, r0, r0 + rm, c0, c0 + cm) +
        divide(map, r0, r0 + rm, c0 + cm + 1, c1) +
        divide(map, r0 + rm + 1, r1, c0, c0 + cm) +
        divide(map, r0 + cm + 1, r1, c0 + cm + 1, c1)
    )

    print 'E'
    # print res
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

    # l = [
    #     (0, 0, 0, 0),
    #     (1, 1, 1, 1),
    #     (0, 0, 3, 3),
    #     (1, 1, 2, 2),
    #     (1, 1, 3, 3),
    #     (2, 2, 0, 0),
    #     (2, 2, 2, 2),
    #     (2, 2, 3, 3),
    #     (3, 3, 3, 3)
    # ]

    rects = mergeAll(divide(map, 0, N-1, 0, M-1))
    # print rects
    # areas = sorted([(dim(r), r)  for r in rects], key=lambda x: max(x[0]))
    # tables = sorted(tables, key=lambda x: max(x))

    # for t in tables:
    #     for a in areas:
    #         if a[0][0] >= t[0] and a[0][1] >= t[1]:
    #             print t[0], t[1]
    #             return



if __name__ == '__main__':
    main()
