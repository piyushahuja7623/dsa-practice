ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
   int rem;
   int carry = 0;
   int sum = 0;
   
   ListNode* l3 = nullptr;
   ListNode* tail = nullptr;
   
   while(l1 != nullptr || l2 != nullptr || carry)
   {
        int x=y=0;
        if(l1 != nullptr)
        x= l1 -> val;
        if(l2 != nullptr)
        y = l2 -> val;

        sum = x + y + carry;
        rem = sum % 10;
        carry = sum / 10;

        ListNode* newNode = new ListNode(rem);

        if(l3 == nullptr)
        l3 = tail = newNode;
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
        
        if(l1 != nullptr)
        l1= l1 -> next;
        if(l2 != nullptr)
        l2 = l2 -> next;    
   }
   return l3;
}