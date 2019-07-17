#include <cstdio>
#include <cstring>

int main(void){
    int n, a, b;
    char name[100];

    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%s%d%d", name, &a, &b);
        if ((a>20 || a<15) || (b<50) || (b>70))
            printf("%s\n", name);
    }


    return 0;
}
