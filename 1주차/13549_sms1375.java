import java.util.*;
import java.io.*;

public class Main {
    public static int[] visited = new int[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        Queue<Integer> queue = new LinkedList<>();

        queue.add(N);
        visited[N] = 1;

        int now;

        while(!queue.isEmpty()) {
            now = queue.poll();

            for(int i = 0; i < 3; i++) {
                int next;
                int time = 0;
                if(i == 0) {
                    next = now * 2;
                } else if(i == 1) {
                    next = now + 1;
                    time++;
                } else {
                    next = now - 1;
                    time++;
                }
                
                if(next >= 0 && next < visited.length && visited[next] == 0) {
                    queue.add(next);
                    visited[next] = visited[now] + time;
                } else if(next >= 0 && next < visited.length && visited[next] > visited[now] + time) {
                    visited[next] = visited[now] + time;
                }
            }

        }
        System.out.println(visited[K] - 1);

    }
}

