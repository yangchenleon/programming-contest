
def dfs(x):
    global num
    global ma
    if (num == n and mat[0][x]):   
        ma += 1
        return
    for i in range(1, n + 1):
        if mat[x][i] and visited[i] == False:
            visited[i] = True
            num += 1
            dfs(i)
            num -= 1
            visited[i] = False

t = int(input())
for _ in range(t):
    n = int(input())
    mat = [[0] * 11 for _ in range(11)]
    visited = [False] * 11
    for i in range(1, n + 1):
        l = [int(k) for k in input().split()]
        m = l[0]
        for j in range(1, m + 1):
            mat[i][l[j]] = 1
            mat[l[j]][i] = 1
    
    num = 0
    ma = 0
    dfs(0)
    print(ma)