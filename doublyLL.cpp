#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* back;
    Node(int value, Node* nextNode = nullptr,
         Node* backNode = nullptr) {
        data = value;
        next = nextNode;
        back = backNode;
    }
};
// Insert at head
Node* inserthead(Node* head, int val) {
    Node* newHead = new Node(val, head, nullptr);
    if (head != nullptr)
        head->back = newHead;
    return newHead;
}
// Insert at tail
Node* inserttail(Node* head, int val) {
    if (head == nullptr)
        return new Node(val);
    Node* tail = head;
    while (tail->next != nullptr)
        tail = tail->next;
    Node* newNode = new Node(val, nullptr, tail);
    tail->next = newNode;
    return head;
}
// Insert at K (1-based)
Node* insertk(Node* head, int val, int k) {
    if (k < 1) {
        cout << "Invalid position\n";
        return head;
    }
    if (k == 1)
        return inserthead(head, val);
    Node* temp = head;
    int cnt = 1;
    while (temp != nullptr) {
        if (cnt == k - 1) {
            Node* front = temp->next;
            Node* newNode = new Node(val, front, temp);
            temp->next = newNode;
            if (front != nullptr)
                front->back = newNode;
            return head;
        }
        temp = temp->next;
        cnt++;
    }
    cout << "Invalid position\n";
    return head;
}
// Insert at index (0-based)
Node* insertatindex(Node* head, int val, int index) {
    if (index < 0) {
        cout << "Invalid index\n";
        return head;
    }
    if (index == 0)
        return inserthead(head, val);
    Node* temp = head;
    int cnt = 0;
    while (temp != nullptr) {
        if (cnt == index - 1) {
            Node* front = temp->next;
            Node* newNode = new Node(val, front, temp);
            temp->next = newNode;
            if (front != nullptr)
                front->back = newNode;
            return head;
        }
        temp = temp->next;
        cnt++;
    }
    cout << "Invalid index\n";
    return head;
}
// Insert before a value
Node* insertbeforevalue(Node* head, int val, int target) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Target value not found\n";
        return head;
    }
    if (temp == head)
        return inserthead(head, val);
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
// Insert after a value
Node* insertaftervalue(Node* head, int val, int target) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Target value not found\n";
        return head;
    }
    Node* front = temp->next;
    Node* newNode = new Node(val, front, temp);
    temp->next = newNode;
    if (front != nullptr)
        front->back = newNode;
    return head;
}
// Delete head
Node* deletehead(Node* head) {
    if (head == nullptr) {
        cout << "Empty list\n";
        return head;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr)
        head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}
