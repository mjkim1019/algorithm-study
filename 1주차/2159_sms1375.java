import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");

        int beforex = Integer.parseInt(input[0]);
        int beforey = Integer.parseInt(input[1]);
        long[][] dp = new long[100001][5];

        int[] dx = {0, -1, 1, 0, 0};
        int[] dy = {0, 0, 0, -1, 1};

        for (int i = 1; i <= n; i++) {
            String[] input2 = br.readLine().split(" ");
            int x = Integer.parseInt(input2[0]);
            int y = Integer.parseInt(input2[1]);

            dp[0][1] = 1;
            dp[0][2] = 1;
            dp[0][3] = 1;
            dp[0][4] = 1;

            for (int j = 0; j < 5; j++) {
                long min = Long.MAX_VALUE;
                for (int k = 0; k < 5; k++) {
                    long temp = dp[i - 1][k] + Math.abs(x + dx[j] - (beforex + dx[k])) + Math.abs(y + dy[j] - (beforey + dy[k]));
                    min = Math.min(min, temp);
                }

                dp[i][j] = min;
            }

            beforex = x;
            beforey = y;
        }

        long min = dp[n][0];

        for (int i = 1; i < 5; i++) {
            min = Math.min(min, dp[n][i]);
        }

        System.out.println(min);
    }
}
