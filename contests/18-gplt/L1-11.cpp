#include <cstdio>
int vis[300];

int main(void){
    char str[int(1e4+5)], ch;
    fgets(str, sizeof(str), stdin);
    while (scanf("%c", &ch)==1 && ch!='\n') vis[(int)ch]=1;
    for (int i=0; str[i]!='\n'; i++)
        if (vis[str[i]]==0) printf("%c", str[i]);
    printf("\n");

    return 0;
}
