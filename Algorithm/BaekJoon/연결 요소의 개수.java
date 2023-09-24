// 11724. 연결 요소의 개수 (https://www.acmicpc.net/problem/11724)

import java.io.*;
import java.util.*;

public class Main {
    static List<Integer>[] list;
    static boolean[] visited;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
        list = new ArrayList[n+1];
        visited = new boolean[n+1];
        
        for (int i = 1; i < n + 1; i++) {
            list[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            list[s].add(e);
            list[e].add(s);
        }

        int cnt = 0;
        for (int i = 1; i < n + 1; i++) {
            if (!visited[i]){
                cnt++;
                dfs(i);
            }
        }
        System.out.println(cnt);
	}
    
    static void dfs(int v){
        if (visited[v]) return;
        
        visited[v] = true;
        
        for (int i : list[v]) {
            if (visited[i] == false) {
                  dfs(i);
            }
        }
    }
}