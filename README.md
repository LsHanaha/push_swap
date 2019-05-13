# push_swap
Because push_swap sounds better than swap_push


The goal is to sort array of integers using two staks.
Difference between this and common task - you can rotate your stacks (command rr makes first value last in stack, second becomes first, command rrr - vice versa). It allows you to use other sorting algoritms (not only bubbles), like quicksort.

Stacks imlemented as array of integhers, commands stored in red-black binary tree (bonuses).

## How to compile:
Run 'make', an executables called `push_swap` and `checker`. 
## Usage
`./push_swap [array_of_int]` - show you commands for sorting array.
`./checker [array_of_int]` - send array in checker. Then you need to input sorting commands in stdin.
