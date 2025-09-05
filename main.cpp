#include <iostream>
#include <vector>
// TEAM members: Kevin Rodriguez, Caleb Clements, Will Mayer

/**
* Determine if a value is in a vector.
* Return true if "key" is one of the values in numbers[0..n-1].
* Return false otherwise.
*/
bool iterativeMember(const std::vector<int> &numbers, size_t n, int key) {
    for (int i = 0; i < n; ++i) { // loop through the vector up to n elements
        if (key == numbers[i]) {  // if we find the key, return true
            return true;
        }
    }
    return false; // not found
}


/**
 * Recursive version of member check
 */
bool recursiveMember(const std::vector<int> &numbers, size_t n, int key) {
    if (n == 0) { // base case: empty range
        return false;
    }
    if (numbers[n-1] == key) { // check last element
        return true;
    }
    return recursiveMember(numbers, n-1, key); // recurse on smaller range
}


/**
 * Iterative comparison of two vectors
 */
bool iterativeAreIdentical(const std::vector<int> &numbers1, const std::vector<int> &numbers2, size_t n) {
    for (int i = 0; i < n; ++i) { // compare each index
        if (numbers1[i] != numbers2[i]) {
            return false; // mismatch found
        }
    }
    return true; // all matched
}


/**
 * Recursive comparison of two vectors
 */
bool recursiveAreIdentical(const std::vector<int> &numbers1, const std::vector<int> &numbers2, size_t n) {
    if (n == 0) { // base case: no elements left
        return true;
    }
    if (numbers1.at(n-1) != numbers2.at(n-1)) { // check last element
        return false;
    }
    return recursiveAreIdentical(numbers1, numbers2, n-1); // recurse down
}


/**
 * Iterative palindrome check
 */
bool iterativePalindrome(const std::string &s) {
    if (s.size() <= 1) return true; // base case: empty/1-char string is palindrome

    // check characters from front and back moving inward
    for (int i = 0, j = s.size()-1; i < s.size()/2; ++i, --j) {
        if(s[i] != s[j]) {
            return false;
        }
    }
    return true;
}


/**
 * Recursive palindrome check
 */
bool recursivePalindrome(const std::string &s, size_t leftIdx, size_t rightIdx) {
    if (leftIdx >= rightIdx) return true; // base case: crossed pointers
    if (s.at(leftIdx) != s.at(rightIdx)) return false; // mismatch
    return recursivePalindrome(s, leftIdx + 1, rightIdx - 1); // shrink inward
}


/**
 * Iterative inversion counter
 */
int countInversionsIteratively(const std::vector<int> &v, size_t n) {
    int counter = 0;
    for (int i = 0; i < n-1; ++i) { // check consecutive pairs
        if (v.at(i) > v.at(i+1)) { // inversion found
            ++counter;
        }
    }
    return counter;
}


/**
 * Recursive inversion counter
 */
int countInversionsRecursively(const std::vector<int> &v, size_t n) {
    if (n == 2) { // base case: only 2 elements
        return (v.at(0) > v.at(1)) ? 1 : 0;
    }
    if (v.at(n-2) > v.at(n-1)) {
        return 1 + countInversionsRecursively(v, n-1); // count + recurse
    }
    return countInversionsRecursively(v, n-1); // just recurse
}


/**
 * Skip non-letters in palindrome functions
 */
void character_check (const std::string&s, int &i, int &j) {
    while (!isalpha(s[i])) { ++i; } // move forward until letter
    while (!isalpha(s[j])) { --j; } // move backward until letter
}


/**
 * Iterative palindrome check (ignores non-letters)
 */
bool iterativePalindrome2(const std::string &s) {
    if (s.size() <= 1) return true;

    for (int i = 0, j = s.size()-1; i < s.size()/2; ++i, --j) {
        character_check(s,i,j); // skip non-letter chars
        if (s.at(i) != s.at(j)) return false;
    }
    return true;
}


/**
 * Recursive palindrome check (ignores non-letters)
 */
