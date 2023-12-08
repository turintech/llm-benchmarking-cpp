# SORT

## SortVector

This sorts an integer vector using `std::sort`. It's quite optimal
already. 

- Parallelise

## DutchFlagPartition

Partitions a vector around some pivot point. 

- Can be reduced to a single for loop

## MaxN

Returns the maximum N values of a vector, relying on `std::sort` initially.

- Could use `std::partial_sort`
- Consider parallelisation
