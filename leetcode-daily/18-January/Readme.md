# 1895. Largest Magic Square

**Platform:** LeetCode  
**Difficulty:** Medium  
**Pattern:** Prefix Sum + Implementation

---

## 🧩 Problem Summary

Given an `m × n` integer grid, return the **side length `k`** of the largest magic square that can be found in the grid.

A `k × k` magic square satisfies:

- All row sums are equal
- All column sums are equal
- Both diagonal sums are equal

> **Note:** A `1 × 1` grid is trivially a magic square.

---

## 💡 Approach

### Key Observations

- A magic square must be **square-shaped**, so the maximum possible size is `min(rows, cols)`.
- Directly computing row, column, and diagonal sums repeatedly would be expensive.
- **Prefix sums** allow constant-time calculation of row and column sums, making validation efficient.

---

## 🧠 Strategy

1. Precompute:
   - Row-wise prefix sums
   - Column-wise prefix sums
2. Iterate over all possible square sizes `k` from **largest to smallest**:
   - For each `(i, j)` top-left corner, check if a `k × k` square fits
   - Validate:
     - All row sums are equal
     - All column sums are equal
     - Both diagonals have the same sum
3. Return the first valid `k` found
4. If none exist, return `1`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(N × M × min(N, M))`  
  (checking all square sizes and positions)

- **Space Complexity:** `O(N × M)`  
  (prefix sum arrays)

Where:

- `N` = number of rows
- `M` = number of columns

---

## 📝 Learnings

- Prefix sums are extremely useful for optimizing repeated range sum queries.
- Iterating from **largest to smallest** allows early termination.
- Implementation-heavy problems require careful indexing and boundary checks.
