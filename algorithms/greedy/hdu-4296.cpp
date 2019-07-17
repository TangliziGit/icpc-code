#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+20;
struct Node{
    long long w, s;
    bool operator < (Node &a) const{
        return w+s<a.w+a.s;
    }
}node[maxn];

int main(void){
    int n;

    while (scanf("%d", &n)==1 && n){
        for (int i=0; i<n; i++)
            scanf("%lld%lld", &node[i].w, &node[i].s);
        sort(node, node+n);

        long long ans=-node[0].s, tot=node[0].w;
        for (int i=1; i<n; i++){
            long long res=tot-node[i].s; tot+=node[i].w;
            if (ans<res) ans=res;
        }printf("%lld\n", ans);
    }

    return 0;
}
