#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Iterative BST insertion
struct Node* iterativeInsert(struct Node* root, int data) {
    struct Node* newNode = createNode(data);
    if (root == NULL) return newNode;

    struct Node* parent = NULL;
    struct Node* current = root;
    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else
            return root; // No duplicates allowed
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// Recursive BST insertion
struct Node* recursiveInsert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = recursiveInsert(root->left, data);
    else if (data > root->data)
        root->right = recursiveInsert(root->right, data);

    return root;
}

// Utility function to print BST in-order (for verification)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Free memory allocated for the BST
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Time comparison function for both insertions
void compareInsertionTimes(int arrays[5][10], int sizes[5]) {
    for (int i = 0; i < 5; i++) {
        printf("\n--- Array %d ---\n", i + 1);
        struct Node* root1 = NULL; // For iterative insertions
        struct Node* root2 = NULL; // For recursive insertions

        // Measure time for iterative insertion
        clock_t startIter = clock();
        for (int j = 0; j < sizes[i]; j++) {
            root1 = iterativeInsert(root1, arrays[i][j]);
        }
        clock_t endIter = clock();
        double timeIter = ((double)(endIter - startIter)) / CLOCKS_PER_SEC;

        // Measure time for recursive insertion
        clock_t startRecur = clock();
        for (int j = 0; j < sizes[i]; j++) {
            root2 = recursiveInsert(root2, arrays[i][j]);
        }
        clock_t endRecur = clock();
        double timeRecur = ((double)(endRecur - startRecur)) / CLOCKS_PER_SEC;

        printf("Iterative Insertion Time: %f seconds\n", timeIter);
        printf("Recursive Insertion Time: %f seconds\n", timeRecur);

        // Optional: Print BST (for verification)
        printf("In-order traversal (Iterative): ");
        inorderTraversal(root1);
        printf("\nIn-order traversal (Recursive): ");
        inorderTraversal(root2);
        printf("\n");

        // Free the trees to prevent memory leaks
        freeTree(root1);
        freeTree(root2);
    }
}

int main() {
    // Sample input arrays (each array will have 10 elements)
    int arrays[5][10] = {
        {30, 20, 40, 10, 25, 35, 50, 5, 15, 45},
        {50, 30, 70, 20, 40, 60, 80, 10, 25, 55},
        {25, 15, 35, 10, 20, 30, 40, 5, 18, 38},
        {45, 20, 55, 10, 30, 50, 60, 5, 25, 65},
        {60, 30, 70, 20, 50, 65, 80, 10, 40, 75}
    };

    // Corresponding sizes of the arrays
    int sizes[5] = {10, 10, 10, 10, 10};

    // Compare the insertion times
    compareInsertionTimes(arrays, sizes);

    return 0;
}
