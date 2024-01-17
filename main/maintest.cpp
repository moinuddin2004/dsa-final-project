#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <limits>
#include <cctype>

using namespace std;

// Node Structure
struct Node
{
    string foodname;
    int quantity;
    float price;
    int data;
    Node *next;
};

// Global Variables
Node *head = nullptr;
Node *list = nullptr;

// Function Declarations
void insertFirst(int data, string foodname, int quantity, float price);
void insertEnd(int data, string foodname, int quantity, float price);
void insertMid(int pos, int data, string foodname, int quantity, float price);
void updateFood(int udata, int uquantity);

/// Display Function
void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();

/// Delete & Count Function
void deletefood(int serial);
int countitem();

/// extra design Function
void cls();
void echo(const string &print);

void br(int line);
void pre(int tab);
void span(int space);
void ccolor(int clr);
void pwellcome();
void loadingbar();
void middle1();
void middtab1();
void backuploader();
void deletebar();

/////////////////////////////////////////////
int c = 0;
int any;
int cardno[100];
float cardmoney[100];
// float totalMoney = 0;
int total_order[100];
int order_quantity[100];
int order = 0;
int uquantity;
int citem;

// Function prototypes
void placeOrder();
void displayItemList();
void displayInstanOrderPreview();
void BackupSystem();
void ItemCounter();
void deleteItem();
void displayCardPayments();
void addBakeryItem();
void displayAdminPanelChoices();
void displayMainMenu();
void displayFoodList();
void displayAdminPanel();
void displayAdminPanelChoices();
void displayPaymentMenu();
void confirmOrder(int foodChoice);
void processPayment(int paymentOption, int foodChoice, int quantity);

// Global variables (for demonstration purposes)
float totalMoney = 0.0;
// int order = 0;
// int totalOrder[100];
// int orderQuantity[100];
// int c = 0; // Number of card transactions

int main()
{
    system("title Bakery Project Management System");
    system("mode con: cols=88 lines=30");

    // loadingbar();
    // cls();
    // pwellcome();
    // Sleep(300);
    // cls();

    head = NULL;
    insertFirst(5, "Birthday Cakes", 23, 120.23);
    insertEnd(6, "Pancakes    ", 13, 100.67);
    insertEnd(1, "Cookies", 8, 720.83);
    insertEnd(2, "Coffee  ", 46, 70.23);
    insertEnd(3, "Brownies   ", 46, 70.23);
    insertEnd(4, "Hot Pudding  ", 34, 60.23);
    insertEnd(7, "Chocolate Ice cream", 7, 520.29);
    insertEnd(8, "Grain Breads", 121, 35.13);
    insertEnd(9, "Cold drinks", 73, 20.13);
    displayMainMenu();
 
    return 0;
}

void displayMainMenu()
{
    br(1);
    main_menu();
    bool exitProgram = false;

    while (!exitProgram)
    {
        
        int mainMenuChoice;
        br(1);
        pre(4);
        cin >> mainMenuChoice;

        switch (mainMenuChoice)
        {
        case 1:
            displayFoodList();
            break;
        case 2:
            displayAdminPanel();
            break;
        case 3:
            cls();
            middle1();
            pre(3);
            cout << "Thank You For Using Our System. \n\t\t\tBrought To You By TEAM: 'Ctrl C+Ctrl V' with CHAT GPT 👀  \n\n\n\n\n\n\n";
            Sleep(1000);
            exitProgram = true; // Set the flag to exit the loop
            break;
        default:
            br(2);
            pre(4);
            cout << "Please Enter Correct Choice";
            Sleep(300);
        }
    }
}

void displayFoodList()
{
    cls();
    cout << "=> Bakery Item List ";
    foodlist();
    placeOrder();
}

void displayAdminPanel()
{
    cls();
    pre(4);
    cout << "1. Main Menu" << endl
         << endl
         << "\t";
    Sleep(300);
    // adminpanelchoice:
    cout << "Please Enter Password or (1 to Back in Main Menu): ";
    int adminPanelChoice;
    cin >> adminPanelChoice;

    if (adminPanelChoice == 1234567)
    {
        displayAdminPanelChoices();
    }
    else if (adminPanelChoice == 1)
    {
        displayMainMenu();
        // Go back to the main menu
    }
    else
    {
        br(2);
        pre(4);
        cout << "Please Enter Correct Choice";
        displayAdminPanelChoices();
    }
}

