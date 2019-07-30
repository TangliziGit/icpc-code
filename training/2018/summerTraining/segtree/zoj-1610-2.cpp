#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=8e3+20;
struct Node{int l, r, clr;}tree[maxn*4];
// -1 for null, -2 for multi
void Build(int node, int L, int R){
    tree[node]=Node{L, R, -1};
    if (L==R) return;
    int M=L+(R-L)/2;
    Build(node*2, L, M);
    Build(node*2+1, M+1, R);
}

void PushDown(int node){
    if (tree[node].clr<0) return;
    tree[node*2].clr=tree[node].clr;
    tree[node*2+1].clr=tree[node].clr;
    tree[node*2+1].clr=-2; // ...
}

void Update(int node, int L, int R, int val){
    if (tree[node].clr==val) return;
    if (L<=tree[node].l && tree[node].r<=R){
        tree[node].clr=val;
        return;
    }
    PushDown(node);
    int &mid=tree[node*2].r;
    if (L<=mid) Update(node*2, L, mid, val);
    if (mid<R)  Update(node*2+1, mid+1, R, val);
    tree[node].clr=-2;
}

int main(void){

    return 0;
}
