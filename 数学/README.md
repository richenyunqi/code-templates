1. 加减乘的同余式
   $$(a+b)\ mod\ n=((a\ mod\ n)+(b\ mod\ n))\ mod\ n$$
   $$(a-b)\ mod\ n=((a\ mod\ n)-(b\ mod\ n)+n)\ mod\ n$$
   $$(ab)\ mod\ n=((a\ mod\ n)(b\ mod\ n))\ mod\ n$$
2. $a\equiv b (mod\ n)$的含义是是`a和b除以n的余数相同`，其充要条件是`a-b是n的整数倍`。
3. 方程$ax+by=c$与方程$ax\equiv c(mod\ b)$是等价的，存在有整数解的充要条件是$gcd(a,b)|c$。
4. 若$gcd(a,b)=1$，且$x_0,y_0$是方程$ax+by=c$的一组解，则该方程的任意解可表示为：$x=x_0+bt,y=y_0-at$，且对任意整数$t$都成立。
5. 裴蜀定理（贝祖定理）：设$a,b$是不全为零的整数，则存在整数$x,y$，使得$ax+by=gcd(a,b)$。
6. 费马小定理：若 $p$ 为素数，$gcd(a,p)=1$ ，则 $a^{p-1}\equiv 1(mod\ p)$，$a^p\equiv a(mod\ p)$ 。
7. 欧拉定理：若$gcd(a,m)=1$，则$a^{\varphi (m)}\equiv 1(mod\ m)$，其中$\varphi (m)$表示$m$的欧拉函数值。
8. 扩展欧拉定理：$$ a^b=\begin{cases}
a^{b\ mod\ \varphi(p)} & gcd(a,p)=1 \\
a^b & gcd(a,p)\not ={1},b<\varphi(p) \\
a^{b\ mod\ \varphi(p)+\varphi(p)} & gcd(a,p)\not ={1},b>=\varphi(p)
\end{cases}$$
9. 排列组合数：
    1. 有重复元素的全排列：有 k 种元素，第 i 种元素有$n_i$个，则$全排列个数=\frac {(n_1+n_2+ \cdots +n_k)!} {n_1!n_2! \cdots n_k!}$
    2. 可重复选择的组合：有 n 个不同元素，每个元素可以选多次，一共选 k 个元素，则$方案数=C(k+n-1,k)$
10. 大素数：$10^9+7,998244353$
