#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for setting width in output

using namespace std;

// Structure to represent an item in the retail shop
struct Item
{
    int id;
    string name;
    float price;
    int quantity;
};

// Function to add a new item to the shop's inventory
void addItem(vector<Item> &inventory)
{
    Item newItem;
    cout << "Enter item ID: ";
    cin >> newItem.id;
    cin.ignore();
    cout << "Enter item name: ";
    getline(cin, newItem.name);
    cout << "Enter item price: ";
    cin >> newItem.price;
    cout << "Enter item quantity: ";
    cin >> newItem.quantity;

    inventory.push_back(newItem);
    cout << "Item added successfully!" << endl;
}

// Function to display all items in the inventory
void displayItems(const vector<Item> &inventory)
{
    if (inventory.empty())
    {
        cout << "No items in the inventory." << endl;
        return;
    }

    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Quantity" << endl;
    cout << "-------------------------------------------------" << endl;

    for (const auto &item : inventory)
    {
        cout << left << setw(10) << item.id
             << setw(20) << item.name
             << setw(10) << item.price
             << setw(10) << item.quantity << endl;
    }
}

// Function to update an item's details by its ID
void updateItem(vector<Item> &inventory)
{
    int id;
    cout << "Enter item ID to update: ";
    cin >> id;

    for (auto &item : inventory)
    {
        if (item.id == id)
        {
            cout << "Enter new price: ";
            cin >> item.price;
            cout << "Enter new quantity: ";
            cin >> item.quantity;
            cout << "Item updated successfully!" << endl;
            return;
        }
    }

    cout << "Item with ID " << id << " not found." << endl;
}

// Function to remove an item from inventory by ID
void removeItem(vector<Item> &inventory)
{
    int id;
    cout << "Enter item ID to remove: ";
    cin >> id;

    for (auto it = inventory.begin(); it != inventory.end(); ++it)
    {
        if (it->id == id)
        {
            inventory.erase(it);
            cout << "Item removed successfully!" << endl;
            return;
        }
    }

    cout << "Item with ID " << id << " not found." << endl;
}

// Main menu for retail shop management
void menu()
{
    cout << "Retail Shop Management System" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Display Items" << endl;
    cout << "3. Update Item" << endl;
    cout << "4. Remove Item" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    vector<Item> inventory;
    int choice;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            addItem(inventory);
            break;
        case 2:
            displayItems(inventory);
            break;
        case 3:
            updateItem(inventory);
            break;
        case 4:
            removeItem(inventory);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
