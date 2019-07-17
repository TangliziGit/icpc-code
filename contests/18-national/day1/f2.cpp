#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+20;
int tmp[maxn];
int last[maxn];
int search(int num, int low, int high){
    int mid;
    while (low<=high){
        mid=(low+high)/2;
        if (num>=last[mid]) low=mid+1;
        else high=mid-1;
    }return low;
}

int upper(int n){
    int size=1;
    last[1]=tmp[1];
    for (int i=2; i<=n; i++){
        if (last[size]<=tmp[i]){
            size++;
            last[size]=tmp[i];
        }else{
            int idx=search(tmp[i], 1, size);
            last[idx]=tmp[i];
        }
    }
    return size;
}

int lower(int n){
    reverse(tmp, tmp+n);
    int ans=upper(n);
    reverse(tmp, tmp+n);
    return ans;
}

int main(void){
    int n, T;

    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i=1; i<=n; i++)
            scanf("%d", &tmp[i]);

        int ans=max(upper(n), lower(n));
        printf("%d %d\n", upper(n), lower(n));
        if (n-1<=ans) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

