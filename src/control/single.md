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

## MaxVector

Returns the max value of a vector. This function is close to optimal 
(for a serial implementation), since max value requires linear time. 
However there are a few possible improvements.

- Compute vector size once and store it before the loop
- Default `max` should be the first element of the vector (assuming not empty)
to account for all negative cases.

## SumModulus

This function sums all values from 0 to `n` that are divisible by `m`. This
implementation creates an intermediate array to store values before iterating
over this array and checking whether the element is divisible by `m`. 

- It is more efficient to simply iterate in some for loop with step size `m`
and sum the values.
- As for `SumRange`, a parallel implementation would be faster.

