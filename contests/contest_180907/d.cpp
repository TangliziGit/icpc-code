#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+20;
int tmp[maxn];

int lower(int n){
    int last[int(1e5)+5], size=0, ans=1; last[size++]=tmp[0];
    for (int i=1; i<n; i++){
        if (last[size-1]>=tmp[i]){
            last[size++]=tmp[i];
            ans++;
        }else{
            int idx=lower_bound(last, last+size, tmp[i])-last;
            last[idx]=tmp[i];
        }
    }
    return ans;
}

int upper(int n){
    int last[int(1e5)+5], size=0, ans=1; last[size++]=tmp[0];
    for (int i=1; i<n; i++){
        if (last[size-1]<=tmp[i]){
            last[size++]=tmp[i];
            ans++;
        }else{
            int idx=lower_bound(last, last+size, tmp[i])-last;
            last[idx]=tmp[i];
        }
    }
    return ans;
}

int main(void){
    int n, k, T;

    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &k);
        for (int i=0; i<n; i++){
            scanf("%d", &tmp[i]);
        }

        int ans=max(upper(n), lower(n));
        // printf("%d %d\n", upper(n), lower(n));
        if (n-ans<=k) printf("A is a magic array.\n");
        else printf("A is not a magic array.\n");
    }

    return 0;
}
