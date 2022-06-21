//###################### REVERSE LINKED LIST ################
//-----------------------------------------------------------
// Given the head of a singly linked list, reverse the list, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
// Example 2:


// Input: head = [1,2]
// Output: [2,1]
// Example 3:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in the list is the range [0, 5000].
// -5000 <= Node.val <= 5000
 
//ITERATIVE METHOD
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* curr = head;
        ListNode* prev= NULL;
        ListNode* next;
        while(curr!=NULL){
            next=curr->next ;
            curr->next= prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};
 
 //Recursive 

 class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) {
            return head;
        }
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node;
    }
};