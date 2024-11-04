# push_swap Project

This project is an algorithm aimed at sorting a list of integers using two stacks and a limited set of operations, with a focus on efficiency and optimization.

## Objective
Sort a stack `A` of integers in ascending order using an auxiliary stack `B` with the fewest possible operations. At the end, stack `A` should be sorted, and stack `B` should be empty.

## Available Operations

### Push
- `pa`: moves the top of `B` to `A`
- `pb`: moves the top of `A` to `B`

### Swap
- `sa`: swaps the first two elements of `A`
- `sb`: swaps the first two elements of `B`
- `ss`: swaps the first two elements of `A` and `B` simultaneously

### Rotate
- `ra`: rotates `A` up
- `rb`: rotates `B` up
- `rr`: rotates `A` and `B` up simultaneously

### Reverse Rotate
- `rra`: rotates `A` down
- `rrb`: rotates `B` down
- `rrr`: rotates `A` and `B` down simultaneously
