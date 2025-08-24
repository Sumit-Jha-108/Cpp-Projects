/*
Original Author : Sumit Kashyap
Demonstrates    : Open-Closed Principle
Explaination    : A class should be open to extensions but closed for modifications.
*/

#include<iostream>
using namespace std;

// comment this part to execute without open-closed
#define WithOpenClosed

#ifndef WithOpenClosed

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
    cout<<"----Without OpenClosed Principle Starts---\n\n";
    Marker m("Luxor" , "Black" , 300);
    Invoice in(m,15);
    InvoicePrinter ip(in);
    InvoiceDAO id(in);
    ip.printInvoice();
    id.saveToDB();
    cout<<"\n----Without OpenClosed Principle ends---\n";
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

// Interface
class InvoiceDAO {
    public:
        virtual void save(Invoice invoice) = 0;
};
class DatabaseInvoiceDAO : public InvoiceDAO {
    public:
        // DatabaseInvoiceDAO();
        void save(Invoice invoice)
        {
            cout<<invoice.getMarker().getName()<<" is Saved to DB\n";
        }
};
class FileInvoiceDAO : public InvoiceDAO {
    public:
        void save(Invoice invoice)
        {
            cout<<invoice.getMarker().getName()<<" is Saved to File\n";
        }
};

int main()
{
    cout<<"----With OpenClosed Principle Starts---\n\n";
    Marker m("Luxor" , "Black" , 300);
    Invoice in(m,15);
    InvoicePrinter ip(in);
    DatabaseInvoiceDAO di;
    FileInvoiceDAO fi;
    ip.printInvoice();
    di.save(in);
    fi.save(in);
    cout<<"\n----With OpenClosed Principle ends---\n";
    return 0;
}
#endif