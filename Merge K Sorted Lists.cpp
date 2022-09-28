//https://leetcode.com/problems/merge-k-sorted-lists/
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

    ListNode* merge(ListNode* v1, ListNode* v2){
        if(v1 == NULL) return v2;
        if(v2 == NULL) return v1;
        
        if(v1->val > v2->val) swap(v1,v2) ;
        
        ListNode* mergedList = v1;
        
        while(v1 != NULL and v2 != NULL){
            ListNode *temp = NULL;
            
            while(v1 != NULL and v1->val <= v2->val){
                temp = v1;
                v1 = v1->next ;
            }
            
            v1 = temp->next ;
            temp->next = v2;
            v2 = temp;
            swap(v1,v2) ;
        }
        
        return mergedList ;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* mergedList = NULL;
        
        for(auto x : lists){
            mergedList = merge(mergedList, x) ;
        }
        
        return mergedList;
    }
};
