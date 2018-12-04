package main

import "fmt"

func doPartion(arr []int, left int, right int) int {
	pivot := arr[right]
	i := left
	for j := left; j < right; j++ {
		if arr[j] <= pivot {
			arr[j], arr[i] = arr[i], arr[j]
			i++
		}
	}
	arr[i], arr[right] = arr[right], arr[i]
	return i
}
func quick_sort(arr []int, left int, right int) {
	if left >= right {
		return
	}
	p := doPartion(arr, left, right)
	quick_sort(arr, left, p-1)
	quick_sort(arr, p+1, right)
}

func main() {
	var slice1 = []int{5, 8, 2, 4, 6, 5, 2}
	quick_sort(slice1, 0, len(slice1)-1)
	fmt.Println(slice1)
}
