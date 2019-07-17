#include <cstdio>
#include <cstring>

int main(void){
    int h, m;

    scanf("%d:%d", &h, &m);
    if (h<12 || (h==12 && m==0) || (h==0 && m==0))
        printf("Only %02d:%02d.  Too early to Dang.\n", h, m);
    else{
        h-=12;
        if (m==0){
            while (h--) printf("Dang");
            printf("\n");
        }else{
            while (h--) printf("Dang");
            printf("Dang\n");
        }
    }

    return 0;
}