bool recursivePalindrome2(const std::string &s, int leftIdx, int rightIdx) {
    if (leftIdx >= rightIdx) return true; // base case
    character_check(s,leftIdx,rightIdx); // adjust to next letters
    if (s.at(leftIdx) != s.at(rightIdx)) return false;
    return recursivePalindrome2(s, leftIdx+1, rightIdx-1); // shrink inward
}


/**
 * Iterative intersection of two vectors
 */
void iterativeIntersection(const std::vector<int> &values1, const std::vector<int> &values2, std::vector<int> &result, std::size_t values1NumElements, std::size_t values2NumElements) {
    for (int i = 0; i < values1NumElements; ++i) { // loop over first vector
        for (int j = 0; j < values2NumElements; ++j) { // check second vector
            if (values1.at(i) == values2.at(j)) { // match found
                result.push_back(values1.at(i));
                break; // avoid duplicates from multiple matches
            }
        }
    }
}


/**
 * Recursive intersection of two vectors
 */
void recursiveIntersection(const std::vector<int> &values1, const std::vector<int> &values2, std::vector<int> &result, std::size_t values1NumElements, std::size_t values2NumElements) {
    if (values1NumElements == 0 || values2NumElements == 0) {
        return; // base case: one list is empty
    }
    for (int j = 0; j < values2NumElements; ++j) { // check last element of v1
        if (values1.at(values1NumElements - 1) == values2.at(j)) {
            result.push_back(values1.at(values1NumElements - 1));
            break;
        }
    }
    // recurse with one fewer element from values1
    return recursiveIntersection(values1, values2, result, values1NumElements - 1, values2NumElements);
}

void testMember( bool (*member)(const std::vector<int> &, size_t, int)) {

    std::vector<int> numbers = {10, 20, 65, 23, 66, 42, 12, 55};
    std::cout << "Testing iterative member begins. \n";
    std::cout << "Do not expect any output if the function works properly.\n";

    // Yes cases:
    for(auto v: numbers) {
        if (!member(numbers, numbers.size(), v)) {
            std::cout << "Iterative member fails. " << v
                      << " is a member, but the function returned false.\n";
            exit(1);
        }
    }

    // No cases
    std::vector<int> numbers2 = {9, 22, 68, 28, 60, 38, 120, 50};
    for(auto v: numbers2) {
        if (member(numbers, numbers.size(), v)) {
            std::cout << "Iterative member fails. " << v
                      << " is not a member, but the function returned true.\n";
            exit(1);
        }
    }

    std::cout << "Testing iterative member ends...\n";
}

void testAreIdentical(bool (*areIdentical)(const std::vector<int> &, const std::vector<int> &, size_t n), int id) {


    std::vector<int> numbers1 = {10, 28, 65, 23, 66, 42, 12, 55};
    std::vector<int> numbers2 = {10, 28, 65, 23, 70, 42, 12, 55};

    std::cout << "Testing are identical begins...\n";
    if( areIdentical(numbers1, numbers1, numbers1.size()) )
        std::cout << "Are Identical works! (" << id << ")" << std::endl;
    else
        std::cout << "iterativeAreIdentical doesn't work! (" << id << ")" << std::endl;

    if( areIdentical(numbers1, numbers2, numbers1.size()) )
        std::cout << "iterativeAreIdentical doesn't work! (" << id + 1 << ")" << std::endl;
    else
        std::cout << "Are Identical works! (" << id + 1 << ")" << std::endl;
    std::cout << "Testing are identical begins...\n";

}

void testInterativePlaindrome() {
    std::string s1 = "madam", s2 = "madman";

    if(iterativePalindrome(s1))
        std::cout << "iterativePalindrome works! (1)" << std::endl;
    else
        std::cout << "iterativePalindrome doesn't work! (1)" << std::endl;


    if(! iterativePalindrome(s2))
        std::cout << "iterativePalindrome works! (3)" << std::endl;
    else
        std::cout << "iterativePalindrome doesn't work! (3)" << std::endl;

}

void testRecursivePalindrome() {
    std::string s1 = "madam", s2 = "madman";

    if(recursivePalindrome(s1, 0, s1.length() - 1))
        std::cout << "recursivePalindrome works! (2)" << std::endl;
    else
        std::cout << "recursivePalindrome doesn't work! (2)" << std::endl;

    if(! recursivePalindrome(s2, 0, s2.length() - 1))
        std::cout << "recursivePalindrome works! (4)" << std::endl;
    else
        std::cout << "recursivePalindrome doesn't work! (4)" << std::endl;

}

