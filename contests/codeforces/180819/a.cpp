#include <cstdio>
#include <cstring>
char str[int(1e5+20)];

int main(void){
    int n;

    scanf("%d", &n);
    scanf("%s", str);

    int vis[30]={0};
    bool flg=false;
    for (int i=0; i<n; i++)
        vis[str[i]-'a']++;
    for (int i=0; i<26; i++)
        if (vis[i]>=2){
            printf("%c", i+'a');
            flg=true; break;
        }
    if (!flg) printf("No\n");
    else printf("Yes\n");

    return 0;
}
