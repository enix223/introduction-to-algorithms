#ifndef MAX_SUB_ARRAY_H_
#define MAX_SUB_ARRAY_H_

#include <array>

namespace Algorithms {

using namespace std;

template <class T>
class FindMaxSubarrayResult {
  size_t low;
  size_t high;
  T max;
};

template <class T, size_t SIZE>
class MaxSubArray {
  typedef int (*Compare)(T left, T right);

 private:
  Compare compareFn;
  T minimumValue;
  T maximumValue;
  FindMaxSubarrayResult<T>* FindMaxSubarrayCrossMid(array<T, SIZE> arr, size_t low, size_t mid, size_t high);

 public:
  // Constructor
  MaxSubArray() {}

  MaxSubArray(T minimumValue, T maximumValue) {
    this->minimumValue = minimumValue;
    this->maximumValue = maximumValue;
  }

  MaxSubArray(T minimumValue, T maximumValue, Compare compareFn) {
    MaxSubArray(minimumValue, maximumValue);
    this->compareFn = compareFn;
  }

  SetCompareFn(Compare fn) {
    this->compareFn = fn;
  }

  SetMinimumValue(T m) {
    this->minimumValue = m;
  }

  FindMaxSubarrayResult<T>* FindMaxSubarray(array<T, SIZE> arr, size_t low, size_t high);
};

}  // namespace Algorithms

#endif /* MAX_SUB_ARRAY_H_ */
