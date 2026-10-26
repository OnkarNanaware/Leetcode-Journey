class MyCalendar {
    set<pair<int, int>> events;

public:
    bool book(int start, int end) {
        auto it = events.lower_bound({start, end});

        // Check the next event
        if (it != events.end() && it->first < end) {
            return false;
        }

        // Check the previous event
        if (it != events.begin()) {
            auto prev = std::prev(it);

            if (prev->second > start) {
                return false;
            }
        }

        events.insert({start, end});
        return true;
    }
};