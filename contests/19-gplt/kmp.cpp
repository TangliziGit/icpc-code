#include <cstdio>
#include <cstring>
char P[100]="aabaaac", T[100]="aabaaabaaac";
int fail[100];
void getFail(int m){
    fail[0]=fail[1]=0;
    for (int i=1; i<m; i++){
        int j=fail[i];
        while (j && P[j]!=P[i]) j=fail[j];
        fail[i+1]=((P[i]==P[j])?j+1:0);
    }
}

int count(int n, int m){
    int cnt=0;
    getFail(m);
    for (int i=0, j=0; i<n; i++){
        while (j && T[i]!=P[j]) j=fail[j];
        if (P[j]==T[i]) j++;
        if (j==m){
            return i-m+1;
        }
    }return cnt;
}

int main(void){
    int n=strlen(T), m=strlen(P);

    getFail(m);
    for (int i=0; i<m; i++)
        printf("%d ", fail[i]);
    printf("\n%d\n", count(n, m));
    
    return 0;
}
