#include <cstdio>
#include <algorithm>
#define debug(x) printf("%s = %d\n", #x, x)
#define fdebug(x) printf("%s = %f\n", #x, x)
using namespace std;
const int maxn=1e3+20;
const double eps=1e-6;
int n, k;
double a[maxn], b[maxn], c[maxn];

bool judge(double avg){
    double sum=0;
    for (int i=0; i<n; i++)
        c[i]=a[i]-avg*b[i];
    // sort(c, c+n, [](int x, int y){return x>y;});
    sort(c, c+n);

    for (int i=k; i<n; i++)
        sum+=c[i];
    return sum>=0;
}

double solve(void){
    double l=0, r=1;
    while (r-l>=eps){
        double mid=(l+r)/2;

        if (judge(mid)) l=mid;
        else r=mid;
    }return r;
}

int main(void){
    while (scanf("%d%d", &n, &k)==2 && n){
        for (int i=0; i<n; i++) scanf("%lf", &a[i]);
        for (int i=0; i<n; i++) scanf("%lf", &b[i]);
        printf("%.0lf\n", 100*solve());
    }

    return 0;
}
