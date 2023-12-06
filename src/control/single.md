# SINGLE.CC

A lot of the single for loop functions are trivially inefficient because
they define unnecessary arrays to store intermediate data

## SumRange

This function sums all values from 0 to `n`. This implementation creates an 
intermediate array to store the range of values from 0 to `n`, before iterating
over this array to sum values. It is more efficient to simply iterate in some
for loop to compute the sum.

It is even more efficient to parallelize this task, summing over groups
of numbers before adding these sums together to get the total.

##

