# 🚀 Push_Swap

## 📌 Introduction
`push_swap` is a C++ program designed to sort a stack of unique integers using a limited set of operations. The goal is to achieve sorting with the **minimum number of operations** possible. 🎯

## 📜 Rules
- Two stacks are used: `a` and `b`.
- Initially, stack `a` contains a random set of unique integers, while stack `b` is empty.
- The sorting must be done in `a` using the following allowed operations:

## 🔄 Available Operations
### 🔀 Swap Operations:
- `sa`: Swap the top two elements of stack `a`.
- `sb`: Swap the top two elements of stack `b`.
- `ss`: Swap the top two elements of both stacks `a` and `b` simultaneously.

### 📤 Push Operations:
- `pa`: Move the top element of `b` to the top of `a`.
- `pb`: Move the top element of `a` to the top of `b`.

### 🔁 Rotate Operations:
- `ra`: Shift all elements of `a` up by one position.
- `rb`: Shift all elements of `b` up by one position.
- `rr`: Shift all elements of both `a` and `b` up by one position.

### 🔄 Reverse Rotate Operations:
- `rra`: Shift all elements of `a` down by one position.
- `rrb`: Shift all elements of `b` down by one position.
- `rrr`: Shift all elements of both `a` and `b` down by one position.

## 🛠 Example Execution
### Initial State:
Stack A: 2 1 3 6 5 8 Stack B: _ _

### Sorting Steps:
```
sa # Swap 2 and 1
pb
pb
pb # Push top three elements from A to B
ra
rb # Rotate both stacks
rra
rrb # Reverse rotate both stacks
sa # Swap again
pa
pa
pa # Push elements back to A
```

### ✅ Final Sorted State:
Stack A: 1 2 3 5 6 8 Stack B: _ _

## 📌 Program Requirements
- **Program Name:** `push_swap`
- **Files:** `Makefile`, `*.h`, `*.c`
- **Allowed Functions:** `read`, `write`, `malloc`, `free`, `exit`
- **Libraries:** `libft` is allowed
- **Constraints:**
  - ❌ No global variables
  - 🔢 Must output the smallest number of instructions to sort `a`
  - 📝 Output must be newline-separated
  - 🚨 Must return an error for invalid inputs

--
## ▶️ Usage
$ ./push_swap 2 1 3 6 5 8

--
##⚠️ Error Handling
`$ ./push_swap 0 one 2 3
`Error
--
##✅ Verification
To check your sorting efficiency:
$ ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
--
##🏗 Sorting Algorithm
This project uses Radix Sort, an efficient non-comparative sorting algorithm, optimized for the given constraints.

--
##🎯 Conclusion
push_swap is a challenging sorting algorithm project that requires optimizing operations to sort a stack with the fewest possible moves. Efficient implementation and algorithmic strategy are key to achieving a competitive solution. 🚀
