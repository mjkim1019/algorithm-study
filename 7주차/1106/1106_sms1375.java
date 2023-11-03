// 실패
// 왜 안되는지 모르겠음
// 가장 효율이 높은 걸로 채우다가 마지막 남은 부분은 하나씩 넣어보면서 비교
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int C = Integer.parseInt(input[0]);
        int N = Integer.parseInt(input[1]);

        int[] cost = new int[N];
        Double[] ppc = new Double[N]; // people per cost

        int max_index = -1;
        double max_ppc = 0;

        for(int i = 0; i < N; i++) {
            String[] input2 = br.readLine().split(" ");

            cost[i] = Integer.parseInt(input2[0]);
            ppc[i] = Double.parseDouble(input2[1]) / cost[i];

            if(max_ppc < ppc[i]) {
                max_ppc = ppc[i];
                max_index = i;
            }
        }

        int pay = 0;

        int max_count = (int) (C / (cost[max_index] * ppc[max_index]));

        pay = cost[max_index] * max_count;

        int rest = C - max_count * (int)(cost[max_index] * ppc[max_index]);

        if(rest == 0) {
            System.out.println(pay);
            System.exit(0);
        }

        int count;
        int min_cost = Integer.MAX_VALUE;
        int temp_people;
        int temp_cost;

        for(int i = 0; i < N; i++) {
            count = 1;
            temp_people = (int)(cost[i] * ppc[i]) * count;
            temp_cost = cost[i] * count;

            while(rest > temp_people) {
                count++;
                temp_people = (int)(cost[i] * ppc[i]) * count;
                temp_cost = cost[i] * count;
            }

            // min_cost 찾기
            if(min_cost > temp_cost) {
                min_cost = temp_cost;
            }
        }

        System.out.println(pay + min_cost);
    }
}

// 실패 진짜 왜 안되는지 모르겠음
// int max_index = -1 부분에서 오류가 발생하는지 왜인지 진짜 모름 그 밑 코드에서 for문을 반드시 돌기 때문에 index가 갱신되어서 오류가 발생하면 안되는데...
import java.util.*;
import java.io.*;

public class Main {
    public static class City implements Comparable<City> {
        int cost;
        int people;
        double ppc; // people per cost
        int addCost;

        City(int cost, int people) {
            this.cost = cost;
            this.people = people;
            this.ppc = people / cost;
        }

        public int compareTo(City o) {
            return this.addCost - o.addCost;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int C = Integer.parseInt(input[0]);
        int N = Integer.parseInt(input[1]);

        List<City> list = new ArrayList<>();

        for(int i = 0; i < N; i++) {
            String[] input2 = br.readLine().split(" ");

            City city = new City(Integer.parseInt(input2[0]), Integer.parseInt(input2[1]));

            list.add(city);
        }

        double max_ppc = Double.MIN_VALUE;
        int max_index = 0;

        for(int i = 0; i < N; i++) {
            City city = list.get(i);
            if(max_ppc < city.ppc) {
                max_ppc = city.ppc;
                max_index = i;
            }
        }

        int pay = 0;

        int max_count = (int) (C / list.get(max_index).people);

        pay = list.get(max_index).cost * max_count;

        int rest = C - max_count * (int) list.get(max_index).people;

        if(rest == 0) {
            System.out.println(pay);
            System.exit(0);
        }

        for(int i = 0; i < N; i++) {
            City city = list.get(i);

            int temp_rest = rest;
            int count = 0;

            while(temp_rest > 0) {
                temp_rest -= city.people;
                count++;
            }
            list.get(i).addCost = count * city.cost;
        }

        Collections.sort(list);

        System.out.println(pay + list.get(0).addCost);
    }
}
