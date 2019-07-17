// Geometry.cpp
#include <bits/stdc++.h>
#define LL long long
#define PI 3.1415926535897932384626
const double eps = 1e-6;
// const int MAXN = (int)1e9 + 5;
using namespace std;
#define Vector Point
#define ChongHe 0
#define NeiHan 1
#define NeiQie 2
#define INTERSECTING 3
#define WaiQie 4
#define XiangLi 5

int dcmp(double x) { return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1); }

struct Point {
    double x, y;

    Point(const Point& rhs): x(rhs.x), y(rhs.y) { } //拷贝构造函数
    Point(double x = 0.0, double y = 0.0): x(x), y(y) { }   //构造函数

    friend istream& operator >> (istream& in, Point& P) { return in >> P.x >> P.y; }
    friend ostream& operator << (ostream& out, const Point& P) { return out << P.x << ' ' << P.y; }

    friend Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
    friend Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
    friend Vector operator * (const Vector& A, const double& p) { return Vector(A.x*p, A.y*p); }
    friend Vector operator / (const Vector& A, const double& p) { return Vector(A.x/p, A.y/p); }
    friend bool operator == (const Point& A, const Point& B) { return dcmp(A.x-B.x) == 0 && dcmp(A.y-B.y) == 0; }
    friend bool operator < (const Point& A, const Point& B) { return A.x < B.x || (A.x == B.x && A.y < B.y); }

    void in(void) { scanf("%lf%lf", &x, &y); }
    void out(void) { printf("%lf %lf", x, y); }
};

struct Line {
    Point P;    //直线上一点
    Vector dir; //方向向量(半平面交中该向量左侧表示相应的半平面)
    double ang; //极角，即从x正半轴旋转到向量dir所需要的角（弧度）

    Line() { }  //构造函数
    Line(const Line& L): P(L.P), dir(L.dir), ang(L.ang) { }
    Line(const Point& P, const Vector& dir): P(P), dir(dir) { ang = atan2(dir.y, dir.x); }

    bool operator < (const Line& L) const { //极角排序
        return ang < L.ang;
    }

    Point point(double t) { return P + dir*t; }
};

typedef vector<Point> Polygon;

struct Circle {
    Point c;    //圆心
    double r;   //半径

    Circle() { }
    Circle(const Circle& rhs): c(rhs.c), r(rhs.r) { }
    Circle(const Point& c, const double& r): c(c), r(r) { }

    Point point(double ang) const { return Point(c.x + cos(ang)*r, c.y + sin(ang)*r); } //圆心角所对应的点
    double area(void) const { return PI * r * r; }
};

double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }  //点积
double Length(const Vector& A){ return sqrt(Dot(A, A)); }
double Angle(const Vector& A, const Vector& B) { return acos(Dot(A, B)/Length(A)/Length(B)); }  //向量夹角
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }    //叉积
double Area(const Point& A, const Point& B, const Point& C) { return fabs(Cross(B-A, C-A)); }

//三边构成三角形的判定
bool check_length(double a, double b, double c) {
    return dcmp(a+b-c) > 0 && dcmp(fabs(a-b)-c) < 0;
}
bool isTriangle(double a, double b, double c) {
    return check_length(a, b, c) && check_length(a, c, b) && check_length(b, c, a);
}

//平行四边形的判定（保证四边形顶点按顺序给出）
bool isParallelogram(Polygon p) {
    if (dcmp(Length(p[0]-p[1]) - Length(p[2]-p[3])) || dcmp(Length(p[0]-p[3]) - Length(p[2]-p[1]))) return false;
    Line a = Line(p[0], p[1]-p[0]);
    Line b = Line(p[1], p[2]-p[1]);
    Line c = Line(p[3], p[2]-p[3]);
    Line d = Line(p[0], p[3]-p[0]);
    return dcmp(a.ang - c.ang) == 0 && dcmp(b.ang - d.ang) == 0;
}

//梯形的判定
bool isTrapezium(Polygon p) {
    Line a = Line(p[0], p[1]-p[0]);
    Line b = Line(p[1], p[2]-p[1]);
    Line c = Line(p[3], p[2]-p[3]);
    Line d = Line(p[0], p[3]-p[0]);
    return (dcmp(a.ang - c.ang) == 0 && dcmp(b.ang - d.ang)) || (dcmp(a.ang - c.ang) && dcmp(b.ang - d.ang) == 0);
}

//菱形的判定
bool isRhombus(Polygon p) {
    if (!isParallelogram(p)) return false;
    return dcmp(Length(p[1]-p[0]) - Length(p[2]-p[1])) == 0;
}

//矩形的判定
bool isRectangle(Polygon p) {
    if (!isParallelogram(p)) return false;
    return dcmp(Length(p[2]-p[0]) - Length(p[3]-p[1])) == 0;
}

//正方形的判定
bool isSquare(Polygon p) {
    return isRectangle(p) && isRhombus(p);
}

