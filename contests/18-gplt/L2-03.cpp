#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e3;
struct Item{
    double stock, val;              // integer can't pass
    Item(double stock=0, double val=0):
        stock(stock), val(val) {}
    bool operator < (const Item &a) const{
        return val*a.stock>stock*a.val;
    }
}item[maxn+5];

int main(void){
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) scanf("%lf", &item[i].stock);
    for (int i=0; i<n; i++) scanf("%lf", &item[i].val);
    sort(item, item+n);

    double ans=0;
    for (int i=0; i<n; i++){
        if (item[i].stock<m) {ans+=item[i].val; m-=item[i].stock;}
        else {ans+=item[i].val*m/(double)item[i].stock; break;}
    }printf("%.2f\n", ans);

    return 0;
}
