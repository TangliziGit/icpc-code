#include <cstdio>
#include <cstring>
const int maxn=1e6+20;
int num[2][15];

void show(int n){
    for (int i=0; i<n; i++)
        printf("+%d ", num[0][i]);
    printf("\n");
    for (int i=0; i<n; i++)
        printf("+%d ", num[1][i]);
    printf("\n");
}

bool find(int n, bool st){
    for (int i=0; i<=9; i++){
        int p=(n-i>=0)?(n-i):(10+n-i);
        if ((p==0 || i==0)&& st) continue;

        if (num[0][i]>0 && num[1][p]>0){
            num[0][i]--; num[1][p]--;
            return true;
        }else if (num[1][i]>0 && num[0][p]>0){
            num[1][i]--; num[0][p]--;
            return true;
        }
    }return false;
}

int main(void){
    int T, cnt=1;

    scanf("%d\n", &T);
    while (T--){
        int len=0; 
        char tmp[maxn];
        memset(num, 0, sizeof(num));

        scanf("%s", tmp); len=strlen(tmp);
        for (int i=0; i<len; i++)
            num[0][tmp[i]-'0']++;
        scanf("%s", tmp);
        for (int i=0; i<len; i++)
            num[1][tmp[i]-'0']++;

        printf("Case #%d: ", cnt++);
        for (int i=0; i<len; i++){
            int m=-1;
            for (int k=9; k>=0; k--)
                if (find(k, i==0)) {m=k; break;}
            if (i==0 && m==0){
                printf("%d", m);
                break;
            }
        }printf("\n");
    }

    return 0;
}
