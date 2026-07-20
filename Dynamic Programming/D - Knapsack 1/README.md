# D - Knapsack 1

## Contest Information

| Property | Value |
|----------|-------|
| **Contest** | Educational DP Contest |
| **Problem** | D - Knapsack 1 |
| **Difficulty** | ⭐⭐⭐☆☆ |
| **Category** | Dynamic Programming |
| **Language** | C++17 |
| **Status** | ✅ Accepted |

---

# Problem Link

https://atcoder.jp/contests/dp/tasks/dp_d

---

# Problem Overview

There are **N** items, each having a **weight** and a **value**.

Choose a subset of items such that:

- The total weight does not exceed the knapsack capacity **W**.
- The total value obtained is maximized.

Each item can be selected **at most once**, making this the classic **0/1 Knapsack Problem**.

---

# Key Observation

For every item, there are exactly two choices:

- **Skip the item**, keeping the current answer unchanged.
- **Take the item**, provided the remaining capacity allows it.

Since each item can only be chosen once, every decision depends on whether the current item is included or excluded.

This naturally leads to Dynamic Programming.

---

# Approach

Let

```
dp[j]
```

represent the **maximum value achievable using a knapsack capacity of exactly `j` (or at most `j`)** after processing the current set of items.

Initially,

```
dp[j] = 0
```

for every capacity.

For each item:

- Traverse capacities **from W down to weight**.
- Either:
  - Ignore the current item.
  - Include it and improve the answer.

Reverse traversal ensures an item is never used more than once.

---

# Algorithm

1. Create a DP array of size `W + 1`.
2. Initialize every state to `0`.
3. Process every item one by one.
4. Traverse capacities from `W` down to the item's weight.
5. Update

```
dp[capacity] =
max(dp[capacity],
    dp[capacity-weight] + value)
```

6. The answer is `dp[W]`.

---

# Complexity Analysis

| Complexity | Value |
|------------|-------|
| **Time Complexity** | **O(N × W)** |
| **Space Complexity** | **O(W)** |

---

# Dynamic Programming State

| State | Meaning |
|--------|---------|
| `dp[j]` | Maximum value obtainable using knapsack capacity `j` |

---

# Transition

For every item `(weight, value)`:

```
dp[capacity] =
max(dp[capacity],
    dp[capacity-weight] + value)
```

where

```
capacity >= weight
```

Capacities are processed in **decreasing order** so that each item contributes only once.

---

# Edge Cases

- Capacity smaller than every item's weight.
- Capacity large enough to include every item.
- Multiple items having identical weights or values.
- Maximum capacity (`W = 100000`).
- Very large total value requiring `long long`.

---

# STL Used

- vector
- pair
- max

---

# Implementation Notes

- Uses **space-optimized Bottom-Up Dynamic Programming**.
- Reverse traversal guarantees the **0/1 property**.
- Uses `long long` since the answer may exceed 32-bit integer limits.
- Suitable for the given constraints.

---

# Key Takeaways

- 0/1 Knapsack is one of the most fundamental Dynamic Programming problems.
- Proper DP state definition simplifies the transition.
- Reverse iteration over capacities prevents selecting the same item multiple times.
- Space optimization reduces memory usage from **O(N × W)** to **O(W)** without affecting the time complexity.

---

# Possible Optimization

The classical DP solution stores an `N × W` table.

Since every state depends only on the previous item, the DP can be compressed into a **single one-dimensional array**, reducing the space complexity from

```
O(N × W)
```

to

```
O(W)
```

while maintaining the same **O(N × W)** time complexity.
