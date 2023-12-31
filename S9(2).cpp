#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int freq;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int key, int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* constructOptimalBST(int keys[], int freq[], int start, int end) {
    if (start > end)
        return NULL;

    int minCostIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (freq[i] < freq[minCostIndex])
            minCostIndex = i;
    }

    struct Node* root = createNode(keys[minCostIndex], freq[minCostIndex]);

    root->left = constructOptimalBST(keys, freq, start, minCostIndex - 1);
    root->right = constructOptimalBST(keys, freq, minCostIndex + 1, end);

    return root;
}
int calculateCost(struct Node* root, int depth) {
    if (root == NULL)
        return 0;

   
    return root->freq * depth + calculateCost(root->left, depth + 1) + calculateCost(root->right, depth + 1);
}
int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n];
    int freq[n];

    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the corresponding frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    struct Node* root = constructOptimalBST(keys, freq, 0, n - 1);
    int totalCost = calculateCost(root, 1);

    printf("\nBinary Search Tree (In-order traversal):\n");
    inOrderTraversal(root);
    printf("\nTotal Cost of Binary Search Tree: %d\n", totalCost);

    return 0;
}
