# C - Vacation

## Contest Information

| Property | Value |
|:---------|:------|
| Contest | Educational DP Contest |
| Problem | C - Vacation |
| Difficulty | ⭐⭐☆☆☆ |
| Category | Dynamic Programming |
| Language | C++17 |
| Status | ✅ Accepted |

---

## Problem Link

https://atcoder.jp/contests/dp/tasks/dp_c

---

## Problem Overview

Taro has **N** vacation days.

For each day, he can perform one of the following activities:

- Swimming
- Bug Catching
- Homework

Each activity provides a certain amount of happiness.

The only restriction is that **the same activity cannot be performed on two consecutive days**.

The objective is to maximize the total happiness earned over all vacation days.

---

## Key Observation

The happiness earned on the current day depends only on:

- the activity chosen today, and
- the activity performed on the previous day.

This means we never need to remember the complete sequence of activities.

Only the best result ending with each activity from the previous day is required.

This property makes the problem a classic **Dynamic Programming** problem.

---

## Approach

Define a DP state:

- `dp[i][0]` → Maximum happiness if Swimming is chosen on day `i`
- `dp[i][1]` → Maximum happiness if Bug Catching is chosen on day `i`
- `dp[i][2]` → Maximum happiness if Homework is chosen on day `i`

For every day:

- Swimming can only follow Bug Catching or Homework.
- Bug Catching can only follow Swimming or Homework.
- Homework can only follow Swimming or Bug Catching.

For each activity, choose the better of the two valid previous activities and add today's happiness.

Finally, the maximum among the three states on the last day is the answer.

---

## Algorithm

1. Create a DP table of size `N × 3`.
2. Initialize the first day's values.
3. Iterate through each remaining day.
4. Compute the best happiness for each activity using the previous day's states.
5. Return the maximum value among the three activities on the final day.

---

## Complexity Analysis

| Complexity | Value |
|:----------|:------|
| Time Complexity | **O(N)** |
| Space Complexity | **O(N)** |

---

## Edge Cases

- Only one vacation day.
- Multiple activities having equal happiness.
- Choosing the locally best activity is not always optimal.
- Maximum input size (`N = 100000`).

---

## Dynamic Programming State

| State | Meaning |
|:------|:--------|
| `dp[i][0]` | Maximum happiness ending with Swimming on day `i` |
| `dp[i][1]` | Maximum happiness ending with Bug Catching on day `i` |
| `dp[i][2]` | Maximum happiness ending with Homework on day `i` |

---

## Transition

```
Swimming
= swimming[i] + max(Bug Catching, Homework)

Bug Catching
= bug[i] + max(Swimming, Homework)

Homework
= homework[i] + max(Swimming, Bug Catching)
```

---

## STL Used

- `vector`
- `max`

---

## Implementation Notes

- Uses bottom-up Dynamic Programming.
- Stores the best possible happiness for every activity on every day.
- Avoids recursion, eliminating stack overflow concerns.
- Suitable for the maximum constraints.

---

## Key Takeaways

- Dynamic Programming is useful when a decision depends only on a limited number of previous states.
- The state should capture only the information required for future transitions.
- Clearly defining DP states often simplifies transition equations.
- Since each state depends only on the previous day, this solution can be further optimized to **O(1)** space.

---

## Possible Optimization

Instead of storing all `N` days, only the previous day's values are required.

This reduces the space complexity from:

```
O(N)
```

to

```
O(1)
```

while maintaining the same **O(N)** time complexity.
