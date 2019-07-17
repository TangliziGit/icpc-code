#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e3+20;
int val[maxn], n, ok=0, idx;
struct Node{
    int val;
    Node *l, *r;
    Node(int val=0, Node* l=NULL, Node* r=NULL)
        :val(val), l(l), r(r) {}
}root;

void build(Node *prev, Node *node){
    if (idx==n) {ok=1; return;}

    printf("-> %d Left %d\n", node->val, val[idx]);
    if (val[idx] < node->val){
        if (prev==NULL || (prev!=NULL && (
                (node->val > val[idx] && val[idx] >= prev->val) ||
                (node->val > val[idx] && node->val < prev->val)
            ))){
            printf("-- 1\n");
            node->l=new Node(val[idx++]);
            build(node, node->l);
        }else{
            printf("-- 2\n");
            return;
        }
    }

    if (idx==n) {ok=1; return;}
    printf("-> %d Right %d\n", node->val, val[idx]);
    if (prev==NULL || (prev!=NULL && (
            (node->val <= val[idx] && val[idx] < prev->val) ||
            (node->val <= val[idx] && node->val >= prev->val)
        ))){
        printf("-- 3\n");
        node->r=new Node(val[idx++]);
        build(node, node->r);
    }else{
        printf("-- 4\n");
        return;
    }
}

void post(Node *node){
    if (node==NULL) return;
    // printf("path %d\n", node->val);
    // printf("left\n");
    post(node->l);
    // printf("right\n");
    post(node->r);
    if (&root==node) printf("%d\n", node->val);
    else printf("%d ", node->val);
}

int main(void){
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &val[i]);

    root.val=val[0]; idx=1;
    build(NULL, &root);
    if (ok) post(&root);

    return 0;
}
