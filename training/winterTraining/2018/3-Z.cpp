#include <cstdio>
#include <cmath>
const double epsilon=1e-6;
double cables[int(1e4)+5];
int n, k;
bool solve(double mid){
    int cnt=0;
    for (int i=0; i<n; i++) cnt+=int(cables[i]/mid);
    return cnt>=k;
}

double search(double min, double max){
    double x=min, y=max;
    while (fabs(y-x)>epsilon){
        double mid=x+(y-x)/2;
        if (solve(mid)) x=mid;
        else y=mid;
    }return (int)(y*100)/(double)100;
}

int main(void){
    while (scanf("%d%d", &n, &k)==2){
        int sum=0;
        for (int i=0; i<n; i++) {scanf("%lf", &cables[i]); sum+=(int)(cables[i]);}
        printf("%.2f\n", search(0, 1e6));
    }

    return 0;
}
