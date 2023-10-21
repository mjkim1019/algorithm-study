import java.util.*;
import java.io.*;

public class Main {
    public static int N, res = 987654321;
    static ArrayList<Integer>[] adj;
    static boolean isAreaA[];
    public static int[] pop;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        pop = new int[N + 1];
        String[] input = br.readLine().split(" ");

        for(int i = 1; i <= N; i++) {
            pop[i] = Integer.parseInt(input[i - 1]);
        }

        adj = new ArrayList[N + 1];

        for(int i = 1; i <= N; i++) {
            String[] input2 = br.readLine().split(" ");
            adj[i] = new ArrayList<>();

            for(int j = 1; j <= Integer.parseInt(input2[0]); j++) {
                adj[i].add(Integer.parseInt(input2[j]));
            }
        }

        isAreaA = new boolean[N + 1];
        selectA(1);

        System.out.println(res == 987654321 ? -1 : res);
    }

    private static void selectA(int index) {
        if(index == N + 1) {
            if(check()) {
                int sumA = 0;
                int sumB = 0;

                for(int i = 1; i <= N; i++) {
                    if(isAreaA[i]) sumA += pop[i];
                    else sumB += pop[i];
                }

                res = Math.min(res, Math.abs(sumA - sumB));
            }
            return;
        }

        isAreaA[index] = true;
        selectA(index + 1);
        isAreaA[index] = false;
        selectA(index + 1);
    }

    private static boolean check() {
        boolean[] visited = new boolean[N + 1];
        int areaA = -1;

        for(int i = 1; i <= N; i++) {
            if(isAreaA[i]) {
                areaA = i;
                break;
            }
        }

        int areaB = -1;

        for(int i = 1; i <= N; i++) {
            if(!isAreaA[i]) {
                areaB = i;
                break;
            }
        }

        if(areaA == -1 || areaB == -1) return false;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(areaA);
        visited[areaA] = true;
        while(!queue.isEmpty()) {
            int now = queue.poll();

            for(int i = 0; i < adj[now].size(); i++) {
                if(visited[adj[now].get(i)]) continue;
                if(!isAreaA[adj[now].get(i)]) continue;
                visited[adj[now].get(i)] = true;
                queue.add(adj[now].get(i));
            }
        }

        queue.add(areaB);
        visited[areaB] = true;
        while(!queue.isEmpty()) {
            int now = queue.poll();

            for(int i = 0; i < adj[now].size(); i++) {
                if (visited[adj[now].get(i)]) continue;
                if (isAreaA[adj[now].get(i)]) continue;
                visited[adj[now].get(i)] = true;
                queue.add(adj[now].get(i));
            }
        }

        for(int i = 1; i <= N; i++) {
            if(!visited[i])
                return false;
        }

        return true;
    }
}
