#include <cstdio>
#include <cstring>
int getMin(int a[]){
    int idx=0;
    for (int i=0; i<3; i++)
        if (a[idx]>a[i]) idx=i;
    return idx;
}

int sum(int a[], int idx){
    int res=0;
    for (int i=0; i<3; i++)
        if (i!=idx) res+=a[i];
    return res;
}

int main(void){
    int tar, now[3];

    while (scanf("%d%d", &tar, &now[0])==2){
        int time=0;
        now[2]=now[1]=now[0];
        while (now[0]<=tar && now[1]<=tar && now[2]<=tar){
            // printf("%d %d %d\n", now[0], now[1], now[2]);
            if (now[0]==now[1] && now[1]==now[2] && now[2]==tar) break;
            int idx=getMin(now), s=sum(now, idx)-1;

            if (s>tar) s=tar;
            now[idx]=s;

            time++;
        }
        printf("%d\n", time);
    }

    return 0;
}
