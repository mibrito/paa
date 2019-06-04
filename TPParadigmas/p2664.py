
def ginastica(T, M, N):
    nValues = N - M + 1
    S = [[0] * (T + 1) for i in range(nValues)]

    for t in range(1, T + 1):
        for i in range(nValues):
            if t is 1:
                S[i][t] = 1
            else:
                if i > 0:
                    S[i][t] = S[i][t] + S[i - 1][t - 1]
                if i < nValues - 1:
                    S[i][t] = S[i][t] + S[i + 1][t - 1]

    return sum([S[i][T] for i in range(nValues)])

def main():
    entry = raw_input().split()
    T = int(entry[0])
    M = int(entry[1])
    N = int(entry[2])
    print(ginastica(T, M, N))

if __name__ == '__main__':
    main()
