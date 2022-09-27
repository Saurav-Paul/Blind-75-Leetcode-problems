//https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        ListNode *fast = head ;
        fast = fast->next ;
        
        while(head != NULL and fast!= NULL and fast->next != NULL){
            if(head == fast) return true;
            head = head->next ;
            fast = fast->next->next ;
        }
        
        return false;
    }
};
