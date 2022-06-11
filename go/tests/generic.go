package main

import "fmt"

func SumIntsOrFloats[K comparable, V int64 | float64](m map[K]V) V {
	var s V
	for _, v := range m {
		s += v
	}
	return s
}

func printAny[T any](t T) {
	println(t)
}

func main() {
	ints := map[string]int64{
		"first":  34,
		"second": 64,
	}

	fmt.Printf("sum ints = %d\n", SumIntsOrFloats(ints))

	fmt.Printf("print any\n")
	printAny(4)
}