//三点共线的判定
bool isCollinear(Point A, Point B, Point C) {
    return dcmp(Cross(B-A, C-B)) == 0;
}

//向量绕起点旋转
Vector Rotate(const Vector& A, const double& rad) { return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad)); }

//向量的单位法线(调用前请确保A 不是零向量)
Vector Normal(const Vector& A) {
    double len = Length(A);
    return Vector(-A.y / len, A.x / len);
}

//两直线交点(用前确保两直线有唯一交点，当且仅当Cross(A.dir, B.dir)非0)
Point GetLineIntersection(const Line& A, const Line& B) {
    Vector u = A.P - B.P;
    double t = Cross(B.dir, u) / Cross(A.dir, B.dir);
    return A.P + A.dir*t;
}

//点到直线距离
double DistanceToLine(const Point& P, const Line& L) {
    Vector v1 = L.dir, v2 = P - L.P;
    return fabs(Cross(v1, v2)) / Length(v1);
}

//点到线段距离
double DistanceToSegment(const Point& P, const Point& A, const Point& B) {
    if (A == B) return Length(P - A);
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
    if (dcmp(Dot(v1, v3)) > 0) return Length(v3);
    return fabs(Cross(v1, v2)) / Length(v1);
}

//点在直线上的投影
Point GetLineProjection(const Point& P, const Line& L) { return L.P + L.dir*(Dot(L.dir, P - L.P)/Dot(L.dir, L.dir)); }

//点在线段上的判定
bool isOnSegment(const Point& P, const Point& A, const Point& B) {
    //若允许点与端点重合，可关闭下面的注释
    //if (P == A || P == B) return true;
    // return dcmp(Cross(A-P, B-P)) == 0 && dcmp(Dot(A-P, B-P)) < 0;
    return dcmp(Length(P-A) + Length(B-P) - Length(A-B)) == 0;
}

//线段相交判定
bool SegmentProperIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
    //若允许在端点处相交，可适当关闭下面的注释
    //if (isOnSegment(a1, b1, b2) || isOnSegment(a2, b1, b2) || isOnSegment(b1, a1, a2) || isOnSegment(b2, a1, a2)) return true;
    double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1);
    double c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
    return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}

//多边形的有向面积
double PolygonArea(Polygon po) {
    int n = po.size();
    double area = 0.0;
    for(int i = 1; i < n-1; i++) {
        area += Cross(po[i]-po[0], po[i+1]-po[0]);
    }
    return area * 0.5;
}

//点在多边形内的判定(多边形顶点需按逆时针排列)
bool isInPolygon(const Point& p, const Polygon& poly) {
    int n = poly.size();
    for(int i = 0; i < n; i++) {
        //若允许点在多边形边上，可关闭下行注释
        // if (isOnSegment(p, poly[(i+1)%n], poly[i])) return true;
        if (Cross(poly[(i+1)%n]-poly[i], p-poly[i]) < 0) return false;
    }
    return true;
}

//过定点作圆的切线
int getTangents(const Point& P, const Circle& C, std::vector<Line>& L) {
    Vector u = C.c - P;
    double dis = Length(u);
    if (dcmp(dis - C.r) < 0) return 0;
    if (dcmp(dis - C.r) == 0) {
        L.push_back(Line(P, Rotate(u, PI / 2.0)));
        return 1;
    }
    double ang = asin(C.r / dis);
    L.push_back(Line(P, Rotate(u, ang)));
    L.push_back(Line(P, Rotate(u, -ang)));
    return 2;
}

//直线和圆的交点
int GetLineCircleIntersection(Line& L, const Circle& C, vector<Point>& sol) {
    double t1, t2;
    double a = L.dir.x, b = L.P.x - C.c.x, c = L.dir.y, d = L.P.y - C.c.y;
    double e = a*a + c*c, f = 2.0*(a*b + c*d), g = b*b + d*d - C.r*C.r;
    double delta = f*f - 4*e*g; //判别式
    if (dcmp(delta) < 0) return 0;  //相离
    if (dcmp(delta) == 0) { //相切
      t1 = t2 = -f / (2 * e);
      sol.push_back(L.point(t1));
      return 1;
    }
    t1 = (-f - sqrt(delta)) / (2.0 * e); sol.push_back(L.point(t1));    // 相交
    t2 = (-f + sqrt(delta)) / (2.0 * e); sol.push_back(L.point(t2));
    return 2;
}

//两圆位置关系判定
int GetCircleLocationRelation(const Circle& A, const Circle& B) {
    double d = Length(A.c-B.c);
    double sum = A.r + B.r;
    double sub = fabs(A.r - B.r);
    if (dcmp(d) == 0) return dcmp(sub) != 0;
    if (dcmp(d - sum) > 0) return XiangLi;
    if (dcmp(d - sum) == 0) return WaiQie;
    if (dcmp(d - sub) > 0 && dcmp(d - sum) < 0) return INTERSECTING;
    if (dcmp(d - sub) == 0) return NeiQie;
    if (dcmp(d - sub) < 0) return NeiHan;

    return 0;
}

