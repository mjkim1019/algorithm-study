import java.util.*;
import java.io.*;

public class Main {
    public static int[] dx = {-1, 1, 0, 0};
    public static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[][] seat = new int[N + 1][N + 1];

        HashMap<Integer, ArrayList<Integer>> hash = new HashMap<>();

        for(int i = 1; i <= N * N; i++) {
            String[] input = br.readLine().split(" ");

            int person = Integer.parseInt(input[0]);
            int like1 = Integer.parseInt(input[1]);
            int like2 = Integer.parseInt(input[2]);
            int like3 = Integer.parseInt(input[3]);
            int like4 = Integer.parseInt(input[4]);

            ArrayList<Integer> like = new ArrayList<>();
            like.add(like1);
            like.add(like2);
            like.add(like3);
            like.add(like4);
            hash.put(person, like);

            int near = -1;
            int empty = -1;
            int xx = 0;
            int yy = 0;
            for(int j = 1; j <= N; j++) {
                for(int k = 1; k <= N; k++) {
                    int tempNear = 0;
                    int tempEmpty = 0;

                    if (seat[j][k] != 0) {
                        continue;
                    }
                    for(int z = 0; z < 4; z++) {
                        int x = j + dx[z];
                        int y = k + dy[z];
                        if(x <= 0 || x > N || y <= 0 || y > N) {
                            continue;
                        }

                        if(seat[x][y] > 0 && (seat[x][y] == like1 || seat[x][y] == like2 || seat[x][y] == like3 || seat[x][y] == like4)) {
                            tempNear++;

                        } else if(seat[x][y] == 0) {
                            tempEmpty++;
                        }
                    }

                    if(tempNear > near) {
                        near = tempNear;
                        empty = tempEmpty;
                        xx = j;
                        yy = k;
                    } else if(tempNear == near && tempEmpty > empty) {
                        near = tempNear;
                        empty = tempEmpty;
                        xx = j;
                        yy = k;
                    }
                }
            }
            seat[xx][yy] = person;
        }
        satisfaction(seat, hash);
    }

    public static void satisfaction(int[][] seat, HashMap<Integer, ArrayList<Integer>> hash) {
        int answer = 0;

        for(int i = 1; i < seat.length; i++) {
            for(int j = 1; j < seat.length; j++) {
                int like = 0;
                for(int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x <= 0 || x > seat.length - 1 || y <= 0 || y > seat.length - 1) {
                        continue;
                    }

                    if(hash.get(seat[i][j]).contains(seat[x][y])) {
                        like++;
                    }
                }

                switch(like) {
                    case 0:
                        break;
                    case 1:
                        answer = answer + 1;
                        break;
                    case 2:
                        answer = answer + 10;
                        break;
                    case 3:
                        answer = answer + 100;
                        break;
                    case 4:
                        answer = answer + 1000;
                        break;
                }
            }
        }
        System.out.println(answer);
    }
}
