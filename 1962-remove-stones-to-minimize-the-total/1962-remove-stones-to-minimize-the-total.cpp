class Solution
{
    public:
        int minStoneSum(vector<int> &piles, int k)
        {
            priority_queue<int> pq;
            for (auto it: piles)
            {
                pq.push(it);
            }
            int minSum = 0;
            while (!pq.empty())
            {
                if (k > 0)
                {
                    int temp = pq.top();

                    pq.pop();
                    int rem = temp / 2;
                    temp = temp - rem;
                    pq.push(temp);
                    k--;
                }
                else
                {
                    int temp = pq.top();
                    cout << temp << endl;
                    minSum += temp;
                    pq.pop();
                }
            }
            
          
            return minSum;
        }
};