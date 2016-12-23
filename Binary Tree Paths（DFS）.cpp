/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> path;
        string out ="";
        FindPath(root,path,out);   //DFS
        return path;
    }
    
   void FindPath(TreeNode *root,vector<string> &path,string out)
   {
         if(root == NULL)
         {
             return;
         }
         out = out + to_string(root->val);
       if(root->left == NULL && root->right == NULL)
       {
           path.push_back(out);
          
           return;
       }
     
       out = out  + "->";
       FindPath(root->left,path,out);
       FindPath(root->right,path,out);
       
   }
};