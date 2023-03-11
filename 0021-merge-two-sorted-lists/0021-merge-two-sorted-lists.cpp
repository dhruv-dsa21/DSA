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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        ListNode* p = list1;
        ListNode* q = list2;
      
        while(p&&q){
            int value1 = p->val;
            int value2 = q->val;
             
             if(value1<value2){
                curr->next = p;
                p = p->next;
            }else{
                curr->next = q;
                q = q->next;
            }
            curr = curr->next;   
        }
       if(p){
           curr->next = p;
       }
        if(q){
            curr->next = q;
        }
        
        return dummy->next;
        
    }
};