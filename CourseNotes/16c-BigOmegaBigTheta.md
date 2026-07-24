# Lecture: Big-Omega (Ω) and Big-Theta (Θ) — Lower Bounds and Tight Bounds

---

## Section 1: Why Big-O Alone Isn't Enough

Recall from the Big-O lecture: $f(n) \in O(g(n))$ means $g(n)$ is an **upper bound** on $f(n)$'s growth — "no slower than."

Here's the catch: technically, **linear search is $O(n^2)$**. It's also $O(n^3)$, and $O(2^n)$. All of these are *true* statements, because $n \le c \cdot n^2$ for large enough $n$ — Big-O never promised you the *tightest* description, only *some* valid upper bound.

To actually pin down how an algorithm behaves, we need two more tools:

- **Big-Omega ($\Omega$)** — a **lower bound**: "no faster than."
- **Big-Theta ($\Theta$)** — a **tight bound**: "grows exactly like."

---

## Section 2: Big-Omega ($\Omega$) — Lower Bound

### Formal Definition

$$f(n) \in \Omega(g(n))$$

if and only if there exist positive constants $c > 0$ and $n_0 \ge 1$ such that:

$$f(n) \ge c \cdot g(n) \quad \text{for all } n \ge n_0$$

> **Key Takeaway:** $g(n)$ is a **floor** — $f(n)$ never grows slower than this, for sufficiently large inputs.

### What Ω Is Used For

1. **Describing an algorithm's best case** — the fewest operations it could possibly do, even on the luckiest input.
2. **Describing a problem's inherent difficulty** — a statement about *every possible algorithm* that solves a problem, not just one implementation (see Section 6).

### Example

Insertion sort, given an already-sorted array, only performs one comparison per element (see `17a-Searching&Sorting.md`, Section 2.2) — it can't possibly do less than scan each element once. That floor is:

$$\text{Insertion Sort (best case)} \in \Omega(n)$$

---

## Section 3: Big-Theta ($\Theta$) — Tight Bound

### Formal Definition

$$f(n) \in \Theta(g(n))$$

if and only if:

$$f(n) \in O(g(n)) \quad \text{AND} \quad f(n) \in \Omega(g(n))$$

Equivalently, there exist positive constants $c_1, c_2 > 0$ and $n_0 \ge 1$ such that:

$$c_1 \cdot g(n) \le f(n) \le c_2 \cdot g(n) \quad \text{for all } n \ge n_0$$

> **Key Takeaway:** $\Theta(g(n))$ sandwiches $f(n)$ between two constant multiples of $g(n)$ — it grows **exactly like** $g(n)$, not just "no faster than."

### This Is Usually What People *Mean*

