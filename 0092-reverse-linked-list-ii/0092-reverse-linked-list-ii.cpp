/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverseBetween(ListNode *head, int left, int right)
        {
            ListNode *temp = head;
            ListNode *before = head, *first = head;
            ListNode *prev, *curr, *nex;
            int n = 1;
            int count = right - left + 1;
            
            if(head==NULL||head->next==NULL){
                return head;
            }
            if(left==1){
                prev = head;
                curr = head->next;
                nex = curr;
                 int i = 0;
                    while (i < count-1)
                    {
                        nex = curr->next;
                        curr->next = prev;
                        prev = curr;
                        curr = nex;
                        i++;
                    }
                before->next = curr;
                return prev;
                
            }
            while (temp != NULL)
            {   
                
                if (n+1 == left)
                {
                    before = temp;
                    prev = before->next;
                    first = prev;
                    curr = prev->next;
                    nex = curr;
                    
                    int i = 0;
                    while (i < count-1)
                    {
                        nex = curr->next;
                        curr->next = prev;
                        prev = curr;
                        curr = nex;
                        i++;
                    }
                    break;
                }
                n++;
                temp = temp->next;
                
            }
            before->next = prev;
            first->next = curr;
            
            
          

            return head;
        }
};