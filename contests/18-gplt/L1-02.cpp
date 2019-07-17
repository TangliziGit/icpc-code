#include <cstdio>
#include <cmath>
int abs(int x){
    if (x>=0) return x;
    return -x;
}
bool judge(int i, int j){
    if (i==0 && j==0) return true;
    if (i<0 && i<=j && j<=-i) return true;
    if (i>0 && -i<=j && j<=i) return true;
    return false;
}

int main(void){
    int n, m; char ch[5];
    scanf("%d%s", &n, ch);

    m=(int)sqrt((n+1)/(float)2);
    for (int i=1-m; i<m; i++, printf("\n"))
        for (int j=1-m; j<=abs(i); j++)
            printf("%c", (judge(i, j))?ch[0]:' ');
    printf("%d\n", n-2*m*m+1);

    return 0;
}
