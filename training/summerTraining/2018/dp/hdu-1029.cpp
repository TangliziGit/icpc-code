#include <cstdio>

int main(void){
    int n;

    while (scanf("%d", &n)==1 && n){
        int cnt=0, tmp, ans;
        for (int i=0; i<n; i++){
            scanf("%d", &tmp);

            if (tmp==ans) cnt++;
            else if (--cnt<0){
                cnt=0; ans=tmp;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
