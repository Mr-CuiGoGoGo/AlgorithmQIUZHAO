
//注：积累题目经验系列----在作图后才写出的代码，原版~~~~（思考时间15min）
//反转链表
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
//没看答案，稍微有点兴奋=。=就一点（毕竟也不难嘛）
//通过看题解，这方法叫做迭代
//下面是  递归（理解了很久），感觉自己想不到这种方法。。
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




