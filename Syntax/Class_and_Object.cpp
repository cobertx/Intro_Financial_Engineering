#include <iostream>
using namespace std;

class Trade {
public:
    string symbol;
    int quantity;
    double price;
    double getTradeValue() {
        return quantity * price;
    }
    void displayTrade() {
        cout << "Symbol: " << symbol 
             << ", Quantity: " << quantity 
             << ", Price: $" << price 
             << ", Total Value: $" << getTradeValue() 
             << endl;
    }
};

int main() {
    Trade trade1;
    Trade trade2;

    trade1.symbol = "AAPL";
    trade1.quantity = 10;
    trade1.price = 180.5;

    trade2.symbol = "TSLA";
    trade2.quantity = 5;
    trade2.price = 250.75;

    trade1.displayTrade();
    trade2.displayTrade();
    return 0;
}