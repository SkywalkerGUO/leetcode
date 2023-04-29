/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstdlib>

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != 0){
            lenA++;
            curA = curA->next;
        }
        while (curB != 0){
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        int d = 0;
        d = abs(lenA - lenB);
        if(lenA < lenB) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        while (d--) {
            curA = curA->next;
        }
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;


    }
};
// @lc code=end

