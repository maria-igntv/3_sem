#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    int time_stamp, id;
    float vit_d, acat, anti_tg, neural_activity, mch;
    float min, max, razn;
    unordered_map<int, vector<float>> neuract; // each id -> neural activity
    multimap<float, int> id_razn;
    vector<float> raznosti;
    vector<int> mn;

    int N;
    cin >> N;

    int cylon = 0; //not cylon

    for (int i = 0; i < N; i++)
    {
        cin >> time_stamp >> id >> vit_d >> acat >> anti_tg >> neural_activity >> mch;
        neuract[id].push_back(neural_activity);
    }

    for (auto ind : neuract)
    {  
        min = *min_element(ind.second.begin(), ind.second.end());
        max = *max_element(ind.second.begin(), ind.second.end());
        razn = max - min;
        if (ind.second.size() > 1)
        {   
            raznosti.push_back(razn);
            id_razn.insert({ razn, ind.first });
            cylon = 1;  
        }

    }

    if (cylon == 0)
        cout << -1 << endl;

    else if (cylon == 1)
    {
        multimap<float, int>::iterator it;
        it = id_razn.begin();

        if (id_razn.size() == 1)
            cout << (*it).second << ' ';

        if (id_razn.size() == 2)
        {
            mn.push_back((*it).second);
            it++;
            mn.push_back((*it).second);
            sort(mn.begin(), mn.end());

            for (auto i : mn) 
                cout << i << ' ';
            cout << endl;
        }

        if (raznosti.size() > 2)
        {
            mn.push_back((*it).second);
            it++;
            mn.push_back((*it).second);
            it++;
            mn.push_back((*it).second);
            sort(mn.begin(), mn.end());
            for (auto i : mn)
                cout << i << ' ';
            cout << endl;
        }

    }

}