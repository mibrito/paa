class Ride():
    def __init__(self, duration, score):
        self.duration = duration
        self.score = score

    def __repr__(self):
        return "(duration: {}, score: {})".format(self.duration, self.score)

def SixFlags(Rides, T):
    m = [[0] * T for i in ]

def main():
    while True:
        try:
            line = input().split()
            N = int(line[0])
            T = int(line[1])

            for i in range(N):
                line = input().split()
        except EOFError:
            break

if __name__ == '__main__':
    main()
