# Recursion Practice

## Student Information
- **Name:** Kevin Rodriguez
- **Student ID:** 008858727
- **Repository:** <https://github.com/Pwingles/recursionPractice>

## Implementation Details
This project implements and tests classic problems both **iteratively** and **recursively**:

- Membership check in a vector
- Equality of two vectors
- Palindrome detection (letters only, and ignoring non-letters)
- Counting adjacent inversions
- Intersection of two vectors 

All functions operate on `std::vector<int>` or `std::string`.  
Recursive solutions follow simple base cases (e.g., `n == 0`, or `leftIdx >= rightIdx`).

## Testing & Status
- **Working:** membership, equality, palindrome (both types), inversion counting.
- **Not yet implemented:** iterative and recursive intersection.
- **How to test:** Run `main.cpp`; success prints messages like `"works! (id)"`. Failures print descriptive errors.
  
## Build & Run
```bash
g++ -std=c++17 -Wall -O2 src/main.cpp -o recursionPractice
./recursionPractice

```

## Collaboration & Sources

This project was completed by:

- Kevin Rodriguez  
- Caleb Clements  
- Will Mayer  

All code was written collaboratively by our group. We discussed design, wrote functions, and tested together.  

