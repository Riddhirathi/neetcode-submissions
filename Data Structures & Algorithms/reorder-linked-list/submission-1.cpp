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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        ListNode* prev = slow->next = nullptr;
        while(mid){
            ListNode* tmp = mid->next;
            mid->next = prev;
            prev = mid;
            mid = tmp;
        }
        ListNode* first = head;
        mid = prev;
        while(mid){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = mid->next;
            first->next = mid;
            mid->next = tmp1;
            first = tmp1;
            mid = tmp2;
        }
    }
};
