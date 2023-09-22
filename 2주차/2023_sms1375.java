import java.util.*;
import java.io.*;

public class Main {
    public static List<Integer> temp_list = new ArrayList<>();
    public static List<Integer> prime_list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        prime_list.add(2);
        prime_list.add(3);
        prime_list.add(5);
        prime_list.add(7);

        make_prime(N);

        for(int i = 0; i < prime_list.size(); i++) {
            System.out.println(prime_list.get(i));
        }

    }

    public static void make_prime(int digit) {
        for(int i = 2; i <= digit; i++) {
            temp_list = new ArrayList<>(prime_list);
            prime_list.clear();

            for(int j = 0; j < temp_list.size(); j++) {
                for(int k = 1; k < 10; k++) {
                    int temp = temp_list.get(j) * 10 + k;
                    if(checkPrime(temp)) prime_list.add(temp);
                }
            }
        }
    }

    public static boolean checkPrime(int n) {
        if(n < 2) return false;

        for(int i = 2; i<=(int)Math.sqrt(n); i++) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
