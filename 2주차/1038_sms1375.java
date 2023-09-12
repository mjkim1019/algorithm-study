import java.util.*;
import java.io.*;

public class Main {
    public static List<Long> num_list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for(int i = 0; i < 10; i++) {
            decreaseNumber(i, 1);
        }

        num_list.sort(Comparator.naturalOrder());

        if(N > 1022) System.out.println("-1");
        else System.out.println( num_list.get(N));
    }

    public static void decreaseNumber(long num, int digit) {
        if(digit > 11) return;

        num_list.add(num);
        for(int i = 0; i < num % 10; i++) {
            decreaseNumber((num * 10) + i, digit + 1);
        }
    }
}

