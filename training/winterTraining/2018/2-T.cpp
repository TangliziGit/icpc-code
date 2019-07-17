#include <cstdio>

int main(void){
    int n, s;

    while (scanf("%d%d", &n, &s)==2){
        long long ans=0;
        for (int i=0, c, y, min; i<n; i++){
            scanf("%d%d", &c, &y);
            if (!i) min=c;
            else if (min>c) min=c;
            ans+=min*y; min+=s;
        }printf("%lld\n", ans);
    }

    return 0;
}
