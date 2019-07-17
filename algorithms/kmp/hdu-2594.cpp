#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn=5e4;
int next[maxn+20];
char str[maxn+20];
void getNext(int next[], char str[], int len){
    next[0]=next[1]=0;
    for (int i=1; i<len; i++){
        int j=next[i];
        while (j && str[i]!=str[j]) j=next[j];
        next[i+1]=(str[i]==str[j]?j+1:0);
    }
}

int main(void){
    char a[maxn+20];
    while (~scanf("%s%s", str, a)){
        int n=strlen(str), m=strlen(a), minn=std::min(n, m);
        for (int i=0; i<m; i++) str[n++]=a[i];
        getNext(next, str, n);
        // for (int i=0; i<n; i++) printf("%d(%d) ", next[i], i);

        int ans=next[n];
        if (ans>minn) ans=minn;
        for (int i=0; i<ans; i++) printf("%c", str[i]);
        if (ans) printf(" %d\n", ans);
        else printf("0\n");
    }

    return 0;
}
