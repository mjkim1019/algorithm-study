import java.util.*;
import java.io.*;

public class Main {
    public static int[][] board;

    public static class Coord {
        int x;
        int y;

        Coord(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        board = new int[9][9];

        for(int i = 0 ; i < 9; i++) {
            String[] input = br.readLine().split(" ");
            for(int j = 0; j < 9; j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }

        sudoku(0, 0);
    }

    public static void sudoku(int row, int col) {
        if(col == 9) {
            sudoku(row + 1, 0);
            return;
        }

        if(row == 9) {
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 9; j++) {
                    System.out.print(board[i][j] + " ");
                }
                System.out.println();
            }
            System.exit(0);
        }

        if(board[row][col] == 0) {
            for(int i = 1; i <= 9; i++) {
                if(inSquare(row, col, i)) {
                    board[row][col] = i;
                    sudoku(row, col + 1);
                }
            }
            board[row][col] = 0;
            return;
        }
        sudoku(row, col + 1);
    }

    public static boolean inSquare(int x, int y, int value) {
        int sx = (x / 3) * 3;
        int sy = (y / 3) * 3;

        for(int i = sx; i < sx + 3; i++) {
            for(int j = sy; j < sy + 3; j++) {
                if(board[i][j] == value) return false;
            }
        }
        return inRow(x, y, value);
    }

    public static boolean inRow(int x, int y, int value) {
        for(int i = 0; i < 9; i++) {
            if(board[x][i] == value) return false;
        }
        return inColumn(x, y, value);
    }

    public static boolean inColumn(int x, int y, int value) {
        for(int i = 0; i < 9; i++) {
            if(board[i][y] == value) return false;
        }
        return true;
    }
}
