// Update   O(1)
// Ask      O(logn)~O(n) (determined by the shape of tree)

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5e4+20;
struct Node{int task, time, prev;}nodes[maxn];
int n, m, prevUpdateTime;
void Update(int node, int task, int time){
    nodes[node]=Node{task, time, nodes[node].prev};
    prevUpdateTime=time;
}

int Ask(int st){
    int ntime=-1, ed=-1;
    for (int i=nodes[st].prev; i!=-1; i=nodes[i].prev)
        if (nodes[i].task>=0 && ntime<nodes[i].time){
            ntime=nodes[i].time; ed=i;
            if (prevUpdateTime==ntime) break;
        }
    if (ed!=-1){
        for (int i=nodes[st].prev; i!=ed; i=nodes[i].prev)
            nodes[i]=Node{nodes[ed].task, nodes[ed].time, nodes[i].prev};
        nodes[st]=Node{nodes[ed].task, nodes[ed].time, nodes[st].prev};
    }return nodes[st].task;
}

int main(void){
    int T, upper, lower, kase=0;

    scanf("%d", &T);
    while (T--){
        prevUpdateTime=-2;
        memset(nodes, -1, sizeof(nodes));
        scanf("%d", &n);
        for (int i=0; i<n-1; i++){
            scanf("%d%d", &lower, &upper);
            nodes[lower].prev=upper;
        }

        char cmd[5]; int node, task;
        scanf("%d", &m);
        printf("Case #%d:\n", ++kase);
        for (int i=0; i<m; i++){
            scanf("%s%d", cmd, &node);
            if (cmd[0]=='C') printf("%d\n", Ask(node));
            else {
                scanf("%d", &task);
                Update(node, task, i);
            }
        }
    }

    return 0;
}
