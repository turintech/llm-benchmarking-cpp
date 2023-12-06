# SINGLE.CC

A lot of the single for loop functions are trivially inefficient because
they define unnecessary arrays to store intermediate data

## SumRange

This function sums all values from 0 to `n`. This implementation creates an 
intermediate array to store the range of values from 0 to `n`, before iterating
over this array to sum values. 

- It is more efficient to simply iterate in some for loop to compute the sum.
- It is even more efficient to parallelize this task, summing over groups
of numbers before adding these sums together to get the total.

## MaxRandom

This function samples `n` random numbers and returns the max. This implementation
creates an intermediate array to store random values before iterating over this
array to find the maximum value (by storing a max value and updating it whenever
an element in the array is greater).

- It is more efficient to iterate in some for loop and only record the maximum
value.
- It is even more efficient to parallelize this task, finding the max values of
smaller groups of random numbers and combining them.

## SumModulus

This function sums all values from 0 to `n` that are divisible by `m`. This
implementation creates an intermediate array to store values before iterating
over this array and checking whether the element is divisible by `m`. 

- It is more efficient to simply iterate in some for loop with step size `m`
and sum the values.
- As for `SumRange`, a parallel implementation would be faster.