void displayAdminPanelChoices()
{
    cls();
    cout << ">>>> Admin Panel <<<<" << endl
         << endl;
    cout << " 1. Total Cash Today" << endl;
    cout << " 2. View Card Pay" << endl;
    cout << " 3. Add Bakery Item" << endl;
    cout << " 4. Delete Item" << endl;
    cout << " 5. Instant Item List" << endl;
    cout << " 6. Item Counter" << endl;
    cout << " 7. Backup System" << endl;
    cout << " 8. Instant Order Preview" << endl;
    cout << "Enter Your Choice from 1-0: ";
    Sleep(250);

    int adminChoice;
    cin >> adminChoice;

    switch (adminChoice)
    {
    case 0:
        displayMainMenu();
        break;
    case 1:
        cls();
        middle1();
        pre(4);
        cout << "Todays Total Cash : " << fixed << setprecision(2) << totalMoney << '\n';
        Sleep(2000);
        break;
    case 2:
        displayCardPayments();
        break;
    case 3:
        addBakeryItem();
        break;
    case 4:
        deleteItem();
        break;
    case 5:
        displayItemList();
        break;
    case 6:
        ItemCounter();
        break;
    case 7:
        BackupSystem();
        break;
    case 8:
        displayInstanOrderPreview();
        break;

    default:
        br(2);
        pre(4);
        cout << "Please Select From List :  ";
        Sleep(500);
    }
}

void displayCardPayments()
{
    if (c != 0)
    {
        cls();
        br(3);
        pre(4);
        cout << " ____________________________\n";
        pre(4);
        cout << "|   Card NO.   |   Money $   |\n";
        pre(4);
        cout << "------------------------------\n";
        pre(4);

        for (int z = 1; z <= c; z++)
        {
            cout << "|  " << cardno[z] << "  | " << fixed << setprecision(2) << cardmoney[z] << " |\n";
            pre(4);
            cout << "------------------------------\n";
            pre(4);
            Sleep(150);
        }
        Sleep(1500);
    }

    if (c == 0)
    {
        cls();
        middle1();
        pre(4);
        cout << "No Card History\n";
    }
    Sleep(1500);
    displayAdminPanelChoices();
}

void addBakeryItem()
{
foodadd:
    cls();

    string ffoodname;
    int fquantity;
    int fdata;
    float fprice;
    int fposi;

    br(3);
    pre(4);
    cout << " Enter Bakery Item Name :  ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, ffoodname);

fquantity:
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    br(2);
    pre(4);
    cout << " Enter Item Quantity :  ";
    cin >> fquantity;

foodserial:
    br(2);
    pre(4);
    cout << " Enter Item Serial :  ";
    cin >> fdata;

    Node *exist = list;
    while (exist->data != fdata)
    {
        if (exist->next == nullptr)
        {
            break;
        }
        exist = exist->next;
    }
    if (exist->data == fdata)
    {
        cls();
        br(5);
        pre(3);
        cout << " Bakery Item Serial Already Exist, Please Re-Enter  ";
        Sleep(2000);
        goto foodserial;
    }

fprice:
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    br(2);
    pre(4);
    cout << " Enter Item Price :  ";
    cin >> fprice;

    br(2);
    pre(4);
    cout << "Submitting your data";
    for (int cs = 0; cs < 4; cs++)
    {
        cout << " .";
        Sleep(500);
    }

    insertEnd(fdata, ffoodname, fquantity, fprice);

    br(2);
    pre(4);
    cout << "Adding Item  Successfull.......\n";

    Sleep(2000);
    displayAdminPanelChoices();
}

