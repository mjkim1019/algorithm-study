import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();

        String boom = br.readLine();

        StringBuilder str = new StringBuilder();

        for(char c : input.toCharArray()) {
            str.append(c);

            int length = str.length();
            if(length >= boom.length() && str.substring(length - boom.length()).equals(boom)) {
                str.setLength((length - boom.length()));
            }
        }

        if(str.length() == 0) System.out.println("FRULA");
        else System.out.println(str);
    }
}
