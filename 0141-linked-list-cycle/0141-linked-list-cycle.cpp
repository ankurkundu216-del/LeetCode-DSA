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
        unordered_set<ListNode*> visited;
        ListNode* curr = head;
        while(curr != nullptr){
            if(visited.count(curr)){
                return true;
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};