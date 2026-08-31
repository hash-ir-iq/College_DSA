#include<iostream>

using namespace std;


template <typename T> class Inventory {
private:
    T* items;
    int capacity;
    int itemCount;
public:
    Inventory(int c) : capacity(c),itemCount(0){
        items = new T[capacity];
    }

    ~Inventory(){
        delete[] items;
    }

    Inventory& operator= (const Inventory& obj){
        this->capacity= obj.capacity;
        this->itemCount = obj.itemCount;
        if(this->items!=NULL){
            delete[] items;
        }
        items = new T[capacity];

        for(int i=0;i<itemCount;i++){
            this->items[i] = obj.items[i];
        }

        return this;
    }

    void incSize(){
        capacity = capacity*2;
        T* temp = new T[capacity];
        for(int i=0;i<itemCount;i++){
            temp[i] = items[i];
        }
        delete[] items;
        items = temp;

    }
    void addItem(T const& item){
        if(itemCount == capacity){
            incSize();
        }
        items[itemCount++] = item;
    }

    Inventory(const Inventory& obj) {
    capacity = obj.capacity;
    itemCount = obj.itemCount;
    items = new T[capacity];
        for(int i = 0; i < itemCount; i++) {
            items[i] = obj.items[i];
        }
    }
    
    friend ostream& operator<<(ostream& out, const Inventory& obj){
        out << "------- Inventory ---------\n\n";
        for(int i=0;i<obj.itemCount;i++){
            out << obj.items[i] <<endl;
        }
        return out;
    }

    int getCapacity(){
        return capacity;
    }

    int getItemCount(){
        return itemCount;
    }
};

int main()
{
    Inventory<int> inventory1(2);
    inventory1.addItem(101);

    inventory1.addItem(205);
    inventory1.addItem(310);
    Inventory<int> inventory2(inventory1);
    cout << inventory2;
    return 0;
}