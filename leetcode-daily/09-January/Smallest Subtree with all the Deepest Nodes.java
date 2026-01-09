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

    public List<TreeNode> bfs(TreeNode root){

        List<TreeNode> ans = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while(!q.isEmpty()){
            int sz = q.size();

            for(int i=0;i<sz;i++){
                TreeNode curr = q.poll();
                ans.add(curr);
                if(curr.left!=null)q.offer(curr.left);
                if(curr.right!=null)q.offer(curr.right);
            }
            if(!q.isEmpty())ans.clear();
        }
        return ans;
    }
    public TreeNode lca(TreeNode root,TreeNode p,TreeNode q){
        if(root==null || p==root || q==root)return root;

        TreeNode l = lca(root.left,p,q);
        TreeNode r = lca(root.right,p,q);

        if(l==null)return r;
        else if(r==null)return l;
        return root;
    }
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        
        List<TreeNode> leaf = bfs(root);

        TreeNode curr = leaf.get(0);
        curr=lca(root,curr,leaf.get(leaf.size()-1));
        return curr;
    }
}