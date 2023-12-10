# def isRight(curr:int):
#     for i in range(curr+1):
#         for j in range(i+1,curr+1):
#             if i==j or res[i]==res[j] or abs(i-j)==abs(res[i]-res[j]):
#                 return False
#     return True

# def NQueen(curr:int):
#     if curr <n:
#         for i in range(n):
#             res[curr]=i
#             if isRight(curr):
#                 NQueen(curr+1)
#     else:
#         # print(res)
#         ress.append(res)

# nums = [int(i) for i in input().split()]
# if len(nums) > 1:
#     for n in nums:
#         ress = list()
#         res=[-1 for i in range(j)]
#         NQueen(0)
#         print(len(ress))
# else:
#     n = nums[0]
#     ress = list()
#     res=[-1 for i in range(n)]
#     NQueen(0)
#     print(len(ress))
#     while True:
#         try:
#             n=int(input())
#             ress = list()
#             res=[-1 for i in range(n)]
#             NQueen(0)
#             print(len(ress))
#         except EOFError:
#             break

def pd(k):
    for i in range(1, k):
        if abs(k - i) == abs(x[k] - x[i]):
            return False
        elif x[k] == x[i]:
            return False
    return True

def check(a):
    if a > n:
        global count
        count += 1
    else:
        return False
    return True


# 第 a 行
def dfs(a):
    if check(a):
        return
    else:
        for i in range(1, n + 1):
            x[a] = i
            if pd(a):
                dfs(a + 1)
            else:
                continue

nums = [int(i) for i in input().split()]
if len(nums) > 1:
    for n in nums:
        count = 0
        # n = int(input())
        x = [0] * (n + 1)
        dfs(1)
        print(count)
else:
    n = nums[0]
    count = 0
    x = [0] * (n + 1)
    dfs(1)
    print(count)
    while True:
        try:
            count = 0
            n = int(input())
            x = [0] * (n + 1)
            dfs(1)
            print(count)
        except EOFError:
            break

