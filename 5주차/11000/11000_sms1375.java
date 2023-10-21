// 시간초과
import java.util.*;
import java.io.*;

public class Main {
    public static int[] use;
    public static class Lecture implements Comparable<Lecture> {
        int start;
        int end;

        Lecture(int start, int end) {
            this.start = start;
            this.end = end;
        }

        public int compareTo(Lecture o) {
            if (this.start != o.start) {
                return this.start - o.start;
            } else {
                return this.end - o.end;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        use = new int[N];

        PriorityQueue<Lecture> queue = new PriorityQueue<>();

        for(int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");

            queue.add(new Lecture(Integer.parseInt(input[0]), Integer.parseInt(input[1])));
        }

        int count = 1;

        while(!queue.isEmpty()) {
            Lecture now = queue.poll();

            for(int i = 0; i < N; i++) {
                if(use[i] > now.start) {
                    if(use[i + 1] == 0) {
                        count++;
                        use[i + 1] = now.end;
                        break;
                    }
                    continue;
                }
                else {
                    use[i] = now.end;
                    break;
                }

            }
        }

        System.out.println(count);

    }
// 성공
import java.util.*;
import java.io.*;

public class Main {
    public static class Lecture implements Comparable<Lecture> {
        int start;
        int end;

        Lecture(int start, int end) {
            this.start = start;
            this.end = end;
        }

        public int compareTo(Lecture o) {
            if (this.start != o.start) {
                return this.start - o.start;
            } else {
                return this.end - o.end;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        PriorityQueue<Lecture> queue = new PriorityQueue<>();

        for(int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");

            queue.add(new Lecture(Integer.parseInt(input[0]), Integer.parseInt(input[1])));
        }

        PriorityQueue<Integer> finish = new PriorityQueue<>();

        while(!queue.isEmpty()) {
            Lecture now = queue.poll();
            finish.add(now.end);
            
            if(finish.peek() <= now.start) {
                finish.poll();
            }
        }

        System.out.println(finish.size());
    }
}
