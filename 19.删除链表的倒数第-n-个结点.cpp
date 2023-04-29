/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* slow = dummyhead;
        ListNode* fast = dummyhead;
        while (n--&& fast != NULL){
            fast = fast->next;
        }
        fast = fast->next;
        while(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummyhead->next;
    }
};
// @lc code=end