void deleteItem()
{

    cls();
    middle1();
    pre(2);
    // cout << "Enter Serial No of the Item To Delete : ";
fdelete:
    int fdelete;
    bool found = false;
    while (true)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Serial No of the Item To Delete : ";

        cin >> fdelete;

        Node *temp = list;
        Node *prev = nullptr;

        while (temp != nullptr)
        {
            if (temp->data == fdelete)
            {
                found = true;
                deletefood(fdelete);

                if (prev == nullptr)
                {
                    // If deleting the first node
                    list = temp->next;
                }
                else
                {
                    // If deleting a node other than the first one
                    prev->next = temp->next;
                }

                delete temp;
                cout << "Number " << fdelete << " deleted successfully." << endl;
                break;
            }

            prev = temp;
            temp = temp->next;
        }

        if (found)
        {
            break; // Exit loop if number found and deleted
        }
        else
        {
            cout << "Please enter a correct number." << endl;
        }
    }
    displayAdminPanelChoices();
}

void displayItemList()
{
    cls();
    foodlist();
    Sleep(1000);

    br(2);
    pre(4);
    cout << "1. <-- back  \n\n";
    pre(5);

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> any;
    displayAdminPanelChoices();
}

void ItemCounter()
{
    citem = countitem();
    cls();
    for (int cs = 1; cs <= citem; cs++)
    {
        middle1();
        pre(4);
        cout << "Item Counting " << cs;
        Sleep(150);
        cls();
    }
    cls();
    middle1();
    pre(4);
    cout << "Total Item Item is --> " << citem << "\n";
    Sleep(2000);
    displayAdminPanelChoices();
}
void BackupSystem()
{
    string date = __DATE__;
    date += ".txt";
    ofstream fptr(date);
    backuploader();

    if (!fptr)
    {
        br(3);
        pre(3);
        cout << "Error!";
        Sleep(500);
        displayAdminPanelChoices();
    }

    fptr << "Total Cash Today : " << fixed << setprecision(2) << totalMoney << "\n\n\n";
    fptr << "Card No ------- Money \n\n";

    for (int l = 1; l <= c; l++)
    {
        fptr << cardno[l] << " ------- " << fixed << setprecision(2) << cardmoney[l] << "\n";
    }

    br(2);
    pre(4);
    cout << "Backup Successful...";
    Sleep(1500);
    fptr.close();
    displayAdminPanelChoices();
}

void displayInstanOrderPreview()
{
    cls();
    br(2);
    pre(2);
    cout << "\n\t\t";
    cout << "______________________________________________________ \n\t\t";
    cout << "|  Order No.  |   Item Name   |  Quantity |  In Stock |\n\t\t";
    cout << "------------------------------------------------------\n\t\t";
    for (int o = 1; o <= order; o++)
    {
        order_view(total_order[o], order_quantity[o], o);
    }

    br(2);
    pre(4);
    cout << "1. <-- back  \n\n";
    pre(5);

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> any;
    displayAdminPanelChoices();
}

