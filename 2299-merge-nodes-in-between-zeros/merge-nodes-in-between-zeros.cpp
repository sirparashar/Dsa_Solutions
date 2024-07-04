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
    ListNode* mergeNodes(ListNode* head) {

        ListNode* dummy = new ListNode();
        ListNode*temp=dummy;
        head=head->next;

        int sum=0;
        while(head!=nullptr){
            sum+=head->val;
            if(head->val==0){
                cout<<sum;
                temp->next = new ListNode(sum);
                temp=temp->next;
                sum=0;
            }
            head=head->next;
        }

        return dummy->next;
        
        
    }
};