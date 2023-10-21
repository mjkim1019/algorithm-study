import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        int[][] lamp = new int[N][M];
        HashMap<String, Integer> map = new HashMap<>();

        for(int i = 0; i < N; i++) {
            String[] input2 = br.readLine().split("");

            for(int j = 0; j < M; j++) {
                lamp[i][j] = Integer.parseInt(input2[j]);
            }
        }

        int K = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++) {
            StringBuilder str = new StringBuilder();
            int zero = 0;

            for(int j = 0; j < M; j++) {
                str.append(lamp[i][j]);

                if(lamp[i][j] == 0) zero++;
            }

            if(zero == 0) {
                if(K % 2 == 0) map.put(str.toString(), map.getOrDefault(str.toString(), 0) + 1);
            } else {
                if(K >= zero && K % 2 == zero % 2) map.put(str.toString(), map.getOrDefault(str.toString(), 0) + 1);
            }
        }

        int max = 0;

        Collection<Integer> values = map.values();

        for (int value : values) {
            if (value > max) {
                max = value;
            }
        }

        System.out.println(max);
    }
}
