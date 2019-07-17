#include <cstdio>
#include <cmath>
const double eps=1e-6;
int getPre(int n, int k){
    double idx=(k*log10(n))-(int)(k*log10(n));//+2+eps;
    return pow(10, idx)*100;
}

int getPost(int n, int k){
    int num=n%1000, ans=1;
    for (int i=0; 1<<i <=k; i++){
        if (k & 1<<i) ans=(ans*(num%1000))%1000;
        num=((long long)num*num)%1000;
    }return ans;
}

int quikPow(int n, int k){
    if (k==0) return 1;
    if (k==1) return n%1000;

    long long tmp=quikPow(n, k/2);
    tmp=(tmp*tmp)%1000;
    if (k%2) tmp=(tmp*n)%1000;
    return tmp;
}

int main(void){
    int T, n, k;

    scanf("%d", &T);
    for (int cnt=1; cnt<=T; cnt++){
        scanf("%d %d", &n, &k);
        int pre=getPre(n, k), post=quikPow(n, k);// getPost(n, k);
        printf("Case %d: %03d %03d\n", cnt, pre, post);
    }

    return 0;
}
