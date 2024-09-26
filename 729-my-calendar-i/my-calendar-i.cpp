class MyCalendar {
public:
vector<pair<int,int>> sched;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto pair : sched){
            int s = pair.first;
            int e = pair.second;

            if(start<e && end>s) {
                return false;
            }
        }
        sched.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */