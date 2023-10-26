import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        List<String> student = new ArrayList<>();

        Queue<Integer>[] bf = new LinkedList[21];

        for(int i = 2; i < 21; i++) bf[i] = new LinkedList<>();

        long count = 0;

        for(int i = 1; i <= N; i++) {
            int length = br.readLine().length();

            if(bf[length].isEmpty()) {
                bf[length].add(i);
            }
            else {
                while(!bf[length].isEmpty()) {
                    if(i - bf[length].peek() <= K) {
                        count += bf[length].size();
                        bf[length].add(i);
                        break;
                    }
                    bf[length].poll();
                }
                if(bf[length].isEmpty()) bf[length].add(i);
            }
        }
        System.out.println(count);
    }
}
