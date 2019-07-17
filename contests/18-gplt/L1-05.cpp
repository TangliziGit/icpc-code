#include <cstdio>
#include <map>
const int NMAX=1000;
struct Item{
    long long id;
    int num;
    Item(long long id=0, int num=0):
        id(id),num(num) {}
}items[NMAX+5];

int main(void){
    int n; long long m;
    scanf("%d", &n);
    for (int i=0, num[2]; i<n; i++){
        scanf("%lld%d%d", &m, &num[0], &num[1]);
        items[num[0]]=Item(m, num[1]);
    }
    scanf("%d", &n);
    for (int i=0, idx; i<n; i++){
        scanf("%d", &idx);
        printf("%lld %d\n", items[idx].id, items[idx].num);
    }

    return 0;
}
