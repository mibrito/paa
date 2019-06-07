WALL = '#'
SPACE = '.'

def maxSubArraySum(a,size):

    max_so_far = a[0] 
    curr_max = a[0]

    for i in range(1,size):
        curr_max = max(a[i], curr_max + a[i])
        max_so_far = max(max_so_far,curr_max)

    return max_so_far

def contiguous(line):
    res = []
    space = 0
    for i in range(len(line)):
        if line[i] == WALL:
            if space > 0:
                res.append((i - space, i - 1))
                space = 0
        else:
            space = space + 1
    return res

def  main ():
    linha = raw_input().split()
    N =  int (linha[ 0 ])
    M =  int (linha[ 1 ])

    map = []
    for i in range(N):
        line = raw_input()
        map.append(line)
        # print [len(i) for i in line.split(WALL)]
        # print line.split(SPACE)

    tables = []
    K = int(raw_input())
    for i in range(K):
        line = raw_input().split()
        tables.append((int(line[0]), int(line[1])))

    for line in map:
        print contiguous(line)

if __name__ == '__main__':
    main()
