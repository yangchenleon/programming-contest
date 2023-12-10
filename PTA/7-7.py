f = [[0x3f3f3f3f] * 205 for _ in range(205)]
l = [[0] * 205 for _ in range(205)]
a = [0] * 205
s = [0] * 205


n = int(input())
nums = [int(i) for i in input().split()]
idx = 1
for i in nums:
    a[idx] = i
    idx += 1

for i in range(1,n+1):
    s[i] = s[i-1] + a[i]
    f[i][1] = 0
for i in range(n+1, 2*n+1):
    s[i] = s[i-1] + a[i-n]
    f[i][1] = 0

for len in range(2, n+1):
    for i in range(1, 2*n-len+1):
        for k in range(1, len):
            f[i][len]=min(f[i][len],f[i][k]+f[i+k][len-k]+s[i+len-1]-s[i-1])
            l[i][len]=max(l[i][len],l[i][k]+l[i+k][len-k]+s[i+len-1]-s[i-1])

maxx = 0
minn=2147483647
for i in range(1, n+1):
    minn=min(minn,f[i][n]);
    maxx=max(maxx,l[i][n]);
print(minn)
print(maxx)