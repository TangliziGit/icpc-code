#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Box{
    int x, y, z;
    Box(int x=0, int y=0, int z=0):
        x(x),y(y),z(z) {}
}box[200];
int n, data[200];
int dp(int idx){
    if (data[idx]!=-1) return data[idx];
    data[idx]=box[idx].z;
    for (int i=0; i<n; i++){
        if (i==idx || box[i].x>=box[idx].x || box[i].y>=box[idx].y) continue;
        data[idx]=max(data[idx], dp(i)+box[idx].z);
    }return data[idx];
}

int main(void){
    int cnt=0;
    while (scanf("%d", &n)==1 && n){
        memset(data, -1, sizeof(data));
        for (int i=0, x, y, z; i<n; i++){
            scanf("%d%d%d", &x, &y, &z);
            box[6*i+0]=Box(x, y, z); box[6*i+1]=Box(x, z, y);
            box[6*i+2]=Box(y, z, x); box[6*i+3]=Box(y, x, z);
            box[6*i+4]=Box(z, x, y); box[6*i+5]=Box(z, y, x);
        }n*=6;

        int max;
        for (int i=0; i<n; i++)
            if (max<dp(i) || i==0) max=dp(i);
        printf("Case %d: maximum height = %d\n", ++cnt, max);
    }

    return 0;
}
