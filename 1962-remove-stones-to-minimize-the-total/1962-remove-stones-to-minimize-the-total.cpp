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
                    temp-= temp / 2;
                    pq.push(temp);
                    k--;
                }
                else
                {
                    minSum += pq.top();
                    pq.pop();
                }
            }
            
          
            return minSum;
        }
};