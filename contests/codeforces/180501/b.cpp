#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long func(long long num[], int idx){
    long long n[15], nn=num[idx];
    memcpy(n, num, sizeof(n));
    n[idx]=0;

    long long a=nn/14, b=nn%14, sum=0;
    for (int i=0; i<14; i++){
        if ((idx+b)>=14 && (i<=(idx+b)%14 || i>idx)) n[i]++;
        else if ((idx+b)<14 && (i>idx && i<=idx+b)) n[i]++;
        n[i]+=a;
        if (n[i]%2==0) sum+=n[i];
    }return sum;
}

int main(void){
    long long num[15], m=0;

    for (int i=0; i<14; i++) scanf("%lld", &num[i]);
    for (int i=0; i<14; i++) m=max(func(num, i), m);
    printf("%lld", m);

    return 0;
}
