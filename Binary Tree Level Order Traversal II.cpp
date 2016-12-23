/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/
/*这个跟前面的那个题很像，可以按之前的那种方式遍历，最后将数组反置就行*/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        queue<TreeNode *> qlist;
        vector<vector<int>> v1;
        if(root == NULL)
        {
            return v1;
        }
        
        qlist.push(root);
        
        while(!qlist.empty())
        {
            int size = qlist.size();
            vector<int> level;
            for(int i = 0; i< size;i++)
            {
                TreeNode *temp = qlist.front();
                qlist.pop();
                level.push_back(temp->val);
                if(temp->left != NULL)
                {
                    qlist.push(temp->left);
                }
                if(temp->right != NULL)
                {
                    qlist.push(temp->right);
                }
                
            }
            v1.push_back(level);
        }
        std::reverse(v1.begin(),v1.end());
        
        return v1;
    }
};