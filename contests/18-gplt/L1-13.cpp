#include <cstdio>
int ans[11]={0, 1, 3, 9, 33, 153, 873, 5913, 46233, 409113, 4037913};

int main(void){
    int n;

    scanf("%d", &n);
    printf("%d\n", ans[n]);

    return 0;
}
