#include <cstdio>
#include <cstring>
struct Course{
    char name[105];
    int deadline, cost;
    Course(char* str=NULL, int deadline=0, int cost=0):
        deadline(deadline), cost(cost){
        if (str) strcpy(name, str);
    }
}course[20];
struct DP{
    int score, costed, select;
}dp[(1<<15)+20];
const int INF=0x3f3f3f3f;

int relu(int x){
    if (x>0) return x;
    return 0;
}

void print(int x){
    if (x==0) return;
    int xx=dp[x].select;
    print(x-(1<<xx));
    printf("%s\n", course[xx].name);
}

int main(void){
    int T, n, deadline, cost;
    char name[105];

    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<n; i++){
            scanf("%s%d%d", name, &deadline, &cost);
            course[i]=Course(name, deadline, cost);
        }

        int end=1<<n;
        dp[0].select=-1;
        for (int i=1; i<end; i++){
            dp[i].score=INF;
            for (int x=n-1; x>=0; x--)
                if (i&(1<<x)){
                    int prev=i-(1<<x),
                        addition=relu(dp[prev].costed+course[x].cost-course[x].deadline);
                    if (addition+dp[prev].score < dp[i].score){
                        dp[i].score=addition+dp[prev].score;
                        dp[i].costed=dp[prev].costed+course[x].cost;
                        dp[i].select=x;
                    }
                }
        }
        printf("%d\n", dp[end-1].score);
        print(end-1);
    }

    return 0;
}
