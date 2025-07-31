class Solution {
public:
    #define pp pair<long long,int>
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        // room[i] = total meetings scheduled in room i
        vector<int> room(n, 0);

        // This min-heap (priority queue) keeps (next_available_time, room_index)
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<int> free(n, 1); // 1 if free, 0 if busy

        for (auto meeting : meetings) {
            long long startTime = meeting[0], endTime = meeting[1];

            // Release rooms whose meetings are finished before or at this startTime
            while (!pq.empty() && pq.top().first <= startTime) {
                free[pq.top().second] = 1;
                pq.pop();
            }

            int roomIndx = -1;
            for (int i = 0; i < n; i++) {
                if (free[i] == 1) {
                    roomIndx = i;
                    break;
                }
            }

            if (roomIndx != -1) {
                // Found a free room
                pq.push({endTime, roomIndx});
                free[roomIndx] = 0;
                room[roomIndx] += 1;
            } else {
                // All occupied: pick the one that gets free earliest (with smallest index if tie)
                auto earliest = pq.top(); pq.pop();
                // shift meeting to when this room is free
                long long new_end = earliest.first + (endTime - startTime);
                pq.push({new_end, earliest.second});
                room[earliest.second] += 1;
            }
        }
        // Compute the answer: room with highest count, lowest index if tie
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (room[i] > room[ans]) ans = i;
        }
        return ans;
    }
};