// Delete tail
Node* deletetail(Node* head) {
    if (head == nullptr) {
        cout << "Empty list\n";
        return head;
    }
    Node* tail = head;
    while (tail->next != nullptr)
        tail = tail->next;
    if (tail == head) {
        delete tail;
        return nullptr;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}
// Delete at K (1-based)
Node* deletek(Node* head, int k) {
    if (k < 1) {
        cout << "Invalid position\n";
        return head;
    }
    if (head == nullptr) {
        cout << "Empty list\n";
        return head;
    }
    if (k == 1)
        return deletehead(head);
    Node* temp = head;
    int cnt = 1;
    while (temp != nullptr && cnt < k) {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr) {
        cout << "Invalid position\n";
        return head;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if (front != nullptr)
        front->back = prev;
    if (prev != nullptr)
        prev->next = front;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}
// Delete at index (0-based)
Node* deleteatindex(Node* head, int index) {
    if (index < 0) {
        cout << "Invalid index\n";
        return head;
    }
    if (head == nullptr) {
        cout << "Empty list\n";
        return head;
    }
    if (index == 0)
        return deletehead(head);
    Node* temp = head;
    int cnt = 0;
    while (temp != nullptr && cnt < index) {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr) {
        cout << "Invalid index\n";
        return head;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if (front != nullptr)
        front->back = prev;
    prev->next = front;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}
// Delete a value
Node* deletevalue(Node* head, int val) {
    if (head == nullptr) {
        cout << "Empty list\n";
        return head;
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != val)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Value not found\n";
        return head;
    }
    if (temp == head)
        return deletehead(head);
    Node* prev = temp->back;
    Node* front = temp->next;
    prev->next = front;
    if (front != nullptr)
        front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}
// Delete before a value
Node* deletebeforevalue(Node* head, int target) {
    if (head == nullptr) {
        cout << "Empty list\n";
        return head;
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != target)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Target value not found\n";
        return head;
    }
    if (temp == head) {
        cout << "No node before the head\n";
        return head;
    }
    Node* nodetodelete = temp->back;
    Node* prev = nodetodelete->back;
    if (prev != nullptr) {
        prev->next = temp;
        temp->back = prev;
    } else {
        head = temp;
        temp->back = nullptr;
    }
    nodetodelete->next = nullptr;
    nodetodelete->back = nullptr;
    delete nodetodelete;
    return head;
}
// Delete after a value
Node* deleteaftervalue(Node* head, int target) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Target value not found\n";
        return head;
    }
    if (temp->next == nullptr) {
        cout << "No node after tail\n";
        return head;
    }
    Node* nodetodelete = temp->next;
    Node* front = nodetodelete->next;
    temp->next = front;
    if (front != nullptr)
        front->back = temp;
    nodetodelete->next = nullptr;
    nodetodelete->back = nullptr;
    delete nodetodelete;
    return head;
}
// Display
void print(Node* head) {
    if (head == nullptr) {
        cout << "Empty list\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Main function
int main() {
    Node* head = nullptr;
    int choice, val, target, k, index, n;
    do {
        cout << "\n\n1. Create list";
        cout << "\n2. Insert at head";
        cout << "\n3. Insert at tail";
        cout << "\n4. Insert at K (1-based)";
        cout << "\n5. Insert at index (0-based)";
        cout << "\n6. Insert before value";
        cout << "\n7. Insert after value";
        cout << "\n8. Delete head";
        cout << "\n9. Delete tail";
        cout << "\n10. Delete at K";
        cout << "\n11. Delete at index";
        cout << "\n12. Delete value";
        cout << "\n13. Delete before value";
        cout << "\n14. Delete after value";
        cout << "\n15. Display";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter number of nodes: ";
                cin >> n;

                if (n < 0) {
                    cout << "Invalid number\n";
                    break;
                }

                while (head != nullptr)
                    head = deletehead(head);

                for (int i = 0; i < n; i++) {
                    cout << "Enter value: ";
                    cin >> val;
                    head = inserttail(head, val);
                }
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                head = inserthead(head, val);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> val;
                head = inserttail(head, val);
                break;

            case 4:
                cout << "Enter value and K: ";
                cin >> val >> k;
                head = insertk(head, val, k);
                break;

            case 5:
                cout << "Enter value and index: ";
                cin >> val >> index;
                head = insertatindex(head, val, index);
                break;

            case 6:
                cout << "Enter value and target: ";
                cin >> val >> target;
                head = insertbeforevalue(head, val, target);
                break;

            case 7:
                cout << "Enter value and target: ";
                cin >> val >> target;
                head = insertaftervalue(head, val, target);
                break;

            case 8:
                head = deletehead(head);
                break;

            case 9:
                head = deletetail(head);
                break;

            case 10:
                cout << "Enter K: ";
                cin >> k;
                head = deletek(head, k);
                break;

            case 11:
                cout << "Enter index: ";
                cin >> index;
                head = deleteatindex(head, index);
                break;

            case 12:
                cout << "Enter value to delete: ";
                cin >> val;
                head = deletevalue(head, val);
                break;

            case 13:
                cout << "Enter target value: ";
                cin >> target;
                head = deletebeforevalue(head, target);
                break;

            case 14:
                cout << "Enter target value: ";
                cin >> target;
                head = deleteaftervalue(head, target);
                break;

            case 15:
                print(head);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 0);
    while (head != nullptr)
        head = deletehead(head);
    return 0;
}