import java.util.*;
import java.io.*;

public class Main {

    public static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        parent = new int[n+1];
        for(int i = 0; i < parent.length; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < m; i++) {
            String[] input2 = br.readLine().split(" ");
            int type = Integer.parseInt(input2[0]);
            int a = Integer.parseInt(input2[1]);
            int b = Integer.parseInt(input2[2]);

            if(type == 0)
                union(a, b);
            else {
                if(find(a) == find(b)) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }

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

