import java.util.*;
import java.io.*;

public class Main {
    public static boolean[] prime;
    public static int[] prime_array;
    public static int count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        if(N < 2) {
            System.out.println("0");
            return;
        }

        make_prime(N);

        findSum(prime_array, N);

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

    public static int findSum(int[] nums, int target) throws IOException {
        int left = 0;
        int right = 0;
        int sum = 0;

        for (int i = left; i <= right; i++) {
            sum += nums[i];
        }
        for (int i = 0;; i++)
            try {
                if (sum == target) {
                    count++;
                    sum = sum + nums[++right] - nums[left++];
                } else if (sum < target) {
                    sum += nums[++right];
                } else {
                    sum -= nums[left];
                    left++;
                }

            } catch (Exception e) {
                break;
            }
        return count;
    }
}
