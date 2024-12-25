
# The Farmer's Dilemma: Crossing the River with a Wolf, Goat, and Cabbage

## Description
This project was developed as part of a university assignment for the **Artificial Intelligence** course at the **University of Ruse "Angel Kanchev"**, Faculty of Electrical Engineering, Electronics, and Automation. The task involves solving the classic "Farmer, Wolf, Goat, and Cabbage" problem programmatically using algorithms that include backtracking and depth-bound search.

---

## Task Description
The problem involves a farmer, a wolf, a goat, and a cabbage located on the left bank of a river. They need to cross to the right bank using a boat. The constraints are:

1. **Backtracking with depth-bound** is used.
2. The boat has a capacity of two, and only the farmer can row.
3. The wolf cannot be left alone with the goat, and the goat cannot be left alone with the cabbage on any bank.

Each type of passenger has a different transportation cost:

- **Wolf (W):** 3 units
- **Goat (G):** 2 units
- **Cabbage (C):** 1 unit
- **Empty Move (P):** 0 units

---

## Problem Representation as a Search Problem
- **State:** ($\alpha_1$, $\alpha_2$, $\alpha_3$)
  - ($\alpha_1$): Farmer's location (East/West bank)
  - ($\alpha_2$): Characters on the east bank (excluding the farmer)
  - ($\alpha_3$): Characters on the west bank (excluding the farmer)

- **Initial State:** (Et, WGC, 0)
- **Goal State:** (Wt, 0, WGC)

---

## Operators
- **W:** Move the wolf
- **G:** Move the goat
- **C:** Move the cabbage
- **P:** Perform an empty move

---

## Heuristic
The solution starts with moving the goat first, as it is the only safe option. When the farmer returns, it is an empty move, as there's no need to bring the goat back. Each subsequent move involves checking the safety of the remaining characters. The problem is solved when the final state mirrors the reverse order of the first two steps.

---

## Developed Modules
1. **`check` Module**
   - **Purpose:** Validates that no dangerous characters are left alone.
   - **Parameters:** 
     - Characters on the east and west banks.
   - **Global Variables Used:** None
   - **Called Functions:** None

2. **`reset` Module**
   - **Purpose:** Resets the program to the last safe state.
   - **Parameters:**
     - Characters on the east and west banks.
   - **Global Variables Used:** 
     - Characters on the east and west banks.

3. **`solve` Module**
   - **Purpose:** Main function to solve the problem.
   - **Parameters:** None
   - **Global Variables Used:** 
     - Characters on the east and west banks.
   - **Called Functions:** `reset`, `check`
