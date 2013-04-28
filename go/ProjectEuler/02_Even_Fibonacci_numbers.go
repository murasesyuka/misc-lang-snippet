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
	for i := 0; i<10; i++{
		fmt.Println(f())
	}
}
