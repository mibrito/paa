BLACK = -1
WHITE = 1
EMPTY = 0
GREY = None

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

    # for k in range(1, N):
    for i in reversed(range(N)):
        for j in range(N - 1):
            v = None
            if (i + j + 1) < N:
                x = compare(S0[i + j][i + 1], S0[i+j+1][i+1])
                y = compare(S0[i + j + 1][i], S0[i+j+1][i+1])
                v = compare(S0[i + j][i], compare(x, y))
            if (i - j - 1) >= 0:
                x = compare(S0[i - j][i - 1], S0[i - j - 1][i - 1])
                y = compare(S0[i - j - 1][i], S0[i - j - 1][i - 1])
                v = compare(S0[i - j][i], compare(x, y))
            if v is BLACK:
                b = b + 1
            elif v is WHITE:
                w = w + 1

    for l in S0:
        print("\t".join([str(i) for i in l]))

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
