class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode* temp = new ListNode(); // Dummy node to start the merged list
        ListNode* cur = temp; // Pointer to track the current node in the merged list

        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        // Attach remaining nodes from list1 or list2, if any
        cur->next = list1 ? list1 : list2;

        // Return the merged list, excluding the dummy node
        ListNode* result = temp->next;
        delete temp; // Free the memory allocated for the dummy node
        return result;
    }
};
