
//ע��������Ŀ����ϵ��----����ͼ���д���Ĵ��룬ԭ��~~~~��˼��ʱ��15min��
//��ת����
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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur_Node = head;
        ListNode *before_Node = nullptr;
        while(cur_Node != nullptr){
            ListNode *temp = cur_Node->next;
            cur_Node->next = before_Node;
            before_Node = cur_Node;
            cur_Node = temp;
           // cout<< "1" <<endl;
        }
        return before_Node;
    }
};
//û���𰸣���΢�е��˷�=��=��һ�㣨�Ͼ�Ҳ�����
//ͨ������⣬�ⷽ����������
//������  �ݹ飨����˺ܾã����о��Լ��벻�����ַ�������
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		if(head==nullptr || head->next==nullptr) {
			return head;
		}
		ListNode *cur = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return cur;
    }
};
*/




