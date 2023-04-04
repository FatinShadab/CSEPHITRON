/*
    Problem Link : https://www.eolymp.com/en/problems/1388
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 101;
const int INF = 1e8;

vector <pair<int, int>> cityMap[N];

int petrol_cost[N];
int travel_cost[N];
bool traveled[N];

void dijkstra(int homeCity){
    priority_queue <pair<int, int>> cityPQ;

    for (int city=1; city<N; city++){
        travel_cost[city] = INF;
    }

    travel_cost[homeCity] = 0;

    cityPQ.push({travel_cost[homeCity], homeCity});

    while (!cityPQ.empty()){
        pair <int, int> city_info = cityPQ.top();

        int city = city_info.second;
        int city_travel_cst = city_info.first;

        cityPQ.pop();

        if (traveled[city]){
            continue;
        }

        traveled[city] = true;

        for (pair <int, int> cnt_city_info : cityMap[city]){
            int cnt_city = cnt_city_info.first;
            int cnt_city_travel_cst = cnt_city_info.second;

            if (travel_cost[city] + cnt_city_travel_cst < travel_cost[cnt_city]){
                travel_cost[cnt_city] = travel_cost[city] + cnt_city_travel_cst;
                cityPQ.push({-1*travel_cost[cnt_city], cnt_city});
            } 
        }
    }
    
}

int main(){

    int numberOfCitys;
    scanf("%d", &numberOfCitys);

    for (int city=1; city<=numberOfCitys; city++){
        scanf("%d", &petrol_cost[city]);
    }

    int numberOfRoads;
    scanf("%d", &numberOfRoads);

    while(numberOfRoads--){
        int from, to;
        scanf("%d %d", &from, &to);

        cityMap[from].push_back({to, petrol_cost[from]});
        cityMap[to].push_back({from, petrol_cost[to]});
    }

    int homeCityNo = 1;
    int dstCityNo = numberOfCitys;

    dijkstra(homeCityNo);

    printf("%d\n", (travel_cost[dstCityNo] == INF) ? -1:travel_cost[dstCityNo]);

    return 0;
}