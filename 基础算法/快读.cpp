inline gg read() {
    gg x = 0, f = 1;
    char ch = cin.get();
    while (!isdigit(ch)) {
        if (ch == '-')
            f = -1;
        ch = cin.get();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = cin.get();
    }
    return x * f;
}