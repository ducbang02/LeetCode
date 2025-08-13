#include <bits/stdc++.h>
using namespace std;

// Định nghĩa node cho danh sách liên kết đơn
struct ListNode {
    int val;            // giá trị lưu trong node
    ListNode *next;     // con trỏ tới node tiếp theo

    ListNode() : val(0), next(nullptr) {}                 // constructor mặc định
    ListNode(int x) : val(x), next(nullptr) {}            // constructor với giá trị
    ListNode(int x, ListNode *next) : val(x), next(next) {} // constructor với giá trị + con trỏ
};

// Time: O(nlog(n)), space: O(n)
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) return nullptr;
    vector<ListNode*> temp;
    ListNode* newHead;
    ListNode* cur = nullptr;
    for (auto x : lists)
    {
        if(!x) return nullptr;
        cur = x;
        while(cur){
            temp.push_back(cur);
            cur = cur->next;
        }
    }
    sort(temp.begin(), temp.end(), [](ListNode* a, ListNode* b){
        return a->val < b->val;
    });
    cur = newHead;
    for(auto x : temp){
        cur->next = x;
        cur = cur->next;
    }
    return newHead->next;
}

