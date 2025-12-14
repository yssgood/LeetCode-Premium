/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    // class Pair{
    //     TreeNode node; 
    //     int index; 
    //     public Pair(TreeNode node, int index){
    //         node = node;
    //         index = index; 
    //     }
    // }
    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> answer = new ArrayList<>(); 
        if(root == null) return answer; 
        Map<Integer, List<Integer>> hashMap = new HashMap<>(); 
        Queue<Pair<TreeNode, Integer>> q = new LinkedList<>(); 
        q.add(new Pair(root, 0)); 

        int minCol = 0; 
        int maxCol = 0; 
        
        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Pair<TreeNode,Integer> p = q.poll(); 
                TreeNode curr = p.getKey(); 
                int index = p.getValue(); 
                hashMap.computeIfAbsent(index, k -> new ArrayList<>()).add(curr.val); 

                minCol = Math.min(minCol, index); 
                maxCol = Math.max(maxCol, index); 
                if(curr.left != null){
                    q.add(new Pair(curr.left, index - 1)); 
                }
                if(curr.right != null){
                    q.add(new Pair(curr.right, index + 1)); 
                }
            }
        }

        for(int i = minCol; i <= maxCol; i++){
            answer.add(hashMap.get(i)); 
        }

        return answer; 
    }
}