#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=26+5;
struct Tree{
	int val, left, right;
	Tree(){}
}tree[maxn];
char pre[maxn], mid[maxn], map[maxn];
int siz, pidx;

int build(int left, int right){
	if (left>right) return -1;
	int midx=map[pre[pidx++]-'A'],
		node=siz++;
	tree[node].val=mid[midx];
	tree[node].left =build(left, midx-1);
	tree[node].right=build(midx+1, right);
	return node;
}

void post(int x){
	if (x<0) return;
	post(tree[x].left);
	post(tree[x].right);
	printf("%c", tree[x].val);
}

int main(void){
	while (scanf("%s%s", pre, mid)==2){
		siz=pidx=0;
		for (int i=0; pre[i]; i++) map[mid[i]-'A']=i;
		build(0, strlen(pre)-1);
		post(0);printf("\n");
	}

	return 0;
}
