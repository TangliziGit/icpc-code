#include <cstdio>
#include <algorithm>
using namespace std;
struct Hero{
    int hp, dps;
    Hero(int hp=0, int dps=0):hp(hp),dps(dps) {}
    bool operator < (const Hero &a) const{
        return dps*a.hp>a.dps*hp;
    }
}heroes[25];

int main(void){
    int n;
    while (scanf("%d", &n)==1 && n){
        for (int i=0; i<n; i++)
            scanf("%d%d", &heroes[i].dps, &heroes[i].hp);
        sort(heroes, heroes+n);
        
        int sum=0, time=0;
        for (int i=0; i<n; i++){
            time+=heroes[i].hp;
            sum+=heroes[i].dps*time;
        }printf("%d\n", sum);
    }

    return 0;        
}
