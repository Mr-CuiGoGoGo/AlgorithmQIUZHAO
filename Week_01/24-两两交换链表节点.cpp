//�������ϵ��=��=------һ��Ҫ��ͼ���˴��ǵ����������ҿ�����Ƶ���˵ݹ飡������
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //if(head == nullptr|| head->next == nullptr) return head;
        ListNode *p = new ListNode(0);
        p->next = head;
        ListNode *cur_Node = p;
        ListNode *l ;//= head;
        ListNode *r ;//= head->next;
        while(head != nullptr&& head->next != nullptr){
            l = head;
            r = head->next;
            cur_Node->next = r;
            l->next = r->next;
            r->next = l;
            cur_Node = l;
            head = l->next; 
        }
        return p->next;
    }
};

//