#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e3+20;

int main(void){
    int n, num[maxn];

    while (scanf("%d", &n)==1 && n){
        for (int i=0; i<n; i++) scanf("%d", &num[i]);

        int last[maxn]={0}, size=0;
        for (int i=0; i<n; i++){
            if (i==0) last[size++]=num[i];
            else if (last[size-1]<num[i]){
                last[size++]=num[i];
            }else{
                int idx=lower_bound(last, last+size, num[i])-last;
                last[idx]=num[i];
            }
        }printf("%d\n", size);
    }

    return 0;
}
