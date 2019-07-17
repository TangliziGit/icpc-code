#include <cstdio>
#include <algorithm>
using namespace std;
const int Max=1e5+5;

int main(void){
    int n, A, B, s[Max];
    long long sum=0;

    scanf("%d%d%d", &n, &A, &B);
    for (int i=0; i<n; i++){
        scanf("%d", &s[i]);
        sum+=s[i];
    }

    bool flg=false;
    sort(s+1, s+n);
    for (int i=n-1; i>=1; i--){
        if (s[0]*A-sum*B>=0){
            printf("%d\n", n-i-1); flg=true; break;
        }
        sum-=s[i];
    }

    if (!flg) printf("%d\n", n-1);

    return 0;
}
