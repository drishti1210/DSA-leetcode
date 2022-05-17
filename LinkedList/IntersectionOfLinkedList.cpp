class Solution {
public:
    int lengthofList(ListNode* tempA){
      if(tempA==NULL)
          return 0;
      int sum=1;
        while(tempA->next !=NULL){
            tempA=tempA->next;
            sum++;
        }
        return sum;
        
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* tempA =headA;
        ListNode* tempB =headB;
        if(tempA== tempB)
            return tempA;
      int lenA = lengthofList(tempA);
     int lenB = lengthofList(tempB);
        cout<<lenA<<endl;
        cout<<lenB;
        
         if(lenA> lenB){
             int diff = lenA- lenB;
             while(diff){
                 tempA= tempA->next;
                 diff--;
             }
         }
        else{
            int diff = lenB-lenA;
              while(diff){
                 tempB= tempB->next;
                 diff--;
             }
        }
        
        while(tempA!= tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
     
        
        
    }
};