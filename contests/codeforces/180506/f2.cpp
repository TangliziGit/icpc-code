#include <cstdio>
#include <map>
using namespace std;
map<long long, int> mp, idx;
int n, a[int(2e5)+5], path[int(2e5)+5];

int main(void){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);

    int m=0, midx=-1;
    for (int i=1; i<=n; i++){
        if (mp.count(a[i])==false) mp[a[i]]=0;
        // if (idx.cout)idx[a[i]]=i;
        if (mp[a[i]-1]>0){
            if (mp.count(a[i]) && mp[a[i]]<mp[a[i]-1]+1){
                mp[a[i]]=mp[a[i]-1]+1;
                path[i]=idx[a[i]-1];
                idx[a[i]]=i;
            }else if (mp.count(a[i])==false){
                mp[a[i]]=mp[a[i]-1]+1;
                path[i]=idx[a[i]-1];
                idx[a[i]]=i;
            }
        }else{
            if (mp.count(a[i])==false){
                mp[a[i]]=1;
                path[i]=-1;
                idx[a[i]]=i;
            }
        }
        if (mp.count(a[i]) && mp[a[i]]>m){
            m=mp[a[i]];
            midx=idx[a[i]];
        }
    }

    printf("%d\n", m);
    for (int i=midx; i!=0 && i!=-1; i=idx[a[i]])
        printf("%d ", a[i]);

    return 0;
}
