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
    int maxLevelSum(TreeNode* root) {
        int level=0;
        int count =1;
        int maxi_sum = INT_MIN;
        int sum=0;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int N = que.size();
            sum=0;
            while(N--){
                TreeNode* curr = que.front();
                que.pop();
                sum+=curr->val;
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            if(sum>maxi_sum){
                maxi_sum = sum;
                level = count;
            }
            count++;
        }
        return level;
    }
};