#pragma once

// Event structure to store x-coordinate and type (start/end of segment)
struct Event {
    int x;
    int type; // 0: start, 1: end
    int index; // Index of the segment in the segments vector
};