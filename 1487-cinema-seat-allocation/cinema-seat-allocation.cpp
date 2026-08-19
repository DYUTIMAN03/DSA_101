class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> mp;

        // Storing reserved seats of each row using bitmask in map
        for(auto& reservedSeat: reservedSeats){
            int row = reservedSeat[0];
            int Seat = reservedSeat[1];

            mp[row] = mp[row] | (1 << Seat);  // Mark this seat as reserved
        }

        // Rows with no reservation → always 2 families
        int result = (n - mp.size()) * 2;

        int mask_A = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int mask_B = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int mask_C = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        // Check every row that has at least one reserved seat
        for(auto& [row, Booked_seat_mask]: mp){
            bool group_A = (Booked_seat_mask & mask_A) == 0;
            bool group_B = (Booked_seat_mask & mask_B) == 0;
            bool group_C = (Booked_seat_mask & mask_C) == 0;

            if(group_A && group_C){
                result += 2;
            }
            else if(group_A || group_B || group_C){
                result++;
            }
        }
        return result;
    }
};