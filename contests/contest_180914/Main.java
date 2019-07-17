// Main.java
import java.math.BigDecimal;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner cin=new Scanner(System.in);
        
        int T=cin.nextInt();
        while (T-- >0){
            Point[] points=new Point[4];
            for (int i=0; i<4; i++){
                points[i]=new Point();
                points[i].x=cin.nextBigDecimal();
                points[i].y=cin.nextBigDecimal();
            }

            Point cir=solve(points);
            BigDecimal disT=(cir.x.subtract(points[3].x).multiply(cir.x.subtract(points[3].x))).add(
                    cir.y.subtract(points[3].y).multiply(cir.y.subtract(points[3].y)));
            BigDecimal disS=(cir.x.subtract(points[0].x).multiply(cir.x.subtract(points[0].x))).add(
                    cir.y.subtract(points[0].y).multiply(cir.y.subtract(points[0].y)));

            if (disT.compareTo(disS)<=0)
                System.out.println("Rejected");
            else
                System.out.println("Accepted");
        }
    }

    private static Point solve(Point p[]){
        BigDecimal a1, a2, b1, b2, c1, c2;
        a1=p[0].x.subtract(p[1].x);
        b1=p[0].y.subtract(p[1].y);
        c1=p[0].x.multiply(p[0].x).subtract(p[1].x.multiply(p[1].x)).add(p[0].y.multiply(p[0].y).subtract(p[1].y.multiply(p[1].y))).divide(new BigDecimal("2"));
        a2=p[0].x.subtract(p[2].x);
        b2=p[0].y.subtract(p[2].y);
        c2=p[0].x.multiply(p[0].x).subtract(p[2].x.multiply(p[2].x)).add(p[0].y.multiply(p[0].y).subtract(p[2].y.multiply(p[2].y))).divide(new BigDecimal("2"));

        BigDecimal y=c1.multiply(a2).subtract(c2.multiply(a1)).divide(a2.multiply(b1).subtract(a1.multiply(b2)));
        BigDecimal x=c1.multiply(b2).subtract(c2.multiply(b1)).divide(b2.multiply(a1).subtract(b1.multiply(a2)));
        return new Point(x, y);
    }
}

class Point{
    public BigDecimal x, y;

    public Point(BigDecimal x, BigDecimal y){
        this.x=x;
        this.y=y;
    }

    public Point(){
    }

    public Point add(Point a){
        BigDecimal x, y;
        x=this.x.add(a.x);
        y=this.y.add(a.y);

        return new Point(x, y);
    }
    public Point sub(Point a){
        BigDecimal x, y;
        x=this.x.subtract(a.x);
        y=this.y.subtract(a.y);

        return new Point(x, y);
    }
    public Point multi(BigDecimal t){
        BigDecimal x, y;
        x=this.x.multiply(t);
        y=this.y.multiply(t);

        return new Point(x, y);
    }
    public Point div(BigDecimal t){
        BigDecimal x, y;
        x=this.x.divide(t);
        y=this.y.divide(t);

        return new Point(x, y);
    }
    public Point inv(){
        BigDecimal x;
        x=this.y.multiply(new BigDecimal("-1"));

        return new Point(x, this.x);
    }

    public BigDecimal cross(Point a){
        BigDecimal tmp_1=this.x.multiply(a.y);
        BigDecimal tmp_2=this.y.multiply(a.x);

        return tmp_1.subtract(tmp_2);
    }
}
