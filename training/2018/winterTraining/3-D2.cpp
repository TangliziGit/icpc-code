#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    int T, n, m, tmp[2000+5];

    scanf("%d", &T);
    while (T--){
        priority_queue<int> que;
        scanf("%d%d", &m, &n);
        int ans=0;
        while (m--){
            for (int i=0; i<n; i++) scanf("%d", &tmp[i]);
            sort(tmp, tmp+n); ans+=tmp[0];
            for (int i=1; i<n; i++){
                if (que.size()==n-1 && tmp[i]-tmp[0]>=que.top()) break;
                que.push(tmp[i]-tmp[0]);
                while (que.size()>=n) que.pop();
            }
        }
        int idx=0;
        for (; que.size(); idx++){
            tmp[idx]=que.top(); que.pop();
        }tmp[idx]=0;
        for (; idx>=0; idx--)
            printf("%d ", ans+tmp[idx]);
    }

    return 0;
}

