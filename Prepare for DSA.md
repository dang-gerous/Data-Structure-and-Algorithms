# Prepare for DSA — Master Visual Revision & Exam Hub

- **Course & Platform:** PTIT Data Structures & Algorithms (`https://code.ptit.edu.vn/courses`)
- **Final Exam Date:** **December 5, 2026** (5 Problems, 90–120 mins)
- **Grading Scale:** 1 AC = **5** | **2 AC = 6 (MAIN GOAL)** | **3 AC = 7 (Safety Buffer)** | 4 AC = 9 | 5 AC = 10
- **How to Compile & Test in Antigravity IDE:**
  1. Open any `.cpp` file (`day01_closest_pairs.cpp` or `practice.cpp`).
  2. Press **`Cmd + S`** to save, then press **`Cmd + Shift + B`**!
  3. Built-in `dayXX_*.cpp` files get **auto-judged** (`AC` / `WA` / `TLE` / `RTE`); any other `.cpp` file runs using **`input.txt`**!

---

## 1. Visual Skill X-Ray & Progress Tracker

| Pillar | Code PTIT Prefix | Exam Role | Start Level (Nov 6) | Target Level |
| :--- | :--- | :--- | :--- | :--- |
| **0. C++ STL Bridge** | All | Unlocks coding from blank page | 15% (Blocked) | **100% Automatic** |
| **A. Sorting & Greedy** | `DSA06`, `DSA03` | **Exam AC #1 Target** | Concept 65% / Code 20% | **Blank-page AC < 20m** |
| **B. Gen & Backtracking** | `DSA01`, `DSA02` | **Exam AC #2 Target (Strongest!)** | Concept 85% / Code 45% | **Blank-page AC < 20m** |
| **C. Stack & Queue** | `DSA07`, `DSA08` | **Exam AC #2 / #3 Backup** | Concept 30% / Code 15% | **Blank-page AC < 25m** |
| **D. Binary Tree** | `DSA11` | **Bonus Insurance AC** | Concept 50% / Code 30% | **Traversals & Level-Order** |

---

## 2. What Depends on What (Visual Architecture)

```
  [ Basic C++: for / while / if ]  (Already solid!)
          │
          ├───────────────────────────────┐
          ▼                               ▼
  [ C++ STL Bridge ]              [ Recursion Call-Stack ]
  vector, sort, pair,             Base case vs Try(i + 1)
  stack, queue, long long                 │
     │               │                    ▼
     ▼               ▼            [ PILLAR B: DSA01 & DSA02 ]
[ PILLAR A ]    [ PILLAR C ]      Generation & Backtracking
DSA06 Sort +    DSA07 Stack +             │
DSA03 Greedy    DSA08 Queue BFS           ▼
                     │            [ PILLAR D: DSA11 ]
                     └──────────► Binary Tree (BFS + DFS)
```

---

## 3. My Personal Mistake Log (Revise Every Morning!)

> **Rule:** Before writing new code each day, spend **3 minutes** reading this section so you never repeat an old bug on exam day.

1. **Sorting Before Sliding Window (Nov 6):**
   - *Bug:* Tried a 2-element window on an unsorted array `[6, 2, 10, 4, 8]`.
   - *Visual Rule:* **Sort FIRST (`[2, 4, 6, 8, 10]`), Window SECOND!** Also: `set` deletes duplicates, so never use `set` when counting pairs.
2. **Off-The-Cliff Index `a[i + 1]` (Nov 6):**
   - *Bug:* Wrote `for (int i = 0; i < n; i++)` with `a[i + 1] - a[i]`. At `i = n - 1`, `a[i + 1]` reads `a[n]` (garbage memory outside `0..n-1`)!
   - *Visual Rule:* `[0][1][2][3][4] | 💥[5]`. If you touch `a[i + 1]`, stop at **`i < n - 1`**!
3. **Missing `{ }` Around Multi-Line Loops (Nov 6):**
   - *Bug:* Forgot `{ ... }` after `for (...)`, so `if` and `cnt++` fell outside the loop and ran only once.
   - *Rule:* **Always put `{ }` on every `for` and `while` loop** unless the entire body is 1 short line.
