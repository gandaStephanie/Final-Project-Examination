#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure for Binary Tree (Camp)
struct CampNode {
    string campName;       // Store the camp name
    CampNode* left;        // Left child node
    CampNode* right;       // Right child node
};

// Node structure for Binary Search Tree (Survivor)
struct SurvivorNode {
    string name;           // Store the survivor's name
    int skillLevel;        // Store the survivor's skill level
    SurvivorNode* left;    // Left child node
    SurvivorNode* right;   // Right child node
};

// Functions for Binary Tree (Camp Management)
CampNode* CreateCamp(string campName) {
    // Create a new camp node and initialize it with the given camp name
    CampNode* newNode = new CampNode();
    newNode->campName = campName;
    newNode->left = newNode->right = NULL;  // Initially no children
    return newNode;
}

CampNode* InsertCamp(CampNode* root, string campName) {
    // Insert a new camp in the binary tree based on the camp name
    if (root == NULL) {
        return CreateCamp(campName);  // Create a new camp node if the tree is empty
    }
    if (campName < root->campName) {
        // Insert in the left subtree if the camp name is smaller
        root->left = InsertCamp(root->left, campName);
    } else {
        // Insert in the right subtree if the camp name is greater
        root->right = InsertCamp(root->right, campName);
    }
    return root;
}

bool SearchCamp(CampNode* root, string campName) {
    // Search for a camp by its name in the binary tree
    if (root == NULL) return false;  // Return false if the tree is empty
    if (root->campName == campName) return true;  // Found the camp
    if (campName < root->campName) return SearchCamp(root->left, campName);  // Search left subtree
    return SearchCamp(root->right, campName);  // Search right subtree
}

CampNode* FindMinCamp(CampNode* root) {
    // Find the node with the minimum camp name (leftmost node)
    while (root && root->left != NULL) {
        root = root->left;  // Traverse left until the leftmost node is found
    }
    return root;
}

CampNode* DeleteCamp(CampNode* root, string campName) {
    // Delete a camp by its name from the binary tree
    if (root == NULL) return root;  // Return if the tree is empty
    if (campName < root->campName) {
        root->left = DeleteCamp(root->left, campName);  // Search and delete from left subtree
    } else if (campName > root->campName) {
        root->right = DeleteCamp(root->right, campName);  // Search and delete from right subtree
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            CampNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            CampNode* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in right subtree)
        CampNode* temp = FindMinCamp(root->right);
        root->campName = temp->campName;  // Copy the inorder successor's content
        root->right = DeleteCamp(root->right, temp->campName);  // Delete the inorder successor
    }
    return root;
}

void PreOrderCamp(CampNode* root) {
    // Preorder traversal of the camp tree (root, left, right)
    if (root == NULL) return;
    cout << root->campName << " ";
    PreOrderCamp(root->left);
    PreOrderCamp(root->right);
}

void InOrderCamp(CampNode* root) {
    // Inorder traversal of the camp tree (left, root, right)
    if (root == NULL) return;
    InOrderCamp(root->left);
    cout << root->campName << " ";
    InOrderCamp(root->right);
}

void PostOrderCamp(CampNode* root) {
    // Postorder traversal of the camp tree (left, right, root)
    if (root == NULL) return;
    PostOrderCamp(root->left);
    PostOrderCamp(root->right);
    cout << root->campName << " ";
}

// Functions for Binary Search Tree (Survivor Management)
SurvivorNode* CreateSurvivor(string name, int skillLevel) {
    // Create a new survivor node with the given name and skill level
    SurvivorNode* newNode = new SurvivorNode();
    newNode->name = name;
    newNode->skillLevel = skillLevel;
    newNode->left = newNode->right = NULL;  // Initially no children
    return newNode;
}

SurvivorNode* InsertSurvivor(SurvivorNode* root, string name, int skillLevel) {
    // Insert a new survivor into the binary search tree based on skill level
    if (root == NULL) {
        return CreateSurvivor(name, skillLevel);  // Create a new survivor node if the tree is empty
    }
    if (skillLevel < root->skillLevel) {
        // Insert in the left subtree if the skill level is smaller
        root->left = InsertSurvivor(root->left, name, skillLevel);
    } else {
        // Insert in the right subtree if the skill level is greater
        root->right = InsertSurvivor(root->right, name, skillLevel);
    }
    return root;
}

