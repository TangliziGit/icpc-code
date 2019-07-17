import math

class Point:
    def __init__(self, x, y):
        self.x=x;
        self.y=y;
    
    def add(self, p):
        return Point(self.x+p.x, self.y+p.y)

    def sub(self, p):
        return Point(self.x-p.x, self.y-p.y)

    def div(self, a):
        return Point(self.x/a, self.y/a)

    def inv(self):
        return Point(self.y*-1, self.x)

class Line:
    def __init__(self, p, dr):
        self.p=p
        self.dr=dr

def cross(a, b):
    return a.x*b.y - a.y*b.x

def GetLineIntersection(A, B):
    u=Point(A.p.x-B.p.x, A.p.y-B.p.y)
    t=cross(B.dr, u)/cross(A.dr, B.dr)
    res=Point(A.p.x+A.dr.x*t, A.p.y+A.dr.y*t)
    return res;

T=int(input())
for kase in range(T):
    point=[]
    inp=[float(x) for x in input().split(" ")]
    for i in range(4):
        point.append(Point(inp[2*i], inp[2*i+1]))
    
    line=[]
    line.append(Line( point[0].add(point[2]).div(2), point[2].sub(point[0]).inv()));
    line.append(Line( point[1].add(point[2]).div(2), point[2].sub(point[1]).inv()));

    cir=GetLineIntersection(line[0], line[1])
    disT=(cir.x-point[3].x)*(cir.x-point[3].x)+(cir.y-point[3].y)*(cir.y-point[3].y)
    disS=(cir.x-point[0].x)*(cir.x-point[0].x)+(cir.y-point[0].y)*(cir.y-point[0].y)

    if disT<=disS:
        print("Rejected")
    else:
        print("Accepted")
