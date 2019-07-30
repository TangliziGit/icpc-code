#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=50+20;
const double eps=1e-8, INF=1e9;
struct Vector{
    double x, y;

    Vector(int x=0, int y=0):x(x), y(y) {}
    // no known conversion for argument 1 from 'Vector' to 'Vector&'
    Vector operator + (Vector p){return Vector(x+p.x, y+p.y);}
    Vector operator - (Vector p){return Vector(x-p.x, y-p.y);}
    Vector operator * (double k){return Vector(k*x, k*y);}
    Vector operator / (double k){return Vector(x/k, y/k);}
    bool operator < (Vector p) const{return (x==p.x)?(y<p.y):(x<p.x);}
    bool operator == (const Vector p) const{return fabs(x-p.x)<eps&&fabs(y-p.y)<eps;}
    double norm(void){return x*x+y*y;}
    double abs(void){return sqrt(norm());}
    double dot(Vector p){return x*p.x+y*p.y;}
    double cross(Vector p){return x*p.y-y*p.x;}
};

int x[maxn], y[maxn], n, T;
double data[maxn][maxn];
bool equal(double a, double b){
    return (b-a)<=eps && (a-b)<=eps;
}

double area(int i, int k, int j){
    Vector va(x[i]-x[j], y[i]-y[j]), vb(x[i]-x[k], y[i]-y[k]),
           vc(x[j]-x[k], y[j]-y[k]);
    double ans=abs(va.cross(vb));
    for (int idx=0; idx<n; idx++) if (idx!=i && idx!=k && idx!=j){
        double sum=0;
        Vector vec1(x[idx]-x[i], y[idx]-y[i]),
            vec2(x[idx]-x[j], y[idx]-y[j]);
        sum+=abs(vec1.cross(va));
        sum+=abs(vec1.cross(vb));
        sum+=abs(vec2.cross(vc));
        if (equal(sum, ans)) return INF;
    }return ans/2.0;
}

double dp(int i, int j){
    if (i+1==j) return 0;
    if (data[i][j]>0) return data[i][j];

    data[i][j]=INF;
    for (int k=i+1; k<=j-1; k++)
        data[i][j]=min(data[i][j],
                max(area(i, k, j), max(dp(i, k), dp(k, j))));
    return data[i][j];
}

int main(void){
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i=0; i<n; i++) scanf("%d%d", &x[i], &y[i]);
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) data[i][j]=-1;
        printf("%.1f\n", dp(0, n-1));
    }

    return 0;
}
