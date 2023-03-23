//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        
         
              Node *dummy = new Node(0);
         Node *curr = dummy;
         curr->next = head;
         bool flag = false;
         Node *p2 = curr,*p1=head;
         
         while(p2->next!=NULL){
             if((p2->next->data)%2==0){
                
                 flag = true;
             }
           
             p2 = p2->next;
            
         }
         
         if(flag==false){
             return head;
         }
         
      int x = 0;
      while(curr!=NULL&&x<N){
             if((curr->next->data)%2!=0&&curr->next->next!=NULL){
                 Node *p = new Node(curr->next->data);
                 curr->next = curr->next->next;
                 p2->next = p;
                 p2 = p;
                
                 
             }else{
                 curr = curr->next;
             }
             x++;
         }
         return dummy->next;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends