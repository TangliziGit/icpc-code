#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000+20;
long long s[maxn];

int main(void){
    int T, n;

    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i=0; i<n; i++) scanf("%lld", &s[i]);

        long long ans=0;
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                for (int k=j+1; k<n; k++){
                    ans=max(ans, (s[i]+s[j])^s[k]);
                    ans=max(ans, (s[j]+s[k])^s[i]);
                    ans=max(ans, (s[k]+s[i])^s[j]);
                }
        printf("%lld\n", ans);
    }

    return 0;
}
