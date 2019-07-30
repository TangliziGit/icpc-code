// bfs or ida*
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
struct Point{
    int loc, time;
    Point(int loc=0, int time=0):loc(loc),time(time) {}
};
const int MAX=int(2e5);
int abs(int n){
    if (n>=0) return n;
    return -1*n;
}
bool dfs(int loc, const int &tar, int depth, const int &maxd){
    if (depth==maxd && loc==tar) return 1;
    else if (depth==maxd) return 0;

    if (loc>tar && loc-tar>maxd-depth) return 0;

    for (int i=0; i<3; i++){
        int nloc;
        if (i<2) nloc=loc+((i==0)?-1:1);
        else{
            if (loc>tar) continue;
            if (loc*2>tar && abs(loc*2-tar)>=abs(loc-tar)) continue;
            nloc=loc*2;
        }

        if (nloc>MAX) continue;
        if (dfs(nloc, tar, depth+1, maxd)) return 1;
    }return 0;
}

int main(void){
    int n, k;
    while (scanf("%d%d", &n, &k)==2)
        for (int maxd=0; ; maxd++)
            if (dfs(n, k, 0, maxd)) {printf("%d\n", maxd); break;}

    return 0;
}
