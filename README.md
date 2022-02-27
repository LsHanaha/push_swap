# push_swap
Because push_swap sounds better than swap_push


The goal is to sort array of integers using two staks.
Difference between this and common task - you can rotate your stacks (command rr makes first value last in stack, second becomes first, command rrr - vice versa). It allows you to use other sorting algoritms (not only bubbles), like quicksort.

Stacks imlemented as array of integhers, commands stored in red-black binary tree (bonuses).

## How to compile:
Run `make`, an executables called `push_swap` and `checker`. 
## Usage
`./push_swap [array_of_int]` - show you commands for sorting array.
`./checker [array_of_int]` - send array in checker. Then you need to input sorting commands in stdin. Return result `OK` or `KO`

## Explanation of commands

| Operation  | Description  |
| ---------- | ------------ |
**sa (sb)**| swap a(b) - swap the first 2 elements at the top of stack a(b).
**ss**| **sa** and **sb** at the same time.
**pa (pb)**| push a(b) - take the first element at the top of b(a) and put it at the top of a(b).
**ra (rb)**| rotate a(b) - shift up all elements of stack a by 1. The first element becomes the last one.
**rr**| **ra** and **rb** at the same time.
**rra (rrb)**| reverse rotate a(b) - shift down all elements of stack a by 1. The last element becomes the first one.
**rrr** | **rra** and **rrb** at the same time.

## Rebiuld the programs

Run `make`, an executables called `push_swap` and `checker`. 
