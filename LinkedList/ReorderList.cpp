class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return ;
        ListNode* slow= head;
        ListNode* fast= head;
        stack<ListNode*> st;
        while( fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast = fast->next->next;
        }
        ListNode* n;
        
        if(fast!=NULL){
            n= slow->next;
            
        }
        else n= slow;
        
        while(n!=NULL){
           st.push(n);
            n= n->next;
            
        }
        fast= head;
        
        while(st.size()){
          
        n = fast->next; 
            fast->next= st.top();
            st.top()->next =n;
            fast=n;
                st.pop();
            
        }
       slow->next= NULL;
        
        
    }
};







