#include <cstdio>
int n, m;
bool nail[50+5][50+5];
long long solve(int n, int m){
    long long prob[50+5][50+5]={0};
    prob[0][0]=((long long)1)<<n;
    for (int y=0; y<n; y++)
        for (int x=0; x<=y; x++)
            if (nail[y][x]){
                prob[y+1][x]+=prob[y][x]/2;
                prob[y+1][x+1]+=prob[y][x]/2;
            }else prob[y+2][x+1]+=prob[y][x];
    return prob[n][m];
}

long long gcd(long long a, long long b){
    return (b==0)?a:gcd(b, a%b);
}

bool input(void){
    char str[5];
    scanf("%s", str);
    if (str[0]=='.') return false;
    return true;
}

int main(void){
    while (scanf("%d%d", &n, &m)==2){
        for (int y=0; y<n; y++)
            for (int x=0; x<=y; x++) nail[y][x]=input();
        
        long long num=solve(n, m), den=((long long)1)<<n, g=gcd(num, den);
        printf("%lld/%lld\n", num/g, den/g);
    }
    
    return 0;
}
