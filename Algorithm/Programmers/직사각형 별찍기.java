// 직사각형 별찍기 (https://school.programmers.co.kr/learn/courses/30/lessons/12969)

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < a; i++) 
            sb.append("*");
        String line = sb.toString();
        for (int i = 0; i < b-1; i++) 
            sb.append("\n" + line);
        
        System.out.print(sb.toString());
    }
}