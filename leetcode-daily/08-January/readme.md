# 1458. Max Dot Product of Two Subsequences

**Platform:** LeetCode  
**Difficulty:** Hard  
**Pattern:** DP on Subsequences

---

## 🧩 Problem Summary

Given two integer arrays `nums1` and `nums2`, return the **maximum dot product** between **non-empty subsequences** of equal length from both arrays.

---

## 💡 Approach

### Key Observation

- This problem is similar to **LCS**, but instead of matching characters, we compute the **dot product**.
- At each index, we have four choices:

  | nums1[i]    | nums2[j]    |
  | ----------- | ----------- |
  | ❌ Not Pick | ❌ Not Pick |
  | ✅ Pick     | ❌ Not Pick |
  | ❌ Not Pick | ✅ Pick     |
  | ✅ Pick     | ✅ Pick     |

dp[i][j] = maximum dot product using non-empty subsequences
from nums1[0..i] and nums2[0..j]

---

### Strategy

1. **Base Case**

   - If either array is exhausted, return `INT_MIN`
   - Zero cannot be used because subsequences must be **non-empty**, and all values could be negative.

2. **Pick Both Elements**

   - Product = `nums1[i] * nums2[j]`
   - Add `max(0, dp[i-1][j-1])` to avoid decreasing the result.

3. **Skip One Element**

   - Skip `nums2[j]` → `dp[i][j-1]`
   - Skip `nums1[i]` → `dp[i-1][j]`

4. **Transition**

dp[i][j] = max(
nums1[i] \* nums2[j] + max(0, dp[i-1][j-1]),
dp[i][j-1],
dp[i-1][j]
)

---

## ⏱️ Complexity Analysis

### Memoization

- **Time Complexity:** `O(N * M)`
- **Space Complexity:** `O(N * M)` (DP table + recursion stack)

---

## 🚀 Optimization

### Tabulation

- Removes recursion stack
- **Time Complexity:** `O(N * M)`
- **Space Complexity:** `O(N * M)`

---

### Space Optimization

- Only the previous row is required
- **Time Complexity:** `O(N * M)`
- **Space Complexity:** `O(M)`

---

## 🧠 Interview Notes

- `INT_MIN` is required because zero is not a valid base case.
- Using `max(0, dp[i-1][j-1])` ensures negative chains do not reduce the product.

---

## 📝 Learnings

- Many hard DP problems are extensions of classic patterns like LCS.
- Handling negative values correctly is crucial in optimization problems.
