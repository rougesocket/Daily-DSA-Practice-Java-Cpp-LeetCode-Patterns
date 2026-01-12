# 1266. Minimum Time Visiting All Points

**Platform:** LeetCode  
**Difficulty:** Easy  
**Pattern:** Math / Greedy

---

## 🧩 Problem Summary

There are `n` points with integer coordinates `points[i] = [xi, yi]`.  
Return the **minimum time in seconds** to visit all the points in the given order.

In **1 second**, you can:

- Move vertically by 1 unit
- Move horizontally by 1 unit
- Move diagonally (1 unit vertically + 1 unit horizontally)

---

## 💡 Approach

### Key Observation

- Diagonal movement allows reducing both the `x` and `y` distances **simultaneously** in one second.
- Therefore, the minimum time required to move from one point to the next is determined by the **maximum** of:
  - Horizontal distance `|x2 - x1|`
  - Vertical distance `|y2 - y1|`

---

### Strategy

1. Iterate through the points in order.
2. For each adjacent pair of points:
   - Compute `dx = |x2 - x1|`
   - Compute `dy = |y2 - y1|`
3. Add `max(dx, dy)` to the total time.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(1)`

Where `N` is the number of points.

---

## 📝 Learnings

- When diagonal movement is allowed, distance problems often reduce to using `max(dx, dy)` instead of Manhattan distance.
- Simple greedy observations can eliminate the need for simulation.
