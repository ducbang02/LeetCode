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

ListNode* reverseList(ListNode* head) {
    if(head == nullptr) return nullptr;
    stack<ListNode*> st;
    ListNode* cur = head;
    while(cur != nullptr){
        st.push(cur);
        cur = cur -> next;
    }
    ListNode* newHead;
    newHead = st.top();
    st.pop();
    cur = newHead;
    while(!st.empty()){
        cur->next = st.top();
        st.pop();
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

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode* pNode4 = &node4;
    ListNode* pNode1 = &node1;
    // Nối các node lại thành danh sách 1 -> 2 -> 3
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    ListNode* pNode5 = reverseList(&node1);

    PrintList(pNode5);
    DeleteList(pNode1);
    DeleteList(pNode5);
    return 0;
}