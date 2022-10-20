class Solution
{
  public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ans = 0, player_index = 0;
        for (const int &trainer : trainers)
            if (player_index < players.size() && players[player_index] <= trainer)
            {
                ans++;
                player_index++;
            };
        return ans;
    }
};