bool SearchSurvivor(SurvivorNode* root, int skillLevel) {
    // Search for a survivor by their skill level
    if (root == NULL) return false;  // Return false if the tree is empty
    if (root->skillLevel == skillLevel) return true;  // Found the survivor
    if (skillLevel < root->skillLevel) return SearchSurvivor(root->left, skillLevel);  // Search left subtree
    return SearchSurvivor(root->right, skillLevel);  // Search right subtree
}

void PreOrderSurvivor(SurvivorNode* root) {
    // Preorder traversal of the survivor tree (root, left, right)
    if (root == NULL) return;
    cout << root->name << " (Skill: " << root->skillLevel << ") ";
    PreOrderSurvivor(root->left);
    PreOrderSurvivor(root->right);
}

void InOrderSurvivor(SurvivorNode* root) {
    // Inorder traversal of the survivor tree (left, root, right)
    if (root == NULL) return;
    InOrderSurvivor(root->left);
    cout << root->name << " (Skill: " << root->skillLevel << ") ";
    InOrderSurvivor(root->right);
}

void PostOrderSurvivor(SurvivorNode* root) {
    // Postorder traversal of the survivor tree (left, right, root)
    if (root == NULL) return;
    PostOrderSurvivor(root->left);
    PostOrderSurvivor(root->right);
    cout << root->name << " (Skill: " << root->skillLevel << ") ";
}

// Heap Functions
void insertMaxHeap(vector<SurvivorNode*>& heap, SurvivorNode* s) {
    // Insert a survivor into a max heap based on skill level
    heap.push_back(s);
    int index = heap.size() - 1;

    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index]->skillLevel > heap[parentIndex]->skillLevel) {
            swap(heap[index], heap[parentIndex]);  // Swap if the current node has higher skill level
            index = parentIndex;  // Move up the heap
        } else {
            break;  // Heap property satisfied
        }
    }
}

void insertMinHeap(vector<SurvivorNode*>& heap, SurvivorNode* s) {
    // Insert a survivor into a min heap based on skill level
    heap.push_back(s);
    int index = heap.size() - 1;

    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index]->skillLevel < heap[parentIndex]->skillLevel) {
            swap(heap[index], heap[parentIndex]);  // Swap if the current node has lower skill level
            index = parentIndex;  // Move up the heap
        } else {
            break;  // Heap property satisfied
        }
    }
}

void displayMaxHeapLeaderboard(const vector<SurvivorNode*>& heap) {
    // Display the leaderboard for max heap (survivors with highest skill levels)
    cout << "Survivor of the Day Leaderboard (Max-Heap):\n";
    for (int i = 0; i < heap.size(); i++) {
        cout << "Name: " << heap[i]->name << ", Skill Level: " << heap[i]->skillLevel << "\n";
    }
}

void displayMinHeapLeaderboard(const vector<SurvivorNode*>& heap) {
    // Display the leaderboard for min heap (survivors with lowest skill levels)
    cout << "Lowest Survivors Leaderboard (Min-Heap):\n";
    for (int i = 0; i < heap.size(); i++) {
        cout << "Name: " << heap[i]->name << ", Skill Level: " << heap[i]->skillLevel << "\n";
    }
}