void placeOrder()
{
    int get_food_choice;

    br(2);
    pre(3);
    cin.ignore();
    cout << "Place Your Order: ";
    cin >> get_food_choice;

    if (get_food_choice == 0)
    {
        displayMainMenu();
    }

    Node *temp;

    temp = list;

    while (temp->data != get_food_choice)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            br(2);
            pre(4);
            echo("Please Choose From List: ");
            br(2);
            Sleep(1000);
            displayFoodList();
        }
    }

    if (get_food_choice == temp->data)
    {
    fcquantity:
        br(2);
        pre(4);
        cout << "Enter Item Quantity : ";

        int fcquantity;
        cin.ignore();
        cin >> fcquantity;

        cls();

        if (fcquantity == 0)
        {
            cls();
            middle1();
            pre(3);
            cout << "Quantity Cannot be Zero ";
            Sleep(2000);
            cls();
            displayFoodList();
        }
        else if (fcquantity > temp->quantity)
        {
            cls();
            middle1();
            pre(3);
            cout << "Out of Stock! ";
            Sleep(2000);
            displayFoodList();
        }

        middle1();
        pre(4);
        cout << "Chosen item " << temp->foodname << " costs " << fixed << setprecision(2) << temp->price * fcquantity << endl;
        pre(4);
        cout << "1. Confirm to buy this \n\n";
        pre(4);
        cout << "2. Item List \n\n";
        cout << "Press 1 to confirm and 2 to go back to the list: ";

    confirm:
        int confirm;
        cin.ignore();
        cin >> confirm;

        if (confirm == 1)
        {
            br(2);
            pre(4);
            cout << " 1. Cash ";
            br(2);
            pre(4);
            cout << " 2. Credit\n";
            cout << "Select Method Of payment 1-2: ";

         payment:
            int payment;
            cin.ignore();
            cin >> payment;

            if (payment == 1)
            {
                totalMoney += temp->price * fcquantity;
                order++;
                total_order[order] = get_food_choice;
                order_quantity[order] = fcquantity;
                uquantity = temp->quantity - fcquantity;

                updateFood(get_food_choice, uquantity);

                cls();
                middle1();
                pre(4);
                cout << "===>THANK YOU<===";
                br(2);
                pre(4);
                cout << "Item Ordered Successfully ...";
                br(2);
                pre(4);
                cout << "1. Wanna Buy Another Delicious ? ";
                br(2);
                pre(4);
                cout << "2. Main Menu \n";
                br(2);
                pre(4);
                cout << "Select: ";

                int ps_menu = 0;
                while (true)
                {
                    cin.ignore();
                    cin >> ps_menu;

                    if (ps_menu == 1)
                    {
                        displayFoodList();
                        break; // exit the loop after calling displayFoodList
                    }
                    else if (ps_menu == 2)
                    {
                        displayMainMenu();
                        break; // exit the loop after calling displayMainMenu
                    }
                    else
                    {
                        br(2);
                        pre(4);
                        cout << "Please Choose from the list : ";
                       
                    }
                }
            }
            /// Credit Card Option
            else if (payment == 2)
            {
                int card_number[100];
                c++;

                cls();
                middle1();
                pre(4);

                cout << "Enter Your Card No : ";
                cin.ignore();
                cin >> card_number[c];

                cardno[c] = card_number[c];

                int pin;

                br(2);
                pre(2);
                cout << "Enter Your Card Pin [we never save your pin]  : ";
                cin >> pin;

                cardmoney[c] = temp->price * fcquantity;
                totalMoney += temp->price * fcquantity;
                order++;
                total_order[order] = get_food_choice;
                order_quantity[order] = fcquantity;
                uquantity = temp->quantity - fcquantity;

                updateFood(get_food_choice, uquantity);

                br(2);
                pre(4);
                cout << "Payment Success...";
                br(2);
                pre(4);
                cout << "1. Wanna Buy Another Delicious ? ";
                br(2);
                pre(4);
                cout << "2. Main Menu \n";
                br(2);
                pre(4);
                cout << "Select: ";

                int ps_menu2 = 0;
                while (true)
                {
                    cin.ignore();
                    cin >> ps_menu2;

                    if (ps_menu2 == 1)
                    {
                        displayFoodList();
                        break; // exit the loop after calling displayFoodList
                    }
                    else if (ps_menu2 == 2)
                    {
                        displayMainMenu();
                        break; // exit the loop after calling displayMainMenu
                    }
                    else
                    {
                        br(2);
                        pre(4);
                        cout << "Please Choose from the list : ";
                        
                    }
                }
            }
            else
            {
                br(2);
                pre(4);
                cout << "Enter Choice from List : ";
                goto payment;
            }
        } /// END Confirm Y/y
        else if (confirm == 2)
        {
            displayFoodList();
        }
        else
        {
            br(2);
            pre(4);
            cout << "Enter Choice from List : ";
            goto confirm;
        } /// end confirm;
    }     /// end get food choice if line
    else
    {
        br(2);
        pre(4);
        echo("Please Choose From List ");
        br(2);
        Sleep(300);
       displayFoodList();
    } /// end get food choice
}

// Initialization and other code here...

// Function Definitions

void insertFirst(int data, string foodname, int quantity, float price)
{
    Node *temp = new Node;
    temp->data = data;
    temp->price = price;
    temp->quantity = quantity;
    temp->foodname = foodname;

    temp->next = head;
    head = temp;

    if (list == nullptr)
    {
        list = head;
    }
}

