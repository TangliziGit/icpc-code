// why it is WA?
#define lson (node*2)
#define rson (node*2+1)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5e4+20;
struct Node{int l, r, llen, rlen, mlen;}tree[maxn*4];
int n, m;
void PushUp(int node){
	tree[node].llen=tree[lson].llen;
	tree[node].rlen=tree[rson].rlen;
	tree[node].mlen=max(tree[lson].mlen, tree[rson].mlen);
	tree[node].mlen=max(tree[node].mlen, tree[lson].rlen+tree[rson].llen);
	// attend to this!
	if (tree[lson].llen==tree[lson].r-tree[lson].l+1)
		tree[node].llen+=tree[rson].llen;
	if (tree[rson].rlen==tree[rson].r-tree[rson].l+1)
		tree[node].rlen+=tree[lson].rlen;
}

void Build(int L, int R, int node=1){
	int len=R-L+1;
	tree[node]=Node{L, R, len, len, len};
	if (len==1) return;
	int M=L+(R-L)/2;
	Build(L, M, lson);
	Build(M+1, R, rson);
	// PushUp(node);
}

void Update(int Q, bool isdel, int node=1){
	if (tree[node].l==tree[node].r) {
		if (isdel) tree[node].llen=tree[node].rlen=tree[node].mlen=0;
		else tree[node].llen=tree[node].rlen=tree[node].mlen=1;
		return;
	}
	// PushDown(); modify single point without PushDown oper.
	int &mid=tree[lson].r;
	if (Q<=mid) Update(Q, isdel, lson);
    else Update(Q, isdel, rson);
	PushUp(node);
}

int Ask(int Q, int node=1){
	// when Q is in this node, and mlen can be decided.
	if (tree[node].r==tree[node].l || tree[node].mlen==0 ||
		tree[node].mlen==tree[node].r-tree[node].l+1)
		return tree[node].mlen;
	int &mid=tree[lson].r;
	if (Q<=mid){
		if (Q<tree[lson].r-tree[lson].rlen+1)
			return Ask(Q, lson);
		else return Ask(Q, lson)+Ask(mid+1, rson);
	}else{
		if (Q>tree[rson].l+tree[rson].llen-1)
			return Ask(Q, rson);
		else return Ask(Q, rson)+Ask(mid, lson);
	}
}

int main(void){
	char cmd[5];
	int sta[maxn], size=0, tmp;

	scanf("%d%d", &n, &m);
	Build(1, n);
	for (int i=0; i<m; i++){
		scanf("%s", cmd);
		if (cmd[0]=='D'){
			scanf("%d", &sta[size]); size++;
			Update(sta[size-1], true);
		}else if (cmd[0]=='R')
			Update(sta[--size], false);
		else if (cmd[0]=='Q'){
			scanf("%d", &tmp);
			printf("%d\n", Ask(tmp));
		}
	}

	return 0;
}
