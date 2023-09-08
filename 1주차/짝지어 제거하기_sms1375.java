import java.util.*;

class Solution
{
    public int solution(String s) {
        int answer = -1;
        Stack<Character> stk = new Stack<>();
        
        for(char c : s.toCharArray()) {
            if(!stk.isEmpty() && stk.peek() == c)
                stk.pop();
            else
                stk.push(c);
        }
        if(stk.isEmpty())
            answer = 1;
        else
            answer = 0;
        return answer;
    }
}
