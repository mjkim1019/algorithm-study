import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        int[] A = new int[N];

        String[] input2 = br.readLine().split(" ");

        for(int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(input2[i]);
        }

        int count = 0;

        int start = 0;

        while(start < N) {
            int sum = 0;

            for(int i = start; i < N; i++) {
                sum += A[i];

                if(sum < M) continue;
                else if(sum == M) {
                    count++;
                    break;
                } else if(sum > M) break;
            }

            start++;
        }

        System.out.println(count);
    }
}
