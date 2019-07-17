#include <cstring>
#include <cstdio>
const int maxn=1e6, maxm=1e4;
char T[maxn+5], P[maxm+5];
int next[maxm+5];
void kmppre(int m){
    next[0]=next[1]=0;
    for (int i=1; i<m; i++){
        int j=next[i];
        while (j && P[j]!=P[i]) j=next[j];
        next[i+1]=(P[i]==P[j]?j+1:0);
    }
}

int kmp(int n, int m){
    int ans=0;
    kmppre(m);
    for (int i=0, j=0; i<n; i++){
        while (j && T[i]!=P[j]) j=next[j];
        if (P[j]==T[i]) j++;
        if (j==m){ans++; j=next[j];}
    }return ans;
}

int main(void){
    int kase;

    scanf("%d", &kase);
    while (kase--){
        scanf("%s%s", P, T);
        printf("%d\n", kmp(strlen(T), strlen(P)));
    }

    return 0;
}
