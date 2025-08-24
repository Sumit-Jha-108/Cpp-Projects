/*
Original Author : Sumit Kashyap
Demonstrates    : Single Resposibility Principle
Explaination    : A class should have only one reason to change.
*/

#include<iostream>
using namespace std;

// comment this part to execute without single responsibility
#define WithSingleRes

#ifndef WithSingleRes

class Marker {
    private:
        string name;
        string colour;
        int price;
    public:
        Marker(string name = "Good" , string colour = "black" , int price = 100)
        {
            this->name = name;
            this->colour = colour;
            this->price = price;
        }
        int getPrice()
        {
            return price;
        }
        string getName()
        {
            return name;
        }
        string getColour()
        {
            return colour;
        }
};
class Invoice {
    private:
        Marker marker;
        int quantity;
    public:
        Invoice(Marker marker , int quantity)
        {
            this->marker = marker;
            this->quantity = quantity;
        }
        int calculateTotal()
        {
            return (marker.getPrice() * quantity);
        }
        void printInvoice()
        {
            cout<<"MarkerName   : "<<marker.getName()<<endl;
            cout<<"MarkerColour : "<<marker.getColour()<<endl;
            cout<<"Price        : "<<calculateTotal()<<endl;
            cout<<endl;
        }
        void saveToDB()
        {
            cout<<marker.getName()<<" is Saved to DB\n";
        }
};

int main()
{
    cout<<"----Without Single Responsibility Principle Starts---\n\n";
    Marker m("Camlin" , "Red" , 200);
    Invoice in(m,10);
    in.printInvoice();
    in.saveToDB();
    cout<<"\n----Without Single Responsibility Principle ends---\n";
    return 0;
}

#else

class Marker {
    private:
        string name;
        string colour;
        int price;
    public:
        Marker(string name = "Good" , string colour = "black" , int price = 100)
        {
            this->name = name;
            this->colour = colour;
            this->price = price;
        }
        int getPrice()
        {
            return price;
        }
        string getName()
        {
            return name;
        }
        string getColour()
        {
            return colour;
        }
};
class Invoice {
    private:
        Marker marker;
        int quantity;
    public:
        Invoice(){}
        Invoice(Marker marker , int quantity)
        {
            this->marker = marker;
            this->quantity = quantity;
        }
        int calculateTotal()
        {
            return (marker.getPrice() * quantity);
        }
        Marker getMarker()
        {
            return marker;
        }
};
class InvoicePrinter {
    private:
        Invoice invoice;
    public:
        InvoicePrinter(Invoice invoice)
        {
            this->invoice = invoice;
        }
        void printInvoice()
        {
            cout<<"MarkerName   : "<<invoice.getMarker().getName()<<endl;
            cout<<"MarkerColour : "<<invoice.getMarker().getColour()<<endl;
            cout<<"Price        : "<<invoice.calculateTotal()<<endl;
            cout<<endl;
        }
};
class InvoiceDAO {
    private:
        Invoice invoice;
    public:
        InvoiceDAO(Invoice invoice)
        {
            this->invoice = invoice;
        }
        void saveToDB()
        {
            cout<<invoice.getMarker().getName()<<" is Saved to DB\n";
        }
};

int main()
{
    cout<<"----With Single Responsibility Principle Starts---\n\n";
    Marker m("Luxor" , "Black" , 300);
    Invoice in(m,15);
    InvoicePrinter ip(in);
    InvoiceDAO id(in);
    ip.printInvoice();
    id.saveToDB();
    cout<<"\n----With Single Responsibility Principle ends---\n";
    return 0;
}

#endif