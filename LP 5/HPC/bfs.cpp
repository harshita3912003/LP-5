#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Inserts a node into the binary tree using level-order insertion
Node* insert(Node* root, int data) {
    if (!root) {
        return new Node(data);
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = new Node(data);
            return root;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = new Node(data);
            return root;
        } else {
            q.push(temp->right);
        }
    }

    return root; // fallback
}

// Performs Breadth-First Search (Level Order Traversal)
void bfs(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << endl;
}

int main() {
    Node* root = nullptr;
    int data;
    char choice;

    do {
        cout << "Enter data: ";
        cin >> data;
        root = insert(root, data);
        cout << "Do you want to insert one more node? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    bfs(root);

    return 0;
}

/*
output : 
Enter data: 1
Do you want to insert one more node? (y/n): y
Enter data: 2
Do you want to insert one more node? (y/n): y
Enter data: 3
Do you want to insert one more node? (y/n): y
Enter data: 6
Do you want to insert one more node? (y/n): y
Enter data: 
9
Do you want to insert one more node? (y/n): y
Enter data: 0
Do you want to insert one more node? (y/n): n
BFS Traversal: 1 2 3 6 9 1 0 


=== Code Execution Successful ===
*/