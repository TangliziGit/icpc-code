#include <cstdio>
int n, ans[10000+5];
void init(void){
    ans[1]=2;
    for (int i=2; i<10000+5; i++)
        ans[i]=ans[i-1]+4*i-3;
}

int main(void){
    init();
    scanf("%*d");
    while (scanf("%d", &n)==1 && n)
        printf("%d\n", ans[n]);

    return 0;
}
