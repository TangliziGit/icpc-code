#include <cstdio>
#include <bitset>
using namespace std;

int main(void){
    int n;

    while (scanf("%d", &n)==1){
        bitset<32> bit(n);
        const char *ans=bit.to_string().c_str();
        for (int i=0, flag=false; i<32; i++){
            if (!flag && ans[i]=='1') flag=true;
            if (flag) printf("%c", ans[i]); 
        }printf("\n");
    }

    return 0;
}
