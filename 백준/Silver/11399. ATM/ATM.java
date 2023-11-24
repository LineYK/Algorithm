import java.io.*;
import java.util.*;

public class Main{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		int[] nums = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).sorted().toArray();
		
		int sum = Arrays.stream(nums).sum();
		int res = sum;
		
		for(int i = n-1; i >= 0; i--){
			sum -= nums[i];
			res += sum;
		}

		System.out.print(res);
	}
}