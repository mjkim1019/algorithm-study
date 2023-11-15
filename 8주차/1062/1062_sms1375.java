import java.util.*;
import java.io.*;

public class Main {
    public static int K;
    public static boolean[] ABC;
    public static String[] word;
    public static int max = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);

        ABC = new boolean[26];

        if(K < 5) {
            System.out.println("0");
            System.exit(0);
        }

        ABC['a' - 'a'] = true;
        ABC['c' - 'a'] = true;
        ABC['i' - 'a'] = true;
        ABC['n' - 'a'] = true;
        ABC['t' - 'a'] = true;

        K -= 5;

        word = new String[N];

        for(int i = 0; i < N; i++) {
            String str = br.readLine();
            word[i] = str.replaceAll("[a, c, i, n, t]", "");
        }

        teach(0, K);

        System.out.println(max);


    }

    public static void teach(int index, int K) {
        if(K == 0) isRead();

        for(int i = index; i < 26; i++) {
            if(ABC[i]) continue;
            else {
                ABC[i] = true;
                teach(i, K - 1);
                ABC[i] = false;
            }
        }
    }

    public static void isRead() {
        int count = 0;
        for(int i = 0; i < word.length; i++) {
            boolean read = true;
            for(int j = 0; j < word[i].length(); j++) {
                if(!ABC[word[i].charAt(j) - 'a']) {
                    read = false;
                    break;
                }
            }
            if(read) count++;
        }
        max = Math.max(max, count);
        return;
    }
}
