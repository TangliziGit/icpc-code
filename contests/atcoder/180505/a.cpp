#include <cstdio>

int main(void){
    int a, b;

    scanf("%d%d", &a, &b);
    if (b>=a) printf("%d\n", a);
    else printf("%d\n", a-1);

    return 0;
}
