BLACK = -1
WHITE = 1
EMPTY = 0
GREY = None

R = 0
C = 0

def isBlack(x):
    return x is BLACK

def isWhite(x):
    return x is WHITE

def isGrey(x):
    return x is None

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

    cols = [None, None]
    rows = [None, None]

    for k in range(1, N):
        for i in range(N - k):
            for j in range((N - k) + 1):
                if j is 0:
                    cols[0] = compare(S0[i][j], S0[i + 1][j])
                    rows[0] = compare(S0[j][i], S0[j][i + 1])
                if j is 1:
                    cols[1] = compare(S0[i][j], S0[i + 1][j])
                    rows[1] = compare(S0[j][i], S0[j][i + 1])

                    S0[i][j-1] = compare(cols[0], cols[1])

                    b = (b + 1) if S0[i][j-1] is BLACK else b
                    w = (w + 1) if S0[i][j-1] is WHITE else w
                else:
                    cols[1] = compare(S0[i][j], S0[i + 1][j])
                    rows[0] = compare(S0[j][i], S0[j][i + 1])

                    S0[i][j-1] = compare(cols[0], cols[1])
                    S0[j-1][i] = compare(cols[0], cols[1])

                    b = (b + 1) if S0[i][j-1] is BLACK else b
                    b = (b + 1) if S0[j-1][i] is BLACK else b
                    w = (w + 1) if S0[i][j-1] is WHITE else w
                    w = (w + 1) if S0[j-1][i] is WHITE else w

                    cols[0] = cols[1]
                    rows[0] = rows[1]

        for l in S0:
            print("\t".join([str(i) for i in l]))
        print('')

    print(b, w)



def main():
    line = raw_input().split()
    N = int(line[0])
    P = int(line[1])

    black = []
    white = []
    board = [ ([0] * N) for i in range(N) ]

    for i in range(P):
        line = raw_input().split()
        board[int(line[0]) - 1][int(line[1]) - 1] = BLACK
        black.append((int(line[0]) - 1, int(line[1]) - 1))
    for i in range(P):
        line = raw_input().split()
        board[int(line[0]) - 1][int(line[1]) - 1] = WHITE
        white.append((int(line[0]) - 1, int(line[1]) - 1))

    print(black)
    print(white)

    go(board, N, P)

if __name__ == '__main__':
    main()
