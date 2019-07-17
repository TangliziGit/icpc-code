#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int n, stick[70];
bool dfs(int cnt, int sum, int ptr, int &maxlen, int &nsum, bool *vis){
    if (cnt==0 && sum==nsum-1) return true;     // 1
    
    for (int i=ptr; i<n; i++){                  // 2
        if (vis[i] || (i && stick[i]==stick[i-1] && !vis[i-1])) continue;       // 3
        if (cnt+stick[i]<maxlen){
            vis[i]=true;
            if (dfs(cnt+stick[i], sum, i+1, maxlen, nsum, vis)) return true;
            vis[i]=false;
            if (cnt==0) return false;           // 4
        }else if (cnt+stick[i]==maxlen){
            vis[i]=true;
            if (dfs(0, sum+1, 0, maxlen, nsum, vis)) return true;
            vis[i]=false;
            return false;                       // 5
        }
    }return false;
}

int main(void){
    while (scanf("%d", &n)==1 && n){
        int sum=0;
        for (int i=0; i<n; i++) {scanf("%d", &stick[i]); sum+=stick[i];}
        sort(stick, stick+n, greater<int>());
        for (int maxlen=stick[0]; maxlen<=sum; maxlen++){
            if (sum%maxlen) continue;           // 6
            
            int nsum=sum/maxlen;
            bool vis[70]={0};                   // pay attention, vis may be destroyed.
            if (dfs(0, 0, 0, maxlen, nsum, vis)){
                printf("%d\n", maxlen);
                break;
            }
        }
    }

    return 0;
}
