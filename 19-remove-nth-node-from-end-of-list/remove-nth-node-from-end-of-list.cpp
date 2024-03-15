class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr; // Handle empty list
        }

        int count = 0;
        ListNode* temp = head;

        // Count the number of nodes in the list
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Calculate the position of the node to be removed from the beginning
        int target = count - n;

        // If the node to be removed is the head node
        if (target == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Traverse the list to find the node just before the target node
        temp = head;
        for (int i = 0; i < target - 1; i++) {
            temp = temp->next;
        }

        // Remove the target node from the list
        ListNode* toRemove = temp->next;
        temp->next = toRemove->next;
        delete toRemove;

        return head;
    }
};
