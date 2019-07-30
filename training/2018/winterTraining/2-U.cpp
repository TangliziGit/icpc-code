#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    int n, size, items[int(1e5)+5];

    while (scanf("%d%d", &n, &size)==2){
        for (int i=0; i<n; i++) scanf("%d", &items[i]);
        sort(items, items+n);

        int sum=0;
        for (int i=0, j=n-1; i<=j; ){
            if (i==j) {sum++; break;}
            else if (items[i]+items[j]<=size) {sum++; i++; j--;}
            else {sum++; j--;}
        }printf("%d\n", sum);
    }

    return 0;
}
