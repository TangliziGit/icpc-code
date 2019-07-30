#include <cstdio>
typedef long long LL;

int main(void){
    LL s, x;

    scanf("%lld%lld", &s, &x);
    if (s<x || (s-x)%2)
        printf("%d\n", 0);
    else{
        LL tmp=(s-x)/2, ans=1;
        for (LL i=0; i<40 && (1LL<<i)<=s; i++){
            LL a=(x&(1LL<<i)), b=(tmp&(1LL<<i));

            if (a && b) {ans=0; break;}
            if (a && !b) ans*=2;
        }
        if (s==x && ans!=0)
            printf("%lld\n", ans-2);
        else
            printf("%lld\n", ans);
    }

    return 0;
}
