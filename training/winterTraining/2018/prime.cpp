#include <cstdio>
#include <cstring>
const int max=50;
int prime[max+5];

int main(void){
    memset(prime, -1, sizeof(prime));
    prime[0]=prime[1]=0;
    for (int i=2; i<max; i++){
        if (prime[i]) for (int k=2*i; k<max; k+=i){
            prime[k]=0;
        }
    }

    for (int i=0; i<max; i++)
        printf("%d, ", prime[i]);

    return 0;
}
