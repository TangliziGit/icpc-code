#include <cstdio>
#define abs(x) (((x)>0)?(x):(-x))
void exgcd(int a, int b, int &d, int &x, int &y){
    if (b==0) {d=a; x=1; y=0;}
    else {exgcd(b, a%b, d, y, x); y-=x*(a/b);}
}

int main(void){
    int a, b, c;

    while (scanf("%d%d%d", &a, &b, &c)==3 && a){
        int x, y, d;
        exgcd(a, b, d, x, y);
        a/=d; b/=d; c/=d;
        x*=c; y*=c;
        
        int ax, ay, bx, by;
        ax=(x%b+b)%b;
        ay=(c-a*ax)/b;
        by=(y%a+a)%a;
        bx=(c-b*by)/a;
        // printf("%d %d||%d %d||%d %d\n", x, y, ax, ay, bx, by);

        if (abs(ax)+abs(ay)<abs(by)+abs(bx))
            printf("%d %d\n", abs(ax), abs(ay));
        else if (abs(ax)+abs(ay)>abs(by)+abs(bx))
            printf("%d %d\n", abs(bx), abs(by));
        else if (a*abs(ax)+b*abs(ay)>b*abs(by)+a*abs(bx))
            printf("%d %d\n", abs(bx), abs(by));
        else printf("%d %d\n", abs(ax), abs(ay));
    }

    return 0;
}
