#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <list>

using namespace std;

//////// Task: 1 (start)
class Restaurant{
    protected:
        int total_tax;

    public:
        int food_item_codes[12];
        int food_item_prices[12];
        string food_item_names[12];

    public:
        Restaurant (){
            this->total_tax = 0;
        }

};
//////// Task: 1 (end)

/////// Task : 2 (start)
Restaurant* create_restaurant(){
    Restaurant * restaurant = new Restaurant();

    int food_item_limit;
    cin>>food_item_limit;
    if (food_item_limit != 12){

        cout<<"!!! ================================== !!!"<<endl;
        cout<<"To constract Restaurant class the food item range ust be - 12"<<endl;
        cout<<"setting food item to 12 by default"<<endl;
        cout<<"!!! ================================== !!!"<<endl;

        food_item_limit = 12;
    }

    for (int i=0; i<food_item_limit; i++){
        cin>>restaurant->food_item_codes[i];
        cin.ignore();
        getline(cin, restaurant->food_item_names[i]);
        cin>>restaurant->food_item_prices[i];
    }   

    return restaurant;
} 
/////// Task : 2 (end)

////// Task : 3 (start)
void show_menu_card(Restaurant* restaurant){
    cout<<"==========================================================================="<<endl;
    cout<<"|                                  MAKE BILL                              |"<<endl;
    cout<<"|=========================================================================="<<endl;
    for (int i=0; i < 12; i++){
        cout<<"|Item Code  - "<<restaurant->food_item_codes[i]<<endl;
        cout<<"|Item Name  - "<<restaurant->food_item_names[i]<<endl;
        cout<<"|Item Price - "<<restaurant->food_item_prices[i]<<endl;
        cout<<"|-------------------------------------------------------------------------|"<<endl;
    }
}
////// Task : 3 (end)

int main(){
    Restaurant* restaurant = create_restaurant();
    show_menu_card(restaurant);
    return 0;
}