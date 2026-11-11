# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        temp = head
        cnt = 0
        if not head:
            return None
        while temp:
            temp = temp.next
            cnt+=1
        k = cnt-n+1
        if k==1:
            return head.next
        temp = head
        while (k-2):
            temp = temp.next
            k-=1
        temp.next = temp.next.next
        return head