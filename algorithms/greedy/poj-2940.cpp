#include <cstdio>
#define abs(x) ((x>0)?(x):(-x))

int main(void){
    int n;

    while (scanf("%d", &n)==1 && n){
        long long add=0, tmp, ans=0;
        for (int i=0; i<n; i++){
            scanf("%lld", &tmp);
            add+=tmp;
            ans+=abs(add);
        }printf("%lld\n", ans);
    }

    return 0;
}
