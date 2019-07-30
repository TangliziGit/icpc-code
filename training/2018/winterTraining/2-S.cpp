#include <cstdio>
#include <algorithm>
using namespace std;
struct Product{
    int time, value;
    Product(void){}
    bool operator < (const Product &a) const{
        return value>a.value;
    }
};

int main(void){
    int n;

    while (scanf("%d", &n)==1 && n){
        Product pdt[int(1e4)+5];
        for (int i=0; i<n; i++)
            scanf("%d%d", &pdt[i].value, &pdt[i].time);
        sort(pdt, pdt+n);

        int vis[int(1e4)+5]={0}, sum=0;
        for (int i=0; i<n; i++){
            int t=pdt[i].time;
            while (t>=1 && vis[t]) t--;
//            printf("v%d t%d\n", pdt[i].value, t);
            if (t) {sum+=pdt[i].value; vis[t]=1;}
        }printf("%d\n", sum);
    }

    return 0;
}
