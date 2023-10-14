import java.util.*;
import java.io.*;

public class Main {
    public static class Point {
        int x;
        int y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public static class Square {
        int x1, y1; // 좌상단
        int x2, y2; // 우하단
        Square(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

        boolean existPlayer() {
            for(Point p : playerList) {
                if(p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2) {
                    rotationList.add(p);
                }
            }
            if(rotationList.isEmpty()) return false;
            else return true;
        }
    }

    public static int N;
    public static int[][] maze;
    public static List<Point> playerList;
    public static List<Point> rotationList;
    public static Point exit;
    public static int count = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]); // 미로의 크기 NxN 배열
        int M = Integer.parseInt(input[1]); // 참가자 수
        int K = Integer.parseInt(input[2]); // 게임 시간

        maze = new int[N + 1][N + 1]; // 좌상단이 (1, 1)이기 때문에 직관적으로 보이기 위해 (N + 1)x(N + 1) 배열을 만들고 [1][1]부터 사용

        for(int i = 1; i < N + 1; i++) {
            String[] input2 = br.readLine().split(" ");
            for(int j = 1; j < N + 1; j++) {
                maze[i][j] = Integer.parseInt(input2[j - 1]);
            }
        }

        playerList = new LinkedList<>();

        for(int i = 0; i < M; i++) {
            String[] input3 = br.readLine().split(" ");
            Point player = new Point(Integer.parseInt(input3[0]), Integer.parseInt(input3[1]));
            playerList.add(player);
        }

        String[] input4 = br.readLine().split(" ");
        exit = new Point(Integer.parseInt(input4[0]), Integer.parseInt(input4[1]));

        while(K-- > 0) {
            move();
            escape();
            if(playerList.isEmpty()) break;

            Square small = findMinimumSquare();
          
            rotation(small);
        }

        System.out.println(count);
        System.out.println(exit.x + " " + exit.y);

    }

    public static void move() {
        for(int i = 0; i < playerList.size(); i++) {
            Point now = playerList.get(i);
            if(now.x > exit.x) {
                if(maze[now.x - 1][now.y] == 0)
                {
                    now.x = now.x - 1;
                    count++;
                }
                // ex) exit(2, 2) now(3, 1)일 때 이동하면 now.x가 exit.x보다 크기 때문에 (2, 1)로 이동하기 전 maze[2][1]을 보고 0이면 이동
                else if(now.y > exit.y && maze[now.x][now.y - 1] == 0) {
                    now.y = now.y - 1;
                    count++;
                }
                else if(now.y < exit.y && maze[now.x][now.y + 1] == 0) {
                    now.y = now.y + 1;
                    count++;
                }
            } else if(now.x < exit.x) {
                if(maze[now.x + 1][now.y] == 0) {
                    now.x = now.x + 1;
                    count++;
                }
                else if(now.y > exit.y && maze[now.x][now.y - 1] == 0) {
                    now.y = now.y - 1;
                    count++;
                }
                else if(now.y < exit.y && maze[now.x][now.y + 1] == 0) {
                    now.y = now.y + 1;
                    count++;
                }
            } else { // now.x == exit.x일 때
                if (now.y > exit.y) {
                    if (maze[now.x][now.y - 1] == 0) {
                        now.y = now.y - 1;
                        count++;
                    }
                } else if (now.y < exit.y) {
                    if (maze[now.x][now.y + 1] == 0) {
                        now.y = now.y + 1;
                        count++;
                    }
                }
            }
        }
    }

    public static void rotation(Square square) {
        int copy[][] = new int[maze.length][maze.length];

        for(int i = 0; i < maze.length; i++) {
            for(int j = 0 ; j < maze.length; j++) {
                copy[i][j] = maze[i][j];
            }
        }

        int sum = square.x2 - square.x1;

        for(int i = square.x1; i <= square.x2; i++) {
            for(int j = square.y1; j <= square.y2; j++) {
                int tempx = i - square.x1;
                int tempy = j - square.y1;
                maze[i][j] = copy[sum - tempy + square.x1][tempx + square.y1];
                if(maze[i][j] != 0) maze[i][j]--;
            }
        }
        rotationList.add(exit);
        for(int i = 0; i < rotationList.size(); i++) {
            Point now = rotationList.get(i);
            int tempx = now.x - square.x1;
            int tempy = now.y - square.y1;
            now.x = tempy + square.x1;
            now.y = sum - tempx + square.y1;
        }
    }

    public static void escape() {
        for(int i = playerList.size() - 1; i >= 0; i--) {
            Point now = playerList.get(i);
            if(now.x == exit.x && now.y == exit.y) {
                playerList.remove(i);
            }
        }
    }

    public static Square findMinimumSquare() { // 필요한 것 : 정사각형의 크기, 정사각형의 최상단
        rotationList = new ArrayList<>();
        for(int sz = 2; sz <= N; sz++) {
            for(int x1 = 1; x1 <= N - sz + 1; x1++) {
                for(int y1 = 1; y1 <= N - sz + 1; y1++) {
                    int x2 = x1 + sz - 1;
                    int y2 = y1 + sz - 1;
                    if(!(x1 <= exit.x && exit.x <= x2 && y1 <= exit.y && exit.y <= y2)) {
                        continue;
                    }

                    Square square = new Square(x1, y1, x2, y2);
                    square.existPlayer();

                    if(!rotationList.isEmpty()) {
                        return square;
                    }
                }
            }
        }
        return new Square(0, 0, 0, 0);
    }
}
