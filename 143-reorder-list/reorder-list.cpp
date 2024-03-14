/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head->next==nullptr){
            return;
        }

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast = fast->next->next;
        }

        prev->next=nullptr;

        ListNode* l1 = head;
        ListNode* l2 = reverse(slow);

        merge(l1,l2);
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next;

        while(cur!=nullptr){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;

        }
        return prev;
    }

    void merge(ListNode* l1,ListNode* l2){
        while(l1!=nullptr){
            ListNode* p1 = l1->next;
            ListNode* p2 = l2->next;
            l1->next=l2;
            if(p1==nullptr){
                break;
            }

            l2->next = p1;
            l1=p1;
            l2=p2;
        }
    }



};