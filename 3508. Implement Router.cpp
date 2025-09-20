#include <bits/stdc++.h>

using namespace std; 

class Router {
private:
    int memoryLimit; 
    unordered_map<int, vector<int>> destTimes;
    queue<vector<int>> packetsQueue;
    unordered_set<long long> encodedPackets;

    long long Encode(int source, int destination, int timestamp) {
        return ((long long)(source) << 40) | ((long long)(destination) << 20) | (long long)(timestamp);
    }


public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
        encodedPackets.reserve(max(1, memoryLimit * 2));
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        long long encodedPacket = Encode(source, destination, timestamp);
        if (encodedPackets.count(encodedPacket))
            return false;
        if (packetsQueue.size() >= memoryLimit)
            forwardPacket();        
        encodedPackets.insert(encodedPacket);
        packetsQueue.push({source, destination, timestamp});

        vector<int> &times = destTimes[destination];
        auto it = lower_bound(times.begin(), times.end(), timestamp);
        times.insert(it, timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packetsQueue.empty())
            return vector<int>();
        vector<int> packet = packetsQueue.front();        
        int source = packet[0], destination = packet[1], timeStamp = packet[2];
        packetsQueue.pop();
        long long encodedPacket = Encode(source, destination, timeStamp);
        encodedPackets.erase(encodedPacket);
        vector<int> &times = destTimes[destination];
        auto it = lower_bound(times.begin(), times.end(), timeStamp);
        times.erase(it);
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (!destTimes.count(destination))
            return 0;
        vector<int> &times = destTimes[destination];
        auto left = lower_bound(times.begin(), times.end(), startTime),
            right = upper_bound(times.begin(), times.end(), endTime);
        return right - left;
    }
};

int main() {

}