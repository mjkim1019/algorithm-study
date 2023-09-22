import java.util.*;
import java.io.*;

public class Main {
    public static int N, M;
    public static int[][] map;
    public static boolean[][] visited;
    public static int[] dx = {-1, 1, 0, 0};
    public static int[] dy = {0, 0, -1, 1};

    public static class Room implements Comparable<Room> {
        int x;
        int y;
        int wall;

        Room(int x, int y, int wall) {
            this.x = x;
            this.y = y;
            this.wall = wall;
        }

        @Override
        public int compareTo(Room n) {
            return this.wall - n.wall;
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        map = new int[M][N];

        for (int i = 0; i < M; i++) {
            String[] input2 = br.readLine().split("");
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(input2[j]);
            }
        }

        visited = new boolean[M][N];

        System.out.println(breakWall());
    }

    public static int breakWall() {
        Queue<Room> queue = new PriorityQueue<>();
        queue.add(new Room(0, 0, 0));
        visited[0][0] = true;

        while (!queue.isEmpty()) {
            Room now = queue.remove();

            if (now.x == M - 1 && now.y == N - 1) {
                return now.wall;
            }

            for (int i = 0; i < 4; i++) {
                int x = now.x + dx[i];
                int y = now.y + dy[i];

                if (x >= 0 && y >= 0 && x < M && y < N && visited[x][y] == false) {
                    if (map[x][y] == 0) {
                        visited[x][y] = true;
                        queue.add(new Room(x, y, now.wall));
                    } else if (map[x][y] == 1) {
                        visited[x][y] = true;
                        queue.add(new Room(x, y, now.wall + 1));
                    }
                }
            }
        }
        return 0;
    }
}

