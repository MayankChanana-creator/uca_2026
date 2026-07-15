import java.util.*;

public class Optimized_evenFib {
    public static long evenFib(int n){
        long a = 2;
        long b = 8;
        long sum = a;
        while(b <= n){
            sum += b;
            long c = 4*b + a;
            a = b;
            b = c;
        }
        return sum;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long ans = evenFib(n);
        System.out.println(ans);
    }
}
