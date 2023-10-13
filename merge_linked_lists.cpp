#include <iostream>

// Define the structure for a node in the linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Create a dummy node to simplify merging
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // If one list is exhausted, append the remaining nodes from the other list
    if (l1) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    return dummy->next;
}

// Function to print a linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create two sorted linked lists
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    // Merge the linked lists
    ListNode* mergedList = mergeTwoLists(list1, list2);

    // Print the merged list
    std::cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
