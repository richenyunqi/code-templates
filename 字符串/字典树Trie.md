# Trie

## 字符串 Trie

```cpp
class Trie {
  public:
    struct TrieNode {
        gg count = 0;  //该结点代表的单词个数,count>0表示这是一个单词结点
        TrieNode* children[128]{};
    };
    Trie() : root(new TrieNode()) {}
    //插入一个单词
    void insert(const string& word) {
        auto i = root;
        for (char c : word) {
            if (not i->children[c]) {
                i->children[c] = new TrieNode();
            }
            i = i->children[c];
        }
        ++i->count;
    }
    //查找一个单词
    bool search(const string& word) {
        auto i = root;
        for (char c : word) {
            if (not i->children[c]) {
                return false;
            }
            i = i->children[c];
        }
        return i->count > 0;  //如果是查找前缀把这条语句换成return true;就可以了
    }

  private:
    TrieNode* root;
};
```

## 01-Trie

```cpp
class Trie {
  public:
    struct TrieNode {
        TrieNode* children[2]{};
    };
    Trie() : root(new TrieNode()) {}
    //插入一个不超过bits位的非负整数
    void insert(gg n) {
        const bitset<bits>& bin(n);
        auto i = root;
        for (gg j = bits - 1; j >= 0; --j) {
            if (not i->children[bin[j]]) {
                i->children[bin[j]] = new TrieNode();
            }
            i = i->children[bin[j]];
        }
    }
    //与bin异或的最大值
    gg search(gg n) {
        const bitset<bits>& bin(n);
        auto i = root;
        gg ans = 0;
        for (gg j = bits - 1; j >= 0; --j) {
            gg k = bin[j] ? 0 : 1;
            if (i->children[k]) {
                ans = ans * 2 + 1;
                i = i->children[k];
            } else {
                ans <<= 1;
                i = i->children[k ^ 1];
            }
        }
        return ans;
    }

  private:
    static constexpr gg bits = 32;
    TrieNode* root;
};
```
