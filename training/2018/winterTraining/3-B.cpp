#include <cstdio>
#include <queue>
using namespace std;
struct Register{
    int id, period, time;
    Register(int id=0, int period=0, int time=0):
        id(id), period(period), time(time) {}
    bool operator < (const Register &a) const{
        return time>a.time||(time==a.time && id>a.id);
    }
};

int main(void){
    int n, id, period;
    char str[10];
    priority_queue<Register> que;

    while (1){
        scanf("%s%d", str, &id);
        if (str[0]!='#'){
            scanf("%d", &period);
            que.push(Register(id, period, period));
        }else{n=id; break;}
    }
    for (int i=0; i<n; i++){
        Register tmp=que.top(); que.pop();
        printf("%d\n", tmp.id);
        que.push(Register(tmp.id, tmp.period, tmp.time+tmp.period));
    }

    return 0;
}
