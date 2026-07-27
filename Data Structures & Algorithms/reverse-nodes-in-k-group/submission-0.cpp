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
    ListNode* getk(ListNode* head, int k) {
        while(head && k>0){
            head = head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* grpPrev = dummy;
        while(true){
            ListNode* kth = getk(grpPrev, k);
            if(!kth) break;
            ListNode* grpNext = kth->next;
            ListNode* prev = kth->next;
            ListNode* cur = grpPrev->next;
            while(cur!=grpNext){
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }
            ListNode* tmp = grpPrev->next;
            grpPrev->next = kth;
            grpPrev = tmp;
        }
        return dummy->next;
    }
};
