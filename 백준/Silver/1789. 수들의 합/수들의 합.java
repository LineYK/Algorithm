import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        
        long res = 1;
        
        while(res * (res+1)/2 <= n) res++;
        
        System.out.print(res -1);
    }
}