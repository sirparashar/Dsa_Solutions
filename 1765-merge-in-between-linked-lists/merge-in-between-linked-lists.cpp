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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp= list1;
        ListNode* connect;
        for(int i =0; i<a-1; i++){
            temp=temp->next;
        }
        connect = temp;

        for(int i=0; i<b-a+1; i++){
         connect = connect -> next;
        }
     //   cout<<connect->val;


        temp->next = list2;

        while(list2->next!=nullptr){
            list2=list2->next;
        }

        list2->next=connect->next;

      return list1;


    }
};