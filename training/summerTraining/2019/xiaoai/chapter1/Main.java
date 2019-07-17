// poj-2823
import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main{
    public static void main(String args[]){
        Scanner cin=new Scanner(System.in);

        while (cin.hasNext()){
            BigInteger num=new BigInteger(cin.nextLine());
            if (num.equals(BigInteger.valueOf(-1))) break;

            System.out.println(solve(num));
        }
    }

    private static String solve(BigInteger num){
        String ans="";

        if (num.compareTo(BigInteger.TEN)<0)
            return num.add(BigInteger.TEN).toString();

        while (!num.equals(BigInteger.ONE)){
            boolean flg=false;
            for (int i=9; i>=2; i--){
                BigInteger bi=BigInteger.valueOf(i);
                if (num.remainder(bi).equals(BigInteger.ZERO)){
                    ans+=i; num=num.divide(bi);
                    flg=true;
                    break;
                }
            }

            if (!flg)
                return "There is no such number.";
        }
        return (new StringBuffer(ans)).reverse().toString();
    }
}
