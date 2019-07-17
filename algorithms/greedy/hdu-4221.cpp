#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+20;
struct Node{
    long long c, d;
    bool operator < (Node &a) const{
        return d<a.d;
    }
}node[maxn];

int main(void){
    int T, n, cnt=1;

    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i=0; i<n; i++)
            scanf("%lld%lld", &node[i].c, &node[i].d);
        sort(node, node+n);

        long long ans=0, sum=0;
        for (int i=0; i<n; i++){
            long long delta=sum+node[i].c-node[i].d;
            if (delta>ans) ans=delta;
            sum+=node[i].c;
        }printf("Case %d: %lld\n", cnt++, ans);
    }

    return 0;
}
