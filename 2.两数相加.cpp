/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curA = l1;
        ListNode* curB = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        int carry = 0;
        while(curA != NULL || curB != NULL||carry > 0){
            int val = carry;
            if (curA != NULL) {
                val += curA->val;
                curA = curA->next;
            }
            if (curB != nullptr) {
                val += curB->val;
                curB = curB->next;
            }
            // 处理进位情况
            carry = val / 10;
            val = val % 10;
            p->next = new ListNode(val);
            p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end

