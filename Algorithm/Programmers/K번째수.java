// K번째수 (https://school.programmers.co.kr/learn/courses/30/lessons/42748)

import java.util.Arrays;
import java.util.stream.IntStream;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] res = new int[commands.length];
        int index = 0;

        for (int[] command : commands) {
            int[] slice = IntStream.rangeClosed(command[0], command[1]).map(i -> array[i - 1]).sorted().toArray();
            res[index++] = slice[command[2] - 1];
        }
        return res;
    }

    public int[] solution2(int[] array, int[][] commands) {
        int[] res = new int[commands.length];
        int index = 0;

        for (int[] command : commands) {
            int[] slice = Arrays.copyOfRange(array, command[0] - 1, command[1]);
            Arrays.sort(slice);
            res[index++] = slice[command[2] - 1];
        }
        return res;
    }
}