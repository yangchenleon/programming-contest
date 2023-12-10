a = list()
n = int(input())
nums = [int(i) for i in input().split()]
for num in nums: 
    if num != 0:
        if len(a) >= 9:
            print("FULL", end=' ')
        else:
            a.append(num)
    elif num == 0:
        if len(a) <= 0:
            print("EMPTY", end=' ')
        else:
            print(a.pop(0), end=' ')
    # print(a)
print('\n', end='')
if len(a) >= 1:
    for i in a:
        print(i, end=' ')

# print(len(a), end=' ')
