#include <string>
#include <iostream>
using namespace std;

class Product {
protected:
    string name;
    string brand;
    double price;
    int quantity;
    string description;

public:
    // Constructor
    Product(const string& name, const string& brand, double price, int quantity, const string& description);

    // Set methods
    void setName(const string& name);
    void setBrand(const string& brand);
    void setPrice(double price);
    void setQuantity(int quantity);
    void setDescription(const string& description);

    // Get methods
    string getName() const;
    string getBrand() const;
    double getPrice() const;
    int getQuantity() const;
    string getDescription() const;

    // Print details (virtual to allow overriding in derived classes)
    virtual void printDetails() const;
};

class Clothing : public Product {
private:
    string size;
    string color;
    string material;

public:
    // Constructor
    Clothing(const string& name, const string& brand, double price, int quantity, const string& description, const string& size, const string& color, const string& material);

    // Set methods
    void setSize(const string& size);
    void setColor(const string& color);
    void setMaterial(const string& material);

    // Get methods
    string getSize() const;
    string getColor() const;
    string getMaterial() const;

    // Print details
    void printDetails() const override;
};

class Electronics : public Product {
private:
    string model;
    string warranty;
    string technicalSpecifications;

public:
    // Constructor
    Electronics(const string& name, const string& brand, double price, int quantity, const string& description, const string& model, const string& warranty, const string& technicalSpecifications);

    // Set methods
    void setModel(const string& model);
    void setWarranty(const string& warranty);
    void setTechnicalSpecifications(const string& technicalSpecifications);

    // Get methods
    string getModel() const;
    string getWarranty() const;
    string getTechnicalSpecifications() const;

    // Print details
    void printDetails() const override;
};

// Implementation of Product class methods
Product::Product(const string& name, const string& brand, double price, int quantity, const string& description)
    : name(name), brand(brand), price(price), quantity(quantity), description(description) {}

void Product::setName(const string& name) { this->name = name; }
void Product::setBrand(const string& brand) { this->brand = brand; }
void Product::setPrice(double price) { this->price = price; }
void Product::setQuantity(int quantity) { this->quantity = quantity; }
void Product::setDescription(const string& description) { this->description = description; }

string Product::getName() const { return name; }
string Product::getBrand() const { return brand; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }
string Product::getDescription() const { return description; }

void Product::printDetails() const {
    cout << "Name: " << name << "\nBrand: " << brand << "\nPrice: " << price << "\nQuantity: " << quantity
         << "\nDescription: " << description << endl;
}

// Implementation of Clothing class methods
Clothing::Clothing(const string& name, const string& brand, double price, int quantity, const string& description, const string& size, const string& color, const string& material)
    : Product(name, brand, price, quantity, description), size(size), color(color), material(material) {}

void Clothing::setSize(const string& size) { this->size = size; }
void Clothing::setColor(const string& color) { this->color = color; }
void Clothing::setMaterial(const string& material) { this->material = material; }

string Clothing::getSize() const { return size; }
string Clothing::getColor() const { return color; }
string Clothing::getMaterial() const { return material; }

void Clothing::printDetails() const {
    Product::printDetails();
    cout << "Size: " << size << "\nColor: " << color << "\nMaterial: " << material << endl;
}

// Implementation of Electronics class methods
Electronics::Electronics(const string& name, const string& brand, double price, int quantity, const string& description, const string& model, const string& warranty, const string& technicalSpecifications)
    : Product(name, brand, price, quantity, description), model(model), warranty(warranty), technicalSpecifications(technicalSpecifications) {}

void Electronics::setModel(const string& model) { this->model = model; }
void Electronics::setWarranty(const string& warranty) { this->warranty = warranty; }
void Electronics::setTechnicalSpecifications(const string& technicalSpecifications) { this->technicalSpecifications = technicalSpecifications; }

string Electronics::getModel() const { return model; }
string Electronics::getWarranty() const { return warranty; }
string Electronics::getTechnicalSpecifications() const { return technicalSpecifications; }

void Electronics::printDetails() const {
    Product::printDetails();
    cout << "Model: " << model << "\nWarranty: " << warranty << "\nTechnical Specifications: " << technicalSpecifications << endl;
}
