# ST 表

## 概述

ST 表全称为`Sparse-Table`，是用于解决`可重复贡献问题`的数据结构。`可重复贡献问题`是指对于运算 $opt$ ，满足 $x\ opt\ x=x$ ，则对应的区间询问就是一个可重复贡献问题。例如，最大值有 $max(x,x)=x$ ，gcd 有 $gcd(x,x)=x$ ，所以 RMQ（RMQ 是英文 `Range Maximum/Minimum Query`的缩写，表示区间最大/最小值。） 和区间 GCD 就是一个`可重复贡献问题`。像区间和就不具有这个性质，如果求区间和的时候采用的预处理区间重叠了，则会导致重叠部分被计算两次。另外， $opt$ 还必须满足结合律才能使用 ST 表求解。

## 模板题

题目大意：给定 n 个数，有 m 个询问，对于每个询问，你需要回答区间 $[l,r]$ 中的最大值。

## 分析

ST 表基于 `倍增` 思想，可以做到 $\Theta (n\log n)$ 预处理， $O(1)$ 回答每个询问。但是不支持修改操作。注意，查询的下标需从 1 开始。

1. 预处理：令 $f(i,j)$ 表示区间 $[i,i+2^j-1]$ 的最大值，则 $f(i,0)=a_i$ 。根据定义式，第二维就相当于倍增的时候“跳了 $2^j-1$ 步”，依据倍增的思路，写出状态转移方程： $f(i,j)=max(f(i,j-1),f(i+2^{j-1},j-1))$ 。
2. 查询：假设每个查询 $[l,r]$ ，则 $f(l,r)=max(f(l,s),f(r-2^s+1,s))$ ，其中 $s=\lfloor \log_2 (r-l+1) \rfloor$ 。

## C++代码

```cpp
template <typename T>
struct Union_Op {
    //将下面的函数替换成你需要的逻辑（这里假设取最大值），默认将这个类传递给ST类作Union_Operation类型参数
    T operator()(const T& a, const T& b) const { return max(a, b); }
};
template <typename T, typename Union_Operation = Union_Op<T>, gg n2 = 20>
class ST {
  public:
    ST(gg len, T* A, const T& default_value) :
        n(len), st(len + 5, vector<T>(n2, default_value)), union_op(Union_Operation()) {
        STinit(A);
    }
    //求[l,r]区间执行union_op后的值
    gg STquery(gg l, gg r) {
        gg s = log2(r - l + 1);
        return union_op(st[l][s], st[r - (1 << s) + 1][s]);
    }

  private:
    gg n;  //记录输入序列的长度
    vector<vector<T>> st;
    Union_Operation union_op;
    void STinit(T* A) {
        for (gg i = 1; i <= n; ++i) {
            st[i][0] = A[i];
        }
        for (gg j = 1; j <= n2; ++j) {
            for (gg i = 1; i + (1 << j) - 1 <= n; ++i) {
                st[i][j] = union_op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
};
```
