# 3047. Find the Largest Area of Square Inside Two Rectangles

**Platform:** LeetCode  
**Difficulty:** Medium  
**Pattern:** Math / Geometry

---

## 🧩 Problem Summary

You are given two 2D integer arrays `bottomLeft` and `topRight`, where:

- `bottomLeft[i] = [aᵢ, bᵢ]` represents the bottom-left corner of the _iᵗʰ_ rectangle
- `topRight[i] = [cᵢ, dᵢ]` represents the top-right corner of the _iᵗʰ_ rectangle

Your task is to find the **maximum possible area of a square** that can fit **entirely inside the intersection of at least two rectangles**.

If no such square exists, return `0`.

---

## 💡 Approach

### Key Observations

- A square can only be formed if **two rectangles intersect**.
- The intersection of two rectangles is itself a **rectangle**.
- The largest square that can fit inside a rectangle has a side length equal to  
  `min(intersection width, intersection height)`.

---

### Rectangle Intersection Logic

For two rectangles `i` and `j`:

- **Intersection width**
  - width = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0])

- **Intersection height**
- height = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1])

- If `width <= 0` or `height <= 0`, the rectangles do **not intersect**.

---

### Strategy

1. Iterate over **all pairs of rectangles**.
2. For each pair:

- Compute intersection width and height.
- If both are positive, compute:
  ```
  side = min(width, height)
  ```

3. Track the **maximum side length** across all valid pairs.
4. Return: maxSide × maxSide

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(N²)`  
  (checking all rectangle pairs)

- **Space Complexity:** `O(1)`

Where `N` is the number of rectangles.

---

## 📝 Learnings

- Many geometry problems reduce to **pairwise comparisons**.
- Always compute intersection boundaries using:
- `max(bottomLeft)`
- `min(topRight)`
- When fitting shapes inside another, identify the **limiting dimension**.
