#include <cstdio>
#include <cstring>

int main(void){
    int tmp, ans=0, pre=-1;

    while (scanf("%d", &tmp)==1 && tmp){
        if (tmp==1){
            ans+=1;
            pre=1;
        }else{
            if (pre==-1 || pre==1){
                ans+=2;
                pre=2;
            }else if (pre>=2){
                ans+=2+pre;
                pre+=2;
            }
        }
    }printf("%d\n", ans);

    return 0;
}
