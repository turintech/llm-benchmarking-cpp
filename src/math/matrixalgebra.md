## Notes

For high performance substitution, 1d matrices are preferred. They work with mkl and sycl directly.
We don't opt for an interface since this would need to be provided to the LLM. In the future, we'd
want a way to refactor from 2d vector implementation to 1d implementation but this is tricky.
