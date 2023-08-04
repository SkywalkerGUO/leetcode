/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> que;
        if(root!=NULL) que.push(root);
        int depth = 0;
        while (!que.empty()){
            int size = que.size();
            depth ++;
            for (int i = 0; i<size; i++){
                Node* node = que.front();
                que.pop();
                for (int j = 0; j<node->children.size(); j++){
                    if (node->children[j]) que.push(node->children[j]);

                }

            }
        }
        return depth;
    }
};
// @lc code=end

