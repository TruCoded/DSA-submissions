#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value, Node* nextNode = nullptr) {
        data = value;
        next = nextNode;
    }
};
Node* insertHead(Node* head, int val) {
    Node* temp = new Node(val, head);
    return temp;
}
Node* insertTail(Node* head, int val) {
    if (head == nullptr) {
        return new Node(val);
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}
// Insert at k: 1 through length + 1
Node* insertk(Node* head, int val, int k) {
    if (k < 1) {
        cout << "Invalid k\n";
        return head;
    }
    if (k == 1)
        return insertHead(head, val);
    int cnt = 0;
    Node* temp = head;
    while (temp != nullptr) {
        cnt++;
        if (cnt == k - 1) {
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    cout << "Invalid position\n";
    return head;
}
Node* insertatIndex(Node* head, int val, int index) {
    if (index < 0) {
        cout << "Invalid index\n";
        return head;
    }
    if (index == 0)
        return insertHead(head, val);
    Node* temp = head;
    int cnt = 0;
    while (temp != nullptr) {
        if (cnt == index - 1) {
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            return head;
        }
        cnt++;
        temp = temp->next;
    }
    cout << "Invalid index\n";
    return head;
}
Node* insertBeforeValue(Node* head, int val, int target) {
    if (head == nullptr) {
        cout << "Target value not found\n";
        return head;
    }
    if (head->data == target)
        return insertHead(head, val);
    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data == target) {
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    cout << "Target value not found\n";
    return head;
}
Node* insertAfterValue(Node* head, int val, int target) {
    if (head == nullptr) {
        cout << "Target value not found\n";
        return head;
    }
   Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == target) {
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    cout << "Target value not found\n";
    return head;
}
Node* deleteHead(Node* head) {
    if (head == nullptr) {
        cout << "Head not found\n";
        return head;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node* deleteTail(Node* head) {
    if (head == nullptr) {
        cout << "Tail not found\n";
        return head;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    return head;
}
Node* deletek(Node* head, int k) {
    if (k < 1) {
        cout << "Invalid position\n";
        return head;
    }
    if (head == nullptr) {
        cout << "List is empty\n";
        return head;
    }
    if (k == 1)
        return deleteHead(head);
    int cnt = 1;
    Node* temp = head;
    while (temp->next != nullptr && cnt < k - 1) {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == nullptr) {
        cout << "Invalid position\n";
        return head;
    }
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
    return head;
}
Node* deleteatIndex(Node* head, int index) {
    if (index < 0) {
        cout << "Invalid index\n";
        return head;
    }
    if (head == nullptr) {
        cout << "Empty list\n";
        return head;
    }
    if (index == 0)
        return deleteHead(head);
    Node* temp = head;
    int cnt = 0;
    while (temp->next != nullptr && cnt < index - 1) {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == nullptr) {
        cout << "Invalid index\n";
        return head;
    }
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
    return head;
}
Node* deletevalue(Node* head, int val) {
    if (head == nullptr) {
        cout << "Empty list\n";
        return head;
    }
    if (head->data == val)
        return deleteHead(head);
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr) {
        if (temp->data == val) {
            prev->next = temp->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Value not found\n";
    return head;
}
Node* deletebeforevalue(Node* head, int target) {
    if (head == nullptr) {
        cout << "Empty list\n";
        return head;
    }

    if (head->data == target) {
        cout << "No node before head\n";
        return head;
    }
    if (head->next != nullptr && head->next->data == target)
        return deleteHead(head);
    Node* temp = head;
    while (temp->next != nullptr &&
           temp->next->next != nullptr) {
        if (temp->next->next->data == target) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            return head;
        }
        temp = temp->next;
    }
    cout << "Target value not found or no node before target\n";
    return head;
}
Node* deletaftervalue(Node* head, int target) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == target) {
            if (temp->next == nullptr) {
                cout << "No node after tail\n";
                return head;
            }
            Node* node_to_delete = temp->next;
            temp->next = node_to_delete->next;
            delete node_to_delete;
            return head;
        }
        temp = temp->next;
    }
    cout << "Value not found\n";
    return head;
}
void print(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
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
        cout << "\n10. Delete at K (1-based)";
        cout << "\n11. Delete at index (0-based)";
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
                    head = deleteHead(head);
                for (int i = 0; i < n; i++) {
                    cout << "Enter value: ";
                    cin >> val;
                    head = insertTail(head, val);
                }
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                head = insertHead(head, val);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> val;
                head = insertTail(head, val);
                break;
            case 4:
                cout << "Enter value and K: ";
                cin >> val >> k;
                head = insertk(head, val, k);
                break;
            case 5:
                cout << "Enter value and index: ";
                cin >> val >> index;
                head = insertatIndex(head, val, index);
                break;
            case 6:
                cout << "Enter value and target: ";
                cin >> val >> target;
                head = insertBeforeValue(head, val, target);
                break;
            case 7:
                cout << "Enter value and target: ";
                cin >> val >> target;
                head = insertAfterValue(head, val, target);
                break;
            case 8:
                head = deleteHead(head);
                break;
            case 9:
                head = deleteTail(head);
                break;
            case 10:
                cout << "Enter K: ";
                cin >> k;
                head = deletek(head, k);
                break;
            case 11:
                cout << "Enter index: ";
                cin >> index;
                head = deleteatIndex(head, index);
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
                head = deletaftervalue(head, target);
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
        head = deleteHead(head);
    return 0;
}