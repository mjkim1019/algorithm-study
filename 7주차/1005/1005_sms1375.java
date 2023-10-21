import java.util.*;
import java.io.*;

public class Main {
    public static List<Integer>[] requires;
    public static int[] build;
    public static int[] build_time;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        while(T-- > 0) {
            String[] input = br.readLine().split(" ");

            int N = Integer.parseInt(input[0]);
            int K = Integer.parseInt(input[1]);

            build = new int[N + 1];

            Arrays.fill(build, -1);
            build_time = new int[N + 1];

            String[] input2 = br.readLine().split(" ");

            for(int i = 1; i <= N; i++) {
                build_time[i] = Integer.parseInt(input2[i - 1]);
            }

            requires = new ArrayList[N + 1];

            for(int i = 0; i < requires.length; i++) {
                requires[i] = new ArrayList<>();
            }

            for(int i = 0; i < K; i++) {
                String[] input3 = br.readLine().split(" ");
                requires[Integer.parseInt(input3[1])].add(Integer.parseInt(input3[0]));
            }

            int W = Integer.parseInt(br.readLine());

            System.out.println(build(W));
        }
    }

    public static int build(int number) {
        if(requires[number].isEmpty()) {
            build[number] = build_time[number];
            return build[number];
        }

        int max = 0;

        for(int i = 0; i < requires[number].size(); i++) {
            int temp = requires[number].get(i);
            if(build[temp] == -1) {
                build[temp] = build(temp);
            }
            if(max < build[temp]) max = build[temp];
        }

        build[number] = max + build_time[number];
        return build[number];
    }
}
