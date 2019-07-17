#include <cstdio>
#include <cstring>

int main(void){
    int x;

    scanf("%d", &x);
    printf("%d\n", (x+1)%7+1);

    return 0;
}
