// bfs or ida*
// why runtime error?
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
struct Point{
    int loc, time;
    Point(int loc=0, int time=0):loc(loc),time(time) {}
};
const int MAX=int(1e5);
int abs(int n){
    return std::abs((float)n);
}
int bfs(int start, int tar){
    bool vis[MAX+5]={0};
    queue<Point> que;
    que.push(Point(start, 0)); vis[start]=true;
    while (que.size()){
        Point p=que.front(); que.pop();

        for (int i=0; i<3; i++){
            int loc;
            if (i<2) loc=p.loc+((i==0)?-1:1);
            else{
                if (p.loc*2>tar && abs(p.loc*2-tar)>abs(p.loc-tar)) continue;
                loc=p.loc*2;
            }

            if (loc>MAX || vis[loc]) continue;
            if (loc==tar) return p.time+1;
            vis[loc]=true;
            que.push(Point(loc, p.time+1));
        }
    }return -1;
}

int main(void){
    int n, k;
    while (scanf("%d%d", &n, &k)==2)
        printf("%d\n", bfs(n, k));

    return 0;
}
