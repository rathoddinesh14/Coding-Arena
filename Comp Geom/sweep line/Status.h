#pragma once

// Sweep Line Status structure to store active segments
struct Status {
    int x, y1, y2;
    int index; // Index of the segment in the segments vector
};