class MyCalendarTwo {
public:
    // Store the intervals that are booked once and twice (overlaps)
    vector<pair<int,int>> bookings;
    vector<pair<int,int>> overlaps;

    MyCalendarTwo() {
        // Initialize with empty vectors
    }
    
    bool book(int start, int end) {
        // Check for triple overlap by going through the existing overlaps
        for (const auto& [s, e] : overlaps) {
            if (start < e && end > s) { // Overlap with already overlapping event
                return false; // Triple booking, return false
            }
        }

        // Add new overlaps to the overlaps vector
        for (const auto& [s, e] : bookings) {
            if (start < e && end > s) { // Overlap with a booking
                overlaps.push_back({max(start, s), min(end, e)}); // Record the overlap
            }
        }

        // Add the new booking to the bookings vector
        bookings.push_back({start, end});
        
        return true; // Booking is valid
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
