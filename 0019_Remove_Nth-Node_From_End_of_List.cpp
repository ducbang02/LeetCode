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

//time: O(n), space: O(n)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    unordered_map<int, ListNode*> map;
    ListNode* cur = head;
    int a = 1;
    while (cur != nullptr) {
        map[a] = cur;
        cur = cur->next;
        a++;
    }
    a--;
    int k = a - n + 1;
    if(k == 1){
        cur = head->next;
        return cur;
    }else{
        map[k-1]->next = map[k]->next;
        return head;
    }
}

//time: O(n), space: O(1)
ListNode* removeNthFromEnd2(ListNode* head, int n) {
    ListNode dummy(0, head);
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    for(int i = 0; i <= n; i++){
        fast = fast->next;
    }

    while(fast != nullptr){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy.next;
}

void PrintList(ListNode *head){
    // Duyệt danh sách
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout<<"\n";
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
    ListNode node5(9);
    ListNode node6(6);
    ListNode node7(1);
    ListNode node8(2);
    ListNode* pNode5 = &node5;
    ListNode* pNode1 = &node1;
    ListNode* pNode8 = &node8;
    // Nối các node lại thành danh sách 1 -> 2 -> 3
    node1.next = &node2;
    // node2.next = &node3;
    // node3.next = &node4;
    // node4.next = &node7;

    // node5.next = &node6;
    // node6.next = &node7;
    // node7.next = &node8;

    PrintList(pNode1);
    ListNode* newNode = removeNthFromEnd2(pNode1, 2);
    PrintList(newNode);

    DeleteList(pNode1);
    DeleteList(pNode5);
    return 0;
}