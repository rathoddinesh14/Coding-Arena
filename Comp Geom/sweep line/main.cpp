#include <iostream>
#include "Event.h"
#include "Segment.h"
#include "Status.h"
#include <vector>
#include <set>
using namespace std;


// Comparison function for sorting events
bool compareEvents(const Event& e1, const Event& e2) {
    if (e1.x != e2.x) return e1.x < e2.x;
    return e1.type < e2.type;
}

struct StatusComparator {
    bool operator()(const Status& s1, const Status& s2) const {
        if (s1.x != s2.x) return s1.x < s2.x;
        if (s1.y1 != s2.y1) return s1.y1 < s2.y1;
        if (s1.y2 != s2.y2) return s1.y2 < s2.y2;
        return s1.index < s2.index;
    }
};

// Sweep Line Algorithm function
std::vector<std::pair<int, int>> sweepLine(std::vector<Segment>& segments) {
    std::vector<Event> events;
    std::vector<std::pair<int, int>> intersections;

    // Create events for all segments
    for (int i = 0; i < segments.size(); i++) {
        events.push_back({segments[i].x1, 0, i});
        events.push_back({segments[i].x2, 1, i});
    }

    // Sort events by x-coordinate
    std::sort(events.begin(), events.end(), compareEvents);

    // Initialize the sweep line status
    std::set<Status, StatusComparator> status;

    // Process events
    for (const Event& e : events) {
        if (e.type == 0) { // Start of segment
            // Add segment to the status
            status.insert({e.x, segments[e.index].y1, segments[e.index].y2, e.index});
        } else { // End of segment
            // Remove segment from the status
            status.erase({e.x, segments[e.index].y1, segments[e.index].y2, e.index});

            // Check for intersections with active segments
            for (const auto& s1 : status) {
                for (const auto& s2 : status) {
                    if (s1.index != s2.index && s1.y1 <= s2.y2 && s2.y1 <= s1.y2) {
                        intersections.push_back({s1.index, s2.index});
                    }
                }
            }
        }
    }

    return intersections;
}

int main() {
    std::vector<Segment> segments = {{1, 1, 3, 3}, {2, 2, 4, 4}};
    std::vector<std::pair<int, int>> intersections = sweepLine(segments);

    std::cout << "Intersections:" << std::endl;
    for (const auto& intersection : intersections) {
        std::cout << "(" << intersection.first << ", " << intersection.second << ")" << std::endl;
    }
}