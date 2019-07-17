#include <cstdio>

int main(void){
    int n ,q;
    long long a[int(2e5)+5], k[int(2e5)+5], sum=0, ls[int(2e5)+5];
    bool mod[int(2e5)+5]={false};

    scanf("%d%d", &n, &q);
    for (int i=0; i<n; i++) {scanf("%lld", &a[i]); sum+=a[i]; ls[i]-=sum;}
    for (int i=0; i<q; i++) {
        scanf("%lld", &k[i]);
        // if (k[i]>=sum){k[i]%=sum; mod[i]=true;}
    }

    long long idx=0, tmp=0;
    for (int i=0; i<q; i++){
        if (tmp!=0){
            if (k[i]>=tmp) {k[i]-=tmp; tmp=0; idx=(idx+1)%n;}
            else {tmp-=k[i]; k[i]=0;}
        }

        if (k[i]>0 && k[i]>=ls[idx]+sum+a[i]) idx=0;
        else while (k[i]>0){
            if (k[i]>=a[idx]) {k[i]-=a[idx]; idx=(idx+1)%n;}
            else {tmp=a[idx]-k[i]; k[i]=0;}
        }

        printf("%lld\n", n-idx);
    }

    return 0;
}
