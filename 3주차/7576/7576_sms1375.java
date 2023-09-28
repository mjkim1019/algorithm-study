import java.util.*;
import java.io.*;

public class Main {
    public static int[] dx = {-1, 1, 0, 0};
    public static int[] dy = {0, 0, -1, 1};

    public static class Tomato implements Comparable<Tomato> {
        int x;
        int y;
        int day;

        Tomato(int x, int y, int day) {
            this.x = x;
            this.y = y;
            this.day = day;
        }
        @Override
        public int compareTo(Tomato o) {
            return this.day - o.day;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int M = Integer.parseInt(input[0]);
        int N = Integer.parseInt(input[1]);

        int[][] box = new int[N][M];

        Queue<Tomato> queue = new PriorityQueue<>();


        for (int i = 0; i < N; i++) {
            String[] input2 = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                int temp = Integer.parseInt(input2[j]);
                box[i][j] = temp;
                if(temp == 1) {
                    Tomato tomato = new Tomato(i, j, temp);
                    queue.add(tomato);
                }
            }
        }

        while(!queue.isEmpty()) {
            Tomato now = queue.poll();

            for(int i = 0; i < 4; i++) {
                int x = now.x + dx[i];
                int y = now.y + dy[i];

                if(x >= 0 && y >= 0 && x < N && y < M) {
                    if(box[x][y] == 0) {
                        box[x][y] = now.day + 1;
                        queue.add(new Tomato(x, y, now.day + 1));
                    }
                }
            }
        }

        int max = Arrays.stream(box).flatMapToInt(Arrays::stream).max().getAsInt();

        boolean hasZero = Arrays.stream(box).flatMapToInt(Arrays::stream).anyMatch(element -> element == 0);

        if(hasZero) System.out.println("-1");
        else System.out.println(max - 1);
    }
}
