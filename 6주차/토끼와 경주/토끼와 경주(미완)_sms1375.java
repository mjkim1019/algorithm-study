import java.util.*;
import java.io.*;

public class Main {
    public static class Rabbit implements Comparable<Rabbit> {
        int id;
        int Dist;
        int Count;
        int Score;
        int x, y;

        Rabbit(int id, int Dist) {
            this.id = id;
            this.Dist = Dist;
            this.Count = 0;
            this.Score = 0;
            this.x = 1;
            this.y = 1;
        }

        void print() {
            System.out.println("id는 " + id + ", Dist는 " + Dist + ", Count는 " + Count + ", Score는 " + Score + ", 위치는 " + x + ", " + y);
        }

        @Override
        public int compareTo(Rabbit o) {
            if(this.Count != o.Count) return Integer.compare(this.Count, o.Count);

            if(this.x + this.y != o.x + o.y) return Integer.compare(this.x + this.y, o.x + o.y);

            if(this.x != o.x) return Integer.compare(this.x, o.x);

            if(this.y != o.y) return Integer.compare(this.y, o.y);

            return Integer.compare(this.id, o.id);
        }
    }
    public static List<Rabbit> list = new ArrayList<>();
    public static PriorityQueue<Rabbit> queue = new PriorityQueue<>();
    public static int N, M;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int Q = Integer.parseInt(br.readLine());

        int max = Integer.MIN_VALUE;

        for(int i = 0; i < Q; i++) {
            String[] input = br.readLine().split(" ");
            switch(input[0]) {
                case "100":
                    N = Integer.parseInt(input[1]) + 1;
                    M = Integer.parseInt(input[2]) + 1;
                    for(int j = 0; j < Integer.parseInt(input[3]); j++) {
                        Rabbit rabbit = new Rabbit(Integer.parseInt(input[4 + 2 * j]), Integer.parseInt(input[5 + 2 * j]));
                        list.add(rabbit);
                        queue.add(rabbit);
                    }
                    break;
                case "200":
                    jumpRabbit(Integer.parseInt(input[1]), Integer.parseInt(input[2]));
                    break;
                case "300":
                    for(int j = 0; j < list.size(); j++) {
                        if(list.get(j).id == Integer.parseInt(input[1])) list.get(j).Dist *= Integer.parseInt(input[2]);
                    }
                    break;
                case "400":
                    for(int j = 0; j < list.size(); j++) {
                        if(list.get(j).Score > max) max = list.get(j).Score;
                    }
                    System.out.println(max);
                    break;
                default:
                    break;
            }
        }
    }

    private static int jumpRabbit(int round, int score) {
        if(round == 0) {
            int max_id = 0;
            int max_xy = Integer.MIN_VALUE;
            for(int i = 0; i < list.size(); i++) {
                if(list.get(i).x + list.get(i).y > max_xy) {
                    max_xy = list.get(i).x + list.get(i).y;
                    max_id = list.get(i).id;
                }
            }

            for(int i = 0; i < list.size(); i++) {
                if(list.get(i).id == max_id) {
                    list.get(i).Score += score;
                }
            }

            return 0;
        }

        Rabbit now = queue.poll();
//        now.print();


        int max_x = 0, max_y = 0;

        for(int i = 0; i < 4; i++) {
            int[] dx = {0, 0, -1, 1};
            int[] dy = {1, -1, 0, 0};
            int tempx = now.x;
            int tempy = now.y;
            for(int j = 0; j < now.Dist; j++) {
                tempx = tempx + dx[i];
                tempy = tempy + dy[i];

                if(tempx <= 0 || tempx >= N) {
                    dx[i] = -1 * dx[i];
                    if(tempx <= 0) tempx += 2;
                    else tempx -= 2;
                }
                if(tempy <= 0 || tempy >= M) {
                    dy[i] = -1 * dy[i];
                    if(tempy <= 0) tempy += 2;
                    else tempy -= 2;
                }
            }
            if(max_x + max_y < tempx + tempy) {
                max_x = tempx;
                max_y = tempy;
            }
            else if(max_x + max_y == tempx + tempy) {
                if(max_x < tempx) {
                    max_x = tempx;
                    max_y = tempy;
                } else if(max_x == tempx) {
                    if(max_y < tempy) {
                        max_x = tempx;
                        max_y = tempy;
                    }
                }
            }
        }
        now.x = max_x;
        now.y = max_y;
        now.Count++;
//        System.out.println(now.id + "번의 토끼가 " + now.x + ", " + now.y + "의 위치로 이동했습니다.");

        for(int i = 0; i < list.size(); i++) {
            if(list.get(i).id == now.id) continue;
            list.get(i).Score += now.x + now.y;
        }

//        System.out.println(round + " 라운드 종료");
//        now.print();
//        System.out.println("-------------------------------------------");
        queue.add(now);
        return jumpRabbit(round - 1, score);
    }
}
