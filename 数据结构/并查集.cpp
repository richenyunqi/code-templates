class UFS {
  public:
    //初始化并查集
    UFS(gg n) : ufs(n) { iota(begin(ufs), end(ufs), 0); }
    //查找结点所在树的根结点并进行路径压缩
    gg findRoot(gg x) { return ufs[x] == x ? x : ufs[x] = findRoot(ufs[x]); }
    //合并两个结点所在集合，如果已在同一集合，返回false
    bool unionSets(gg a, gg b) {
        a = findRoot(a), b = findRoot(b);
        if (a == b) {
            return false;
        }
        ufs[a] = b;
        return true;
    }

  private:
    vector<gg> ufs;
};