void testInterativePlaindrome2() {
    std::string s3 = "a man, a plan, a canal, panama", s4 = "a man, no plan, a canal, panama";

    if(iterativePalindrome2(s3))
        std::cout << "iterativePalindrome2 works! (5)" << std::endl;
    else
        std::cout << "iterativePalindrome2 doesn't work! (5)" << std::endl;

    if(! iterativePalindrome2(s4))
        std::cout << "iterativePalindrome2 works! (5)" << std::endl;
    else
        std::cout << "iterativePalindrome2 doesn't work! (5)" << std::endl;

}

void testRecursivePlaindrome2() {
    std::string s3 = "a man, a plan, a canal, panama", s4 = "a man, no plan, a canal, panama";

    if(recursivePalindrome2(s3, 0, s3.length() - 1))
        std::cout << "recursivePalindrome2 works! (6)" << std::endl;
    else
        std::cout << "recursivePalindrome2 doesn't work! (6)" << std::endl;

    if(! recursivePalindrome2(s4, 0, s4.length() - 1))
        std::cout << "recursivePalindrome2 works! (6)" << std::endl;
    else
        std::cout << "recursivePalindrome2 doesn't work! (6)" << std::endl;

}

void testCountInversions(int (*countInversions)(const std::vector<int> &, size_t), int id) {
    std::vector<int> increasing = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        decreasing = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        mixed = {1, 10, 2, 9, 3, 8, 4, 7, 5, 5};
    int mixedInversions = 4;

    if(countInversions(increasing, increasing.size()) == 0)
        std::cout << "Count Inversions works! (" << id << ")\n";
    else
        std::cout << "Count Inversions doesn't work! (" << id << ")\n";

    if(countInversions(decreasing, increasing.size()) == decreasing.size() - 1)
        std::cout << "Count Inversions works! (" << id + 1 << ")\n";
    else
        std::cout << "Count Inversions doesn't work! (" << id + 1 << ")\n";

    if(countInversions(mixed, increasing.size()) == mixedInversions)
        std::cout << "Count Inversions works! (" << id + 2 << ")\n";
    else
        std::cout << "Count Inversions doesn't work! (" << id + 2 << ")\n";

}

void testIntersection(void (*intersection)(const std::vector<int> &values1,
                                   const std::vector<int> &values2,
                                   std::vector<int> &result,
                                   size_t values1NumElements, size_t values2NumElements),
                      int id) {

    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
            v2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
            v3 = {10, 11, 12, 13, 14},
            result;


    // a full intersection

    std::cout << "Testing intersection begins...\n";
    std::cout << "No output will be printed if all tests pass.\n";
    intersection(v1, v2, result, v1.size(), v2.size());
    if(result.size() != v1.size()) {
        std::cout << "Intersection fails (" << id << ")\n";
        return;
    }

    for(auto v: result)
        if(!iterativeMember(v1, v1.size(), v)) {
            std::cout << "Intersection fails (" << id + 1 << ")\n";
            return;
        }


    // v1 and v3 have only one value in common

    std::vector<int> result2;
    intersection(v1, v3, result2, v1.size(), v3.size());

    if(result2.size() != 1) {
        std::cout << "Intersection fails (" << id + 2 << ")\n";
        return;
    }

    if(result2.at(0) != 10)
        std::cout << "Intersection fails (" << id + 3 << ")\n";

    std::cout << "Testing intersection ends...\n";
}

int main() {

    testMember(iterativeMember);
    testMember(recursiveMember);

    testAreIdentical(iterativeAreIdentical, 1);
    testAreIdentical(recursiveAreIdentical, 3);

    testInterativePlaindrome();
    testRecursivePalindrome();

    testInterativePlaindrome2();
    testRecursivePlaindrome2();

    testCountInversions(countInversionsIteratively, 1);
    testCountInversions(countInversionsRecursively, 4);

    testIntersection(iterativeIntersection, 1);
    testIntersection(recursiveIntersection, 5);


    return 0;
}
