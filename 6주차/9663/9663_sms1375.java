import java.util.*;
import java.io.*;

public class Main {
    public static int count = 0;
    public static int N;
    public static int[] col;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        col = new int[N];

        NQueen(0);

        System.out.println(count);
    }

    public static void NQueen(int a) {
        if (a == N) {
            count++;
            return;
        }

        for (int i = 0; i < N; i++) {
            col[a] = i;
            if(promising(a)) {
                NQueen(a + 1);
            }
        }
    }

    public static boolean promising(int b) {
        for (int i = 0; i < b; i++) {
            if (col[i] == col[b] || Math.abs(col[i] - col[b]) == Math.abs(i - b)) return false;
        }
        return true;
    }
}
