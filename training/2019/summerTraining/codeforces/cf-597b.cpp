#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=5e5+20;
struct Item{
    int a, b;
    Item(){}

    bool operator < (const Item &x) const{
        if (b==x.b) return a<x.a;
        return b<x.b;
    }
}items[maxn];

int main(void){
    int n;
    while (scanf("%d", &n)==1){
        for (int i=0; i<n; i++)
            scanf("%d%d", &items[i].a, &items[i].b);

        sort(items, items+n);

        int prev=0, cnt=0;
        for (int i=0; i<n; i++) if (prev<items[i].a){
            prev=items[i].b;
            cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
