#include <cstdio>
#include <cstring>

int main(void){
    int len;
    char pad[10], xx[100];

    scanf("%d%s\n", &len, pad);
    fgets(xx, sizeof(xx), stdin);
    xx[strlen(xx)-1]=0;

    if (strlen(xx)<=len){
        for (int i=0; i+strlen(xx)<len; i++)
            printf("%c", pad[0]);
        printf("%s\n", xx);
    }else{
        for (int i=strlen(xx)-len; i<strlen(xx); i++)
            printf("%c", xx[i]);
        printf("\n");
    }

    return 0;
}
