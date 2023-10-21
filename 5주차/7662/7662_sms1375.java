// 시간초과
import java.util.*;
import java.io.*;

public class Main {
    public static List<Integer> valid = new ArrayList<>();

    public static class Map implements Comparable<Map>{
        int key;
        int value;

        Map(int key, int value) {
            this.key = key;
            this.value = value;
        }

        public int compareTo(Map o) {
            return this.value - o.value;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++) {
            int k = Integer.parseInt(br.readLine());

            PriorityQueue<Map> min = new PriorityQueue<>();
            PriorityQueue<Map> max = new PriorityQueue<>(Collections.reverseOrder());
            for(int j = 0; j < k; j++) {
                String[] input = br.readLine().split(" ");

                String op = input[0];
                int value = Integer.parseInt(input[1]);

                if(op.equals("I")) {
                    Map map = new Map(j, value);
                    min.add(map);
                    max.add(map);
                } else if(op.equals("D") && value == -1) {
                    max.remove(min.poll());

                } else {
                    min.remove(max.poll());
                }
            }
            if(min.isEmpty() && max.isEmpty()) {
                System.out.println("EMPTY");
            } else {
                System.out.println(max.peek().value + " " + min.peek().value);
            }
        }
    }
}

// 성공
import java.util.*;
import java.io.*;

public class Main {
    public static TreeMap<Integer, Integer> map;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++) {
            int k = Integer.parseInt(br.readLine());

            map = new TreeMap<>();
            for(int j = 0; j < k; j++) {
                String[] input = br.readLine().split(" ");

                String op = input[0];
                int value = Integer.parseInt(input[1]);

                if(op.equals("I")) {
                    map.put(value, map.getOrDefault(value, 0) + 1);
                } else if(map.size() == 0) {
                    continue;
                } else {
                    if(op.equals("D") && value == -1) {
                        int num = map.firstKey();
                        map.put(num, map.get(num) - 1);
                        if(map.get(num) < 1) map.remove(num);
                    } else {
                        int num = map.lastKey();
                        map.put(num, map.get(num) - 1);
                        if(map.get(num) < 1) map.remove(num);
                    }
                }
            }

            if(map.size() == 0) {
                System.out.println("EMPTY");
            } else {
                System.out.println(map.lastKey() + " " + map.firstKey());
            }
        }
    }
}
