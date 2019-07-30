#include <cstdio>
#include <cstring>

int main(void){
    long long n, u, d;

    while (scanf("%lld%lld%lld", &n, &u, &d)==3 && n+u+d){
        long long pos=0, cnt=0;
        while (true){
            pos+=u; cnt++;
            if (pos>=n) break;
            pos-=d; cnt++;
        }

        printf("%lld\n", cnt);
    }

    return 0;
}
