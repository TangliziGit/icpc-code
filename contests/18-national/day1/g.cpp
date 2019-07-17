#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const double eps=1e-6;
const int maxn=100+20;
const double PI=3.1415926;
double x[maxn], y[maxn], cx, cy;
int n;
bool equal(double a, double b){
    return (a-b)<eps && (b-a)<eps;
}

bool solve(void){
    double k1=(y[1]-y[0])/(x[1]-x[0]), k2=(y[2]-y[0])/(x[2]-x[0]);
    if (equal(x[2], x[1]) && equal(x[1], x[0])) return false;
    if (equal(k1, k2)) return false;

    double a1, b1, c1, a2, b2, c2;
    a1=x[0]-x[1];
    b1=y[0]-y[1];
    c1=(x[0]*x[0]-x[1]*x[1]+y[0]*y[0]-y[1]*y[1])/2;
    a2=x[0]-x[2];
    b2=y[0]-y[2];
    c2=(x[0]*x[0]-x[2]*x[2]+y[0]*y[0]-y[2]*y[2])/2;
    cy=(c1*a2-c2*a1)/(a2*b1-a1*b2);
    cx=(c1*b2-c2*b1)/(b2*a1-b1*a2);
    return true;
}

int main(void){
    int T;

    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i=0; i<n; i++)
            scanf("%lf%lf", &x[i], &y[i]);
        if (solve()==false){
            printf("NO\n");
            continue;
        }

        bool xflg=0;
        bool vis[maxn]={0};
        double xx=x[0]-cx, yy=y[0]-cy;
        for (int k=1; k<n; k++){
            // printf("%lf, %lf\n", xx, yy);
            double tmpx=xx, tmpy=yy, th=2*PI/(double)n;
            xx=tmpx*cos(th)-tmpy*sin(th);
            yy=tmpx*sin(th)+tmpy*cos(th);

            bool flg=0;
            for (int i=1; i<n; i++) if (!vis[i]){
                if (equal(xx, x[i]-cx) && equal(yy, y[i]-cy)){
                    vis[i]=1; flg=1;
                    break;
                }
            }
            if (flg==0) xflg=1;
        }

        // printf("%lf %lf\n", cx, cy);
        if (xflg==1) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}
