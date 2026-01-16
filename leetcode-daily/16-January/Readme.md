# 2943. Maximize Area of Square Hole in Grid

**Platform:** LeetCode  
**Difficulty:** Medium  
**Pattern:** Sorting / Consecutive Sequence

---

## 🧩 Problem Summary

You are given two integers `n` and `m`, along with two integer arrays `hBars` and `vBars`.

- `hBars` represents removable **horizontal bars**
- `vBars` represents removable **vertical bars**

After removing any number of bars (possibly none), return the **maximum possible area of a square-shaped hole** in the grid.

---

## 📌 Important Notes

- The grid consists of `n + 2` horizontal bars and `m + 2` vertical bars.
- Bars are indexed starting from **1**.
- Each cell in the grid is initially of size `1 × 1`.
- Bars not listed in `hBars` or `vBars` are **fixed** and cannot be removed.

---

## 💡 Approach

### Key Observations

- Removing a **single bar** does not necessarily increase the size of the hole.
- Removing **consecutive bars** increases the effective side length of the hole.
- The same logic applies independently to:
  - Horizontal bars → height
  - Vertical bars → width
- Since we are asked to form a **square** (not a rectangle):
  - Both sides must be equal
  - Hence, the achievable side length is the **minimum** of:
    - Maximum consecutive removable horizontal bars
    - Maximum consecutive removable vertical bars

> Removing extra bars beyond this minimum does not help, as it would form a rectangle instead of a square.

---

### Strategy

1. Sort `hBars` and `vBars` to group consecutive indices.
2. Find the **longest consecutive sequence** in `hBars`.
3. Find the **longest consecutive sequence** in `vBars`.
4. The side of the square is: side = min(maxHorizontal, maxVertical)
5. Return: area = side × side

---

### Finding the Longest Consecutive Sequence

- Traverse the sorted array:
- Extend the current sequence if the difference between adjacent elements is `1`
- Otherwise, reset the counter
- Track and return the maximum length found

---

## ⏱️ Complexity Analysis

- **Time Complexity:**  
  `O(N log N + M log M)`  
  (Sorting both arrays)

- **Space Complexity:**  
  `O(1)` (Ignoring sorting space)

Where:

- `N` = size of `hBars`
- `M` = size of `vBars`

---

## 📝 Learnings

- Always reason from the **smallest unit** (1×1 grid) and analyze how operations expand it
- Consecutive sequences often signal **sorting + linear scan**
- Constraints like “square” vs “rectangle” usually imply taking a **minimum**