// Main Function
int main() {
    CampNode* campRoot = NULL;
    SurvivorNode* survivorRoot = NULL;
    vector<SurvivorNode*> maxHeap, minHeap;
    int choice, skillLevel;
    string campName, survivorName;

    while (true) {
        // Display the main menu
        cout << "\n=== Zombie Apocalypse Survival System ===\n";
        cout << "1. Camp Management (Binary Tree)\n";
        cout << "2. Survivor Skills (BST)\n";
        cout << "3. Leaderboard Management (Heap)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int campChoice;
                while (true) {
                    // Display camp management options
                    cout << "\n--- Camp Management ---\n";
                    cout << "1. Add Camp\n2. Search Camp\n3. Delete Camp\n";
                    cout << "4. Display Preorder\n5. Display Inorder\n6. Display Postorder\n7. Exit to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> campChoice;

                    if (campChoice == 7) break;

                    switch (campChoice) {
                        case 1:
                            cout << "Enter camp name: ";
                            cin.ignore();
                            getline(cin, campName);
                            campRoot = InsertCamp(campRoot, campName);
                            break;
                        case 2:
                            cout << "Enter camp name to search: ";
                            cin.ignore();
                            getline(cin, campName);
                            if (SearchCamp(campRoot, campName)) {
                                cout << "Camp found: " << campName << "\n";
                            } else {
                                cout << "Camp not found.\n";
                            }
                            break;
                        case 3:
                            cout << "Enter camp name to delete: ";
                            cin.ignore();
                            getline(cin, campName);
                            campRoot = DeleteCamp(campRoot, campName);
                            break;
                        case 4:
                            cout << "Preorder Traversal: ";
                            PreOrderCamp(campRoot);
                            cout << "\n";
                            break;
                        case 5:
                            cout << "Inorder Traversal: ";
                            InOrderCamp(campRoot);
                            cout << "\n";
                            break;
                        case 6:
                            cout << "Postorder Traversal: ";
                            PostOrderCamp(campRoot);
                            cout << "\n";
                            break;
                        default:
                            cout << "Invalid choice. Try again.\n";
                    }
                }
                break;
            }

            case 2: {
                int survivorChoice;
                while (true) {
                    // Display survivor management options
                    cout << "\n--- Survivor Skills ---\n";
                    cout << "1. Add Survivor\n2. Search Survivor\n3. Display Preorder\n4. Display Inorder\n5. Display Postorder\n6. Exit to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> survivorChoice;

                    if (survivorChoice == 6) break;

                    switch (survivorChoice) {
                        case 1:
                            cout << "Enter survivor name: ";
                            cin.ignore();
                            getline(cin, survivorName);
                            cout << "Enter skill level: ";
                            cin >> skillLevel;
                            survivorRoot = InsertSurvivor(survivorRoot, survivorName, skillLevel);
                            insertMaxHeap(maxHeap, CreateSurvivor(survivorName, skillLevel));
                            insertMinHeap(minHeap, CreateSurvivor(survivorName, skillLevel));
                            break;
                        case 2:
                            cout << "Enter skill level to search: ";
                            cin >> skillLevel;
                            if (SearchSurvivor(survivorRoot, skillLevel)) {
                                cout << "Survivor found with skill level " << skillLevel << ".\n";
                            } else {
                                cout << "Survivor not found.\n";
                            }
                            break;
                        case 3:
                            cout << "Preorder Traversal: ";
                            PreOrderSurvivor(survivorRoot);
                            cout << "\n";
                            break;
                        case 4:
                            cout << "Inorder Traversal: ";
                            InOrderSurvivor(survivorRoot);
                            cout << "\n";
                            break;
                        case 5:
                            cout << "Postorder Traversal: ";
                            PostOrderSurvivor(survivorRoot);
                            cout << "\n";
                            break;
                        default:
                            cout << "Invalid choice. Try again.\n";
                    }
                }
                break;
            }

            case 3: {
                int heapChoice;
                while (true) {
                    // Display leaderboard management options
                    cout << "\n--- Leaderboard Management ---\n";
                    cout << "1. Display Survivor of the Day (Max-Heap)\n";
                    cout << "2. Display Lowest Survivors (Min-Heap)\n";
                    cout << "3. Exit to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> heapChoice;

                    if (heapChoice == 3) break;

                    switch (heapChoice) {
                        case 1:
                            displayMaxHeapLeaderboard(maxHeap);
                            break;
                        case 2:
                            displayMinHeapLeaderboard(minHeap);
                            break;
                        default:
                            cout << "Invalid choice. Try again.\n";
                    }
                }
                break;
            }

            case 4:
                // Exit the program
                cout << "Exiting the program. Stay safe!\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
