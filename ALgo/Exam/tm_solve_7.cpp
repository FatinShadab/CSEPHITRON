/*
    Problem Link --> https://lightoj.com/problem/country-roads
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define MAX_CITY_NUM 505

vector <int> cityNetwork[MAX_CITY_NUM];
int roadCost[MAX_CITY_NUM][MAX_CITY_NUM];
int cityDistance[MAX_CITY_NUM];

int totalCities, totalRoads, homeCity;

void setEnv(){
    for(int i=0; i<MAX_CITY_NUM; cityDistance[i++]=INF);
    for(int i=0; i<MAX_CITY_NUM; cityNetwork[i++].clear());
    for(int i=0; i<MAX_CITY_NUM; i++)for(int j=0; j<MAX_CITY_NUM; j++)roadCost[i][j]=0;
}

void dijkstraAlgo(){
    queue <int> cityQueue;
    cityQueue.push(homeCity);
    cityDistance[homeCity] = 0;

    while (!cityQueue.empty()){
        int currentCity = cityQueue.front();
        cityQueue.pop();

        for (int neighbourCity : cityNetwork[currentCity]){
            int maxCost = max(cityDistance[currentCity], roadCost[currentCity][neighbourCity]);
            if (cityDistance[neighbourCity] > maxCost){
                cityDistance[neighbourCity] = maxCost;
                cityQueue.push(neighbourCity);
            }
        }
    }

    return;
}

void solve(int testCase){
    cin >> totalCities >> totalRoads;

    while (totalRoads--){
        int srcCity, destCity, roadCst;
        cin >> srcCity >> destCity >> roadCst;

        if (roadCost[srcCity][destCity]){
            roadCost[srcCity][destCity] = roadCost[destCity][srcCity] = min(roadCost[srcCity][destCity], roadCst);
            continue;
        }

        cityNetwork[srcCity].push_back(destCity);
        cityNetwork[destCity].push_back(srcCity);
        roadCost[srcCity][destCity] = roadCost[destCity][srcCity] = roadCst;
    }

    cin >> homeCity;

    dijkstraAlgo();

    cout<< "Case " << testCase << ":\n";
    for (int city=0; city < totalCities; city++){
        if (cityDistance[city] != INF){
            cout << cityDistance[city] << "\n";
            continue;
        }
        cout<< "Impossible\n";
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;

    for (int tc=1; tc<=T; tc++){
        setEnv();
        solve(tc);
    }
}