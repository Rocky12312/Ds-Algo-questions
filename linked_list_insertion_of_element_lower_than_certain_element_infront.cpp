class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode*prev = head;
        ListNode*forw = head;
        while(forw->next != NULL){
            if(forw->val == x){
                break;
            }
            forw = forw->next;
        }
        ListNode*prev_n = NULL;
        cout<<forw->val;
        prev_n = forw;
        if(forw->next != NULL){
            forw = forw->next;
        }
        while(forw != NULL){
            if(forw->val <= x){
                prev_n->next = forw->next;
                forw->next = prev;
                prev = forw;
                forw = prev_n->next;
            }else{
                prev_n = forw;
                forw = forw->next;
            }
            if(forw==NULL){
                break;
            }
        }
        return prev;
    }
};
