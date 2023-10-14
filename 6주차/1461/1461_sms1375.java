import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        PriorityQueue<Integer> pbooks = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> nbooks = new PriorityQueue<>();
        List<Integer> list = new ArrayList<>();

        String[] input2 = br.readLine().split(" ");
        for(int i = 0; i < N; i++) {
            if(Integer.parseInt(input2[i]) >= 0) pbooks.add(Integer.parseInt(input2[i]));
            else nbooks.add(Integer.parseInt(input2[i]));
        }

        pbooks.add(0);
        nbooks.add(0);

        if(pbooks.peek() >= Math.abs(nbooks.peek())) {
            list.add(pbooks.poll()); // 리스트에 양수의 최댓값 추가
            for(int i = 0; i < M - 1; i++) {
                pbooks.poll();
            }
        } else {
            list.add(Math.abs(nbooks.poll())); // 리스트에 음수의 최댓값 추가
            for(int i = 0; i < M - 1; i++) {
                nbooks.poll();
            }
        }

        while(!nbooks.isEmpty()) {
            list.add(2 * Math.abs(nbooks.poll()));
            for(int i = 0; i < M - 1; i++) {
                nbooks.poll();
            }
        }

        while(!pbooks.isEmpty()) {
            list.add(2 * pbooks.poll());
            for(int i = 0; i < M - 1; i++) {
                pbooks.poll();
            }
        }

        int answer = 0;

        for(int i : list) {
            answer += i;
        }

        System.out.println(answer);
    }
}
