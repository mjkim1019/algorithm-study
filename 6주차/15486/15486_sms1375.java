import java.util.*;
import java.io.*;

public class Main {
    public static class Consult {
        int day, cost;
        Consult(int day, int cost) {
            this.day = day;
            this.cost = cost;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        Consult[] schedule = new Consult[N + 1];

        int[] dp = new int[N + 1];

        for(int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");

            int T = Integer.parseInt(input[0]);
            int P = Integer.parseInt(input[1]);

            schedule[i] = new Consult(T, P);
        }
        schedule[N] = new Consult(0, 0);

        int max = Integer.MIN_VALUE;

        for(int i = 0; i < N + 1; i++) {
            if(max < dp[i]) max = dp[i];

            int next = i + schedule[i].day;
            
            if(next <= N) dp[next] = Math.max(dp[next], max + schedule[i].cost);
        }

        System.out.println(dp[N]);
    }
}
