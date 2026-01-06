# 1161. Maximum Level Sum of a Binary Tree

**Platform:** LeetCode  
**Difficulty:** Medium  
**Pattern:** BFS / Level Order Traversal

---

## 🧩 Problem Summary

Given the root of a binary tree, return the **level number (1-indexed)** which has the **maximum sum of node values**.  
If there are multiple levels with the same maximum sum, return the **smallest level number**.

---

## 💡 Approach

### Key Observation

- Each level of the tree can be processed independently.
- A **level order traversal (BFS)** naturally allows us to compute the sum of nodes at each level.

### Strategy

1. Perform BFS using a queue.
2. For each level:
   - Compute the sum of node values.
   - Compare it with the maximum sum seen so far.
3. If the current level sum is greater, update:
   - `maxSum`
   - `answerLevel`
4. Increment level counter and continue.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(N)` — each node is visited once.
- **Space Complexity:** `O(N)` — queue storage in worst case.

---

## 🧠 Interview Notes

- BFS is preferred over DFS when level-wise computation is required.
- Be careful with:
  - Initializing `maxSum` as `Integer.MIN_VALUE`
  - Returning the **smallest level** in case of ties.

---

## 📝 Learnings

- Level indexing should start from **1**, not 0.
- Proper initialization avoids edge case failures when all values are negative.

---
