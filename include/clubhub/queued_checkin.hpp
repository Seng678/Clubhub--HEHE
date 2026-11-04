// include/clubhub/queued_checkin.hpp
#pragma once
#include <chrono>
#include <optional>
#include <string>
#include <vector>

namespace clubhub {

enum class SyncState { Pending, Sent, Accepted, Rejected };

// One check-in recorded on an organiser's phone while offline.
struct QueuedCheckIn {
    std::string localId;     // UUID made on the device at scan time; never changes on retry
    std::string deviceId;    // which phone made the scan
    std::string eventId;
    std::string studentId;
    std::chrono::sys_seconds scannedAt;  // device clock: may be wrong, so the server also stores receivedAt
    int attempts{0};         // number of upload attempts so far
    SyncState state{SyncState::Pending};
    std::optional<std::string> rejectReason;  // set by the server when state is Rejected
};

class CheckInQueue {
public:
    // false if this student is already queued for this event
    bool enqueue(QueuedCheckIn item);

    // oldest first; what the next sync attempt uploads
    std::vector<QueuedCheckIn> pending() const;

    void markAccepted(const std::string& localId);
    void markRejected(const std::string& localId, const std::string& reason);

private:
    std::vector<QueuedCheckIn> items_;
};

} // namespace clubhub