//周日用数字0表示
gg monthdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  //平年时每个月有多少天
gg daysOfMonth(gg y, gg m) {                                             //判断y年m月有几天
    if ((y % 400 == 0 || y % 4 == 0 && y % 100 != 0) && m == 2)          // y年是闰年且查询2月有几天
        return 29;                                                       //闰年2月有29天
    return monthdays[m];                                                 //直接返回monthdays的相应位置的天数
}
gg determineWeek(gg y, gg m, gg d, gg week = 2) {  //根据1850年1月1日是周二，返回y年m月d日是周几
    for (gg i = 1850; i < y; ++i) {                //检查1850年到y年经历的年份
        gg temp = (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) ? 366 : 365;  //平年有365天，闰年有366天
        week = (week + temp) % 7;                                            //更新week
    }
    for (gg i = 1; i < m; ++i)                  //检查1月到m月的月份
        week = (week + daysOfMonth(y, i)) % 7;  //求出该月有几天，并更新week
    return (week + d - 1) % 7;                  //返回周几，注意周日用0表示
}
gg determineDayOfNumberWeek(gg y, gg m, gg b, gg c) {  //判断y年m月第b个星期c是几号
    gg week = determineWeek(y, m, 1);                  //确定y年m月1日是周几
    return 1 + (c + 7 - week) % 7 + 7 * (b - 1);
}