//经验积累系列——看了老师视频果断看题解！！！等我看完视频来此哈希！！！！
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(slow != fast){
            if(fast == nullptr || fast->next == nullptr){
                return false;
            }
            else{
                slow = slow->next;
                fast = fast->next->next; 
            }
        }
        return true;
        
    }
};
//确实挺惨的。。。只击败了25%。等我看完哈希，再约！！！