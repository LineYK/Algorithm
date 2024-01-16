/*
380. 삽입 삭제 GetRandom O(1) 삽입

RandomizedSet 클래스를 구현합니다:

RandomizedSet() - RandomizedSet 객체를 초기화합니다.

void insert(int val) - 항목이 존재하지 않으면 세트에 항목 값을 삽입합니다. 항목이 존재하지 않으면 참을 리턴하고, 그렇지 않으면 거짓을 리턴합니다.

void remove(int val) - 아이템이 존재할 경우 세트에서 아이템 값을 제거합니다. 아이템이 존재하면 참을 리턴하고, 그렇지 않으면 거짓을 리턴합니다.

int getRandom() - 현재 요소 집합에서 임의의 요소를 리턴합니다 (이 메서드가 호출될 때 적어도 하나의 요소가 존재한다는 것은 보장됩니다). 각 요소는 반환될 확률이 동일해야 합니다.
각 함수가 평균 O(1) 시간 복잡도로 작동하도록 클래스의 함수를 구현해야 합니다.



예제 1:
Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[널, 참, 거짓, 참, 2, 참, 거짓, 2]

설명
랜덤화셋 랜덤화셋 = 새로운 랜덤화셋();
randomizedSet.insert(1); // 집합에 1을 삽입합니다. 1이 성공적으로 삽입되면 참을 반환합니다.
randomizedSet.remove(2); // 2가 집합에 존재하지 않으므로 false를 반환합니다.
randomizedSet.insert(2); // 세트에 2를 삽입하고 참을 반환합니다. 이제 Set에 [1,2]가 포함됩니다.
randomizedSet.getRandom(); // getRandom()은 무작위로 1 또는 2를 반환해야 합니다.
randomizedSet.remove(1); // 집합에서 1을 제거하고 참을 반환합니다. 이제 세트에 [2]가 포함됩니다.
randomizedSet.insert(2); // 2가 이미 집합에 있으므로 false를 반환합니다.
randomizedSet.getRandom(); // 2가 집합에 있는 유일한 숫자이므로 getRandom()은 항상 2를 반환합니다.


제약 조건:
-2^31 <= val <= 2^31 - 1
삽입, 제거, getRandom을 최대 2 * 105번 호출합니다.
getRandom이 호출될 때 데이터 구조에 적어도 하나의 요소가 있을 것입니다.
*/

class RandomizedSet {
    private Set<Integer> set;

    public RandomizedSet() {
        set = new HashSet<>();
    }
    
    public boolean insert(int val) {
        return set.add(val);
    }
    
    public boolean remove(int val) {
        return set.remove(val);
    }
    
    public int getRandom() {
        int idx = 0;
        int[] arr = new int[set.size()];
        for (int n : set) {
            arr[idx++] = n;
        }
        return arr[(int) (Math.random() * arr.length)];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */