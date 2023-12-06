# DOUBLE.CC

## SumSquare

Sums all values squared from 0 to `n`. 

- This can be made much more efficient by removing one of the loops

## SumTriangle

Sums triangle numbers from 0 to `n`.

- Triangle values are analytic, and so only a single loop is needed
to sum over them.

## CountPairs

Returns number of pairs from a randomly generated set of `n` numbers 
from 0 to `m`. Note that this doesn't count instances where there are
more than 2 of the same number.

- Using a different datastructure for counting would speed up
this task significantly.

## CountDuplicates

Creates two randomly generated ordered sets (from 0 to `m`) and returns
a sum of the number of times values at the same index are the same.

- It's possible to reduce this to a single for loop.
- Since the values are all generated interally, storing the arrays isn't
necessary.

## SumMatrix

Returns the sum of a (n, n,) tensor.

- This task would work better parallelized.



