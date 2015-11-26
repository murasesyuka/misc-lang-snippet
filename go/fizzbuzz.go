package main

import "fmt"
//mainパッケージにmain()を置けば実行形式が作られる

func main() {
	// パッケージ名.関数名
	for i := 1; i < 20; i++{
		if i % 15 == 0 {
			fmt.Println("FizzBuzz.")
		} else if i % 3 == 0 {
			fmt.Println("Fizz.")
		} else if i % 5 == 0 {
			fmt.Println("Buzz.")
		} else {
			fmt.Println(i)
		}
	}
}
