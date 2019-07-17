#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;
map<int, int> smap;
set<int> vis;
int n, m, k, id;

int main(void){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &k);
        for (int j=0; j<k; j++){
            scanf("%d", &id);
            if (!smap.count(id))
                smap[id]=k;
            else
                smap[id]=max(smap[id], k);
        }
    }

    scanf("%d", &m);
    for (int i=0; i<m; i++){
        scanf("%d", &id);
        if ((!smap.count(id) || smap[id]==1) && !vis.count(id)){
            if (vis.size()!=0) printf(" ");
            printf("%d", id);
            vis.insert(id);
        }
    }

    if (vis.size()==0) printf("No one is handsome\n");
    else printf("\n");

    return 0;
}
