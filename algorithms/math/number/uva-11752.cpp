#include <set>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;
int list[100]={4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,26,27,28,30,32,33,34,35,36,38,39,40,42,44,45,46,48,49,50,51,52,54,55,56,57,58,60,62,63,64};
set<unsigned long long> ans;
void solve(void){
    ans.insert(1);
    unsigned long long range=ULONG_LONG_MAX;
    for (unsigned long long i=2, ed=(1<<16)-1; i<=ed; i++) if (!ans.count(i)){
        unsigned long long tmp=i*i*i*i;
        int idx=4, end=ceil(64*log(2)/log(i))-1;
        for (int j=0; list[j] && list[j]<=end; j++){
            while (idx<list[j] && idx<=end && tmp<range) idx++, tmp*=i;
            ans.insert(tmp);
        }
    }ans.erase(0);
}

int main(void){
    solve();
    for (set<unsigned long long>::iterator it=ans.begin(); it!=ans.end(); it++)
        printf("%llu\n", *it);

    return 0;
}
