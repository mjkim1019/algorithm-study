import java.util.*;
import java.io.*;

class Tower {
    int index;
    int height;

    Tower() {
    }
    Tower(int index, int height) {
        this.index = index;
        this.height = height;
    }
}

public class Main {
    public static int index;
    public static int height;
    public static int target;
    public static int count;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");

        Stack<Tower> stack = new Stack<>();
        Tower top = new Tower();

        for(int i = 0; i < N; i++) {
            index = i + 1;
            height = Integer.parseInt(input[i]);
            if(stack.isEmpty()) {
                System.out.print("0 ");
                stack.push(new Tower(index, height));
                top = stack.peek();
                continue;
            }

            if(top.height < height) {
                System.out.print("0 ");
                stack.push(new Tower(index, height));
                top = stack.peek();
            } else {
                while(stack.peek().height < height) {
                    stack.pop();
                }
                System.out.print(stack.peek().index + " ");
                stack.push(new Tower(index, height));
            }
        }
    }
}
