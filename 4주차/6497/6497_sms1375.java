import java.util.*;
import java.io.*;

public class Main {
    public static int[] parent;

    public static class Lamp implements Comparable<Lamp> {
        int x;
        int y;
        int meter;

        Lamp(int x, int y, int meter) {
            this.x = x;
            this.y = y;
            this.meter = meter;
        }

        @Override
        public int compareTo(Lamp o) {
            return this.meter - o.meter;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<Lamp> list = new ArrayList<>();
        while(true) {
            String[] input = br.readLine().split(" ");

            int m = Integer.parseInt(input[0]);
            int n = Integer.parseInt(input[1]);

            if (m == 0 && n == 0) return;

            parent = new int[m + 1];

            for (int i = 0; i < m; i++) {
                parent[i] = i;
            }

            int sum = 0;
            int cost = 0;

            list.clear();

            for (int i = 0; i < n; i++) {
                String[] input2 = br.readLine().split(" ");

                int home1 = Integer.parseInt(input2[0]);
                int home2 = Integer.parseInt(input2[1]);
                int distance = Integer.parseInt(input2[2]);

                list.add(new Lamp(home1, home2, distance));

                sum = sum + distance;
            }

            Collections.sort(list);

            for(int i = 0; i < list.size(); i++) {
                Lamp lamp = list.get(i);

                if(find(lamp.x) != find(lamp.y)) {
                    cost = cost + lamp.meter;
                    union(lamp.x, lamp.y);
                }
            }

            System.out.println(sum - cost);
        }
    }

    public static int find(int x) {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    public static void union(int a, int b) {
        int A = find(a);
        int B = find(b);
        if(A == B)
            return;
        parent[B] = A;
    }
}
