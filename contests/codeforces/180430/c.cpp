#include <cstdio>
#include <algorithm>
using namespace std;

struct Iv{
    int left, right, idx;

    Iv(int left=-1, int right=-1, int idx=0):
        left(left), right(right), idx(idx) {}
    bool operator < (const Iv &rhs) const{
        if (left!=rhs.left) return left<rhs.left;
        return right>rhs.right;
    }
}ivs[int(3e5)+5];
int n;

int main(void){
    int left, right;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d%d", &left, &right);
        ivs[i]=Iv(left, right, i+1);
    }

    bool flg=false;
    sort(ivs, ivs+n);
    for (int i=1; i<n; i++){
        if (ivs[i-1].left<=ivs[i].left && ivs[i-1].right>=ivs[i].right){
            printf("%d %d\n", ivs[i].idx, ivs[i-1].idx);
            flg=true;
            break;
        }
    }

    if (!flg) printf("-1 -1\n");

    return 0;
}