//两圆相交的面积
double GetCircleIntersectionArea(const Circle& A, const Circle& B) {
    int rel = GetCircleLocationRelation(A, B);
    if (rel < INTERSECTING) return min(A.area(), B.area());
    if (rel > INTERSECTING) return 0;
    double dis = Length(A.c - B.c);
    double ang1 = acos((A.r*A.r + dis*dis - B.r*B.r) / (2.0*A.r*dis));
    double ang2 = acos((B.r*B.r + dis*dis - A.r*A.r) / (2.0*B.r*dis));
    return ang1*A.r*A.r + ang2*B.r*B.r - A.r*dis*sin(ang1);
}

//凸包(Andrew算法)
//如果不希望在凸包的边上有输入点，把两个 <= 改成 <
//如果不介意点集被修改，可以改成传递引用
Polygon ConvexHull(vector<Point> p) {
    //预处理，删除重复点
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int n = p.size(), m = 0;
    Polygon res(n+1);
    for(int i = 0; i < n; i++) {
        while(m > 1 && Cross(res[m-1]-res[m-2], p[i]-res[m-2]) <= 0) m--;
        res[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--) {
        while(m > k && Cross(res[m-1]-res[m-2], p[i]-res[m-2]) <= 0) m--;
        res[m++] = p[i];
    }
    m -= n > 1;
    res.resize(m);
    return res;
}

//点P在有向直线L左边的判定(线上不算)
bool isOnLeft(const Line& L, const Point& P) {
    return Cross(L.dir, P-L.P) > 0;
}

//半平面交主过程
//如果不介意点集被修改，可以改成传递引用
Polygon HalfPlaneIntersection(vector<Line> L) {
    int n = L.size();
    int head, rear;     //双端队列的第一个元素和最后一个元素的下标
    vector<Point> p(n); //p[i]为q[i]和q[i+1]的交点
    vector<Line> q(n);  //双端队列
    Polygon ans;

    sort(L.begin(), L.end());   //按极角排序
    q[head=rear=0] = L[0];  //双端队列初始化为只有一个半平面L[0]
    for(int i = 1; i < n; i++) {
        while(head < rear && !isOnLeft(L[i], p[rear-1])) rear--;
        while(head < rear && !isOnLeft(L[i], p[head])) head++;
        q[++rear] = L[i];
        if (fabs(Cross(q[rear].dir, q[rear-1].dir)) < eps) {    //两向量平行且同向，取内侧的一个
            rear--;
            if (isOnLeft(q[rear], L[i].P)) q[rear] = L[i];
        }
        if (head < rear) p[rear-1] = GetLineIntersection(q[rear-1], q[rear]);
    }
    while(head < rear && !isOnLeft(q[head], p[rear-1])) rear--; //删除无用平面
    if (rear - head <= 1) return ans;   //空集
    p[rear] = GetLineIntersection(q[rear], q[head]);    //计算首尾两个半平面的交点

    for(int i = head; i <= rear; i++) { //从deque复制到输出中
        ans.push_back(p[i]);
    }
    return ans;
}

const int maxnn=1e3+20;
Point tar[maxnn];
int n;
bool judge(double k, Polygon p, bool isInclude){
    for (unsigned int i=0; i<p.size(); i++)
        p[i].x*=k, p[i].y*=k;

    for (int i=0; i<n; i++){
        bool res=isInPolygon(tar[i], p);

        if (isInclude && res==false) return false;
        if (!isInclude && res==true) return false;
    }return true;
}

double solve(Polygon &p){
    double l=0, r=2e9, out=0, in=0;

    while (r-l>eps){
        out=(l+r)/2;
        if (judge(out, p, true)) r=out;
        else l=out;
    }

    l=0, r=2e9;
    while (r-l>eps){
        in=(l+r)/2;
        if (judge(in, p, false)) l=in;
        else r=in;
    }

    // printf("%lf %lf\n", in, out);
    return (in*in)/(out*out);
}

int main(void){
    while(scanf("%d", &n)==1){
        for (int i=0; i<n; i++)
            scanf("%lf%lf", &tar[i].x, &tar[i].y);

        int idx=0;
        double ans=0;
        Point base(1, 0);
        for (int i=3; i<=8; i++){
            double mat[4];
            Point _tmp=base, tmp=base;
            Polygon poly;
            mat[0]=cos(2*PI/i);
            mat[1]=-sin(2*PI/i);
            mat[2]=sin(2*PI/i);
            mat[3]=cos(2*PI/i);

            poly.push_back(base);
            for (int j=1; j<i; j++){
                _tmp=tmp;
                tmp.x=mat[0]*_tmp.x+mat[1]*_tmp.y;
                tmp.y=mat[2]*_tmp.x+mat[3]*_tmp.y;
                poly.push_back(tmp);
            }

            double res=solve(poly);
            if (ans<res){
                ans=res; idx=i;
            }
        }

        printf("%d %.6f\n", idx, ans);
    }
    return 0;
}
