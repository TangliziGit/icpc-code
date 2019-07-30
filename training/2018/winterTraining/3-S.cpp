#include <cstdio>
#include <queue>
using namespace std;
int map[10][10];
int nsize=1, dir[4][2]={1, 0, 0, 1, -1, 0, 0, -1};
struct Node{
    int x, y, pre;
    Node(int x=0, int y=0, int pre=-1):
        x(x),y(y),pre(pre) {}
}node[30];
void show(int idx){
    if (idx==-1) return;
    show(node[idx].pre);
    printf("(%d, %d)\n", node[idx].y, node[idx].x);
}

void bfs(void){
    queue<int> que;
    que.push(0); map[0][0]=1;
    while (que.size()){
        int idx=que.front(); que.pop();

        for (int i=0; i<4; i++){
            int x=node[idx].x+dir[i][0], y=node[idx].y+dir[i][1];
            
            if (y<0 || y>=5 || x<0 || x>=5) continue;
            if (map[y][x]) continue;
            if (y==4 && x==4) {show(idx); printf("(4, 4)\n"); return;}
            map[y][x]=1;
            node[nsize].x=x; node[nsize].y=y; node[nsize].pre=idx;
            que.push(nsize++);
        }
    }
}

int main(void){
    for (int y=0; y<5; y++)
        for (int x=0; x<5; x++)
            scanf("%d", &map[y][x]);
    bfs();

    return 0;
}
