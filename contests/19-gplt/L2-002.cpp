#include <cstdio>
#include <map>
#include <set>
using namespace std;
const int maxn=1e5+20;
struct Node{
    int addr, value, next;
    Node(){}
    Node(int addr, int value, int next)
        :addr(addr), value(value), next(next) {}
}dup[maxn];
map<int, Node> nmap;
set<int> vis;
int start, n;

int main(void){
    int addr, value, next;

    scanf("%d%d", &start, &n);
    for (int i=0; i<n; i++){
        scanf("%d%d%d", &addr, &value, &next);
        nmap[addr]=Node(addr, value, next);
    }

    int dsiz=0, ptr=start;
    while (ptr!=-1){
        Node node=nmap[ptr];
        if (vis.count(abs(node.value)))
            dup[dsiz++]=node;
        else{
            vis.insert(abs(node.value));
            if (ptr==start) printf("%05d %d ", node.addr, node.value);
            else printf("%05d\n%05d %d ", node.addr, node.addr, node.value);
        }ptr=node.next;
    }printf("-1\n");

    for (int i=0; i<dsiz; i++){
        Node &node=dup[i];
        if (i==0) printf("%05d %d ", node.addr, node.value);
        else printf("%05d\n%05d %d ", node.addr, node.addr, node.value);
    }
    if (dsiz!=0) printf("-1\n");

    return 0;
}