4. **Champion Counter Reset (Nov 6):**
   - *Rule:* When a smaller gap beats `best`, **reset `cnt = 1`** (`if (d < best) { best = d; cnt = 1; } else if (d == best) { cnt++; }`).
5. **Binary Tree — 3-Dot Outline Walk & Ghost Leaf Bug (Nov 6):**
   - *Bug 1:* Printed root `1` twice in Preorder (`1->2->4->5->1->3->6`) and swapped `2` & `5` in Inorder.
   - *Visual Fix:* Put 3 dots on every node and trace counter-clockwise around the tree:
     - **Left dot** = **Preorder** (`Root -> Left -> Right`)
     - **Bottom dot** = **Inorder** (`Left -> Root -> Right`)
     - **Right dot** = **Postorder** (`Left -> Right -> Root`)
   - *Bug 2 (Ghost Leaf):* `if (root == NULL) return 0;` (**NOT `1`!**). Empty child = `0`; real leaf (`left == NULL && right == NULL`) = `1`.

---

## 4. The 6 Core C++ Skeletons (Memorize Through Blank-Page Typing)

### Skeleton 1: Universal Code PTIT Multi-Test Header
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

void solve() {
    // Tip: Declare vectors/stacks INSIDE solve() so every test case starts clean!
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```

### Skeleton 2: Sorting + Custom Comparator (`DSA06` / `DSA03`)
```cpp
// Rule: NEVER use <= inside cmp(), ALWAYS strict < or > !
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second < b.second; // end ascending
    return a.first > b.first;                             // tie: start descending
}
```

### Skeleton 3: Backtracking `Try(i)` + Undo Law (`DSA01` / `DSA02`)
```cpp
int n, X[25];
bool used[25]; // reset to false!

void Try(int i) {
    for (int val = 1; val <= n; val++) {
        if (!used[val]) {
            X[i] = val;
            used[val] = true;      // 1. CHOOSE
            if (i == n) {
                // print X[1..n]
            } else {
                Try(i + 1);        // 2. EXPLORE
            }
            used[val] = false;     // 3. UNDO (clean footprints!)
        }
    }
}
```

### Skeleton 4: Stack with Empty Guardrail (`DSA07`)
```cpp
stack<char> st;
// NEVER call st.top() or st.pop() without checking !st.empty() FIRST!
if (!st.empty() && st.top() == '(') {
    st.pop();
}
```

### Skeleton 5: Queue BFS Number Generator (`DSA08005` / `DSA08017`)
```cpp
queue<string> q;
q.push("6");
q.push("8");
while (!q.empty()) {
    string cur = q.front();
    q.pop();
    if ((int)cur.size() > n) break;
    cout << cur << " ";
    q.push(cur + "6");
    q.push(cur + "8");
}
```

### Skeleton 6: Binary Tree Recursion & Level-Order (`DSA11`)
```cpp
struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

