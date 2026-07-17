import java.util.*;
public class Brute_Force_evenFib {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int i = 0;
        int j = 1;
        int sum = 0;
        for(int k = i;k<=n;k++){
            int curr = i+j;
            if(curr % 2 == 0 && curr <= n){
                sum += curr;
            }
            if(curr > n){
                break;
            }
            i = j;
            j = curr;
        }
        System.out.println(sum);

    }    
}
