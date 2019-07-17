#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main(void){
    int T, m, n, temp[2000+5];

    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &m, &n);
        priority_queue<int> que;
        for (int i=0, tmp; i<n; i++){
            scanf("%d", &tmp);
            que.push(tmp);
        }
        while (--m){
            priority_queue<int> tmp;
            for (int i=0; i<n; i++) scanf("%d", &temp[i]);
            while (que.size()){
                int num=que.top(); que.pop();
                for (int i=0; i<n; i++){
                    if (tmp.size()<n) tmp.push(temp[i]+num);
                    else if (temp[i]+num<tmp.top()){
                        tmp.pop(); tmp.push(temp[i]+num);
                    }
                }
            }
            que=tmp;
        }
        int size=0;
        while (que.size()) {
            temp[size++]=que.top(); que.pop();
        }
        for (int i=n-1; i>=0; i--)
            printf("%d%c", temp[i], (i==0)?'\n':' ');
    }

    return 0;
}
