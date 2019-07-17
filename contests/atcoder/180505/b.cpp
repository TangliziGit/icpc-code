#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    int a, b, c, k;

    scanf("%d%d%d%d", &a, &b, &c, &k);
    if (a<b) swap(a, b);
    if (a<c) swap(a, c);
    printf("%d\n", b+c+(a<<k));

    return 0;
}
