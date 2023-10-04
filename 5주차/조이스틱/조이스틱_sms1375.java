import java.util.*;
import java.io.*;

class Solution {
    public int solution(String name) {   
        HashMap<String, Integer> map = new HashMap<>(){{
            put("A", 0);
            put("B", 1);
            put("C", 2);
            put("D", 3);
            put("E", 4);
            put("F", 5);
            put("G", 6);
            put("H", 7);
            put("I", 8);
            put("J", 9);
            put("K", 10);
            put("L", 11);
            put("M", 12);
            put("N", 13);
            put("O", 12);
            put("P", 11);
            put("Q", 10);
            put("R", 9);
            put("S", 8);
            put("T", 7);
            put("U", 6);
            put("V", 5);
            put("W", 4);
            put("X", 3);
            put("Y", 2);
            put("Z", 1);
        }};
        
        int length = name.length();
        String[] input = name.split("");
        
        int answer = 0;
        int updown = 0;
        int leftright = length - 1;
        
        int next;
        
        for(int i = 0; i < length; i++) {
            updown = updown + map.get(input[i]);
            
            next = i + 1; // 다음 문자 확인
            while(next < length && input[next].charAt(0) == 'A') next++;
            
            leftright = Math.min(leftright, i * 2 + length - next);
            leftright = Math.min(leftright, (length - next) * 2 + i);
        }
        
        answer = updown + leftright;
        return answer;
    }
}
