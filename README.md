<!-- YoRHa archive -->
```
▸ YoRHa // ARCHIVE — PUSH_SWAP
```

A C program that sorts integers on a stack using a second stack and a minimal set of operations, printing the instructions it used.

| UNIT DATA | |
|---|---|
| Type | 42 Lausanne common-core project · solo |
| Stack | C · Makefile |
| Status | ■ COMPLETE |

## ▸ Overview
Stack `a` receives the numbers, stack `b` is auxiliary. Dedicated routines handle 2 to 5 values; a Turk-style algorithm is used below 300 values and a custom routine above (a radix sort in `src/sort/sort_radix.c` is kept but not called). The bonus builds a `checker` that reads instructions from standard input and reports `OK` or `KO`.

## ▸ Usage
```bash
make && ./push_swap 3 2 5 1 4
make bonus && ./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
```

---
<sub>▸ Archived by UNIT ALDE-OLI · [profile](https://github.com/alde-oli)</sub>
