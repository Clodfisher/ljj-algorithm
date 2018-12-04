package main

import "fmt"

func doMerge(arr []int, left int, mid int, right int) {
	var tmpSlice = make([]int, right-left+1)
	i := left
	j := mid + 1
	k := 0
	for i <= mid && j <= right {
		if arr[i] <= arr[j] {
			tmpSlice[k] = arr[i]
			i++
		} else {
			tmpSlice[k] = arr[j]
			j++
		}
		k++
	}
	if i == mid+1 {
		for j <= right {
			tmpSlice[k] = arr[j]
			k++
			j++
		}
	}
	if j == right+1 {
		for i <= mid {
			tmpSlice[k] = arr[i]
			k++
			i++
		}
	}

	for k = 0; k <= right-left; k++ {
		arr[left+k] = tmpSlice[k]
	}
}

func merge_sort(arr []int, left int, right int) {
	if left >= right {
		return
	}
	mid := (left + right) / 2
	merge_sort(arr, left, mid)
	merge_sort(arr, mid+1, right)
	doMerge(arr, left, mid, right)
}

func main() {
	var slice1 = []int{5, 8, 2, 4, 6, 5, 2}
	merge_sort(slice1, 0, len(slice1)-1)
	fmt.Println(slice1)
}
