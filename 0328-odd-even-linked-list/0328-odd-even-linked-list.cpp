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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL){
            return head;
        }
        ListNode *temp = head;
        bool flag = false;
        ListNode*dummy = new ListNode(0);
        ListNode *curr = dummy;
        curr->next = head;
        int count = 1;
        while(temp->next!=NULL){
            temp = temp->next;
            count++;
        }
        int i = 0;
        while(curr->next!=NULL&&i<count){
            if(flag==true){
                 ListNode *x = curr->next;
                curr->next = curr->next->next;
               temp->next = x;
                x->next = NULL;
                temp = x;
                flag = false;
            }else{
                curr = curr->next;
                flag = true;
            }
            i++;
        }
        return dummy->next;
        
    


    }
};