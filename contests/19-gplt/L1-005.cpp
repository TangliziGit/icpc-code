#include <cstdio>

int main(void){
    int a, b, num;
    bool pre=false;

    scanf("%d%d", &a, &b);
    num=a*b;
    while (num>0){
        if (pre==false && num%10==0)
            ;
        else{
            printf("%d", num%10);
            pre=true;
        }
        num/=10;
    }printf("\n");

    return 0;
}
