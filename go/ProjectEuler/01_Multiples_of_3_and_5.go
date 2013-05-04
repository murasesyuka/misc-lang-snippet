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

func sum(a []int) int {
	var s int = 0
	for _, v := range a {
		s += v
	}
	return s
}

func main() {
	s := 0
	var z []int
	c := 10000
	z = make([]int, 0, c)
	for i := 0; i < c; i++ {
		s += i
		
		if is_multi_3_5(i) {
			z = append(z,i)
		}
	}
	fmt.Println(sum(z))
}
