#include "max_sub_array.h"

namespace Algorithms {

template <class T, size_t SIZE>
FindMaxSubarrayResult<T>* MaxSubArray<T, SIZE>::FindMaxSubarray(array<T, SIZE> arr, size_t low, size_t high) {
  if (low == high) {
    FindMaxSubarrayResult res = {
        .low = low,
        .high = high,
        .max = array[low],
    };
    return &res;
  }

  size_t mid = high / 2;
  FindMaxSubarrayResult<T>* left = FindMaxSubarray(arr, low, mid);
  FindMaxSubarrayResult<T>* right = FindMaxSubarray(arr, mid + 1, high);
  FindMaxSubarrayResult<T>* middle = findMaxSubarrayCrossMid(arr, low, mid, high);
  if (left->max >= middle->max && left->max >= right->max) {
    FindMaxSubarrayResult res = {
        .low = low,
        .high = mid,
        .max = left->max,
    };
    return &res;
  } else if (right >= middle->max && right >= left->max) {
    FindMaxSubarrayResult res = {
        .low = mid + 1,
        .high = high,
        .max = right->max,
    };
    return &res;
  }

  return &middle;
}

template <class T, size_t SIZE>
FindMaxSubarrayResult<T>* MaxSubArray<T, SIZE>::FindMaxSubarrayCrossMid(array<T, SIZE> arr, size_t low, size_t mid, size_t high) {
  T leftSum = this->minimumValue;
  T rightSum = this->minimumValue;
  T sum = arr[mid];
  FindMaxSubarrayResult<T> res = {0};
  for (size_t i = mid - 1; i > low; i--) {
    sum += arr[i];
    if (sum > leftSum) {
      leftSum = sum;
    } else {
      res.low = i;
      break;
    }
  }

  sum = arr[mid + 1];
  for (size_t i = mid + 2; i < high; i++) {
    sum += arr[i];
    if (sum > rightSum) {
      rightSum = sum;
    } else {
      res.high = i;
      break;
    }
  }

  res.max = leftSum + rightSum;

  return &res;
}

}  // namespace Algorithms
