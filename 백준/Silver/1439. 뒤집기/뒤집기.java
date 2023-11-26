import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String oneAndZero = br.readLine();
		long one = Arrays.stream(oneAndZero.split("0")).filter(s -> !s.isEmpty()).count();
		long zero = Arrays.stream(oneAndZero.split("1")).filter(s -> !s.isEmpty()).count();

		System.out.print(Math.min(one, zero));
	}
}