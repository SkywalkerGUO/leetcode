/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start
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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        if (postorder.size()==0) return NULL;
        //后序遍历最后一个元素是中间节点
        int rootval = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(rootval);

        //叶子节点
        if (postorder.size() == 1) return root;

        //中序遍历的切割点
        int inorder_cut;
        for(inorder_cut = 0; inorder_cut< inorder.size(); inorder_cut++){
            if (inorder[inorder_cut]==rootval) break;
        }
        //切中序
        vector<int> leftinorder(inorder.begin(), inorder.begin()+inorder_cut);
        vector<int> rightinorder(inorder.begin()+inorder_cut+1, inorder.end() );
        postorder.pop_back();
        //切后序
        vector<int> leftpostorder(postorder.begin(), postorder.begin() + leftinorder.size());
        vector<int> rightpostorder(postorder.begin() + leftinorder.size(), postorder.end());

        root->left = traversal(leftinorder, leftpostorder);
        root->right = traversal(rightinorder, rightpostorder);

        return root;


    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()==0 || postorder.size()==0) return NULL;
        return traversal(inorder, postorder);
    }
};
// @lc code=end

