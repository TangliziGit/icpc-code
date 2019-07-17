#include <cstdio>
const int MAX=100000*2;
long long sumv[MAX+5], addv[MAX+5], num[MAX/2+5];
int ql, qr, ul, ur, uv;
void Build(int rt, int l, int r){
    if (l==r) {sumv[rt]=num[l]; return;}
    int mid=l+(r-l)/2;
    Build(rt<<1, l, mid);
    Build(rt<<1|1, mid+1, r);
    sumv[rt]=sumv[rt<<1]+sumv[rt<<1|1];    // PushUp
}

void PushDown(int rt, int ln, int rn){
    addv[rt<<1]+=addv[rt];
    sumv[rt<<1]+=addv[rt]*ln;
    addv[rt<<1|1]+=addv[rt];
    sumv[rt<<1|1]+=addv[rt]*rn;
    addv[rt]=0;
}

long long Query(int rt, int l, int r){
    if (ql<=l && r<=qr) return sumv[rt];
    int mid=l+(r-l)/2; long long sum=0;
    if (addv[rt]) PushDown(rt, mid-l+1 ,r-mid);
    if (ql<=mid) sum+=Query(rt<<1, l, mid);
    if (qr>=mid+1) sum+=Query(rt<<1|1, mid+1, r);
    return sum;
}

void Update(int rt, int l, int r){
    if (ul<=l && r<=ur){sumv[rt]+=uv*(r-l+1); addv[rt]+=uv; return;}
    
    int mid=l+(r-l)/2;
    if (addv[rt]) PushDown(rt, mid-l+1, r-mid);
    if (ul<=mid) Update(rt<<1, l, mid);
    if (ur>=mid+1) Update(rt<<1|1, mid+1, r);
    sumv[rt]=sumv[rt<<1]+sumv[rt<<1|1];
}

int main(void){
    int n, q;
    char ch[5];

    scanf("%d%d", &n, &q);
    for (int i=1; i<=n; i++) scanf("%lld", &num[i]);  // 1
    Build(1, 1, n);
    for (int i=0; i<q; i++){
        scanf("%s", ch);
        if (ch[0]=='C'){
            scanf("%d%d%d", &ul, &ur, &uv);
            Update(1, 1, n);
        }else if (ch[0]=='Q'){
            scanf("%d%d", &ql, &qr);
            printf("%lld\n", Query(1, 1, n));
        }
    }

    return 0;
}
