# 1975. Maximum Matrix Sum

**Platform:** LeetCode  
**Difficulty:** Medium  
**Pattern:** Greedy

---

## 🧩 Problem Summary

Given an `n x n` integer matrix, you can multiply any adjacent element by `-1` any number of times.  
Return the **maximum possible sum** of all matrix elements after performing any number of such operations.

---

## 💡 Approach

### Key Observation

- Since multiplying by `-1` can be done any number of times, **only the sign parity matters**.
- We can freely move negative signs across the matrix.

### Strategy

1. Take the **absolute value of every element** and add it to the total sum.
2. Count how many elements are **negative**.
3. Track the **minimum absolute value** in the matrix.

### Why This Works

- If the number of negative elements is **even**, all values can be made positive.
- If the number of negative elements is **odd**, exactly one element must remain negative.
- To maximize the sum, that negative value should be the **smallest absolute value**.

### Final Calculation

- If negative count is even → result = total sum
- If negative count is odd → result = `totalSum - 2 * minAbsoluteValue`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 🧠 Interview Notes

- This problem tests greedy thinking and observation, not matrix traversal.
- Always consider **sign parity** in problems involving flipping values.
- Avoid simulating operations; derive the math directly.

---

## 📝 Learnings

- Greedy solutions often rely on global observations.
- Absolute values simplify sign-based problems significantly.
