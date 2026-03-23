# 1594. Maximum Non-Negative Product in a Matrix

**Platform:** LeetCode  
**Difficulty:** Medium  
**Pattern:** DP on Grid

---

## 🧩 Problem Summary

You are located at the top-left corner `(0, 0)` of a matrix. At each step, you can move either **right** or **down**.

Among all possible paths from `(0, 0)` to `(m - 1, n - 1)`, find the path that yields the **maximum non-negative product**.

- The product of a path is the product of all visited cells.
- Return the result modulo `1e9 + 7`.
- If the maximum product is negative, return `-1`.

---

## 💡 Approach

### Key Observations

- If all numbers were positive, we could simply take the **maximum product path** using DP.
- However, due to **negative numbers**, the situation becomes tricky:
  - A **negative × negative = positive**
  - A **positive × negative = negative**
- So, at every cell, we must track:
  - **Maximum product so far**
  - **Minimum product so far**

> Why track minimum?  
> Because a large negative value can become the **maximum positive** when multiplied by another negative number.

---

## 🧠 Strategy

1. Create two DP tables:
   - `maxDP[i][j]` → maximum product reaching `(i, j)`
   - `minDP[i][j]` → minimum product reaching `(i, j)`

2. Initialize:
   - `maxDP[0][0] = grid[0][0]`
   - `minDP[0][0] = grid[0][0]`

3. Fill first row and first column:
   - Only one path exists → cumulative multiplication

4. For each cell `(i, j)`:
   - Consider values from:
     - Top `(i-1, j)`
     - Left `(i, j-1)`
   - Compute:
     ```
     maxDP[i][j] = max(all previous values) * grid[i][j]
     minDP[i][j] = min(all previous values) * grid[i][j]
     ```

5. Final Answer:
   - Take `max(maxDP[n-1][m-1], minDP[n-1][m-1])`
   - If result < 0 → return `-1`
   - Else return result % `1e9+7`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(N × M)`
- **Space Complexity:** `O(N × M)`

Where:

- `N` = number of rows
- `M` = number of columns

---

## 📝 Learnings

- When dealing with multiplication and negative numbers:
  - Always track both **maximum and minimum**
- Grid DP problems often require **state expansion** beyond a single value
- Sign handling is critical in product-based problems

---
