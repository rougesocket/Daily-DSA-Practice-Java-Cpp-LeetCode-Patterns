# 712. Minimum ASCII Delete Sum for Two Strings

**Platform:** LeetCode  
**Difficulty:** Medium  
**Pattern:** DP on Subsequence (LCS Variant)

---

## 🧩 Problem Summary

Given two strings `s1` and `s2`, return the **minimum ASCII sum of deleted characters** required to make the two strings equal.

---

## 💡 Approach

### Key Observation

- After deleting characters from both strings, the remaining characters must form a **common subsequence**.
- To minimize the total deletion cost, we should **maximize the ASCII sum of the common subsequence** that remains.
- This makes the problem a **variation of the Longest Common Subsequence (LCS)** problem, where:
  - Instead of tracking length, we track the **maximum ASCII sum** of the common subsequence.

---

### Strategy

1. Compute the **total ASCII sum** of all characters in `s1` and `s2`.
2. Use DP to compute the **maximum ASCII sum of the common subsequence** between `s1` and `s2`.
3. The minimum deletion cost is: (total sum of s1 + total sum of s2) − 2 × (LCS ASCII sum)

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(N × M)`
- **Space Complexity:** `O(N × M)`

Where `N` and `M` are the lengths of `s1` and `s2`.

---

## 🚀 Optimization

### Tabulation

- Eliminates recursion stack overhead
- **Time Complexity:** `O(N × M)`
- **Space Complexity:** `O(N × M)`

---

### Space Optimization

- Only the previous row is required to compute the current row
- **Time Complexity:** `O(N × M)`
- **Space Complexity:** `O(M)`

---

## 📝 Learnings

- Many subsequence-based DP problems are **extensions of classic LCS patterns**.
- Always verify whether a problem optimizes **length**, **sum**, or **cost** — not all LCS variants are about length.
