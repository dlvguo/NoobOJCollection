class MyCalendar {
private:
    map<int,int> calendar;
public:
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        auto iter = calendar.lower_bound(start);
        //第一个大于等于插入元素的时间段。这个时间段的起始时间不能小于插入时间的终止时间
        if(iter != calendar.end() && iter->first < end)
            return false;
        //迭代器往前走一步就是小于等于当前时间段的最大时间段。这个时间段的终止时间不能大于插入的起始时间
        if(iter != calendar.begin() && (--iter)->second > start)
            return false;
        calendar[start] = end;
        return true;
    }
};
