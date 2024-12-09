Description of Each Functionality in the Code
This program provides a comprehensive system to manage camps, survivors, and leaderboards during a fictional zombie apocalypse scenario. It utilizes binary trees, binary search trees (BSTs), and heaps for data organization and efficient operations. Below is a breakdown of each functionality in the code:

1. Camp Management (Binary Tree)
Purpose: Manages a collection of camps in a hierarchical structure using a binary tree.

Key Functionalities:

Add Camp:

Inserts a new camp into the binary tree, ensuring proper positioning based on alphabetical order.
Function: InsertCamp()
Helper Function: CreateCamp()
Search Camp:

Checks if a camp exists in the binary tree by traversing it.
Function: SearchCamp()
Delete Camp:

Removes a camp from the binary tree, rebalancing the tree as needed.
Function: DeleteCamp()
Helper Function: FindMinCamp() (finds the minimum node in the right subtree for replacement during deletion).
Display Camps:

Displays camps in Preorder, Inorder, or Postorder traversals, which offer different perspectives on the data structure.
Functions:
PreOrderCamp()
InOrderCamp()
PostOrderCamp()
2. Survivor Skills Management (Binary Search Tree)
Purpose: Tracks survivors and their skill levels using a binary search tree (BST) for efficient searching and ranking.

Key Functionalities:

Add Survivor:

Inserts a survivor with their skill level into the BST, maintaining the order where lower skill levels go to the left and higher ones to the right.
Function: InsertSurvivor()
Helper Function: CreateSurvivor()
Search Survivor:

Finds a survivor based on their skill level.
Function: SearchSurvivor()
Display Survivors:

Outputs the list of survivors in Preorder, Inorder, or Postorder traversal orders, showing their names and skill levels.
Functions:
PreOrderSurvivor()
InOrderSurvivor()
PostOrderSurvivor()
3. Leaderboard Management (Heap)
Purpose: Maintains leaderboards of survivors using heaps for ranking by highest and lowest skill levels.

Key Functionalities:

Insert into Max-Heap:

Adds a survivor to a heap structure where the survivor with the highest skill level always remains at the top.
Function: insertMaxHeap()
Insert into Min-Heap:

Adds a survivor to a heap structure where the survivor with the lowest skill level always remains at the top.
Function: insertMinHeap()
Display Max-Heap Leaderboard:

Shows the survivors ranked by the highest skill levels.
Function: displayMaxHeapLeaderboard()
Display Min-Heap Leaderboard:

Shows the survivors ranked by the lowest skill levels.
Function: displayMinHeapLeaderboard()
4. Main Program Execution
Purpose: The main() function serves as the central hub for user interaction. It coordinates the functionality described above through a menu-driven system.

Key Functionalities:

Main Menu:

Provides access to three primary features: Camp Management, Survivor Skills Management, and Leaderboard Management.
Facilitates exit from the program.
Error Handling:

Validates user input to ensure correct menu navigation.
