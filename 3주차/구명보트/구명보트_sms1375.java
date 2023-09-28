import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        Arrays.sort(people);
		
        int min = 0;
        int max = people.length - 1;

        while(max >= min) {
            if(people[max] + people[min] <= limit) {
                answer++;
                max--;
                min++;
            }
            else {
                answer++;
	            max--;
            }
        }
        return answer;
    }
}
