#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1020;
struct Node{
    int b, j;
    bool operator < (const Node &a) const{
        return j>a.j;
    }
}node[maxn];

int main(void){
    int n, cnt=0;

    while (scanf("%d", &n)==1 && n){
        for (int i=0; i<n; i++) scanf("%d%d", &node[i].b, &node[i].j);
        sort(node, node+n);

        int ans=0, sum=0;
        for (int i=0; i<n; i++){
            sum+=node[i].b;
            ans=max(sum+node[i].j, ans);
        }printf("Case %d: %d\n", ++cnt, ans);
    }

    return 0;
}
