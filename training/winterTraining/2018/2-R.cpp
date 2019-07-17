#include <cstdio>
#include <algorithm>
using namespace std;
struct Item{
    int time, level;
    Item(void){}
    bool operator < (const Item &a) const{
        return (time>a.time)||(time==a.time && level>a.level);
    } 
};

int main(void){
    int n, m;

    while (scanf("%d%d", &n, &m)==2 && n){
        Item machine[int(1e5)+5], task[int(1e5)+5];
        for (int i=0; i<n; i++) scanf("%d%d", &machine[i].time, &machine[i].level);
        for (int i=0; i<m; i++) scanf("%d%d", &task[i].time, &task[i].level);
        sort(task, task+m); sort(machine, machine+n);

        long long sum=0, number=0;
        int levels[105]={0};
        for (int i=0, j=0; i<m; i++){
            for ( ;j<n && machine[j].time>=task[i].time; j++)
                levels[machine[j].level]++;
            for (int l=task[i].level; l<=100; l++) if (levels[l]){
                number++; sum+=500*task[i].time+2*task[i].level;
                levels[l]--;
                break;
            }
        }printf("%lld %lld\n", number, sum);
    }

    return 0;
}
