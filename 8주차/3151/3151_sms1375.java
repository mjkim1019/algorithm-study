import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] skill = new int[N];

        String[] input = br.readLine().split(" ");

        for(int i = 0; i < N; i++) {
            skill[i] = Integer.parseInt(input[i]);
        }

        Arrays.sort(skill);

        long count = 0;

        for(int i = 0; i < N; i++) {
            if(skill[i] > 0) break;
            int need = 0 - skill[i];

            int start = i + 1;
            int end = N - 1;

            while(start < end) {
                int sum = skill[start] + skill[end];

                if(sum == need) {
                    int start_count = 1;
                    int end_count = 1;

                    if(skill[start] == skill[end]) {
                        int n = end - start + 1;
                        count += n * (n - 1) / 2;
                        break;
                    }

                    while(skill[start] == skill[start + 1]) {
                        start_count++;
                        start++;
                    }
                    while(skill[end] == skill[end - 1]) {
                        end_count++;
                        end--;
                    }

                    count += start_count * end_count;
                }
                
                if(sum > need) end--;
                else start++;
            }
        }

        System.out.println(count);
    }
}
