#include <cstring>
#include <cstdio>
#define lowbit(x) ((x)&(-x))
int n, arr[int(5e4)+5];
long long getsum(int idx){
    long long sum=0;
    for (int i=idx; i>0; i-=lowbit(i))
        sum+=arr[i];
    return sum;
}

void add(int idx, int num){
    for (int i=idx; i<=n; i+=lowbit(i))
        arr[i]+=num;
}

int main(void){
    char str[20];
    int T, kcase=1, oper[2];

    scanf("%d", &T);
    while (scanf("%d", &n)==1){
        memset(arr, 0, sizeof(arr));
        for (int i=1, tmp; i<=n; i++){
            scanf("%d", &tmp);
            add(i, tmp);
        }
        printf("Case %d:\n", kcase++);
        while (scanf("%s", str)==1 && str[0]!='E'){
            scanf("%d%d", &oper[0], &oper[1]);
            if (str[0]=='Q') printf("%lld\n", getsum(oper[1])-getsum(oper[0]-1));
            else if (str[0]=='A') add(oper[0], oper[1]);
            else if (str[0]=='S') add(oper[0], -1*oper[1]);
        }
    }

    return 0;
}
