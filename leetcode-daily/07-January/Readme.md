# 1339. Maximum Product of Splitted Binary Tree

**Platform:** LeetCode  
**Difficulty:** Medium  
**Pattern:** Tree + DFS (Subtree Sum)

---

## 🧩 Problem Summary

Given the root of a binary tree, remove exactly one edge to split the tree into two subtrees.  
Return the **maximum product** of the sums of the two resulting subtrees.

---

## 💡 Approach

### Key Observation

- Removing an edge splits the tree into:
  - A subtree with sum `subTreeSum`
  - The remaining tree with sum `totalSum - subTreeSum`
- The product is: subTreeSum \* (totalSum - subTreeSum)

---

### Strategy

1. Compute the total sum of the tree using DFS.
2. Perform another DFS to compute subtree sums.
3. At each node:
   - Treat the subtree rooted at that node as one part.
   - Compute the product and update the maximum.
4. Return the maximum product modulo `10^9 + 7`.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(N)` — each node is visited once.
- **Space Complexity:** `O(N)` — recursion stack in worst case.

---

## 🧠 Interview Notes

- Use `long / long long` to avoid overflow.
- Precision errors occur if `double` is used.
- Modulo is applied only at the end.

---

## 📝 Learnings

- Subtree sum problems often require **post-order DFS**.
- Product-based problems demand careful datatype selection.
