import java.util.*;
import java.io.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int time = 0;
        int now_bridge = 0;
        boolean once = true;
        
        Queue<Integer> bridge = new LinkedList<>();
        
        for (int truck : truck_weights) {
            while (true) {
                if (once) {
                    bridge.add(truck);
                    now_bridge += truck;
                    time++;
                    once = false;
                    break;
                }
                if (bridge.size() == bridge_length) {
                    now_bridge -= bridge.poll();
                } else if (now_bridge + truck <= weight) {
                    bridge.add(truck);
                    now_bridge += truck;
                    time++;
                    break;
                } else {
                    bridge.add(0);
                    time++;
                }
            }
        }
        
        time = time + bridge_length;
        
        return time;
    }
}
