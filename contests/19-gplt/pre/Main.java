import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
    final int maxn=1000+20;

    static class Pair implements Comparable<Pair> {
        int x, y;
        Pair(int X, int Y){
            x=X; y=Y;
        }

        public int compareTo(Pair a){
            if (y!=a.y) return -y+a.y;
            return x-a.x;
        }

        public String toString(){
            return x+" "+y;
        }
    }

    public static void main(String[] args){
        int cnt=0;
        Scanner in=new Scanner(System.in);
        PrintWriter out=new PrintWriter(System.out);

        while (true){
            int n=in.nextInt();
            if (n==0) break;
            
            Pair[] pairs=new Pair[n];
            for (int i=0; i<n; i++)
                pairs[i]=new Pair(in.nextInt(), in.nextInt());
            Arrays.sort(pairs);

            int ans=0, sum=0;
            for (Pair p: pairs){
                sum+=p.x;
                ans=Math.max(sum+p.y, ans);
            }
            out.println("Case "+ ++cnt+": "+ans);
            out.flush();
        }
        out.close();
    }

    static void print(Object...x){
        System.out.println(Arrays.deepToString(x));
    }

}
