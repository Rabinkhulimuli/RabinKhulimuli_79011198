#include <iostream>
using namespace std;

struct bst {
    int data;
    bst* left;
    bst* right;
};

void insert_bst(bst*& root, int num) {
    if (root == nullptr) {
        root = new bst;
        root->data = num;
        root->left = nullptr;
        root->right = nullptr;
    } else if (num < root->data) {
        insert_bst(root->left, num);
    } else if (num > root->data) {
        insert_bst(root->right, num);
    } else {
        cout << "Duplicate entry" << endl;
    }
}

void search_bst(bst* root, int num) {
    if (root == nullptr) {
        cout << "Item not found" << endl;
        return;
    }

    if (num < root->data) {
        search_bst(root->left, num);
    } else if (num > root->data) {
        search_bst(root->right, num);
    } else {
        cout << "Item found" << endl;
    }
}

bst* findMax(bst* root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

bst* remove_bst(bst* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }

    if (val < root->data) {
        root->left = remove_bst(root->left, val);
    } else if (val > root->data) {
        root->right = remove_bst(root->right, val);
    } else {
        if (root->left == nullptr) {
            bst* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            bst* temp = root->left;
            delete root;
            return temp;
        } else {
            bst* temp = findMax(root->left);
            root->data = temp->data;
            root->left = remove_bst(root->left, temp->data);
        }
    }

    return root;
}

void display_bst_inorder(bst* root) {
    if (root == nullptr) {
        return;
    }
    display_bst_inorder(root->left);
    cout << root->data << " ";
    display_bst_inorder(root->right);
}

int main() {
    bst* root = nullptr;
    int ch, num;
    while (true) {
        cout << "Choose one of the following choices" << endl;
        cout << "1. Insert 2. Search 3. Remove 4. Display 5. Exit" << endl;
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter the number to be inserted" << endl;
                cin >> num;
                insert_bst(root, num);
                break;
            case 2:
                cout << "Enter the number to be searched" << endl;
                cin >> num;
                search_bst(root, num);
                break;
            case 3:
                cout << "Enter the number to be deleted" << endl;
                cin >> num;
                root = remove_bst(root, num);
                break;
            case 4:
                cout << "BST values in sorted order: ";
                display_bst_inorder(root);
                cout << endl;
                break;
            case 5:
                return 0;
            default:
                cout << "Choose the right choice" << endl;
                break;
        }
    }
    return 0;
}
