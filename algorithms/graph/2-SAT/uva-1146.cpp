#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2*2e3, maxm=maxn*maxn;
struct Edge{
    int to, nxt;
    Edge(int to=0, int nxt=-1)
        :to(to), nxt(nxt) {}
}edges[maxm];
int head[maxn], esiz, n;
int time[maxn][2];
int trace[maxn*2], satCnt;
bool mark[maxn*2];

void init(void){
    memset(head, -1, sizeof(head));
    esiz=0;
}

void addEdge(int to, int from){
    edges[esiz]=Edge(to, head[from]);
    head[from]=esiz++;
}

void addClause(int x, int xval, int y, int yval){
    x=x*2+xval;
    y=y*2+yval;
    addEdge(x^1, y);
    addEdge(y^1, x);
}

bool dfs(int x){
    if (mark[x^1]) return false;
    if (mark[x]) return true;
    mark[x]=true;
    trace[satCnt++]=x;
    for (int i=head[x]; i!=-1; i=edges[i].nxt)
        if (!dfs(edges[i].to)) return false;
    return true;
}

bool SAT(int n){
    satCnt=0;
    memset(trace, 0, sizeof(trace));
    memset(mark, 0, sizeof(mark));
    for (int i=0; i<n*2; i+=2){
        if (!mark[i] && !mark[i+1]){
            satCnt=0;
            if (!dfs(i)){
                while (satCnt>0) mark[trace[--satCnt]]=false;
                if (!dfs(i+1)) return false;
            }
        }
    }
    return true;
}

bool judge(int mid){
    init();
    for (int i=0; i<n; i++) for (int j=i+1; j<n; j++){
        for (int a=0; a<2; a++) for (int b=0; b<2; b++) {
            // i select A time, or j select B time;
            if (abs(time[i][a]-time[j][b])<mid) addClause(i, a^1, j, b^1);
        }
    }
    return SAT(n);
}

int solve(void){
    int l=0, r=1e7;
    while (l<r){
        int mid=(r+l)/2;
        if (judge(mid)) r=mid;
        else l=mid+1;
    }

    // printf("%d %d\n", l, r);
    for (int i=max(0, l-5); i<=min((int)1e7, r+5); i++)
        if (judge(i)) return i;
    return -1;
}

int main(void){
    while (scanf("%d", &n)==1 && n){
        for (int i=0; i<n; i++) scanf("%d%d", &time[i][0], &time[i][1]);
        printf("%d\n", solve());
    }

    return 0;
}
