 #include <iostream>

using namespace std;

class cashRegister {
private:
    int cashOnHand=0;

public:
    cashRegister() {
        cashOnHand = 0;
    }

    cashRegister(int cash) {
        cashOnHand = cash;
    }

    int getCurrentBalance() {
        return cashOnHand;
    }

    void acceptAmount(int cash) {
        cashOnHand += cash;
    }
};

class dispenserType : public cashRegister {
private:
    int numberOfItems;
    double cost;

public:

    dispenserType() {
        numberOfItems = 0;
        cost = 0;
    }

    dispenserType(int item, int c) {
        numberOfItems = item;
        cost = c;
    }

    int getNoOfItems() {
        return numberOfItems;
    }

    int getCost() {
        return cost;
    }

    void makeSale() {
        numberOfItems--;
        acceptAmount(cost);
    }
};

void showSelection() {
    cout << " *** Welcome To The Candy Shop ***" << endl;
    cout << "To select an item, enter" << endl;
    cout << "1 for candy" << endl;
    cout << "2 for chips" << endl;
    cout << "3 for gum" << endl;
    cout << "4 for cookies" << endl;
    cout << "5 to exit" << endl;
}

void sellProduct(dispenserType& dispenser, cashRegister& reg) { // takes two parameters, references the two classes
    if (dispenser.getNoOfItems() > 0) {
        int cost = dispenser.getCost();
        cout << "Please deposit " << cost <<" cents"<< endl;
        int deposit;
        cin >> deposit;
    
    while (deposit < cost) {
            cout << "Please deposit an additional " << cost - deposit <<" cents"<< endl;
            int extra;
            cin >> extra;
            deposit += extra;
        }
        reg.acceptAmount(cost);//adds the cost of the item to the cash register's balance.
        dispenser.makeSale();// decrements the number of items in the dispenser by one and also adds the cost of the item to the cash register's balance.
        cout << "Collect your item at the bottom and enjoy!" << endl;
        cout<<"_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*"<<endl ;
    }
     else {
        cout << "Sorry, this item is sold out." << endl;
    }
    
}

int main() {
    dispenserType  candy(1, 50);  // (holds num of item, how much it costs)
    dispenserType chips(1, 65);
    dispenserType gum(1, 25);
    dispenserType cookies(1, 95);
    cashRegister reg(500); //how much is in register

    int choice = 0;
    showSelection();
    while (choice != 5) {
    cin >> choice;
    if (choice == 1) {
        sellProduct(candy, reg);
        showSelection();
    } 
    else if (choice == 2) {
        sellProduct(chips, reg);
        showSelection();
    } 
    else if (choice == 3) {
        sellProduct(gum, reg);
        showSelection();
    } 
    else if (choice == 4) {
        sellProduct(cookies, reg);
        showSelection();
    } 
    else if (choice == 5) {
        break;
    } 
    else {
        cout << "Invalid selection." << endl;
        showSelection();
    }
}
    return 0;
}

