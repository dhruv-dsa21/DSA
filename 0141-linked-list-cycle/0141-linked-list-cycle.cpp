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
        
        unordered_map<ListNode* ,int>mp;
        while(head!=NULL){
            if(mp[head]==0){
                 mp[head]++;
                head = head->next;
            }else{
                return true;
            }
           
        }
        return false;
        
    }
};