#include <cstdio>
int np, n;
const double pi=3.1415926, epsilon=1e-5;
double pie[int(1e4)+5];
bool solve(double mid){
    int cnt=0;
    for (int i=0; i<np; i++) cnt+=int(pie[i]/mid);
    return cnt>=n;
}

double search(double max){
    double x=0, y=max;
    while (y-x>epsilon){
        double mid=x+(y-x)/2;
        if (solve(mid)) x=mid;
        else y=mid;
    }return y;
}

int main(void){
    int T;

    scanf("%d", &T);
    while (T--){
        double max;
        scanf("%d%d", &np, &n); n++;
        for (int i=0, tmp; i<np; i++){
            scanf("%d", &tmp);
            pie[i]=tmp*tmp*pi;
            if (pie[i]>max || i==0) max=pie[i];
        }
        printf("%.4f\n", search(max));
    }

    return 0;
}
