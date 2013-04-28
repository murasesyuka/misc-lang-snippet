package main

import (
	"fmt"
)

func prime_divide(n int) []int {
	r := make([]int, 0, 10)
	a := 2
	for ; a <= n; {
		if n % a == 0 {
			r = append(r,a)
			n /= a
		} else {
			a++
		}
	}
	return r
}

func main(){
	// 13195 is prime 5, 7, 13, 29
	//600851475143
	
	//fmt.Println(prime_divide(8))
	fmt.Println(prime_divide(13195))
}
