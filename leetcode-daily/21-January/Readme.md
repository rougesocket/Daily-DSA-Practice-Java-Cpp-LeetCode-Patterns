# 3315. Construct the Minimum Bitwise Array II

**Platform:** LeetCode  
**Difficulty:** Medium  
**Pattern:** Bit Manipulation

---

## 🧩 Problem Summary

You are given an array `nums` consisting of `n` **prime integers**.

Construct an array `ans` of length `n` such that for every index `i`: ans[i] OR (ans[i] + 1) == nums[i]

If it is not possible to construct such a value, set `ans[i] = -1`.

> **Constraint:** Each `ans[i]` must be **minimized**.

---

## 💡 Approach

### Key Observations

- Except for `2`, **all prime numbers are odd**.
- For an odd number `x`, `x + 1` is even.
- In binary representation:
  - Adding `1` flips the **rightmost `0` bit** to `1`
  - All trailing `1`s to its right become `0`

Example:
39 -> 0010 0111
40 -> 0010 1000
OR -> 0010 1111

- This means:
  - To satisfy `a OR (a + 1) = nums[i]`
  - `nums[i]` must have **at least one `0` bit**
  - We can construct the smallest possible `a` by:
    - Finding the **first `0` bit from the right**
    - Clearing the bit immediately to its left

- **Special Case:**
  - `nums[i] = 2` (the only even prime)
  - Its LSB is `0`, and there is no bit to the left → **impossible**

---

## 🧠 Strategy

1. Iterate over the array `nums`
2. If the value is `2`, append `-1`
3. Otherwise:
   - Scan bits from **LSB to MSB**
   - Find the first `0` bit
   - Clear the bit immediately to its left
4. Add the resulting number to `ans`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(N × 32)`  
  (checking bits for each number)

- **Space Complexity:** `O(1)`  
  (excluding output array)

Where:

- `N` = size of `nums`

---

## 📝 Learnings

- Binary behavior of `x` and `x + 1` is a powerful tool in bit manipulation problems.
- Observing patterns in binary transitions often removes the need for brute force.
- Always handle edge cases early (`2` in this problem).
