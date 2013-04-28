package main

import (
	"fmt"
	)

func is_multi_3_5(n int) bool {
	switch {
	case (n % 3) == 0:
		return true
	case (n % 5) == 0:
		return true
	}
	return false
}

func main() {
	sum := 0
	var z []int
	z = make([]int, 0, 10)
	for i := 0; i < 10; i++ {
		sum += i
		z = append(z,i)
		fmt.Println(i)
		fmt.Println(is_multi_3_5(i))
	}
	fmt.Println(sum)
	fmt.Println(z)
}
