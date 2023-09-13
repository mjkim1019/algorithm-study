import java.util.*;
import java.io.*;

class Dice {
    int top = 0, bottom = 0, up = 0, down = 0, left = 0, right = 0;

    public void copyBottom(int bottom) {
        this.bottom = bottom;
    }

    public void printTop() {
        System.out.println(this.top);
    }

    public void rollRight() {
        int temp = this.top;
        this.top = this.left;
        this.left = this.bottom;
        this.bottom = this.right;
        this.right = temp;
    }

    public void rollLeft() {
        int temp = this.top;
        this.top = this.right;
        this.right = this.bottom;
        this.bottom = this.left;
        this.left = temp;
    }

    public void rollUp() {
        int temp = this.top;
        this.top = this.down;
        this.down = this.bottom;
        this.bottom = this.up;
        this.up = temp;
    }

    public void rollDown() {
        int temp = this.top;
        this.top = this.up;
        this.up = this.bottom;
        this.bottom = this.down;
        this.down = temp;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        int[][] map = new int[N][M];

        int sx = Integer.parseInt(input[2]);
        int sy = Integer.parseInt(input[3]);

        int count = Integer.parseInt(input[4]);
        int[] order = new int[count];

        for(int i = 0; i < N; i++) {
            String[] input2 = br.readLine().split(" ");
            for(int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(input2[j]);
            }
        }

        String[] input3 = br.readLine().split(" ");
        for(int i = 0; i < count; i++) {
            order[i] = Integer.parseInt(input3[i]);
        }

        Dice dice = new Dice();
        int nowx = sx;
        int nowy = sy;
        for(int i = 0; i < order.length; i++) {
            switch (order[i]) {
                case 1:
                    nowy = nowy + 1;
                    dice.rollRight();
                    break;
                case 2:
                    nowy = nowy - 1;
                    dice.rollLeft();
                    break;
                case 3:
                    nowx = nowx - 1;
                    dice.rollUp();
                    break;
                case 4:
                    nowx = nowx + 1;
                    dice.rollDown();
                    break;
                default :
                    break;
            }

            if(nowx >= N) {
                nowx = nowx - 1;
                dice.rollUp();
                continue;
            } else if(nowx < 0) {
                nowx = nowx + 1;
                dice.rollDown();
                continue;
            } else if(nowy >= M) {
                nowy = nowy - 1;
                dice.rollLeft();
                continue;
            } else if(nowy < 0) {
                nowy = nowy + 1;
                dice.rollRight();
                continue;
            } else {
                if(map[nowx][nowy] == 0) map[nowx][nowy] = dice.bottom;
                else {
                    dice.copyBottom(map[nowx][nowy]);
                    map[nowx][nowy] = 0;
                }
                dice.printTop();
            }
        }
    }
}

