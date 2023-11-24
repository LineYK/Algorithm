import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nums = br.readLine().split("");
        
        Arrays.sort(nums);
        
        StringBuilder sb = new StringBuilder();

        Arrays.stream(nums).forEach(t -> sb.append(t));
        
        sb.reverse();

        System.out.println(sb.toString());
    }
}