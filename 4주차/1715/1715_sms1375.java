import java.util.*;
import java.io.*;

public class Main {
    public static int[][] board;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> queue = new PriorityQueue<>();

        for(int i = 0; i < N; i++) {
            queue.add(Integer.parseInt(br.readLine()));
        }

        int sum = 0;

        while(!queue.isEmpty()) {
            Integer a = queue.poll();
            Integer b = queue.poll();

            if(a == null || b == null) break;

            int temp = a + b;

            sum = sum + temp;

            queue.add(temp);
        }

        System.out.println(sum);

    }
}
