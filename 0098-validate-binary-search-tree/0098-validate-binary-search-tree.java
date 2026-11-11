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
class Pair{
    long min;
    long max;
    Pair(long max,long min){
        this.max=max;
        this.min=min;
    }
 }
class Solution {
    boolean flag=true;
    public boolean isValidBST(TreeNode root) {
        traverse(root);
        return flag;
    }
    Pair traverse(TreeNode root){
        if(root==null)return new Pair(Long.MIN_VALUE,Long.MAX_VALUE);
        Pair lst= traverse(root.left);
        Pair rst= traverse(root.right);
        if(lst.max >= root.val ||rst.min <= root.val)flag=false;
        long mx= Math.max((root.val),Math.max(lst.max ,rst.max));
        long mn= Math.min((root.val),Math.min(lst.min,rst.min));
        return new Pair(mx,mn);
    }
}