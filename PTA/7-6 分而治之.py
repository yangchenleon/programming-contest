n, m = map(int, input().split())
a = [0] * m
b = [0] * m
for i in range(m):
    data = list(map(int, input().split()))
    a[i] = data[0]
    b[i] = data[1]
k = int(input())
for i in range(k):
    flag = 0
    vis = [0] * n
    data2 = list(map(int, input().split()))
    for x in data2[1:]:
        vis[x - 1] = 1
    for z in range(m):
        if not vis[a[z] - 1] and not vis[b[z] - 1]:
            flag = 1
            break
    if flag:
        print("NO")
    else:
        print("YES")