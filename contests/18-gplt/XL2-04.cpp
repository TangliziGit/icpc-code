// pre (T) = root + pre(left) + pre(right)
// in  (T) = pre(left) + root + pre(right)
// post(T) = pre(left) + pre(right) + root
#include <cstdio>
#include <cstring>
const int maxn=1000;
struct Node{
    int val, right, left, parent;
    Node(int val=0, int parent=-1, int right=-1, int left=-1):
        val(val), parent(parent), right(right), left(left) {}
}node[maxn+5], mnode[maxn+5];
int nsize=0, seq[maxn+5];
void insert(int root, int proot, const int &val){
    printf("-%d %d %d\n", root, proot, val);
    if (root==-1 || nsize==0){
        printf("insert!\n");
        node[nsize++]=Node(val, proot);
        if (proot!=-1 && node[proot].val<=val) node[proot].right=nsize-1;
        else if (proot!=-1) node[proot].left=nsize-1;
    }else if (val>=node[root].val) insert(node[root].right, root, val);
    else insert(node[root].left, root, val);
}

void minsert(int root, int proot, const int &val){
    printf("-%d %d %d\n", root, proot, val);
    if (root==-1 || nsize==0){
        printf("insert!\n");
        mnode[nsize++]=mnode(val, proot);
        if (proot!=-1 && mnode[proot].val>val) mnode[proot].right=nsize-1;
        else if (proot!=-1) mnode[proot].left=nsize-1;
    }else if (val<mnode[root].val) insert(mnode[root].right, root, val);
    else insert(mnode[root].left, root, val);
}

bool pre(int root, int &idx){
    if (root==-1 || idx==nsize) return true;    // nsize checking can be omited
    printf("%d %d %d\n", node[root].val, seq[idx], idx);
    if (node[root].val!=seq[idx++]) return false;
    if (!pre(node[root].left, idx)) return false;
    if (!pre(node[root].right, idx)) return false;
    return true;
}

void post(int root){
    if (root==-1) return;
    post(node[root].left);
    post(node[root].right);
    printf("%d%c", node[root].val, (root==nsize)?'\n':' ');
}

int main(void){
    int n, idx=0;

    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &seq[i]);
        insert(0, -1, seq[i]);
    }
    if (pre(0, idx)){
        printf("YES\n");
        post(0);
    }else printf("NO\n");

    return 0;
}
