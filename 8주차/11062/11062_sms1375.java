import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        while(T-- > 0) {
            int N = Integer.parseInt(br.readLine());

            int[] card = new int[N + 1];
            int[][] dp = new int[N + 2][N + 1];

            String[] input = br.readLine().split(" ");

            for(int i = 1; i <= N; i++) {
                card[i] = Integer.parseInt(input[i - 1]);
            }

            boolean Aturn = true;

            if(N % 2 == 0) Aturn = false;

            for(int i = 1 ; i <= N ; i ++) {
                for(int j = 1 ; j <= N - i + 1 ; j ++) {
                    int row = j;
                    int col = i + j - 1;

                    if(Aturn) {   
                        dp[row][col] = Math.max(dp[row + 1][col] + card[row], dp[row][col - 1] + card[col]);
                    } else {
                        dp[row][col] = Math.min(dp[row + 1][col], dp[row][col - 1]);
                    }
                }
                Aturn = !Aturn;
            }

            System.out.println(dp[1][N]);
        }
    }
}
