import java.util.*;
import java.io.*;

class Solution {
    public int solution(int N, int number) {
        List<Integer>[] count = new ArrayList[9];
        
        for(int i = 0; i < count.length; i++) {
            count[i] = new ArrayList<>();
        }
        
        count[1].add(N);
        
        for(int i = 2; i <= 8; i++) {
            for(int j = 1; j < i; j++) {
                for(Integer k : count[j]) {
                    for(Integer l : count[i - j]) {
                        count[i].add(k + l);
                        count[i].add(k - l);
                        count[i].add(k * l);
                        if(l != 0) count[i].add(k / l);
                    }
                }
            }
            
            int temp = N;
            for(int j = 1; j < i; j++) {
                temp *= 10;
                temp += N;
            }
            count[i].add(temp);
        }
        
        for(int i = 1; i <= 8; i++) {
            if(count[i].contains(number)) return i;
        }
        
        return -1;
    }
}
