#include "calc.h"
#include <numeric>
#include <limits>

int16_t Calc::compute_average(const std::vector<int16_t>& vec) {
    if (vec.empty()) return 0;

    int64_t sum = 0;
    for (int16_t val : vec) {
        sum += val;
    }

    int64_t avg = sum / static_cast<int64_t>(vec.size());

    if (avg > std::numeric_limits<int16_t>::max()) {
        return std::numeric_limits<int16_t>::max(); // 32767
    }
    if (avg < std::numeric_limits<int16_t>::min()) {
        return std::numeric_limits<int16_t>::min(); // -32768
    }

    return static_cast<int16_t>(avg);
}