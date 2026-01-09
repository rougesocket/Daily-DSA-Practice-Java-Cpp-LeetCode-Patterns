# 865. Smallest Subtree with All the Deepest Nodes

**Platform:** LeetCode  
**Difficulty:** Medium  
**Pattern:** DFS / BFS

---

## 🧩 Problem Summary

Given the root of a binary tree, return the smallest subtree that contains **all the deepest nodes** in the original tree.  
A node is considered deepest if it has the maximum depth among all nodes in the tree.

---

## 💡 Approach

### Key Observation

- The idea is to locate all the deepest nodes using BFS (or DFS) and then find the **Lowest Common Ancestor (LCA)** of the leftmost and rightmost deepest nodes.
- This works because the required subtree must be common to **all deepest leaves**, and the LCA of the extreme deepest nodes will include all others.

---

### Strategy

1. Perform **BFS** and store all nodes at the deepest level in a list.
2. Compute the **LCA** of the first and last nodes in this list.
3. Return the LCA as the root of the smallest subtree containing all deepest nodes.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(N)` — each node is visited once.
- **Space Complexity:** `O(N)` — for BFS queue and recursion stack in LCA.

---

## 🧠 Interview Notes

- This problem can also be solved using a **single DFS traversal** by returning both depth and subtree root.
- When asked to find a common parent among multiple nodes, always consider whether **LCA** can be applied.

---

## 📝 Learnings

- Problems involving “smallest subtree” or “common ancestor” often reduce to **LCA-based solutions**.
- BFS is useful when identifying nodes at the same depth before applying tree logic.
