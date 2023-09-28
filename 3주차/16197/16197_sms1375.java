import java.util.*;
import java.io.*;

public class Main {
    public static int N, M;
    public static char[][] board;
    public static int[] dx = {-1, 1, 0, 0};
    public static int[] dy = {0, 0, -1, 1};

    public static Queue<Coin> queue;

    public static class Coin {
        int x;
        int y;
        int move;

        Coin(int x, int y, int move) {
            this.x = x;
            this.y = y;
            this.move = move;
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        board = new char[N][M];

        queue = new LinkedList<>();

        for (int i = 0; i < N; i++) {
            char[] input2 = br.readLine().toCharArray();
            for (int j = 0; j < M; j++) {
                if (input2[j] == 'o') {
                    Coin coin = new Coin(i, j, 0);
                    queue.add(coin);
                }
                board[i][j] = input2[j];
            }
        }

        System.out.println(moveCoin());
    }

    public static int moveCoin() {
        while(!queue.isEmpty()) {
            Coin coin1 = queue.poll();
            Coin coin2 = queue.poll();

            if(coin1.move >= 10) return -1;

            for (int i = 0; i < 4; i++) {
                Boolean exist1 = true;
                Boolean exist2 = true;

                int x1 = coin1.x + dx[i];
                int x2 = coin2.x + dx[i];
                int y1 = coin1.y + dy[i];
                int y2 = coin2.y + dy[i];

                if (x1 >= N || x1 < 0 || y1 >= M || y1 < 0) exist1 = false;
                if (x2 >= N || x2 < 0 || y2 >= M || y2 < 0) exist2 = false;


                if (!exist1 && !exist2) continue;
                if (!exist1 || !exist2) {
                    return coin1.move + 1;
                }

                if (board[x1][y1] == '#' && board[x2][y2] == '#') continue;

                if (board[x1][y1] == '#') {
                    x1 = coin1.x;
                    y1 = coin1.y;
                }
                if (board[x2][y2] == '#') {
                    x2 = coin2.x;
                    y2 = coin2.y;
                }

                queue.add(new Coin(x1, y1, coin1.move + 1));
                queue.add(new Coin(x2, y2, coin1.move + 1));
            }
        }
        return -1;
    }
}
