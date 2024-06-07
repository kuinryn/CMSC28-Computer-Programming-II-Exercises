#include "ProductInventory.h" //include the header file containing class declarations
#include <iostream>
using namespace std;

int main() {
    // Variables to store user input
    string name, brand, description, category, size, color, material, model, warranty, technicalSpecifications;
    double price;
    int quantity;

    // Loop to add multiple products
    while (true) {
        cout << "Enter product name: "; //prompt the user to enter the product name
        getline(cin, name); //read the product name
        cout << "Enter brand: "; //prompt the user to enter the brand
        getline(cin, brand); //read the brand
        cout << "Enter price: "; //prompt the user to enter the price
        cin >> price; //read the price
        cout << "Enter quantity: "; //prompt the user to enter the quantity
        cin >> quantity; //read the quantity
        cout << "Enter description: "; //prompt the user to enter the description
        cin.ignore(); //ignore the left over newline character
        getline(cin, description);//read the description
        cout << "Enter category (Clothing or Electronics): "; //prompt the user to enter the category
        getline(cin, category); //read the category

        // Validate category input
        if (category == "Clothing" || category == "clothing") { //check if the category is clothing
            cout << "Enter size: "; //promt the user to enter size
            getline(cin, size); //read the size
            cout << "Enter color: "; //prompt the user to enter the color
            getline(cin, color); //read the color
            cout << "Enter material: "; //prompt the user to enter the material
            getline(cin, material); //read the material

            // Create instance of Clothing
            Clothing clothingItem(name, brand, price, quantity, description, size, color, material);

            // Print details of the Clothing item
            cout << "\nClothing Details:\n";
            clothingItem.printDetails(); //call the printDetails function of Clothing
        } else if (category == "Electronics" || category == "electronics") { //check if the category is Electronics
            cout << "Enter model: "; //prompt the user to enter the model
            getline(cin, model); //read the model
            cout << "Enter warranty: "; //promt the user to enter the warranty
            getline(cin, warranty); //read the warranty
            cout << "Enter technical specifications: "; //prompt the user to enter the technical specifications
            getline(cin, technicalSpecifications); //read the technical specifications

            // Create instance of Electronics
            Electronics electronicsItem(name, brand, price, quantity, description, model, warranty, technicalSpecifications);

            // Print details of the Electronics item
            cout << "\nElectronics Details:\n";
            electronicsItem.printDetails(); //call the printDetails function of Electronics
        } else {
            cout << "Invalid category! Please enter Clothing or Electronics." << endl; //display error message if user input neither required ot he clothing or electronics
        }

        cout << "\nWould you like to add another product? (yes/no): "; //prompt the user if they want to add another product
        string choice;
        cin >> choice; //read the choice
        if (choice != "yes") { //if choice is not "yes", exit the loop
            break;
        }

        cin.ignore(); //ignore newline character for getline after cin
        cout << "\n";
    }

    return 0;
}
