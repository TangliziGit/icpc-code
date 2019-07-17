#include <cstdio>
#include <cstring>
const int maxn=1e6;
char str[maxn+5];
int next[maxn+5];
void getnext(int next[], char str[], int len){
    next[0]=next[1]=0;
    for (int i=1; i<len; i++){
        int j=next[i];
        while (j && str[i]!=str[j]) j=next[j];
        next[i+1]=(str[i]==str[j]?j+1:0);
    }
}

int main(void){
    while (scanf("%s", str)==1 && str[0]!='.'){
        int n=strlen(str);
        getnext(next, str, n);
        printf("%d\n", n/(n-next[n]));
    }

    return 0;
}
