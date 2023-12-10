
import queue
q = queue.PriorityQueue()
a = [0] * 100
s = 0

n = int(input())
l = list(input().split())
print(l)
for i in range(0, 2 * n, 2):
    ch = l[i]
    x = int(l[i + 1])
    a[i] = q.put(x)
while not q.empty():
    x = q.get()
    y = q.get()
    s = s + x + y
    q.put(x + y)

m = int(input())
for i in range(m):
    s1 = 0
    st = list()
    for i in range(n):
        l = input().spilt()
        ch = l[0]
        st.append(l[1])
        s1 = s1 + len(l[1]) * a[i]
    if s == s1:
        jdg = True
        for i in range(n):
            for j in range(i + 1, n):
                flag = 0
                size = max(len(st[i]), len(st[j]))
                for k in range(size):
                    if(st[i][k] != st[j][k]):
                        flag = 1
                if(not flag):
                    jdg = False
        if jdg:
            print("Yes")
        else:
            print("No")
    else:
        print("No")