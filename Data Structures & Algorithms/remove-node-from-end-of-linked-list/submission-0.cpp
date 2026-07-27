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

        int cnt = 0;
        ListNode* cur = head;

        while(cur){
            cnt++;
            cur = cur->next;
        }

        // Delete the head
        if(cnt == n){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int steps = cnt - n;

        cur = head;

        while(steps > 1){
            cur = cur->next;
            steps--;
        }

        cur->next = cur->next->next;

        return head;
    }
};
