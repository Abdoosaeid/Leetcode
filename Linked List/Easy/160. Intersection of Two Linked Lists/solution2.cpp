/*
* Author: Abdoo__said
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Initialize two pointers to the heads of the linked lists
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        // Iterate until either the pointers meet (intersection) or both reach the end
        while(temp1 != temp2){
            // Move both pointers to the next node
            temp1 = temp1->next;
            temp2 = temp2->next;

            // Check for intersection
            if(temp1 == temp2){
                return temp1;
            }

            // If one pointer reaches the end, reset it to the head of the other list
            if(temp2 == NULL){
                temp2 = headA;
            }
            if(temp1 == NULL){
                temp1 = headB;
            }
        }

        // Return the intersection node or nullptr if there is no intersection
        return temp1;
    }
};
