import java.util.*;
import java.io.*;

public class Island implements Comparable<Island> {
    int a;
    int b;
    int cost;
    
    Island(int a, int b, int cost) {
        this.a = a;
        this.b = b;
        this.cost = cost;
    }
    
    public int compareTo(Island o) {
        return this.cost - o.cost;
    }
    
}

class Solution {
    public static int[] parent;
    public int solution(int n, int[][] costs) {
        parent = new int[n + 1];
        for(int i = 1; i<=n; i++) parent[i] = i;
        
        PriorityQueue<Island> order = new PriorityQueue<>();
        
        for(int i = 0; i < costs.length; i++) {
            order.offer(new Island(costs[i][0], costs[i][1], costs[i][2]));
        }
        
        int answer = 0;
        
        while(!order.isEmpty()) {
            Island now = order.poll();
            
            if(find(now.a) == find(now.b)) continue;
            
            union(now.a, now.b);
            
            answer = answer + now.cost;
        }
        
        return answer;
    }
    
    public int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    public void union(int a, int b) {
        int A = find(a);
        int B = find(b);
        if(A == B) return;
        parent[B] = A;
    }
}
