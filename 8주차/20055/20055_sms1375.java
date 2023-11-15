import java.util.*;
import java.io.*;

public class Main {
    public static int[] A;
    public static boolean[] robot;
    public static int N;
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        A = new int[2 * N + 1];
        robot = new boolean[N + 1];

        String[] input2 = br.readLine().split(" ");

        for(int i = 0; i < 2 * N; i++) {
            A[i + 1] = Integer.parseInt(input2[i]);
        }

        int count = 1;

        while(true) {
            rotation();
            moveRobot();
            upRobot();
            if(isContinue(K)) {
                count++;
                continue;
            }
            else break;
        }
        System.out.println(count);
    }

    public static void rotation() {
        int temp = A[1];
        A[0] = temp;
        for(int i = 1; i <= 2 * N; i++) {
            if(i == 2 * N) {
                A[1] = A[0];
            } else {
                temp = A[i + 1];
                A[i + 1] = A[0];
                A[0] = temp;
            }
        }

        boolean[] copy = robot.clone();

        for(int i = 1; i < robot.length - 1; i++) {
            robot[i] = copy[i - 1];
        }
    }

    public static void moveRobot() {
        for(int i = robot.length - 2; i >= 1; i--) {
            if(robot[i] && !robot[i + 1] && A[i + 1] > 0) {
                robot[i] = false;
                A[i + 1]--;
                if(i + 1 != N) robot[i + 1] = true;
            }
        }
    }

    public static void upRobot() {
        if(A[1] != 0) {
            robot[1] = true;
            A[1]--;
        }
    }

    public static boolean isContinue(int K) {
        int countZero = 0;
        for(int i = 1; i < A.length; i++) {
            if(A[i] == 0) countZero++;
        }

        if(countZero >= K) return false;
        else return true;
    }
}
