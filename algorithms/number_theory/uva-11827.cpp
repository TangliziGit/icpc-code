#include <cstdio>
#include <sstream>
#include <algorithm>
using namespace std;
long long gcd(long long a, long long b){
    return (b==0)?a:gcd(b, a%b);
}

int main(void){
    int T;
    long long n[105];
    char line[1000];

    scanf("%d\n", &T);
    while (T--){
        fgets(line, sizeof(line), stdin);
        int size=0;
        long long m=0;
        stringstream in(line);

        while (in >> n[size]) size++;
        for (int i=0; i<size-1; i++)
            for (int j=i+1; j<size; j++)
                if (i!=j) m=max(gcd(n[i], n[j]), m);
        printf("%lld\n", m);
    }

    return 0;
}
