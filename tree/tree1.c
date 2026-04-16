#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void printInRange(struct Node* root, int low, int high) {
    if (root == NULL)
        return;

    if (root->val > low)
        printInRange(root->left, low, high);

    if (root->val >= low && root->val <= high)
        printf("%d ", root->val);

    if (root->val < high)
        printInRange(root->right, low, high);
}

int main() {
    struct Node* root = NULL;
    int n, val, low, high;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter range (low high): ");
    scanf("%d %d", &low, &high);

    printf("Elements in range: ");
    printInRange(root, low, high);

    return 0;
}
