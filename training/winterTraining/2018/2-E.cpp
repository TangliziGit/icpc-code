#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
    int a, b;
    double k;
    Node(double k=0, int a=0, int b=0):k(k),a(a),b(b) {}
    bool operator < (const Node a) const{
        return k < a.k;
    }
}node[1000];

int main(void){
    int m, n, a, b;

    while (scanf("%d%d", &m, &n)==2 && m!=-1){
        for (int i=0; i<n; i++){
            scanf("%d%d", &a, &b);
            node[i]=Node(a/(double)b, a, b);
        }

        sort(node, node+n);
        double ans=0;
        for (int i=n-1; i>=0; i--){
            if (m>=node[i].b) {ans+=node[i].a; m-=node[i].b;}
            else {ans+=node[i].k*m; break;}
        }printf("%.3f\n", ans);
    }

    return 0;
}
