#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=30+20;
map<int, int> midx;
struct Node{
    int val, l, r;
    Node(int val, int l=-1, int r=-1)
        :val(val), l(l), r(r) {}
    Node(){}
}nodes[maxn+20];
int n, mid[maxn], post[maxn], siz;
int ptr;

int build(int L, int R){
    // printf("%d %d mid.val%d ptr%d\n", L, R, mid[midx[post[ptr]]], ptr);
    // getchar();

    if (ptr==-1 || L>R) return -1;
    if (L==R) {
        nodes[siz]=Node(post[ptr--]);
        return siz++;
    }
    
    int idx=midx[post[ptr]], id=siz;
    Node &node=nodes[siz++];
    node.val=post[ptr--];
    node.r=build(max(idx+1, L), R);
    node.l=build(L, min(idx-1, R));
    return id;
}

void bfs(int x){
    queue<int> que;
    que.push(x);
    while (que.size()){
        int idx=que.front(); que.pop();
        if (idx==x) printf("%d", nodes[idx].val);
        else printf(" %d", nodes[idx].val);
        // getchar();
        if (nodes[idx].l!=-1) que.push(nodes[idx].l);
        if (nodes[idx].r!=-1) que.push(nodes[idx].r);
    }printf("\n");
}

int main(void){
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &post[i]);
    for (int i=0; i<n; i++) scanf("%d", &mid[i]), midx[mid[i]]=i;
    ptr=n-1; siz=0;
    build(0, n-1);
    bfs(0);

    return 0;
}
