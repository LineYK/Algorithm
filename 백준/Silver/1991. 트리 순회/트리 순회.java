/*
트리 순회
 
시간 제한   메모리 제한
2 초   128 MB
문제
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.

예를 들어 위와 같은 이진 트리가 입력되면,

전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
가 된다.

입력
첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현한다.

출력
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

예제 입력 1 
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .
예제 출력 1 
ABDCEFG
DBAECFG
DBEGFCA
*/

import java.io.*;
import java.util.*;

public class Main {
  
  static Node[] tree;
  static StringBuilder sb = new StringBuilder();
  
   public static void main(String[] args) throws IOException {
    
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
      int n = Integer.parseInt(br.readLine());
      tree = new Node[n + 1];
      
      for (int i = 0; i < n; i++) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        char rootVal = st.nextToken().charAt(0);
        char leftVal = st.nextToken().charAt(0);
        char rightVal = st.nextToken().charAt(0);
        
        if (tree[rootVal - 'A'] == null) {
          tree[rootVal - 'A'] = new Node(rootVal);
        }
        if (leftVal != '.') {
          tree[leftVal - 'A'] = new Node(leftVal);
          tree[rootVal - 'A'].left = tree[leftVal - 'A'];
        }
        if (rightVal != '.') {
          tree[rightVal - 'A'] = new Node(rightVal);
          tree[rootVal - 'A'].right = tree[rightVal - 'A'];
        }
      }
      preorder(tree[0]);
      sb.append('\n');
      
      inorder(tree[0]);
      sb.append('\n');
      
      postorder(tree[0]);
      
      System.out.print(sb);
   }
   
   static void preorder (Node node) {
     if (node == null) return;
     sb.append(node.val);
     preorder(node.left);
     preorder(node.right);
   }
   
   static void inorder (Node node) {
     if (node == null) return;
     inorder(node.left);
     sb.append(node.val);
     inorder(node.right);
   }
   
   static void postorder (Node node) {
     if (node == null) return;
     postorder(node.left);
     postorder(node.right);
     sb.append(node.val);
   }
   
}

class Node {
    char val;
    Node left;
    Node right;
    
    public Node (char val) {
      this.val = val;
    }
  }