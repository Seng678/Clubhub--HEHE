#include "clubhub/event_csv.hpp"
#include <sstream>
#include <stdexcept>

namespace clubhub {

EventLoadResult loadEventsCsv(std::istream& in) {
    EventLoadResult result;
    std::string line;
    int lineNo = 1;
    
    if (!std::getline(in, line)) {
        return result;
    }
    
    while (std::getline(in, line)) {
        ++lineNo;
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        if (line.empty()) {
            continue;
        }

        std::istringstream lineStream(line);
        std::string id, title, startStr, location, capStr;
        
        if (!std::getline(lineStream, id, ',') ||
            !std::getline(lineStream, title, ',') ||
            !std::getline(lineStream, startStr, ',') ||
            !std::getline(lineStream, location, ',') ||
            !std::getline(lineStream, capStr, ',')) {
            result.errors.push_back({lineNo, "row must have exactly 5 fields"});
            continue;
        }

        std::string extraField;
        if (std::getline(lineStream, extraField, ',')) {
            result.errors.push_back({lineNo, "row has too many fields"});
            continue;
        }

        try {
            int capacity = std::stoi(capStr);
            TimePoint start = parseTimePoint(startStr);
            result.events.emplace_back(id, title, start, location, capacity);
        } catch (const std::exception& e) {
            result.errors.push_back({lineNo, e.what()});
        }
    }
    
    return result;
}

} // namespace clubhub