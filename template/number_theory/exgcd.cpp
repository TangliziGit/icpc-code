#include <cstdio>

void exgcd(int a, int b, int &d, int &x, int &y){
    if (b==0) {d=a; x=1; y=0;}
    else {exgcd(b, a%b, d, y, x); y-=x*(a/b);}
}

int main(void){
    int a, b, d, x, y;

    scanf("%d%d", &a, &b);
    exgcd(a, b, d, x, y);
    printf("%d %d %d\n", d, x, y);

    return 0;
}
