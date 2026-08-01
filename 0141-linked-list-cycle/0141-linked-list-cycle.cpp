/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* slow = head;
        ListNode* fast = head;
        //Traverse untill fast and fast->next are valid
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;//1step
            fast = fast->next->next;//2step
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};