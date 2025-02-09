# std::vector<bool> Gotchas:  Unexpected Behavior

This repository demonstrates the subtle and often unexpected behavior of `std::vector<bool>` in C++. Unlike other standard vector types, `std::vector<bool>` is specialized for space optimization.  This specialization leads to deviations from typical vector operations.  The code examples illustrate these differences and offer safer alternatives.

**Problem:**

`std::vector<bool>` doesn't store booleans directly as individual objects; instead, it packs them as bits within a memory block.  This has significant implications for operations like:

* **Element access:** `operator[]` returns a proxy object, not a direct reference.   Modifying the proxy object doesn't immediately update the vector.
* **Iteration:** Iterators provided are not standard random-access iterators, affecting algorithms.
* **Copying:** Copying involves bitwise manipulation, not the usual object copy semantics.

**Solution:**

For most cases, using `std::vector<bool>` is discouraged, especially if the expected behavior aligns with other standard vector types. To avoid these issues consider using `std::vector<char>` (representing booleans as 0 or 1) or `std::vector<int8_t>` for better predictable behavior, or, when memory is of great importance and appropriate for the use case, a specialized bitset class from a library, or implementing a custom bitset solution.