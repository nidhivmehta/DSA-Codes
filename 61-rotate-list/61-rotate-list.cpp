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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==0 || head->next==0 || k==0)
            return head;
        
        ListNode *cur = head;
        int len = 1;
        while(cur->next != 0) {
            cur = cur->next;
            len++;
        }
        
        cur->next = head;
        
        k = k%len;
        int end = len-k;
        
        for(int i=0; i<end; i++){
            cur = cur->next;
        }
        head = cur->next;
        cur->next=NULL;
        
        return head;
        
    }
};