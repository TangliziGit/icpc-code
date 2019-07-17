#include <set>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=200000;
set<int> vis;

int main(void){
    int n, ptr=0, num[maxn+5], ans;
    scanf("%d", &n);
    for (int i=0, tmp; i<n; i++){
        scanf("%d", &tmp);
        if (vis.count(tmp)) continue;
        vis.insert(tmp); num[ptr++]=tmp;
    }
    for (int i=0, tmp; i<n; i++){
        scanf("%d", &tmp);
        for (int i=0; i<ptr; i++) ans^=tmp+num[i];
    }printf("%d\n", ans);

    return 0;
}
