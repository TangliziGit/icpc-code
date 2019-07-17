#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e3+20;
struct Node{
    int val, num;
    Node(int val, int num)
        :val(val), num(num) {}
    Node(){}
    bool operator < (Node &a) const {
        return val*a.num>num*a.val;
    }
}node[maxn];
int n, size;

int main(void){
    scanf("%d%d", &n, &size);
    for (int i=0; i<n; i++) scanf("%d", &node[i].num);
    for (int i=0; i<n; i++) scanf("%d", &node[i].val);
    sort(node, node+n);

    double ans=0;
    for (int i=0; i<n && size!=0; i++){
        if (size>node[i].num){ans+=node[i].val; size-=node[i].num;}
        else{
            ans+=size*node[i].val/(double)node[i].num;
            break;
        }
    }printf("%.2f\n", ans);

    return 0;
}
