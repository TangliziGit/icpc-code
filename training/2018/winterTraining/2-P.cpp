#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Work{
    int date, score;
    Work(int date=0, int score=0):
        date(date),score(score) {}
    bool operator < (const Work &a) const{
        return score>a.score;
    }
};

int main(void){
    int T, n;
    
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        Work works[1000+5];
        for (int i=0; i<n; i++) scanf("%d", &works[i].date);
        for (int i=0; i<n; i++) scanf("%d", &works[i].score);
        sort(works, works+n);

        int vis[1000+5]={0}, sum=0;
        for (int i=0; i<n; i++){
            int date=(works[i].date<=1000)?works[i].date:1000;
            while (date>=1 && vis[date]) date--;
            if (date) vis[date]=1;
            else sum+=works[i].score;
        }printf("%d\n", sum);
    }

    return 0;
}
