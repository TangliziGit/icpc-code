#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn=105;
int in[maxn+5], out[maxn+5], topo[maxn+5];
bool G[maxn+5][maxn+5], rG[maxn+5][maxn+5], vis[maxn+5];

int topoSortR(int n){
    int size=0, arg=0;
    while (size<=n){
        int cnt=0;
        for (int from=1; from<=n; from++) if (out[from]==0){
            if (++cnt==2) return size;
            for (int to=1; to<=n; to++) if (rG[from][to])
                out[to]--;
            if (!vis[from]) {vis[from]=true; arg++;}
        }
        if (arg==0) break;
        size+=arg; arg=0;
    }return size;
}

int topoSort(int n){
    int size=0, arg=0;
    while (size<=n){
        int cnt=0;
        for (int from=1; from<=n; from++) if (in[from]==0){
            if (++cnt==2) return size;
            for (int to=1; to<=n; to++) if (G[from][to])
                in[to]--;
            if (!vis[from]) {vis[from]=true; arg++;}
        }
        if (arg==0) break;
        size+=arg; arg=0;
    }return size;
}

bool connective(int n){
    queue<int> que;
    bool nvis[maxn+5]={false};
    int cnt=1;
    nvis[1]=true; que.push(1);
    
    while (que.size()){
        int from=que.front(); que.pop();

        for (int to=1; to<=n; to++) if (!nvis[to] && (G[from][to] || rG[from][to])){
            que.push(to); cnt++; nvis[to]=true;
        }
    }return cnt==n;
}

void init(void){
    memset(G, false, sizeof(G));
    memset(rG, false, sizeof(rG));
    memset(in, 0, sizeof(in));
    memset(vis, false, sizeof(vis));
}

int main(void){
    int a, b, n, m;

    init();
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++){
        scanf("%d%d", &a, &b);
        rG[a][b]=G[b][a]=true;
        in[a]++; out[b]++;
    }
    
    if (connective(n)) printf("%d\n", topoSort(n)+topoSortR(n));
    else printf("0\n");

    return 0;
}
