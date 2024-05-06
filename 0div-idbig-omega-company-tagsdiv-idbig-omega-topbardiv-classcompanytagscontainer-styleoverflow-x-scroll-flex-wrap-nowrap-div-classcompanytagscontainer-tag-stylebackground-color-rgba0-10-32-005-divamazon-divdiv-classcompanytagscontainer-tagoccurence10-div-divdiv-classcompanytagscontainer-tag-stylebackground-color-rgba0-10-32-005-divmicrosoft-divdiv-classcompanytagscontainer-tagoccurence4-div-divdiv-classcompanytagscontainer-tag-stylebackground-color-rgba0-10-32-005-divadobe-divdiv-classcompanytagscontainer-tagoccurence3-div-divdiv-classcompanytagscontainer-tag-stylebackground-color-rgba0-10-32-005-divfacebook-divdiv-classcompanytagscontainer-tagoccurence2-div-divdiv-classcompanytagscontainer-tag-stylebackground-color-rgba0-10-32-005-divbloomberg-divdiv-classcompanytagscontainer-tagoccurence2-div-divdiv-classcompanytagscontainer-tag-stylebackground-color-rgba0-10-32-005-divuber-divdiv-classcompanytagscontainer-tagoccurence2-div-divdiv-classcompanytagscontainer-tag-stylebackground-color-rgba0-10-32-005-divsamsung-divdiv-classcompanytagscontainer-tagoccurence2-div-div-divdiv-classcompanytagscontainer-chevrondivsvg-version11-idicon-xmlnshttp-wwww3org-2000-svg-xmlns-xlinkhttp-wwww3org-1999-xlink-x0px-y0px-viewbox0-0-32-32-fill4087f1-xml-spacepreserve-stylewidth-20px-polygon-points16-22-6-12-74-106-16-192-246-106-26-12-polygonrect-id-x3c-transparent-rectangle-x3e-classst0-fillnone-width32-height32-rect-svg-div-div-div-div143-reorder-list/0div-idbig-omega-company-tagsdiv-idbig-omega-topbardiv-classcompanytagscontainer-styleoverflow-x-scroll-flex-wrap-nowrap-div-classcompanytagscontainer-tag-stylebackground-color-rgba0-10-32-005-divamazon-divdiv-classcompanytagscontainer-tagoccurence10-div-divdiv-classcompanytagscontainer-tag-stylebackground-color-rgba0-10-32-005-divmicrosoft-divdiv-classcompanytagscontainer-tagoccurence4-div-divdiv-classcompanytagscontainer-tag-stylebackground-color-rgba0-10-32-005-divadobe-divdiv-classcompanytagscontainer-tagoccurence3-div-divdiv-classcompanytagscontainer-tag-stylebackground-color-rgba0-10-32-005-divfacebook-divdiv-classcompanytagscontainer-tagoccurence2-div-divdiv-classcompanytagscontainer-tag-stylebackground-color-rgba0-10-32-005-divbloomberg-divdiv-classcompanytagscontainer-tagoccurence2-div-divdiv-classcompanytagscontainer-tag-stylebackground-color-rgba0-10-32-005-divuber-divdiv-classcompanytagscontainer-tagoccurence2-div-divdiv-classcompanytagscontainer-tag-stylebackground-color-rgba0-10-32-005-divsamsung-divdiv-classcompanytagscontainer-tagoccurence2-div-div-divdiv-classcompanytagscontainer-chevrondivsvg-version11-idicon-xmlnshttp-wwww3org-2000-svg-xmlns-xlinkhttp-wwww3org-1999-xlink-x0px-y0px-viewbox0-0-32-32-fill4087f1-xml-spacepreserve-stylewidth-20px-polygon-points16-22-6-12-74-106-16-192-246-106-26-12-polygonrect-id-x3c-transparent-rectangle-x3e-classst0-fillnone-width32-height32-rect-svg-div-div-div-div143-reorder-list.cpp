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
    void reorderList(ListNode* node) {
        queue<ListNode*>q;
        stack<ListNode*>s;
        if(node==NULL)return;
        if(node->next==NULL)return;
        ListNode* head = node;
        while(head!=NULL){
            q.push(head);
            s.push(head);
            head=head->next;
        }
        ListNode* last =node;
        q.pop();
        ListNode* prev = NULL;
        int len = s.size();
        
        while(len>0){
            last->next=s.top();
            prev = last;
            last=last->next;
            s.pop();
            len--;
            if(len>0){
                last->next= q.front();
                prev = last;
                last=last->next;
                q.pop();
                len--;
            }  
        }
        last->next = NULL;
    }
};