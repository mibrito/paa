BLACK = 'b'
WHITE = 'w'
EMPTY = 'e'
GREY = 'g'

def compare (a, b):
    if (a is b and a is BLACK) or (a is BLACK and b is EMPTY) or (b is BLACK and a is EMPTY):
        return BLACK
    if (a is b and a is WHITE) or (a is WHITE and b is EMPTY) or (b is WHITE and a is EMPTY):
        return WHITE
    if a is b and a is EMPTY:
        return EMPTY
    return GREY

def go(S0, N, P):
    b = P
    w = P

    res = [None, None]

    for k in range(1, N):
        for i in range(N - k):
            for j in range((N - k) + 1):
                if j is 0:
                    res[0] = compare(S0[i][j], S0[i + 1][j])
                else:
                    res[1] = compare(S0[i][j], S0[i + 1][j])
                    S0[i][j-1] = compare(res[1], res[0])

                    b = (b + 1) if S0[i][j-1] is BLACK else b
                    w = (w + 1) if S0[i][j-1] is WHITE else w

                    res[0] = res[1]

        for l in S0:
            print("\t".join([str(i) for i in l]))
        print('')

    print(b, w)



def main():
    line = raw_input().split()
    N = int(line[0])
    P = int(line[1])

    board = [ ([EMPTY] * N) for i in range(N) ]

    for i in range(P):
        line = raw_input().split()
        board[int(line[0]) - 1][int(line[1]) - 1] = BLACK
    for i in range(P):
        line = raw_input().split()
        board[int(line[0]) - 1][int(line[1]) - 1] = WHITE

    go(board, N, P)

if __name__ == '__main__':
    main()
