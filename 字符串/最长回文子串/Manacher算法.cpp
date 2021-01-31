string longestPalindrome(string& s) {
    string news = "$#";
    for (gg i = 0; i < s.size(); ++i)
        news = news + s[i] + "#";
    vector<gg> p(news.size(), 1);
    gg x = 0, xr = 0;
    for (gg i = 1; i < news.size(); ++i) {
        if (i < xr)
            p[i] = min(xr - i, p[2 * x - i]);
        while (i + p[i] < news.size() && news[i - p[i]] == news[i + p[i]])
            ++p[i];
        if (xr < i + p[i]) {
            x = i;
            xr = i + p[i];
        }
    }
    gg k = max_element(begin(p) + 1, end(p)) - begin(p);
    return s.substr((k - p[k]) / 2, p[k] - 1);  //返回最长回文子串
}
