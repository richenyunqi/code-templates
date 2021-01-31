# ACM、OI、OJ、PAT、CSP 题目常用代码模板

## 前言

本仓库主要提供 ACM、OI、OJ、PAT、CSP 题目中常见算法和数据结构的实现，它们都以**基于 C++11 语法的 C++接口**的形式呈现。如果有问题或者感觉我的代码中有 bug，可以随时提 issue。

浏览本仓库请注意以下几点：

1. 本仓库不负责讲解任何相关知识点，有关知识点的讲解和汇总可参考[OI wiki](https://oi-wiki.org/)。
2. 本代码仓库中所有整型数据均使用`long long`类型存储。之所以不用 `int` 是因为 `int` 很容易造成数据溢出错误。为了编码方便，可以使用为`long long`定义一个类型别名`gg`，代码可以是`using gg=long long`。本代码仓库中所有代码均默认导入了这行定义类型别名的代码，即**本代码仓库中所有的`gg`均表示`long long`类型**，请务必注意！
3. 本仓库的代码经常会开一个非常大的全局数组，维度通常为`MAX`，`MAX`通常表示问题数据规模的上限。在使用这样的代码时，你需要在定义这个数组之前定义并初始化`MAX`变量，代码可以是`constexpr gg MAX=1e5+5`。
4. 代码中出现的`ni`变量代表当前数据的总数，例如输入序列所包含的元素个数。

目前代码仓库还在完善中，部分模板代码还没有完全更新，之后还会添加一批新的模板代码，敬请期待！

## 插件安装

为了更好地浏览本仓库，建议使用 `chrome` 或新版 `Edge` 浏览器并安装以下插件（这里提供的插件链接需要科学上网才能打开）：

1. [Octotree](https://chrome.google.com/webstore/detail/octotree/bkhaagjahfmjljalopjnoealnfndnagc):对打开的 Github 代码仓库，像 IDE 一样提供项目目录自动生成一个仓库目录树侧边栏，通过这个插件你可以很方便地打开这个仓库内的任何一个文件。
2. [MathJax Plugin for Github](https://chrome.google.com/webstore/detail/mathjax-plugin-for-github/ioemnmodlmafdkllaclgeombjnmnbima)：对`github`上`markdown`文本的`latex`语法进行渲染。
3. [GayHub](https://chrome.google.com/webstore/detail/gayhub/mdcffelghikdiafnfodjlgllenhlnejl)：为 Github 上的 markdown 文本自动生成目录。该插件似乎还拥有类似于 Octotree 生成目录树的功能，但是目前该功能已失效，而作者至今尚未修复。

## 相关链接

有关知识点的讲解和汇总可参考[OI wiki](https://oi-wiki.org/)，有关练习题目可参考[一个动态更新的洛谷综合题单](https://studyingfather.com/archives/841)。本仓库也参考了这两个网站的内容，在此对 OI wiki 和综合题单的撰写者和维护者表示诚挚的谢意。
