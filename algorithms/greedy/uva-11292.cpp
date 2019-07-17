#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=20000+20;

int main(void){
    int n, m;
    long long dra[maxn], kni[maxn];

    while (scanf("%d%d", &n, &m)==2 && n){
        for (int i=0; i<n; i++) scanf("%lld", &dra[i]);
        for (int i=0; i<m; i++) scanf("%lld", &kni[i]);
        sort(dra, dra+n); sort(kni, kni+m);

        int ptr=0; bool flg=(m<n);
        long long ans=0;
        if (!flg) for (int i=0; i<n; i++){
            while (ptr<m && kni[ptr]<dra[i]) ptr++;
            if (ptr>=m) {flg=true; break;}
            ans+=kni[ptr++];
        }

        if (flg) printf("Loowater is doomed!\n");
        else printf("%lld\n", ans);
    }

    return 0;
}
