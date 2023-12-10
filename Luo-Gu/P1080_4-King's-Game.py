N = int(input())
k = input().split()
sum = int(k[0])
ps=[]
for i in range(N):
    p = input().split()
    ps.append((int(p[0]), int(p[1])))
ps.sort(key = lambda x:x[0]*x[1])
res = -1
for i in range(N):
    res = max(res,sum // (ps[i])[1])
    sum *= (ps[i])[0]
print(res)