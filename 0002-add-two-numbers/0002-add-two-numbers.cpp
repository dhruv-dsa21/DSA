
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        while(p||q||carry){
            int ans = 0;
            int val1 = 0,val2 = 0;
               if(p){
                   val1 = p->val;
               }
                
            
                if(q){
                    val2 = q->val;
                }
                
            
            ans = val1 + val2 + carry;
            ListNode* nodex = new ListNode(ans%10);
            carry = ans/10;
            curr->next = nodex;
            curr = curr->next;
            if(p){
                p = p->next;
            }
            if(q){
                q = q->next;
            }
            
        }
        return dummy->next;
    }
};