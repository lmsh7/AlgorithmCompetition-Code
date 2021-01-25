package main

import (
	"bufio"
	. "fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	const N int = 1e6
	lpf := [N + 1]int{1: 1}//定义长度为1e6 + 1的数组, lpf[1]设为1
	//lpf为最大质因数的缩写
	for i := 2; i <= N; i++ {
		if lpf[i] == 0 {
			for j := i; j <= N; j += i {
				if lpf[j] == 0 {
					lpf[j] = i
				}
			}
		}
	}
	core := func(x int) int {
		c := 1
		for x > 1 {
			p := lpf[x]
			e := 1
			for x /= p; lpf[x] == p; x /= p {
				e ^= 1
			}
			if e == 1 {
				c *= p
			}
		}
		return c
	}
	var t, n, q int
	var w int64
	for Fscan(in, &t); t > 0; t-- {
		cnt := map[int]int{}
		for Fscan(in, &n); n > 0; n-- {
			var la int
			Fscan(in, &la)
			cnt[core(la)] ++
		}
		max_0, max_1 := 0, cnt[1]
		for v, c := range cnt {
			max_0 = max(max_0, c)
			if v > 1 && c & 1 == 0 {
				max_1 += c
			}
		}
		for Fscan(in, &q); q > 0 ; q-- {
			if Fscan(in, &w); w == 0 {
				Fprintln(out, max_0)
			} else {
				Fprintln(out, max(max_0, max_1))
			}
		}
	}
}

func max(x int, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}