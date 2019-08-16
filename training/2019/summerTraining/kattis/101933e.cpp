#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
map<LL, double> prop;
int state[2][7];
LL sta(void){
    LL s=0;
    for (int i=6; i>0; i--) s=s*10+state[1][i];
    for (int i=6; i>0; i--) s=s*10+state[0][i];
    return s;
}

LL CHK=1e6;
bool isWin(LL s){return s<CHK;}
bool isFail(LL s){return s%CHK==0;}


double dp(LL s, int rest){
    if (prop.count(s)) return prop[s];
    if (isWin(s)) return 1;
    // if (isFail(s) || rest==0) return 0;
    if (rest==0) return 0;

    int sum=0;
    for (int x=0; x<2; x++)
        for (int i=1; i<=6; i++) sum+=state[x][i];

    prop[s]=0;
    for (int x=0; x<2; x++)
        for (int i=1; i<=6; i++) if (state[x][i]){
            state[x][i]--;
            state[x][i-1]++;
            double res=dp(sta(), rest-1);
            state[x][i]++;
            state[x][i-1]--;
            prop[s]+=res*(double)state[x][i]/(double)sum;
        }
    // printf("%lld: %f s%d\n", s, prop[s], sum);
    return prop[s];
}

int main(void){
    int n, m, d, tmp;

    while (scanf("%d%d%d", &n, &m, &d)==3){
        prop.clear();
        memset(state, 0, sizeof(state));
        for (int i=0; i<n; i++){
            scanf("%d", &tmp);
            state[0][tmp]++;
        }

        for (int i=0; i<m; i++){
            scanf("%d", &tmp);
            state[1][tmp]++;
        }

        printf("%.8f\n", dp(sta(), d));
    }

    return 0;
}
