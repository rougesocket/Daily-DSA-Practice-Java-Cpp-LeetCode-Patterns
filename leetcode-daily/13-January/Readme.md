# 3453. Separate Squares I

**Platform:** LeetCode  
**Difficulty:** Medium  
**Pattern:** Binary Search on Answer (Search Space)

---

## 🧩 Problem Summary

You are given a 2D integer array `squares`, where each  
`squares[i] = [xi, yi, li]` represents:

- `(xi, yi)` → bottom-left corner of a square
- `li` → side length of the square

All squares are parallel to the x-axis.

Your task is to find the **minimum y-coordinate** of a horizontal line such that:

> The **total area above the line** equals the **total area below the line**.

### Important Notes

- Squares **may overlap**
- Overlapping areas must be **counted multiple times**
- The horizontal line may **pass through squares**

---

## 💡 Approach

### Key Observations

- If a y-coordinate `p` satisfies the condition (area above = area below), then:
  - Any value slightly greater than `p` (e.g. `p + ε`) will also satisfy it.
- Hence, the valid answers form a **continuous range**.
- We are asked for the **minimum** such value → classic **tick–cross pattern**.
- This makes the problem ideal for **Binary Search on the answer space**.

---

### Area Contribution Logic

For a candidate horizontal line at height `mid`, each square contributes area in one of three ways:

1. **Completely below the line**
   - Entire area contributes to **below**
2. **Completely above the line**
   - Entire area contributes to **above**
3. **Line intersects the square**
   - Split area into:
     - Below area: `(mid - y) * l`
     - Above area: `(y + l - mid) * l`

> Note: `y + l` is the top boundary of the square.

---

### Strategy

1. Define search space:
   - `low = 0`
   - `high = 2e9 + 1` (maximum possible y-range based on constraints)
2. Run binary search for a **fixed number of iterations** to achieve precision.
3. For each `mid`:
   - Compute total area **above** and **below** the line.
   - If `below > above`, move the line **upward**
   - Else, move the line **downward**
4. The final answer converges at the **right pointer**

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(N × log(range))`
- **Space Complexity:** `O(1)`

Where `N` is the number of squares.

---

## 📝 Learnings

- Binary Search is applicable even on **continuous values**
- When a condition holds over a **range**, think in terms of **binary search on answer**
- Use `double` to safely avoid overflow in area calculations
