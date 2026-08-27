class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;

        for(int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

        for(auto &it : mp) {
            pq.push({it.second, it.first});
        }

        string ans = "";
        pair<int,char> prev = {0, '#'};   // previous character

        while(!pq.empty()) {

            auto [num, ch] = pq.top();
            pq.pop();

            // If same as previous, use another character
            if(ch == prev.second) {

                if(pq.empty())
                    return "";

                auto [num2, ch2] = pq.top();
                pq.pop();

                ans += ch2;
                num2--;

                if(num2 > 0)
                    pq.push({num2, ch2});

                pq.push({num, ch});

                prev = {num2, ch2};
            }
            else {
                ans += ch;
                num--;

                if(num > 0)
                    pq.push({num, ch});

                prev = {num, ch};
            }
        }

        return ans;
    }
};

