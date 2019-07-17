#include <cstdio>
#include <cstring>
const int maxn=1e6;
int n, next[maxn+20], len[maxn+20];
char str[maxn+20];
void getnext(int next[], char str[], int len){
    next[0]=next[1]=0;
    for (int i=1; i<len; i++){
        int j=next[i];
        while (j && str[i]!=str[j]) j=next[j];
        next[i+1]=(str[i]==str[j]?j+1:0);
    }
}

int main(void){
    int cnt=1;
    while (scanf("%d", &n)==1 && n){
        scanf("%s", str);
        getnext(next, str, n); len[1]=1;
        printf("Test case #%d\n", cnt++);
        for (int i=2; i<=n; i++){
            if (next[i]==0) len[i]=i;
            else if (i-next[i]==len[next[i]]){
                len[i]=len[next[i]];
                printf("%d %d\n", i, i/len[i]);
            }else len[i]=i;
        }printf("\n");
    }

    return 0;
}
