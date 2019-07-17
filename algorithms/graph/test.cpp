#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <functional>
using namespace std;

double getRand(int n){
    return (rand()%n+1)/(double)100;
    // return rand()%n+1;
}

int main(void){
    long long n=1e5, emax;
    long long m=n;

    printf("1\n%lld %lld %d\n", n, m, rand()%1000+1);
    srand((unsigned)time(NULL));
    // for (int cnt=0; cnt<3; cnt++){
        for (int i=0; i<n; i++) printf("%lld ", rand()%n+1);
        printf("\n");
        for (int i=0; i<m; i++)
            printf("%lld %lld %d\n", rand()%n+1, rand()%n+1, rand()%1000+1);
    //}
    
    return 0;
}
