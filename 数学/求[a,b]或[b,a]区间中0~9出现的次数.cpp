vector<gg> f(gg a, gg b) {
    if (a < b)
        swap(a, b);
    vector<gg> ans(10);
    gg left1 = a / 10, left2 = b / 10, cur1 = a % 10, cur2 = b % 10, right1 = 0, right2 = 0, p = 1;
    while (!(left1 == 0 && cur1 == 0)) {
        for (gg digit = 0; digit < 10; ++digit) {
            ans[digit] += (left1 - left2 - 1) * p;
            if (cur1 > digit)
                ans[digit] += p;
            else if (cur1 == digit)
                ans[digit] += (p == 1) ? 1 : (right1 + 1);
            if (digit == 0 && cur2 == 0 && left2 == 0)
                continue;
            if (cur2 < digit)
                ans[digit] += p;
            else if (cur2 == digit)
                ans[digit] += (p == 1) ? 1 : (p - right2);
        }
        right1 = cur1 * p + right1;
        right2 = cur2 * p + right2;
        cur1 = left1 % 10;
        cur2 = left2 % 10;
        left1 /= 10;
        left2 /= 10;
        p *= 10;
    }
    return ans;
}
