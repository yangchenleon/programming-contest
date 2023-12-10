def init(N, f):
    for i in range(10):
        if i != 4:
            f[1][i] = 1
    for i in range(2, N):
        for j in range(10):
            if j == 4: continue
            for k in range(10):
                if j == 4 or (j == 6 and k == 2): continue
                f[i][j] += f[i - 1][k]

def dp(n, f):
    if n == 0: return 1
    nums = list()
    while n > 0:
        nums.append(n % 10)
        n //= 10
    res, last = 0, 0
    for i in range(len(nums) - 1, -1, -1):
        x = nums[i]
        for k in range(x):
            if k == 4 or (last == 6 and k == 2): continue
            res += f[i + 1][k]
        if x == 4 or (last == 6 and x == 2):
            break
        else:
            last = x
        if i == 0: res += 1
    return res

N = 11
f = [[0] * 10 for _ in range(N)]
init(N, f)
n, m = map(int, input().split())
print(dp(m, f) - dp(n - 1, f))