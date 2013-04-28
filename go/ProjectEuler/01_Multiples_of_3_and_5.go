package main

import (
	"fmt"
	)

func main() {
	sum := 0
	var z []int
	z = make([]int, 10, 10)
	for i := 0; i < 10; i++ {
		sum += i
		z[i] = i
	}
	fmt.Println(sum)
	fmt.Println(z)
}
