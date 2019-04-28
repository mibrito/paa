import sys

WHITE = 'w'
GREY = 'g'
BLACK = 'b'
INF = 9999999

class Graph:
    N = M = 0
    dMax = 0
    dMin = 0
    adj = {}

    def __init__(self, N, M):
        self.N = N
        self.M = M
        for i in range(1, self.N+1):
            self.adj[i] = []

    def addEdge(self, a, b):
        self.adj[a].append(b)
        self.adj[b].append(a)

    def bfs(self, start):
        color = {i: WHITE for i in range(1, self.N+1)}
        d = {i: INF for i in range(1, self.N+1)}

        queue = [start]
        d[start] = 0
        while queue:
            n = queue.pop(0)
            for i in self.adj[n]:
                if color[i] is WHITE:
                    color[i] = GREY
                    d[i] = d[n] + 1
                    queue.append(i)
            color[n] = BACK
        # print(d)
        return d

def main (filename):
    f = open(filename, 'r')
    (N, M) = f.readline().split()
    graph = Graph(int(N), int(M))

    for i in range(1, graph.M+1):
        (a, b) = f.readline().split()
        graph.addEdge(int(a), int(b))

    # for i in range(1, self.N+1):
    #     (c, d) = readline
    f.close()

    nodes = {i: False for i in range(1, graph.N+1)}
    for i in range(1, graph.N+1):
        d = graph.bfs(i)


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('Usage: python main.py <graph.in>')
    else:
        main(sys.argv[1])
