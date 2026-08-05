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
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};