#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

/**
 * Node structure for the Binary Search Tree.
 * Using a class for Node to maintain consistency with OOP principles.
 */
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    // Internal helper for recursive insertion
    TreeNode* insertInternal(TreeNode* node, int value) {
        if (!node) return new TreeNode(value);

        if (value < node->data)
            node->left = insertInternal(node->left, value);
        else if (value > node->data)
            node->right = insertInternal(node->right, value);

        return node;
    }

    // Internal helper for in-order traversal
    void inOrderInternal(TreeNode* node) {
        if (!node) return;
        inOrderInternal(node->left);
        std::cout << node->data << " ";
        inOrderInternal(node->right);
    }

    // Helper to find the successor for deletion
    TreeNode* getMinNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left) current = current->left;
        return current;
    }

    TreeNode* deleteInternal(TreeNode* node, int key) {
        if (!node) return nullptr;

        if (key < node->data)
            node->left = deleteInternal(node->left, key);
        else if (key > node->data)
            node->right = deleteInternal(node->right, key);
        else {
            // Case 1 & 2: One child or No child
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            TreeNode* temp = getMinNode(node->right);
            node->data = temp->data;
            node->right = deleteInternal(node->right, temp->data);
        }
        return node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertInternal(root, value);
    }

    void remove(int key) {
        root = deleteInternal(root, key);
    }

    void displayInOrder() {
        if (!root) {
            std::cout << "Tree is currently empty." << std::endl;
            return;
        }
        inOrderInternal(root);
        std::cout << std::endl;
    }

    bool search(int key) {
        TreeNode* current = root;
        while (current) {
            if (key == current->data) return true;
            current = (key < current->data) ? current->left : current->right;
        }
        return false;
    }
};

int main() {
    BinarySearchTree bst;

    // Building the tree with a specific test set
    int initialValues[] = {25, 15, 30, 10, 20, 35, 5};
    for (int val : initialValues) {
        bst.insert(val);
    }

    std::cout << "--- Binary Search Tree Management ---" << std::endl;
    std::cout << "Initial Sorted Tree: ";
    bst.displayInOrder();

    // Testing search functionality
    int target = 20;
    std::cout << "Searching for " << target << ": " << (bst.search(target) ? "Found" : "Not Found") << std::endl;

    // Testing removal
    std::cout << "\nRemoving node 15..." << std::endl;
    bst.remove(15);
    std::cout << "Tree after removal: ";
    bst.displayInOrder();

    return 0;
}

#endif