int countLeaves(Node* root) {
    if (root == NULL) return 0; // Empty != Leaf!
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}
```

---

## 5. Spaced-Revision Problem Tracker (`1 – 3 – 7` Rule)

Mark every problem right after solving:
- 🔴 **Red:** Needed hints/template → **MUST blind re-code tomorrow (`D+1`)**
- 🟡 **Yellow:** Solved alone, slow or had `WA`/`RTE` → **Blind re-code on `D+3`**
- 🟢 **Green:** Blank-screen `AC` on 1st try (< 20 mins) → **Exam-ready!**

### Week 1 (Nov 6 – Nov 12): C++ STL Bridge + Sorting (`DSA06`) + Greedy (`DSA03`)
- [ ] **Day 1 (Nov 6):** `day01_closest_pairs.cpp` (`BRT`/`DSA06031`), `DSA06001` (Sắp xếp xen kẽ), `DSA06002` (Sắp xếp theo trị tuyệt đối) — *Status:* 🔴
- [ ] **Day 2 (Nov 7):** *[D+1 Blind Re-code Day 1]* + `DSA06010`, `DSA06022`
- [ ] **Day 3 (Nov 8):** `DSA06009` (Cặp số tổng bằng K), `DSA06014`, `DSA06044`
- [ ] **Day 4 (Nov 9):** *[D+1/D+3 Review]* + Binary search `lower_bound` drills (`DSA06015` / `DSA06031`)
- [ ] **Day 5 (Nov 10):** Greedy `DSA03001` (Đổi tiền), `DSA03002` (Nhầm chữ số), `DSA03004` (Tổng nhỏ nhất)
- [ ] **Day 6 (Nov 11):** *[D+1 Review]* + `DSA03008` (Sắp xếp công việc 1 — Interval Greedy!)
- [ ] **Day 7 (Nov 12):** **Mini-Contest #1 (60 mins, 3 unseen `DSA06`/`DSA03` problems — Goal: 2/3 AC)**

### Week 2 (Nov 13 – Nov 19): Generation (`DSA01`) & Backtracking (`DSA02`)
- [ ] **Days 8–9 (Nov 13–14):** `DSA01001`–`DSA01005` (Nhị phân, Tổ hợp, Hoán vị), `DSA01007`, `DSA01008` + *1 Week-1 review/day*
- [ ] **Days 10–11 (Nov 15–16):** `DSA02001`, `DSA02002`, `DSA02003` (Mê cung 1), `DSA02006` (Dãy con tổng bằng K)
- [ ] **Days 12–13 (Nov 17–18):** `DSA02012` (Đếm đường đi), `DSA02016` (Quân hậu 1), `DSA02029` (Tháp Hà Nội)
- [ ] **Day 14 (Nov 19):** **Mock Exam #2 (90 mins, 4 mixed problems from Weeks 1–2 — Goal: 2–3 AC)**

### Week 3 (Nov 20 – Nov 26): Stack (`DSA07`), Queue (`DSA08`), & Binary Tree (`DSA11`)
- [ ] **Days 15–16 (Nov 20–21):** `day01_valid_brackets.cpp` (`DSA07110`), `DSA07003`, `DSA07004`, `DSA07013`, `DSA07027` (Next Greater Element)
- [ ] **Days 17–18 (Nov 22–23):** `DSA08001`–`DSA08003`, `DSA08005` (Số nhị phân 1..N), `DSA08007` (BDN 1), `DSA08017` (Số Lộc Phát 1)
- [ ] **Days 19–20 (Nov 24–25):** `DSA11001`, `DSA11004` (Level-Order), `DSA11008` (Kiểm tra node lá), `DSA11010`
- [ ] **Day 21 (Nov 26):** **Full 5-Problem Mock #3 (90 mins — Practice scanning all 5 & sniping easiest 2)**

### Week 4 + Final Sprint (Nov 27 – Dec 5): Exam Simulations & Polish
- [ ] **Days 22–23 (Nov 27–28):** Optional high-ROI templates (`DSA05001` LCS / `DSA05004` LIS / `DSA09004` DFS) OR Red-list wipeout
- [ ] **Day 24 (Nov 29):** **Full 5-Problem Timed Mock #4 (90 mins)**
- [ ] **Day 25 (Nov 30):** **Full 5-Problem Timed Mock #5 (90 mins)**
- [ ] **Day 26 (Dec 1):** **Full 5-Problem Timed Mock #6 (90 mins)**
- [ ] **Days 27–28 (Dec 2–3):** Re-type all **6 Core Skeletons** from blank screen in < 30 mins + clear remaining Yellow tags
- [ ] **Day 29 (Dec 4):** Light visual review of Section 3 & Section 4 only; stop coding by 8:00 PM; 8h sleep
- [ ] **Dec 5 — EXAM DAY:** Scan all 5 problems (7 mins) → Lock AC #1 → Lock AC #2 → Check `long long`, `!st.empty()`, `i < n - 1` → **Grade 6–7 Achieved!**
