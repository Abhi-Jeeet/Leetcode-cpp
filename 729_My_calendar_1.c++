class MyCalendar {
public:
    vector<pair<int,int>> calendar;
    
    bool book(int start, int end) {
        for(const auto [start1, end1]: calendar){
            if(end > start1 && start<end1){
                return false;
            }
        } 
        calendar.emplace_back(start,end);
        return true;
        
    }
};