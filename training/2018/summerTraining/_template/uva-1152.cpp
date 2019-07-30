#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=4e3;

struct HashMap{
    static const int mask=0x7fffff;
    int q[mask+1], p[mask+1];
    void clear() {memset(q, 0, sizeof(q));}
    int& operator [](int k){
        int i;
        for (i=k&mask; q[i]&&p[i]!=k; i=(i+1)&mask);
        p[i]=k; return q[i];
    }
}hash;

int main(void){
    int T, n, num[4][maxn];

    scanf("%d", &T);
    while (T--){
        hash.clear();
        scanf("%d", &n);
        for (int i=0; i<n; i++)
            for (int j=0; j<4; j++) scanf("%d", &num[j][i]);
        for (int i=0; i<4; i++) sort(num[i], num[i]+n);
        
        int ans=0;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) hash[num[0][i]+num[1][j]]++;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) ans+=hash[-(num[2][i]+num[3][j])];
        printf("%d\n", ans);
    }

    return 0;
}
