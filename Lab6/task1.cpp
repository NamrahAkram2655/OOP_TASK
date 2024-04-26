#include <iostream>
#include <string>

using namespace std;

class Item
{
private:
    int id;
    string name;
    int quantity;
    float cost;

public:
    void setid(int id)
    {
        if (id > 0)
        {
            this->id = id;
        }
        else
        {
            this->id = 0;
        }
    }
    void setname(string name)
    {
        this->name = name;
    }
    void setquantity(int quantity)
    {
        if (quantity > 0)
        {
            this->quantity = quantity;
        }
        else
        {
            this->quantity = 0;
        }
    }
    void setcost(float cost)
    {
        if (cost > 0)
        {
            this->cost = cost;
        }
        else
        {
            this->cost = 0;
        }
    }
    int getid() const
    {
        return id;
    }
    string getname() const
    {
        return name;
    }
    int getquantity() const
    {
        return quantity;
    }
    float getcost() const
    {
        return cost;
    }

    Item(int id, string name, int quantity, float cost)
    {
        setid(id);
        setname(name);
        setquantity(quantity);
        setcost(cost);
    }
    Item(int id, string name, int quantity)
    {
        setid(id);
        setname(name);
        setquantity(quantity);
        this->cost = 0;
    }
    Item(int id, string name, float cost)
    {
        setid(id);
        setname(name);
        setcost(cost);
        this->quantity = 0;
    }

    Item(const Item &obj)
    {
        this->id = obj.id;
        this->name = obj.name;
        this->quantity = obj.quantity;
        this->cost = obj.cost;
    }
    ~Item()
    {
        cout << "Destructor executed\n";
    }

    void setItem(int id, string name, int quantity, float cost)
    {
        setid(id);
        setname(name);
        setquantity(quantity);
        setcost(cost);
    }

    void getitem()
    {
        cout << "\n\nENTER DATA OF ITEM \n\n";
        cout << "Id : ";
        cin >> id;
        cout << "Name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Quantity : ";
        cin >> quantity;
        cout << "Cost : ";
        cin >> cost;

        setid(id);
        setname(name);
        setquantity(quantity);
        setcost(cost);
    }

    void putItem() const
    {
        cout << "\n";
        cout << "Id : " << id << "\n";
        cout << "Name : " << name << "\n";
        cout << "Quantity : " << quantity << "\n";
        cout << "Cost : " << cost << "\n";
    }

    float getTotalCost()
    {
        float result = 0;
        if (quantity >= 1)
        {
            for (int i = 0; i < quantity; i++)
            {
                result = cost + result;
            }
            return result;
        }
        else
        {
            return 0.0;
        }
    }

    bool isequal(const Item &obj) const
    {
        return (id == obj.id && name == obj.name && quantity == obj.quantity && cost == obj.cost);
    }

    void updatename(Item arr[], const int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (this->id == arr[i].id)
            {
                this->name = arr[i].name;
            }
        }
    }

    float getminimumCost(Item arr[], const int size) const
    {
        float min = arr[0].cost;
        for (int i = 0; i < size; i++)
        {
            if (min > arr[i].cost)
            {
                min = arr[i].cost;
            }
        }
        return min;
    }

    float getAveragePrice(Item arr[], const int size)
    {
        float result = 0.0;
        for (int i = 0; i < size; i++)
        {
            result = arr[i].cost + result;
        }
        cost = result / size;
        return cost;
    }
};

int main()
{
    Item o1[3] = {Item(0, "", 0, 4), Item(0, "", 0, 7), Item(0, "", 0, 2)};

    Item obj(23, "SHEZAN", 2, 1.5), obj2(0, "", 0, 0), obj3(0, "", 0, 0);

    cout << "\n obj2 is equal to obj3 " << obj2.isequal(obj3) << endl;
   
    for (int i = 0; i < 3; i++)
    {
        o1[i].getitem();
    }

    cout << "\nUpdated Name : ";
    
    obj.updatename(o1, 3);
    obj.putItem();

    float min;
    cout << "\nMinimum cost in array is : ";
    cout << obj2.getminimumCost(o1, 3);

    cout << "\nThe average cost is : " << obj3.getAveragePrice(o1, 3) << endl;

    cout << "\n obj2 is equal to obj3 " << obj2.isequal(obj3) << endl;

    Item obj4(16, "", 4, 4);
    cout<<"total cost is : "<<obj4.getTotalCost()<<endl;
    return 0;
}