# 3314. Construct the Minimum Bitwise Array I

**Platform:** LeetCode  
**Difficulty:** Easy  
**Pattern:** Bit Manipulation (Brute Force)

---

## 🧩 Problem Summary

You are given an array `nums` consisting of `n` **prime integers**.

Construct an array `ans` of length `n` such that for every index `i`: ans[i] OR (ans[i] + 1) == nums[i]

If it is not possible to construct such a value, set `ans[i] = -1`.

> **Constraint:** Each `ans[i]` must be **minimized**.

---

## 💡 Approach

### Key Observation

- The constraints are small enough to allow a **brute-force solution**.
- Since `ans[i]` must be minimized, we can try all possible values smaller than `nums[i]` and stop at the first valid one.

---

## 🧠 Strategy

1. Iterate over each element in `nums`.
2. For the current number `x`, try all values `a` from `1` to `x - 1`.
3. Check if: a OR (a + 1) == x
4. If a valid `a` is found:

- Assign `ans[i] = a`
- Stop searching further (to ensure minimality).

5. If no valid value exists, assign `ans[i] = -1`.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(N × N)`
- **Space Complexity:** `O(1)` (excluding output array)

Where:

- `N` = size of `nums`

---

## 📝 Learnings

- Always analyze constraints before over-optimizing.
- Brute-force solutions can be perfectly valid when limits are small.
- Minimization problems often benefit from early stopping.
