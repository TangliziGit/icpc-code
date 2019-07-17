// Main.java
import java.math.BigDecimal;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner cin=new Scanner(System.in);
        

    }
}

private class Point{
    public BigDecimal x, y;

    Point(BigDecimal x, BigDecimal y){
        this.x=x;
        this.y=y;
    }

    public Point add(BigDecimal a){
        BigDecimal x, y;
        x=this.x.add(a.x); y=this.y.add(a.y);

        return Point(x, y);
    }
}
