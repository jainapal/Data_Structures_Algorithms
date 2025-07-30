class Solution {
public:
    ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {
        if(head==NULL){
            if(K==1) return new ListNode(X);
            else return head;
        }
        if(K==1) return new ListNode(X,head); //x gives val and head gives next pointer i,e x->next = head
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            if(cnt == K - 1){
                ListNode* newNode=new ListNode(X,temp->next);
                temp->next=newNode;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};
TC = O(N)