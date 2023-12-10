"""我去明明是一个很简单的dp，结果用python半天写不出来
首先是python的多维数组问题，然后是拷贝问题，再是x，y轴搞错了（太久没写了）
最后是算法问题，我以为是多维数组问题，改成一维的也不行，最后发现根本问题在初始化x=0行和y=0列设置为1，
这没有考虑到马恰好挡在这个这些位置，就错了"""

bx, by, cx, cy = [int(i) for i in input().split()]
dp = [0] * (by + 1)
s = [[0] * (by + 1) for i in range(bx+1)]  # 对多维数组得这样写
dp[0] = 1

for hdx, hdy in [[-1,2],[1,2],[2,1],[2,-1],[-1,-2],[1,-2],[-2,1],[-2,-1],[0,0]]:
   hx = cx + hdx
   hy = cy + hdy
   if hx > bx or hy > by or hx < 0 or hy < 0:
      continue
   else:
      s[hx][hy] = -1

for x in range(bx + 1):
   for y in range(by + 1):
      if s[x][y] == -1:
         dp[y] = 0
      else:
         if y > 0:
            dp[y] = dp[y - 1] + dp[y]

print(dp[by])
