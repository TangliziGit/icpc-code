#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e5+20;
int A[maxn], n;

bool islower(void){
    int k=-1, a[maxn];
    memcpy(a, A, sizeof(A));
    for (int i=1; i<n; i++){
        if (a[i]<=a[i-1]) continue;
        else{
            k=i; 
            a[i]=a[i-1];
            break;
        }
    }
    if (k<0) return true;


    for (int i=1; i<n; i++){
        if (a[i]<=a[i-1]) continue;
        else if (k==i) continue;
        else return false;
    }
    return true;
}

bool isupper(void){
    int k=-1, a[maxn];
    memcpy(a, A, sizeof(A));
    for (int i=1; i<n; i++){
        if (a[i]>=a[i-1]) continue;
        else{
            k=i; 
            a[i]=a[i-1];
            break;
        }
    }
    if (k<0) return true;
    for (int i=1; i<n; i++){
        if (a[i]>=a[i-1]) continue;
        else if (k==i) continue;
        else return false;
    }return true;
}

int main(void){
    int T;

    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i=0; i<n; i++) scanf("%d", &A[i]);
        if (islower() || isupper()) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
