BLACK = -1
WHITE = 1
EMPTY = 0

R = 0
C = 0

def isBlack(x):
    return x is BLACK

def isWhite(x):
    return x is WHITE

def isGrey(x):
    return x is None

def go(S0, N, P):
    b = P
    w = P

    black = [[False] * 2 for i in range(2)]
    white = [[False] * 2 for i in range(2)]
    grey = [[False] * 2 for i in range(2)]

    for k in range(1, N):
        for i in range(N - k):
            for j in range((N - k) + 1):
                if j is 0:
                    black[C][0] = isBlack(S0[i][j]) or isBlack(S0[i + 1][j])
                    white[C][0] = isWhite(S0[i][j]) or isWhite(S0[i + 1][j])
                    grey[C][0] = isGrey(S0[i][j]) or isGrey(S0[i + 1][j])
                else:
                    black[C][1] = isBlack(S0[i][j]) or isBlack(S0[i + 1][j])
                    white[C][1] = isWhite(S0[i][j]) or isWhite(S0[i + 1][j])
                    grey[C][1] = isGrey(S0[i][j]) or isGrey(S0[i + 1][j])

                    _black = black[C][0] or black[C][1]
                    _white = white[C][0] or white[C][1]
                    _grey = grey[C][0] or grey[C][1]

                    black[C][0] = black[C][1]
                    white[C][0] = white[C][1]
                    grey[C][0] = grey[C][1]

                    if (_black and not _white and not _grey):
                        S0[i][j-1] = BLACK
                        b = b + 1
                    elif (_white and not _black and not _grey):
                        S0[i][j-1] = WHITE
                        w = w + 1
                    elif (_grey and not _black and not _white):
                        S0[i][j-1] = 0
                    else:
                        S0[i][j-1] = None

    print(b, w)



def main():
    line = raw_input().split()
    N = int(line[0])
    P = int(line[1])

    black = []
    white = []
    board = [ ([0] * N) for i in range(N+1) ]

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
