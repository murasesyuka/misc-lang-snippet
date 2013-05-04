package main

import (
	"fmt"
	"math/big"
)

func prime_divide(n *big.Int) []*big.Int {
	r := make([]*big.Int, 0, 10)
	a := big.NewInt(2)
	
	for ; a.Cmp(n) == -1 || a.Cmp(n) == 0; {
		t := big.NewInt(0)
		t.Mod(n,a)

		if t.Cmp(big.NewInt(0)) == 0 {
			r = append(r, a)
			a = big.NewInt(a.Int64())
			n.Quo(n, a)
		} else {
			a.Add(a, big.NewInt(1))
		}
	}
	return r
}

func main(){
	// 13195 is prime 5, 7, 13, 29
	//600851475143
	
	//fmt.Println(prime_divide(8))
	//fmt.Println(prime_divide(13195))
	
	//ret := prime_divide(big.NewInt(13195))
	ret := prime_divide(big.NewInt(600851475143))
	
	fmt.Println(ret[len(ret)-1:])
}
