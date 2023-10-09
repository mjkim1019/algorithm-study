import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        boolean[] remote = new boolean[10];

        if(M != 0) {
            String[] input = br.readLine().split(" ");
            for (int i = 0; i < M; i++) remote[Integer.parseInt(input[i])] = true;
        }

        int now = 100;

        if(N == 100) System.out.println("0");
        else if(M == 10) System.out.println(Math.abs(now - N));
        else {
            int count = Math.abs(now - N);

            for(int i = 0; i <= 1000000; i++) {
                String number[] = Integer.toString(i).split("");

                boolean flag = true;
                for(String index : number) {
                    if(remote[Integer.parseInt(index)]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    count = Math.min(count, number.length + Math.abs(i - N));
                }
            }
            System.out.println(count);
        }
    }
}
