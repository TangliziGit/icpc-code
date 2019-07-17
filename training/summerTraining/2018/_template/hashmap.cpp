#include <map>
#include <climits>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct HashMap{
    static const int mask=0x7ffffff;
    int q[mask+1], p[mask+1];
    void clear() {memset(q, 0, sizeof(q));}
    int& operator [](int k){
        int i;
        for (i=k&mask; q[i]&&p[i]!=k; i=(i+1)&mask);
        p[i]=k; return q[i];
    }
}hashmap;

int main(void){
    map<int, int> mmap;
    for (int i=-20000; i<=20000; i++){
        mmap[i]=i; hashmap[i]=i;
        printf("%d\n", i);
    }

    for (int i=-20000; i<=20000; i++)
        if (mmap[i]!=hashmap[i]) printf("%d: %d %d\n", i, mmap[i], hashmap[i]);
    printf("done.\n");

    return 0;
}
