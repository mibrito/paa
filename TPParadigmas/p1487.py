class Ride():
    def __init__(self, duration, score):
        self.duration = duration
        self.score = score

    def __repr__(self):
        return "(duration: {}, score: {})".format(self.duration, self.score)

def SixFlags(rides, T):
    k = [[0] * (T+1) for i in range(len(rides) + 2)]

    for r in range(len(rides) + 1):
        for c in range(T+1):
            if r is 0 or c is 0:
                k[r][c] = 0
            elif rides[r-1].duration <= c:
                k[r][c] = max(rides[r-1].score + k[r][c - rides[r-1].duration], k[r-1][c])
            else:
                k[r][c] = k[r-1][c]


    return k[len(rides)][T]

def main():
    j = 0
    while True:
        rides = []

        line = raw_input().split()
        N = int(line[0])
        T = int(line[1])

        if N is 0:
            break

        for i in range(N):
            line = raw_input().split()
            rides.append(Ride(int(line[0]), int(line[1])))

        print(SixFlags(rides, T))

if __name__ == '__main__':
    main()
