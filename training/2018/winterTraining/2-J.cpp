#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct DNA{
    char str[55];
    int n, len, ori;
    DNA(void):len(0) {}
    bool operator < (const DNA &a) const{
        return (n<a.n)||(n==a.n && ori<a.ori);
    }
    void set(int len, int o){
        ori=o; n=0;
        int a=0, c=0, g=0;
        for (int i=len-1; i>=0; i--)
            switch (str[i]){
                case 'A':a++; break;
                case 'C':c++; n+=a; break;
                case 'G':g++; n+=a+c; break;
                case 'T':n+=a+c+g; break;
            }
    }
};

int main(void){
    int n, m;

    while (scanf("%d%d", &n, &m)==2 && n){
        DNA dna[105];
        for (int i=0; i<m; i++) {
            scanf("%s", dna[i].str);
            dna[i].set(n, i);
        }
        sort(dna, dna+m);
        for (int i=0; i<m; i++) printf("%s\n", dna[i].str);
    }

    return 0;
}
