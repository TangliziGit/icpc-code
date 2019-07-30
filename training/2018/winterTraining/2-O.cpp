#include <cstdio>
#include <cmath>
const int MAX=31268;
long long sum[MAX+5];
char ans[143360+5];
int func(int m){
    static int n=0;
    int i=1;
    while (m/10) m/=10, i++;
    return n+=i;
}

void init(void){
    sum[0]=0;
    for (int i=1; i<=MAX; i++)
        sum[i]+=sum[i-1]+func(i);
    for (int i=1, d=1, tmp=10, size=0; i<=MAX; i++){
        sprintf(ans+size, "%d", i);
        if (i==tmp) {d++; tmp*=10;}
        size+=d;
    }
}

int search(int n){
    int l=0, r=MAX;
    while (l<r-1){
        int mid=l+(r-l)/2;
        if (sum[mid]>n) r=mid;
        else if (sum[mid]==n) return mid;
        else l=mid;
    }return n-sum[l];
}

int main(void){
    int n;
    
    init();scanf("%*d");
    while (scanf("%d", &n)==1) printf("%c\n", ans[search(n)-1]);

    return 0;
}
