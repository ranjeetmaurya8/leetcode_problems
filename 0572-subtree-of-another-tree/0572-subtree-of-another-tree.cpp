/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

bool issametree(TreeNode* p, TreeNode* q){
    if(p == NULL ||  q == NULL){
        return p == q;
    }

    return p->val == q->val &&
           issametree(p->left, q->left)&&
           issametree(p->right, q->right); 

}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         if(root == NULL ||  subRoot == NULL){
        return root == subRoot;
    }

        if(root->val == subRoot->val && issametree(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    
    }
};