#include <cstdio>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

int main(void){
    int a, b, n, num, tmp[20+5];

    while (scanf("%d%d%d", &a, &b, &n)==3 && a){
        for (int i=0; i<a+b; i++) scanf("%d", &tmp[i]);
        std::sort(tmp, tmp+a+b);

        priority_queue<int> low;
        priority_queue<int, vector<int>, greater<int> > high;
        for (int i=0; i<b; i++) low.push(tmp[i]);
        for (int i=a+b-1; i>=b; i--) high.push(tmp[i]);

        long long sum=0;
        for (int i=0; i<n-a-b; i++){
            scanf("%d", &num);
            if (num>high.top()){
                high.push(num);
                num=high.top(); high.pop();
            }else if (num<low.top()) {
                low.push(num);
                num=low.top(); low.pop();
            }sum+=num;
        }printf("%f\n", sum/(double)(n-a-b));
    }

    return 0;
}
