// 비밀지도 (https://school.programmers.co.kr/learn/courses/30/lessons/17681)

class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        for (int i = 0; i < n; i ++) {
            String bin = Integer.toBinaryString(arr1[i] | arr2[i]);
            if (bin.length() != n) {
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < n-bin.length(); j++) 
                    sb.append(0);
                sb.append(bin);
                bin = sb.toString();
            }
            answer[i] = bin.replaceAll("1", "#").replaceAll("0", " ");
        }
        return answer;
    }

    public String[] solution2(int n, int[] arr1, int[] arr2) {
        String[] result = new String[n];
        for (int i = 0; i < n; i++) {
            result[i] = Integer.toBinaryString(arr1[i] | arr2[i]);
        }

        for (int i = 0; i < n; i++) {
            result[i] = String.format("%" + n + "s", result[i]);
            result[i] = result[i].replaceAll("1", "#");
            result[i] = result[i].replaceAll("0", " ");
        }

        return result;
    }
}