When someone casually says "this algorithm is $O(n \log n)$," they usually mean the bound is *achieved* — i.e., they mean $\Theta(n \log n)$, but say Big-O out of habit, because Big-O is the notation most people learn first. Saying merge sort is "$O(n^2)$" is technically true (it's a valid upper bound) but **useless** — it throws away the precision of knowing merge sort's growth is *exactly* $n \log n$, not just *at most* $n^2$.

### Worked Proof: Extending the 16b Example

Recall from `16b-Big0Notation.md`, Section 3, we proved $f(n) = 3n^2 + 5n + 2 \in O(n^2)$ using $c = 10$, $n_0 = 1$. To upgrade that to $\Theta(n^2)$, we also need the $\Omega$ half:

For all $n \ge 1$: $3n^2 + 5n + 2 \ge 3n^2$ (since $5n + 2 \ge 0$).

So $f(n) \ge 3 \cdot n^2$ for all $n \ge 1$ — choose $c_1 = 3$.

Combined with the earlier upper bound ($c_2 = 10$):

$$3n^2 \le 3n^2 + 5n + 2 \le 10n^2 \quad \text{for all } n \ge 1$$

Therefore $3n^2 + 5n + 2 \in \Theta(n^2)$. $\blacksquare$

---

## Section 4: Important — These Apply *Per Case*, Not Just Per Algorithm

This is the single most common source of confusion with $\Theta$: **you can't always say "this algorithm is $\Theta(g(n))$" without saying *which case* you mean.**

Some algorithms behave the same way regardless of input — for those, a single $\Theta$ describes them completely. Others behave very differently on different inputs, and you must specify best/average/worst case separately.

| Algorithm | Best Case | Worst Case | Single $\Theta$ for the whole algorithm? |
|-----------|-----------|------------|---------------------------------------------|
| Selection Sort | $\Theta(n^2)$ | $\Theta(n^2)$ | **Yes** — always scans the full remainder regardless of input order |
| Merge Sort | $\Theta(n \log n)$ | $\Theta(n \log n)$ | **Yes** — always splits and merges fully regardless of input order |
| Linear Search | $\Theta(1)$ | $\Theta(n)$ | No — depends entirely on where (or whether) the target is found |
| Insertion Sort | $\Theta(n)$ | $\Theta(n^2)$ | No — depends on how much shifting the input requires |
| Quick Sort | $\Theta(n \log n)$ | $\Theta(n^2)$ | No — depends on how balanced the pivot's partitions are |

For the "No" rows, the honest statement is always case-qualified: "insertion sort's *worst case* is $\Theta(n^2)$," not "insertion sort is $\Theta(n^2)$." This is exactly what the **Best / Average / Worst** columns in the `17a` sorting table are already tracking — they're really $\Theta$ values for each case, even though that table (like most references) writes them using the more familiar $O$ symbol.

---

## Section 5: Revisiting the Sorting Table with Correct Notation

| Algorithm | Best Case | Average Case | Worst Case |
|-----------|-----------|----------------|---------------|
| Linear Search | $\Theta(1)$ | $\Theta(n)$ | $\Theta(n)$ |
| Binary Search | $\Theta(1)$ | $\Theta(\log n)$ | $\Theta(\log n)$ |
| Selection Sort | $\Theta(n^2)$ | $\Theta(n^2)$ | $\Theta(n^2)$ |
| Insertion Sort | $\Theta(n)$ | $\Theta(n^2)$ | $\Theta(n^2)$ |
| Merge Sort | $\Theta(n \log n)$ | $\Theta(n \log n)$ | $\Theta(n \log n)$ |
| Quick Sort | $\Theta(n \log n)$ | $\Theta(n \log n)$ | $\Theta(n^2)$ |

Notice every entry here is a **tight** bound ($\Theta$), because for a specific, fixed case (e.g. "worst case"), we actually know the exact growth rate — not just an upper limit. The $O$ notation in `17a` was describing the same reality; $\Theta$ is just the more precise way to say it once you're being careful.

**Quick Sort in general** (not qualified by case) is still correctly described as $O(n^2)$ — since across *all* possible inputs, $n^2$ is a valid ceiling — but its *typical*, average-case behavior is $\Theta(n \log n)$. Both statements are true; they're answering different questions.

---

## Section 6: A Problem-Level Lower Bound (Enrichment)

$\Omega$ isn't only used to describe one algorithm's best case — it can describe the **inherent difficulty of a problem itself**, independent of any specific algorithm.

**Classic result:** any sorting algorithm that works only by *comparing* elements (as every algorithm in `17a` does) requires **$\Omega(n \log n)$ comparisons in the worst case** — no comparison-based sort can ever beat this, no matter how cleverly it's written.

**Why (sketch):** there are $n!$ possible orderings of $n$ elements. A comparison-based sort has to be able to distinguish between all of them, and each comparison only answers a yes/no question — so in the worst case, it needs at least $\log_2(n!)$ comparisons to narrow down which ordering it has, and $\log_2(n!)$ grows as $\Theta(n \log n)$.

This is exactly why merge sort's $\Theta(n \log n)$ worst case is considered **asymptotically optimal** — it's not just fast, it's provably as good as any comparison-based sort can ever be. (Non-comparison sorts, like counting sort, can beat this bound under specific conditions — but that's outside this course's scope.)

---

## Section 7: Interactive Class Activity

> **Instructor Instructions:** Same format as the Big-O activity — pairs or small groups, 8 minutes to work, 7 minutes to review on the board.

### Task: Classify Best/Worst Case with Ω and Θ

For each snippet, state the **best-case** and **worst-case** running time using $\Theta$, and explain why they differ (or don't).

#### Snippet A (C++)
```cpp
bool contains(const std::vector<int>& arr, int target) {
    for (int x : arr) {
        if (x == target) return true;
    }
    return false;
}
```

#### Snippet B (C++)
```cpp
void fillZeros(std::vector<int>& arr) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
        arr[i] = 0;
    }
}
```

### Solutions & Explanation Key (For Review)

**Snippet A:** Best case $\Theta(1)$ (target is the first element — loop exits immediately). Worst case $\Theta(n)$ (target is last, or absent — every element is checked). These differ because the loop can exit early depending on *where* the target is, just like linear search.

**Snippet B:** Best case $\Theta(n)$, worst case $\Theta(n)$ — **the same**. There's no early exit and no dependence on the input's values at all; every element is visited exactly once no matter what. This is a case where a single $\Theta(n)$ correctly describes the whole algorithm, the same way Selection Sort and Merge Sort don't need case-qualification.

---

## Section 8: Notation Cheat Sheet

| Symbol | Name | Meaning | Analogy |
|--------|------|---------|---------|
| $O(g(n))$ | Big-O | Upper bound — "at most" | $\le$ |
| $\Omega(g(n))$ | Big-Omega | Lower bound — "at least" | $\ge$ |
| $\Theta(g(n))$ | Big-Theta | Tight bound — "exactly" | $=$ |

- $O$ is the most commonly used in casual conversation, but it's the *least* precise of the three — it never promises the bound is achievable.
- $\Theta$ is the most informative, but only when you're careful to say *which case* (best/average/worst) you're describing, per Section 4.
- If you can prove both $O(g(n))$ and $\Omega(g(n))$ for the same $g(n)$, you've proven $\Theta(g(n))$ — that's literally the definition.

---
