/* -----------------------------------
 *  WARNING:
 * -----------------------------------
 *  Your code may fail to compile
 *  because it contains public class
 *  declarations.
 *  To fix this, please remove the
 *  "public" keyword from your class
 *  declarations.
 */
import java.io.*;
import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }

    public String toString(){
        return val+"";
    }
}

class Solution {
    private int K;
    public ListNode reverseKGroup(ListNode head, int k) {
        this.K=k;
        return solve(head);
    }
    
    private ListNode solve(ListNode head){
        ListNode[] bottoms=hook(head, K);
        // print(bottoms[0], bottoms[1]);
        if (bottoms[1]!=null){
            head.next=solve(bottoms[1]);
            return bottoms[0];
        }return head;
    }
    
    private ListNode[] hook(ListNode pre, int rest){
        if (pre==null) return new ListNode[]{null, null};
        if (rest==1) return new ListNode[]{null, pre.next};
        ListNode node=pre.next;
        ListNode[] bottoms=hook(node, rest-1);
        if (bottoms[1]!=null)
            node.next=pre;
        if (bottoms[1]!=null && bottoms[0]==null)
            bottoms[0]=node;
        return bottoms;
    }
    
    private static void print(Object...obj){
        System.out.println(Arrays.deepToString(obj));
    }
}

public class MainClass {
    public static int[] stringToIntegerArray(String input) {
        input = input.trim();
        input = input.substring(1, input.length() - 1);
        if (input.length() == 0) {
          return new int[0];
        }
    
        String[] parts = input.split(",");
        int[] output = new int[parts.length];
        for(int index = 0; index < parts.length; index++) {
            String part = parts[index].trim();
            output[index] = Integer.parseInt(part);
        }
        return output;
    }
    
    public static ListNode stringToListNode(String input) {
        // Generate array from the input
        int[] nodeValues = stringToIntegerArray(input);
    
        // Now convert that list into linked list
        ListNode dummyRoot = new ListNode(0);
        ListNode ptr = dummyRoot;
        for(int item : nodeValues) {
            ptr.next = new ListNode(item);
            ptr = ptr.next;
        }
        return dummyRoot.next;
    }
    
    public static String listNodeToString(ListNode node) {
        if (node == null) {
            return "[]";
        }
    
        String result = "";
        while (node != null) {
            result += Integer.toString(node.val) + ", ";
            node = node.next;
        }
        return "[" + result.substring(0, result.length() - 2) + "]";
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = in.readLine()) != null) {
            ListNode head = stringToListNode(line);
            line = in.readLine();
            int k = Integer.parseInt(line);
            
            ListNode ret = new Solution().reverseKGroup(head, k);
            
            String out = listNodeToString(ret);
            
            System.out.print(out);
        }
    }
}
