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

	s := 0
	i := 0
	for _, e := range z {
		i++
		if i % 2 == 0 {
			//fmt.Println(e)
			s += e
		}
	}
	
	fmt.Println(s)
}
