import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++) {
            String str = br.readLine();
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            str = new String(chars);
            List<String> anagrams = getAnagram(str);

            for (String anagram : anagrams) {
                System.out.println(anagram);
            }
        }

    }

    public static List<String> getAnagram(String str) {
        List<String> anagrams = new ArrayList<>();
        generateAnagram(anagrams, str.toCharArray(), 0);
        return anagrams;
    }

    private static void generateAnagram(List<String> anagrams, char[] chars, int index) {
        if(index == chars.length - 1) {
            anagrams.add(new String(chars));
        } else{
            for(int i = index; i < chars.length; i++) {
                if(i != index && chars[i] == chars[index]) {
                    continue;
                }
                swap(chars, index, i);
                generateAnagram(anagrams, Arrays.copyOf(chars, chars.length), index + 1);
            }
        }
    }

    private static void swap(char[] chars, int i, int j) {
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }
}
