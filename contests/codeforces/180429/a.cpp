#include <cstdio>
const int max=105;

int main(void){
    int n, s, hour, minu[max];

    scanf("%d%d", &n, &s);
    for (int i=0; i<n; i++){
        scanf("%d%d", &hour, &minu[i]);
        minu[i]+=60*hour;
    }

    bool flg=false;
    if (s+1 < minu[0]) {printf("0 0\n"); flg=true;}
    else for (int i=0; i<n-1; i++)
        if (minu[i]+s*2+1 < minu[i+1]){
            // printf("--%d %d\n", minu[i]+s*2+1, minu[i+1]);
            printf("%d %d\n", (minu[i]+s+1)/60, (minu[i]+s+1)%60);
            flg=true;
            break;
        }

    if (!flg) printf("%d %d\n", (minu[n-1]+s+1)/60, (minu[n-1]+s+1)%60);

    return 0;
}
