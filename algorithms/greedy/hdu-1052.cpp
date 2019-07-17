#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    int n, a[1020], b[1020];

    while (scanf("%d", &n)==1 && n){
        for (int i=0; i<n; i++) scanf("%d", &a[i]);
        for (int i=0; i<n; i++) scanf("%d", &b[i]);
        sort(a, a+n); sort(b, b+n);

        int head=0, last=n-1, alast=n-1, i=0, cnt=0;
        while (i<=alast){
            if (b[i]<a[head]){
                head++; cnt++; i++;
            }else if (b[i]>a[head]){
                head++; alast--; cnt--;
            }else if (b[i]==a[head]){
                if (b[alast]<a[last]){
                    alast--; last--; cnt++;
                }else if (b[alast]>a[last]){
                    alast--; head++; cnt--;
                }else{
                    if (a[head]<b[alast]) cnt--;
                    else if (a[head]>b[alast]) cnt++;
                    alast--; head++;
                }
            }
        }printf("%d\n", cnt*200);
    }

    return 0;
}
