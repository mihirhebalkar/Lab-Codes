#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<float, int> p1, pair<float, int> p2)
{
    return p1.first > p2.first; 
}

float fractional_knapsack(vector<int> weights, vector<int> values, int capacity)
{
    int len = weights.size();
    float total_value = 0;  

    vector<pair<float, int>> ratio(len);  


    for(int i = 0; i < len; i++)
        ratio[i] = make_pair(float(values[i]) / weights[i], i);  

    sort(ratio.begin(), ratio.end(), compare);


    for(int i = 0; i < len; i++)
    {
        if(capacity == 0)
            break;
        
        int index = ratio[i].second;

        if(weights[index] <= capacity)
        {
            capacity -= weights[index];
            total_value += values[index];
        }
        else
        {
            total_value += values[index] * (float(capacity) / weights[index]);
            capacity = 0;  // Knapsack is now full
        }
    }
    return total_value;
}

int main()
{
    cout << "Enter the weights of the items (end with -1):" << endl;
    vector<int> weights;

    while(true)
    {
        int weight;
        cin >> weight;

        if(weight == -1)
            break;

        weights.push_back(weight);
    }

    cout << "Enter the profits of each item (end with -1):" << endl;
    vector<int> values;

    while(true)
    {
        int value;
        cin >> value;

        if(value == -1)
            break;
        
        values.push_back(value);
    }

    cout << "\nRatios (value/weight) of items: ";
    for(size_t i = 0; i < weights.size(); i++)
    {
        float temp = float(values[i]) / weights[i];
        cout << temp << " ";
    }
    cout << endl;

    cout << "Enter the capacity of the knapsack: ";
    int capacity;
    cin >> capacity;

    cout << "The maximum value possible based on current list is: " << fractional_knapsack(weights, values, capacity) << endl;

    return 0;
}
