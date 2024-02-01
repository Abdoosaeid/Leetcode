/*
* Author: Abdoo__said
*/
#include <map>  // Include the necessary header for using std::map
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Create a map to store nodes and their occurrences in the first linked list
        std::map<ListNode*, int> mp;

        // Iterate through the first linked list and populate the map
        ListNode *item1 = headA;
        while (item1) {
            mp[item1]++;
            item1 = item1->next;
        }

        // Iterate through the second linked list
        ListNode *item2 = headB;
        while (item2) {
            // Check if the current node is present in the map
            if (mp[item2] > 0) {
                // If yes, it means this node is the intersection point
                return item2;
            }
            item2 = item2->next;
        }

        // If no intersection is found, return NULL
        return NULL;
    }
};
