BLACK = -1
WHITE = 1
EMPTY = 0

def isBlack(x):
    return x is BLACK

def isWhite(x):
    return x is WHITE

def isNone(x):
    return x is None

def go(board, N, P):
    b = P
    w = P

    S0 = board
    for k in range(1, N):
        for i in range(N - k):
            for j in range((N - k) + 1):
                if j is 0:
                    black0 = isBlack(S0[i][j]) or isBlack(S0[i + 1][j])
                    white0 = isWhite(S0[i][j]) or isWhite(S0[i + 1][j])
                    none0 = isNone(S0[i][j]) or isNone(S0[i + 1][j])
                else:
                    black1 = isBlack(S0[i][j]) or isBlack(S0[i + 1][j])
                    white1 = isWhite(S0[i][j]) or isWhite(S0[i + 1][j])
                    none1 = isNone(S0[i][j]) or isNone(S0[i + 1][j])

                    black = black0 or black1
                    white = white0 or white1
                    none = none0 or none1

                    black0 = black1
                    white0 = white1
                    none0 = none1

                    if (black and not white and not none):
                        S0[i][j-1] = BLACK
                        b = b + 1
                    elif (white and not black and not none):
                        S0[i][j-1] = WHITE
                        w = w + 1
                    elif (none and not black and not white):
                        S0[i][j-1] = 0
                    else:
                        S0[i][j-1] = None

    print(b, w)



def main():
    line = raw_input().split()
    N = int(line[0])
    P = int(line[1])

    board = [ ([0] * N) for i in range(N+1) ]

    for i in range(P):
        line = raw_input().split()
        board[int(line[0]) - 1][int(line[1]) - 1] = BLACK
    for i in range(P):
        line = raw_input().split()
        board[int(line[0]) - 1][int(line[1]) - 1] = WHITE

    go(board, N, P)

if __name__ == '__main__':
    main()
