import java.util.*;
import java.io.*;

public class Main {

    static int x;
    private static BufferedReader br;

    static boolean isVampire(int x) {
        char[] origin = Integer.toString(x).toCharArray();
        Arrays.sort(origin);

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                char[] divided = (Integer.toString(i) + Integer.toString(x / i)).toCharArray();
                Arrays.sort(divided);

                if (Arrays.equals(origin, divided)) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));

        while(true) {
            x = Integer.parseInt(br.readLine());
            if (x == 0) break;

            while (!isVampire(x)) {
                x++;
            }
            System.out.println(x);
        }
    }
}
