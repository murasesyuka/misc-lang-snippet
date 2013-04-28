package main

import (
	"fmt"
)

func fibonacci() func() int {
	a,b := 1,2
	return func() int {
		r := a
		a,b = b,a+b
		return r
	}
}


func main() {
	f := fibonacci()
	z := make([]int, 0, 10)
	for {
		i := f()
		if i < 400000000{
			z = append(z,i)
		} else {
			break
		}
	}

	fmt.Println(z)
}
