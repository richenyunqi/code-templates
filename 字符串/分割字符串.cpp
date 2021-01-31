vector<string> split(const string& s, string c = " ") {
    vector<string> ans;
    for (gg i = 0, j = 0; i < s.size(); i = j + 1) {
        j = s.find(c, i);
        if (j == string::npos)
            j = s.size();
        ans.push_back(s.substr(i, j - i));
    }
    return ans;
}