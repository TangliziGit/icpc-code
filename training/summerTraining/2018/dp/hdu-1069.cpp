#include <cstdio>
#include <cstring>
struct Box{
    int x, y, hei;
    Box(int x=0, int y=0, int hei=0):
        x(x), y(y), hei(hei) {}
    bool operator < (const Box &a) const{
        if (x<a.x && y<a.y) return true;
        if (y<a.x && x<a.y) return true;
        return false;
    }
}box[100];
bool G[100][100];
int data[100], n;
int max(int a, int b){
    if (a<b) return b;
    return a;
}

int dp(int x){
    if (data[x]>0) return data[x];
    data[x]=0;
    for (int i=0; i<n; i++) if (G[x][i])
        data[x]=max(data[x], dp(i));
    data[x]+=box[x].hei;
    return data[x];
}

int main(void){
    int kase=1;

    while (scanf("%d", &n)==1 && n){
        n*=3;
        memset(G, false, sizeof(G));
        memset(data, -1, sizeof(data));
        for (int i=0; i<n; i+=3){
            scanf("%d%d%d", &box[i].x, &box[i].y, &box[i].hei);
            box[i+1]=Box(box[i].hei, box[i].x, box[i].y);
            box[i+2]=Box(box[i].hei, box[i].y, box[i].x);
        }

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (i!=j){
                    if (box[i]<box[j]) G[j][i]=true;
                    else if(box[j]<box[i]) G[i][j]=true;
                }

        int ans=0;
        for (int i=0; i<n; i++)
            ans=max(ans, dp(i));
        printf("Case %d: maximum height = %d\n", kase++, ans);
    }

    return 0;
}
