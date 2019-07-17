def gcd(a, b):
    return b if a%b==0 else gcd(b, a%b)

a=0 
b=1
ta=0 
tb=0
n=int(input())
for item in input().split(' '):
    ta, tb=[int(x) for x in item.split('/')]
    tg=gcd(ta, tb)
    ta/=tg
    tb/=tg

    a*=tb
    ta*=b
    b*=tb
    a+=ta

    g=gcd(a, b)
    a/=g 
    b/=g

if a/b==0:
    print(int(a%b), '/', int(b), sep='');
elif a%b==0:
    print(int(a/b), sep='')
else:
    print(int(a/b), ' ', int(a%b), '/', int(b), sep='')
