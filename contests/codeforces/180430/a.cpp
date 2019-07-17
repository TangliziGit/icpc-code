#include <cstdio>

int main(void){
    char str[105];
    int n, zeros=0;

    scanf("%d%s", &n, str);
    for (int i=0; i<n; i++)
        if (str[i]=='0') zeros++;

    if (n==1 && zeros==1) printf("0\n");
    else {
        printf("1");
        for (int i=0; i<zeros; i++) printf("0");
        printf("\n");
    }

    return 0;
}