void insertEnd(int data, string foodname, int quantity, float price)
{
    Node *temp = new Node;
    temp->data = data;
    temp->price = price;
    temp->quantity = quantity;
    temp->foodname = foodname;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = temp;
        list = head;
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void insertmid(int pos, int data, string foodname, int quantity, float price)
{
    Node *temp = new Node;
    temp->data = data;
    temp->price = price;
    temp->quantity = quantity;
    temp->foodname = foodname;

    while (head->next->data != pos)
    {
        head = head->next;
    }

    temp->next = head->next;
    head->next = temp;
}

void deletefood(int serial)
{
    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr && temp->data != serial)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "\n\n\n\n\t\t\t" << temp->data << "Item Not Found\n";
        Sleep(500);
        return;
    }

    if (prev == nullptr)
    {
        head = temp->next;
    }
    else
    {

        prev->next = temp->next;
    }

    cout << "\n\n\n\n\t\t\tDeleting Item " << serial;
    deletebar();
    cout << "\n\n\n\n\t\t\tDeleted Successfully \n";
    Sleep(500);

    delete temp;
    cout << "Item deleted successfully." << endl;
}

void updateFood(int udata, int uquantity)
{
    Node *temp = list;
    while (temp->data != udata)
    {
        temp = temp->next;
    }
    if (temp->data == udata)
    {
        temp->quantity = uquantity;
    }
}

int countitem()
{
    Node *temp = list;
    int countitem = 0;
    if (temp == nullptr)
    {
        countitem = 0;
    }
    else
    {
        countitem = 1;
        while (temp->next != nullptr)
        {
            countitem++;
            temp = temp->next;
        }
    }
    return countitem;
}

void foodlist()
{
    ccolor(0);
    cout << "\n\t\t ______________________________________________________ ";
    ccolor(26);
    cout << "\n\t\t|  Item No.  |   Item Name   |  Price  |   In Stock   |";
    ccolor(26);
    cout << "\n\t\t-------------------------------------------------------";
    ccolor(26);

    Node *temp = list;
    while (temp != nullptr)
    {
        ccolor(26);
        cout << "\n\t\t|     " << temp->data << "      |    " << temp->foodname << "  |    " << fixed << setprecision(2) << temp->price << "   |    " << temp->quantity << "    |";
        ccolor(26);
        cout << "\n\t\t-------------------------------------------------------";
        temp = temp->next;
        Sleep(100);
    }
    ccolor(26);
}

void order_view(int order, int quantity, int or_no)
{
    ccolor(26);

    Node *temp = list;

    while (temp != nullptr && temp->data != order)
    {
        temp = temp->next;
    }

    if (temp != nullptr && temp->data == order)
    {
        ccolor(26);

        cout << "\n\t\t";
        ccolor(62);
        cout << "|     " << or_no << "      |    " << temp->foodname << "  |     " << quantity << "     |     " << temp->quantity << "     |";
        ccolor(26);
        cout << "\n\t\t";
        ccolor(62);
        cout << "-------------------------------------------------------";

        Sleep(100);
    }

    ccolor(26);
}

void main_menu()
{

    cls();
    br(5);
    pre(3);
    echo(">> 1. Bakery Item List");
    Sleep(400);
    br(2);
    pre(3);
    echo(">> 2. Admin Panel");
    Sleep(400);
    br(2);
    pre(3);
    echo(">> 3. Exit");
    Sleep(400);

    br(1);
}

