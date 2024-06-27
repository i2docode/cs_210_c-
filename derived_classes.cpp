#include <iostream>
#include <string>
using namespace std;

/*
Derived class concept

Commonly, one class is similar to another class but with some additions or variations. 

Ex: A store inventory system might use a class called GenericItem that has itemName and itemQuantity data members.

But for produce (fruits and vegetables), a ProduceItem class with data members itemName, itemQuantity, and expirationDate may be desired.


Inheritance
A derived class (or subclass) is a class that is derived from another class, called a base class (or superclass).

Any class may serve as a base class. 

The derived class is said to inherit the properties of the base class, a concept called inheritance. 

An object declared of a derived class type has access to all the public members of the derived class as well as the public members of the base class.

A derived class is declared by placing a colon ":" after the derived class name, followed by a member access specifier like public and a base class name. 

Ex: class DerivedClass: public BaseClass { ... };. The figure below defines the base class GenericItem and derived class ProduceItem that inherits from GenericItem.



*/

// Base class

//2 data members + 3 member functions = 5 class members.
class GenericItem {
   public:
      void SetName(string newName) { 
          itemName = newName; 
      }
   
      void SetQuantity(int newQty) {
          itemQuantity = newQty; 
      }
   
      void PrintItem() {
          cout << itemName << " " << itemQuantity << endl;
      }
   
   private:
      string itemName;
      int itemQuantity;
};

// Derived class inherits from GenericItem 
class ProduceItem : public GenericItem {

   public:

      void SetExpiration(string newDate) { 
          expirationDate = newDate; 
      }
   
      string GetExpiration() { 
          return expirationDate; 
      }
   
   private:
      string expirationDate;
};

int main(){
    cout << "test" << endl;

   GenericItem miscItem;
   ProduceItem perishItem;
   
   miscItem.SetName("Crunchy Cereal");
   miscItem.SetQuantity(9);
   miscItem.PrintItem();
   
   perishItem.SetName("Apples");
   perishItem.SetQuantity(40);
   perishItem.SetExpiration("Dec 5, 2019");
   perishItem.PrintItem();
   cout << "  (Expires: " << perishItem.GetExpiration()
        << ")" << endl;
   
   return 0;


   /*
    Inheritance scenarios

    Various inheritance variations are possible:

    A derived class can serve as a base class for another class. Ex: class FruitItem: public ProduceItem {...} creates a derived class FruitItem from ProduceItem, which was derived from GenericItem.

    A class can serve as a base class for multiple derived classes. Ex: class FrozenFoodItem: public GenericItem {...} creates a derived class FrozenFoodItem that inherits from GenericItem, just as ProduceItem inherits from GenericItem.

    A class may be derived from multiple classes. Ex: class House: public Dwelling, public Property {...} creates a derived class House that inherits from base classes Dwelling and Property.

    
   
   
   */
}