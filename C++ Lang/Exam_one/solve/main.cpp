#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <string>
#include <list>

using namespace std;

struct user_order{
    int table_no;
    int number_of_items;
    int item_codes[12];
    int item_quantities[12];
};

//////// Task: 1 (start)
class Restaurant{
    protected:
        double total_tax;

    public:
        int food_item_codes[12];
        int food_item_prices[12];
        string food_item_names[12];

    public:
        Restaurant (){
            this->total_tax = 0;
        }

        void add_tax(double tax){
            this->total_tax += tax;
            cout<<"The total tax of the restaurant is "<<this->total_tax<<endl;
        }

};
//////// Task: 1 (end)

int valid_food_item_code(int code, Restaurant* restaurant){
    /*
    This function will return 1 if the code is valid or 0.
    */
    for(int i=0; i<12; i++){
        if (code == restaurant->food_item_codes[i]){
            return 1;
        }
    }

    return 0;
};

int get_code_idx(int code, Restaurant* restaurant){
    for(int i=0; i<12; i++){
        if (code == restaurant->food_item_codes[i]){
            return i;
        }
    }
    return -1;
};

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
};
////// Task : 3 (end)

///// Task : 4 (start)
struct user_order take_user_order(Restaurant* restaurant){
    struct user_order order;

    cout<<"\nEnter Table No : ";
    cin>>order.table_no;
    cout<<"\nEnter Number of Items : ";
    cin>>order.number_of_items;

    if (order.number_of_items > 12){

        while (order.number_of_items > 12){
            cout<<"\nWe only have 12 Items in Menu !"<<endl;
            cout<<"\nEnter Number of Items : ";
            cin>>order.number_of_items;
        }

    }

    for (int i=0; i<order.number_of_items; i++){

        cout<<"\nEnter Item "<<i+1<<" Code : ";
        cin>>order.item_codes[i];
// Task : 8 (start)
        if (valid_food_item_code(order.item_codes[i], restaurant) != 1){
            while (valid_food_item_code(order.item_codes[i], restaurant) != 1){
                cout<<"\n"<<"Invalid code : "<<order.item_codes[i]<<". "<<"Enter Item "<<i+1<<" Code again : ";
                cin>>order.item_codes[i];
            }
        }
// Task : 8 (end)
        cout<<"\nEnter Item "<<i+1<<" Quantity : ";
        cin>>order.item_quantities[i];
    }
    
    return order;
}
///// Task : 4 (end)

//// Task : 5 (start)
void handle_order(Restaurant* restaurant, struct user_order order){
    int total_bill = 0;
    cout<<"==========================================================================="<<endl;
    cout<<"                                 BILL SUMMARY                              "<<endl;
    cout<<"==========================================================================="<<endl;
    cout<<"Table No : "<<order.table_no<<"\n"<<endl;
    for (int i=0; i<order.number_of_items; i++){
        int idx = get_code_idx(order.item_codes[i], restaurant);
        cout<<"Item Code :        "<<order.item_codes[i]<<endl;
        cout<<"Item Name :        "<<restaurant->food_item_names[idx]<<endl;
        cout<<"Item Price :       "<<restaurant->food_item_prices[idx]<<endl;
        cout<<"Item Quantity :    "<<order.item_quantities[i]<<endl;
        cout<<"Item Total Price : "<<restaurant->food_item_prices[idx]*order.item_quantities[i]<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
        total_bill += restaurant->food_item_prices[idx]*order.item_quantities[i];
    }
/// Task : 6 (start)
    double tax = (total_bill * 5)/100.0;
    double net_total = total_bill + tax;
    cout<<"TAX              : "<<tax<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<"NET TOTAL        : "<<net_total<<endl;
    cout<<"===========================================================================\n"<<endl;
// Task : 7 (start)
    restaurant->add_tax(tax);
// Task : 7 (end)
/// Task : 6 (end)
};
//// Task : 5 (end)

int main(){
    Restaurant* restaurant = create_restaurant();

    while (1){
        show_menu_card(restaurant);

        struct user_order order = take_user_order(restaurant);

        handle_order(restaurant, order);
    }   

    return 0;
}