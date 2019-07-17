def gcd(a, b):
    if a%b==0:
        return b
    return gcd(b, a%b);

n=int(input())
num=list(sorted([int(x) for x in input().split(" ")]))

cnt=0;g=num[1]-num[0]
for i in range(1, n-1):
    g=gcd(g, num[i+1]-num[i])
for i in range(n-1):
    cnt+=(num[i+1]-num[i])//g-1;
print(cnt)
