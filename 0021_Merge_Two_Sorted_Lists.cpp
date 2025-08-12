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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;
    vector<ListNode*> v;
    ListNode* cur = list1;

    while(cur != nullptr){
        v.push_back(cur);
        cur = cur ->next;
    }

    cur = list2;
    while(cur != nullptr){
        v.push_back(cur);
        cur = cur ->next;
    }

    sort(v.begin(), v.end(), [](ListNode* a, ListNode* b){
        return a->val < b->val;
    });
    ListNode* newHead = v[0];
    cur = newHead;
    for (int i = 1; i < v.size(); i++){
        cur->next = v[i];
        cur = cur->next;
    }
    cur->next = nullptr;
    return newHead;
}

void PrintList(ListNode *head){
    // Duyệt danh sách
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
}

void DeleteList(ListNode *&head){
    ListNode* current = head;
    while (current != nullptr) {
        ListNode*temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    // Tạo 3 node

    ListNode node1(11);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(9);
    ListNode node6(6);
    ListNode node7(1);
    ListNode node8(2);
    ListNode* pNode5 = &node5;
    ListNode* pNode1 = &node1;
    // Nối các node lại thành danh sách 1 -> 2 -> 3
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    node5.next = &node6;
    node6.next = &node7;
    node7.next = &node8;

    ListNode* newNode = mergeTwoLists(pNode1, pNode5);
    PrintList(newNode);
    DeleteList(newNode);
    DeleteList(pNode1);
    DeleteList(pNode5);
    return 0;
}