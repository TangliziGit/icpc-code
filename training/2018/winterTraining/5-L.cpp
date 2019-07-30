#include <cstdio>
#include <cstring>
#define lowbit(x) ((x)&(-x))
int n, tree[5000+5];
int sum(int x){
    int result=0;
    for (int i=x; i>0; i-=lowbit(i)) result+=tree[i];
    return result;
}

void add(int x){
    for (int i=x; i<=n; i+=lowbit(i))
        tree[i]+=1;
}

int main(void){
    while (scanf("%d", &n)==1){
        int inv=0, ans, num[5000+5];
        memset(tree, 0, sizeof(tree));
        for (int i=0; i<n; i++){
            scanf("%d", &num[i]);
            inv+=sum(n)-sum(num[i]+1);
            add(num[i]+1);
        }ans=inv;
        for (int i=0; i<n-1; i++){
            inv=inv-num[i]+n-1-num[i];
            if (ans>inv) ans=inv;
        }printf("%d\n", ans);
    }

    return 0;
}
