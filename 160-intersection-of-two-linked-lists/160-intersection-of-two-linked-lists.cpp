/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;	
        ListNode *ptr2 = headB;
        int len1=0, len2=0;	

        while(ptr1) {
            len1++;
            ptr1=ptr1->next;
        }
        while(ptr2) {
            len2++;
            ptr2=ptr2->next;
        }
        ptr1=headA;	
        ptr2=headB;

        int diff = abs(len1-len2);

        if(len1>len2) {		
            for(int i=0; i<diff; i++)
                ptr1=ptr1->next;
        }
        else {
            for(int i=0; i<diff; i++)
                ptr2=ptr2->next;
        }

        while(ptr1!=NULL) {
            if(ptr1 == ptr2)
                return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};