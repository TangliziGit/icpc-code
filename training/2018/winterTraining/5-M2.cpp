// delta[i]=a[i]-a[i-1];
// ndelta[i]=(i-1)*delta[i]
// SUM(i)=i*preSum(delta[i])-preSum(ndelta[i])
#include <cstdio>
#define lowbit(x) ((x)&(-x))
const int MAX=100000;
long long delta[MAX+5], ndelta[MAX+5], num[MAX+5];
int q, n;
void add(long long *arr, int x, int value){
    for (int i=x; i<=n; i+=lowbit(i)) arr[i]+=value;
}

long long sum(long long *arr, int x){
    long long result=0;
    for (int i=x; i>0; i-=lowbit(i)) result+=arr[i];
    return result;
}

long long Sum(int x){
    return x*sum(delta, x)-sum(ndelta, x);
}

long long Query(int a, int b){
    return Sum(b)-Sum(a-1);
}

int main(void){
    char ch[5];
    int a, b, c;
    scanf("%d%d", &n, &q);
    for (int i=1; i<=n; i++){
        scanf("%lld", &num[i]);
        add(delta, i, num[i]-num[i-1]);
        add(ndelta, i, (i-1)*(num[i]-num[i-1]));
    }
    for (int i=0; i<q; i++){
        scanf("%s", ch);
        if (ch[0]=='Q'){
            scanf("%d%d", &a, &b);
            printf("%lld\n", Query(a, b));
        }else if (ch[0]=='C'){
            scanf("%d%d%d", &a, &b, &c);
            add(delta, a, c);       add(delta, b+1, -c);
            add(ndelta, a, (a-1)*c);    add(ndelta, b+1, -b*c);
        }
    }

    return 0;
}