void ccolor(int clr)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, clr);
}
void pwellcome()
{
    ccolor(26);

    string welcome = "WELCOME";
    string welcome2 = " TO";
    string welcome3 = " HAPPY BAKERY HOUSE";
    string welcome4 = " MANAGEMENT SYSTEM";
    string Members = "MEMBERS";
    string M1 = "MOIN UDDIN(LEADER)  ";
    string M2 = "ESHAN ANSARI ";
    string M3 = "RIZWAN HUSSAIN ";
    string M4 = "MUZAMMIL ";

    cout << "\n\n\n\n\n\t\t\t";
    for (char c : welcome)
    {
        cout << " " << c;
        Sleep(100);
    }
    ccolor(26);
    cout << "\n\n\t\t\t\t ";
    for (char c : welcome2)
    {
        cout << " " << c;
        Sleep(100);
    }
    ccolor(26);
    cout << "\n\n\n\t\t\t ";
    for (char c : welcome3)
    {
        if (c != 'D')
        {
            cout << " " << c;
        }
        else
        {
            cout << " " << c;
        }
        Sleep(100);
    }
    ccolor(26);
    cout << "\n\n\n\t\t\t\t ";
    for (char c : welcome4)
    {
        if (c != 'A' && c != 'E')
        {
            cout << " " << c;
        }
        else
        {
            cout << " " << c;
        }
        Sleep(100);
    }
    ccolor(26);
    cls();

    cout << "\n\n\n\n\n\t\t\t";
    for (char c : Members)
    {
        cout << " " << c;
        Sleep(100);
    }
    ccolor(26);
    cout << "\n\n\n\t\t\t\t ";
    for (char c : M1)
    {
        if (c != 'D')
        {
            cout << " " << c;
        }
        else
        {
            cout << " " << c;
        }
        Sleep(100);
    }
    ccolor(26);
    cout << "\n\n\n\t\t\t\t ";
    for (char c : M2)
    {
        if (c != 'D')
        {
            cout << " " << c;
        }
        else
        {
            cout << " " << c;
        }
        Sleep(100);
    }
    ccolor(26);
    cout << "\n\n\n\t\t\t\t ";
    for (char c : M3)
    {
        if (c != 'D')
        {
            cout << " " << c;
        }
        else
        {
            cout << " " << c;
        }
        Sleep(100);
    }
    ccolor(26);
    cout << "\n\n\n\t\t\t\t ";
    for (char c : M4)
    {
        if (c != 'D')
        {
            cout << " " << c;
        }
        else
        {
            cout << " " << c;
        }
        Sleep(100);
    }
    ccolor(26);
    cout << "\n\n\n\t\t\t\t ";
}

void loadingbar()
{
    for (int i = 15; i <= 100; i += 5)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\t\t\t\t" << i << " %% Loading...\n\n\t\t";
        for (int j = 0; j < i; j += 2)
        {
            ccolor(160 + j);
            cout << " ";
            ccolor(26);
        }
        Sleep(100);
        if (i == 90 || i == 50 || i == 96 || i == 83)
        {
            Sleep(100);
        }
    }
}
void deletebar()
{
    for (int i = 15; i <= 100; i += 5)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\t\t\t\t" << i << " %% Delete...\n\n\t\t";
        for (int j = 0; j < i; j += 2)
        {
            ccolor(160 + j);
            cout << " ";
            ccolor(26);
        }
        Sleep(100);
        if (i == 90 || i == 50 || i == 96 || i == 83)
        {
            Sleep(100);
        }
    }
}

void backuploader()
{
    for (int i = 15; i <= 100; i += 5)
    {
        system("cls");
        ccolor(26);
        cout << "\n\n\n\n\n\n\n\t\t\t\t" << i << " %% Backing UP DATA...\n\n\t\t";
        for (int j = 0; j < i; j += 2)
        {
            ccolor(120 + j);
            cout << " ";
            ccolor(26);
        }
        Sleep(50);
        if (i == 90 || i == 50 || i == 96 || i == 83)
        {
            Sleep(50);
        }
    }
}

void middle1()
{
    cout << "\n\n\n\n\n\n\n";
}

void middtab1()
{
    cout << "\t\t\t\t\t";
}

void cls()
{
    system("cls");
}

void echo(const string &print)
{
    cout << print << endl;
}

void br(int line)
{
    for (int i = 0; i < line; i++)
    {
        cout << "\n";
    }
}

void pre(int tab)
{

    for (int i = 0; i < tab; i++)
    {
        cout << "\t";
    }
}
void span(int space)
{

    for (int i = 0; i < space; i++)
    {
        cout << " ";
    }
}
