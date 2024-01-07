#!/usr/bin/env python3

from typing import List

def merge_sort(arr: List[int]) -> List[int]:
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)

def merge(left: List[int], right: List[int]) -> List[int]:
    result = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
       
    result += left[i:]
    result += right[j:]

    return result

def test_merge_sort():
    import random
    for _ in range(100):
        n = random.randint(1,100)
        arr = [random.randint(0, 100) for _ in range(n)]
        sorted_arr = sorted(arr)
        assert merge_sort(arr) == sorted_arr

test_merge_sort()
print("merge_sort paseed")
