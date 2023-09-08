import java.util.*;
import java.io.*;

public class Main {
    public static boolean[] prime;
    public static int[] prime_array;

    public static List<Integer> prime_list = new ArrayList<>();
//    public static List<Integer> prime_sum = new ArrayList<>(); // 리스트로 만들고 중복 검사하면 시간이 오래걸림
    public static Set<Integer> prime_sum = new HashSet<>(); // 따라서 Set으로 만들어 중복 검사할 필요 없게 해서 성공

    public static List<Integer> prime_multy = new ArrayList<>();
    public static List<String> num_list = new ArrayList<>();
    public static List<String> numbers = new ArrayList<>();

    public static int count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int K = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);


        make_prime((int) Math.pow(10, K));


        for(int i = 0; i < prime_array.length; i++) {

            if(prime_array[i] != 0) {
                prime_list.add(prime_array[i]);
            }
        }


        prime_sum();

        prime_multy();

        for (int i = 0; i <= 9; i++) {
            numbers.add(Integer.toString(i));
        }

        make_number(K, "");

        for(int i = 0; i < num_list.size(); i++) {
            int valid = Integer.parseInt(num_list.get(i));
            int modify = valid;
            if(prime_sum.contains(valid)) {
                while(modify % M == 0) {
                    modify /= M;
                }
                if(prime_multy.contains(modify)) {
                    count++;
                }
            }
        }
        
        System.out.print(count);
    }

    public static void make_prime(int N) {
        prime = new boolean[N + 1];

        if (N < 2) {
            return;
        }

        prime[0] = prime[1] = true;

        for (int i = 2; i <= Math.sqrt(N); i++) {
            if (prime[i] == true) {
                continue;
            }

            for (int j = i * i; j < prime.length; j = j + i) {
                prime[j] = true;
            }
        }

        prime_array = new int[N];
        int index = 0;
        for (int i = 0; i < prime.length; i++) {
            if (!prime[i]) {
                prime_array[index] = i;
                index++;
            }
        }
    }

    public static void prime_sum() {
        for (int i = 0; i < prime_list.size(); i++) {
            for (int j = i + 1; j < prime_list.size(); j++) {
                int sum = prime_list.get(i) + prime_list.get(j);
                if (sum > 100000) break;
                prime_sum.add(sum);
            }
        }
    }

    public static void prime_multy() {
        for(int i = 0; i < prime_list.size(); i++) {
            for(int j = 0; j < prime_list.size(); j++) {
                if((long)(prime_list.get(i) * prime_list.get(j)) > 100000) break;
                if(!prime_multy.contains(prime_list.get(i) * prime_list.get(j))) {
                    prime_multy.add(prime_list.get(i) * prime_list.get(j));
                }
            }
        }
    }

    public static void make_number(int K, String current) {
        if (K == 0) {
            num_list.add(current);
            return;
        }

        for (int i = 0; i <= 9; i++) {
            if (!current.contains(Integer.toString(i))) {
                if (current.isEmpty() && i == 0) {
                    continue;
                }
                make_number(K - 1, current + i);
            }
        }
    }
}
