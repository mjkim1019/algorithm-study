// 시간초과
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");

        int[] arr = new int[N];

        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
      
        int start = 0;
        int end = arr.length - 1;

        int ALK = 0;
        int ACID = 0;

        int min = Integer.MAX_VALUE;
        while(start < end) {
            int sum = arr[start] + arr[end];

            if(sum > 0) {
                if(min >= sum) {
                    min = sum;
                    ALK = arr[start];
                    ACID = arr[end];
                }
                end--;
                continue;
            } else if(sum < 0) {
                if(min >= Math.abs(sum)) {
                    min = Math.abs(sum);
                    ALK = arr[start];
                    ACID = arr[end];
                }
                start++;
                continue;
            }
        }

        System.out.println(ALK + " " + ACID);
    }
}

// 성공
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");

        int[] arr = new int[N];

        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }

        int start = 0;
        int end = arr.length - 1;

        int ALK = 0;
        int ACID = 0;

        int min = Integer.MAX_VALUE;
        while(start < end) {
            int sum = arr[start] + arr[end];

            if(sum >= 0) {
                if(min >= sum) {
                    min = sum;
                    ALK = start;
                    ACID = end;
                }
                end--;
            } else if(sum < 0) {
                if(min >= Math.abs(sum)) {
                    min = Math.abs(sum);
                    ALK = start;
                    ACID = end;
                }
                start++;
            }
        }

        System.out.println(arr[ALK] + " " + arr[ACID]);
    }
}
