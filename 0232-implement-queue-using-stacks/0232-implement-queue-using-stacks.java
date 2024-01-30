/*
232. 스택을 사용하여 큐 구현하기

두 개의 스택만 사용하여 선입선출(FIFO) 큐를 구현하세요. 
구현된 큐는 일반 큐의 모든 기능(푸시, peek, 팝, 비우기)을 지원해야 합니다.

MyQueue 클래스를 구현합니다:

void push(int x) 요소 x를 큐의 뒤쪽으로 밀어 넣습니다.
int pop() 큐의 앞쪽에서 요소를 제거하여 반환합니다.
int peek() 큐의 앞쪽에 있는 엘리먼트를 리턴합니다.
boolean empty() 큐가 비어 있으면 참을, 그렇지 않으면 거짓을 반환합니다.

참고:
스택의 표준 연산만 사용해야 합니다. 즉, 맨 위로 밀어넣기, 맨 위에서 엿보기/팝업, 크기, 비어 있음 연산만 유효합니다.
사용 중인 언어에 따라 스택이 기본적으로 지원되지 않을 수 있습니다. 스택의 표준 연산만 사용하는 한 목록 또는 deque(양방향 큐)를 사용하여 스택을 시뮬레이션할 수 있습니다.
 

예제 1:
입력
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[널, 널, 널, 널, 1, 1, 거짓]

설명
내 큐 내 큐 = 새로운 내 큐();
myQueue.push(1); // 대기열은: [1]
myQueue.push(2); // 큐는: [1, 2] (가장 왼쪽이 큐의 앞쪽)
myQueue.peek(); // 반환 1
myQueue.pop(); // 1을 반환하고, 큐는 [2]입니다.
myQueue.empty(); // false 반환
 

제약 조건:

1 <= x <= 9
푸시, 팝, 피크, 비우기를 최대 100번 호출할 수 있습니다.
팝과 피크에 대한 모든 호출은 유효합니다.
 

후속 질문: 각 작업의 시간 복잡도가 O(1)이 되도록 큐를 구현할 수 있을까요? 즉, n개의 연산을 수행하면 그 중 하나의 연산이 더 오래 걸리더라도 전체적으로는 O(n)의 시간이 소요됩니다.
*/

class MyQueue {

    private Deque<Integer> inStack;
    private Deque<Integer> outStack;

    public MyQueue() {
        inStack = new ArrayDeque<>();
        outStack = new ArrayDeque<>();
    }
    
    public void push(int x) {
        inStack.push(x);
    }
    
    public int pop() {
        peek();
        return outStack.pop();
    }
    
    public int peek() {
        if(outStack.isEmpty())
            while(!inStack.isEmpty())
                outStack.push(inStack.pop());
        return outStack.peek();
    }
    
    public boolean empty() {
        return inStack.isEmpty() && outStack.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */