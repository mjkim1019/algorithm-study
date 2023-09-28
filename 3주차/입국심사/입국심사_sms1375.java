import java.util.*;
import java.io.*;

class Solution {
    public long solution(int n, int[] times) {
        long answer = Long.MAX_VALUE;
        
        int examiner = times.length;
        
        Arrays.sort(times);
        
        long maxTime = (long)times[examiner - 1] * n;
        long minTime = 0;
        
        long averageTime;
        long sum = 0;
        
        while(minTime <= maxTime) {
            averageTime = (minTime + maxTime) / 2;
            sum = 0;
            for(int time : times) sum = sum + averageTime / time;
            
            if(sum >= n) {
                answer = Math.min(answer, averageTime);
                maxTime = averageTime - 1;
            } else {
                minTime = averageTime + 1;
            }
        }
        
        return answer;
    }
}
