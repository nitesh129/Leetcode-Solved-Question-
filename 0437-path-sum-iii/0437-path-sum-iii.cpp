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
    void solve(TreeNode* root , int &k,long long currsum ,unordered_map<long long , int>&mpp,int &count){
        if(!root) return ;
        currsum+=root->val;
        if(mpp.count(currsum-k)){
            count+=mpp[currsum-k];
        }
        mpp[currsum]++;
        solve(root->left , k , currsum , mpp,count);
        solve(root->right , k , currsum , mpp,count);
        mpp[currsum]--;

    }
    int pathSum(TreeNode* root, int targetSum) {
        int count =0;
        unordered_map<long long , int>mpp;
        mpp[0]=1;
        solve(root,targetSum,0,mpp,count);
        return count;
    }
};