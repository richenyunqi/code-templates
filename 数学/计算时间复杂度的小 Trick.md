# 计算时间复杂度的小 Trick

记录一些计算时间复杂度时可能会用到的一些小 Trick。

1. 在 $[1,10^6]$ 中，一个数最多有 240 个约数。另外当 $n$ 不是特别大时，约数个数的估计公式为 $\sqrt[3]{n}$ 。
2. 给定一个数组，以某个右端点为结尾的所有子数组中，其中不同的 `或`/`与`/`lcm`/`gcd` 的值至多只有 $\log n$ 个。
