#include <cstdio>

int main(void){
    char ch; int vis[30]={0};

    while (scanf("%c", &ch)==1 && ch!='\n')
        if (ch<='9' && ch>='0') vis[ch-'0']++;
    for (int i=0; i<30; i++)
        if (vis[i]) printf("%d:%d\n", i, vis[i]);

    return 0;
}
