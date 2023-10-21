// 실패(시간초과)
// 아마 contain부분에서 시간 많이 쓰는듯
import java.util.*;
import java.io.*;

public class Main {
    public static List<Integer>[] friends;
    public static boolean flag;
    public static int count = 0;
    public static List<Integer> list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        friends = new ArrayList[N];

        list = new ArrayList<>();

        for(int i = 0; i < friends.length; i++) { // List배열 선언하고 ArrayList 할당해줘야 함
            friends[i] = new ArrayList<>();
        }

        for(int i = 0; i < M; i++) {
            String[] input2 = br.readLine().split(" ");
            int A = Integer.parseInt(input2[0]);
            int B = Integer.parseInt(input2[1]);

            friends[A].add(B);
            friends[B].add(A);
        }

        for(int i = 0; i < N; i++) {
            isFriend(i, 0);
            list.clear();
        }

        if(flag) System.out.println("1");
        else System.out.println("0");

//        for (int i = 0; i < friends.length; i++) {
//            System.out.println("List " + i + ": " + friends[i]);
//        }
    }

    public static void isFriend(int f, int count) {
        for(int i = 0; i < friends[f].size(); i++) {
            list.add(f);
            if(count == 4) {
                flag = true;
                return;
            }
            if(!list.contains(friends[f].get(i))) // 이전에 갔던 곳으로 가면 안됨
            {
//                list.add(friends[f].get(i));
                isFriend(friends[f].get(i), count + 1);
            }
        }
    }
}

// 성공
// 리스트 확인하는 시간 >>>>> 배열 확인하는 시간
import java.util.*;
import java.io.*;

public class Main {
    public static List<Integer>[] friends;
    public static boolean flag;
    public static List<Integer> list;
    public static boolean[] check;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        friends = new ArrayList[N];

        list = new ArrayList<>();

        check = new boolean[N];

        for(int i = 0; i < friends.length; i++) { // List배열 선언하고 ArrayList 할당해줘야 함
            friends[i] = new ArrayList<>();
        }

        for(int i = 0; i < M; i++) {
            String[] input2 = br.readLine().split(" ");
            int A = Integer.parseInt(input2[0]);
            int B = Integer.parseInt(input2[1]);

            friends[A].add(B);
            friends[B].add(A);
        }

        for(int i = 0; i < N; i++) {
            isFriend(i, 0);
            Arrays.fill(check, false);
        }

        if(flag) System.out.println("1");
        else System.out.println("0");
    }

    public static void isFriend(int f, int count) {
        for(int i = 0; i < friends[f].size(); i++) {
            check[f] = true;
            if(count == 4) {
                flag = true;
                return;
            }
            if(!check[friends[f].get(i)]) isFriend(friends[f].get(i), count + 1);
            check[f] = false; // 백트래킹
        }
    }
}
