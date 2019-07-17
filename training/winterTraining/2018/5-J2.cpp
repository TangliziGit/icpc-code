#include <cstdio>
#include <cstring>
#define lowbit(x) ((x)&(-x))
const int XMAX=32000;
int n, stars[XMAX+5];
int sum(int x){
    int result=0;
    for (int i=x; i>0; i-=lowbit(i))
        result+=stars[i];
    return result;
}

void add(int x){
    for (int i=x; i<=XMAX+1; i+=lowbit(i))
        stars[i]++;
}

int main(void){
    while (scanf("%d", &n)==1){
        int level[15000+5]={0};
        memset(stars, 0, sizeof(stars));
        for (int i=0, x, y; i<n; i++){
            scanf("%d%d", &x, &y);
            level[sum(x+1)]++;
            add(x+1);
        }
        for (int i=0; i<n; i++) printf("%d\n", level[i]);
    }

    return 0;
}
