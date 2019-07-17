#include <cstdio>

int main(void){
    int n, k;

    scanf("%d%d", &n, &k);
    while (k--){
        if (n%10==0) n/=10;
        else n--;
    }printf("%d\n", n);

    return 0;
}
