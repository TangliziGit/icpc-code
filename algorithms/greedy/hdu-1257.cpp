#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    int n, hei[int(1e5)+5];
    
    while (scanf("%d", &n)==1 && n){
        for (int i=0; i<n; i++) scanf("%d", &hei[i]);

        int last[int(1e5)+5], size=0, ans=1; last[size++]=hei[0];
        for (int i=1; i<n; i++){
            if (last[size-1]<hei[i]){
                last[size++]=hei[i];
                ans++;
            }else{
                int idx=lower_bound(last, last+size, hei[i])-last;
                last[idx]=hei[i];
            }
        }printf("%d\n", ans);
    }

    return 0;
}
