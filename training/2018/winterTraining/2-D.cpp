#include <cstdio>
const double g=9.81;

int main(void){
    double k, m, h, l;

    while (scanf("%lf%lf%lf%lf", &k, &l, &h, &m)==4 && k){
        if (h<=l){
            if (2*g*h<=100) printf("James Bond survives.\n");
            else printf("Killed by the impact.\n");
        }else{
            double ans=2*g*h-k*(h-l)*(h-l)/m;
            if (ans<0) printf("Stuck in the air.\n");
            else if (ans<=100) printf("James Bond survives.\n");
            else printf("Killed by the impact.\n");
        }
    }

    return 0;
}
