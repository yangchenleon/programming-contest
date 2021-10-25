a=input()
b=a.split()
n=int(b[0])
m=int(b[1])
cnt=0
for i in range(0,n):
    tmp=input()
    if "qiandao" in tmp or "easy" in tmp:
        continue
    else:
        cnt=cnt+1
        if(cnt>m):
            print(tmp)
if cnt<=m:
    print("Wo AK le")

