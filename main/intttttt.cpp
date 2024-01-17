int main()
{
    system("title Bakery Project Management System");
    system("mode con: cols=88 lines=30");

    loadingbar();
    cls();
    pwellcome();
    Sleep(300);
    cls();

    int c = 0;
    int any;
    int cardno[100];
    float cardmoney[100];
    float totalmoney = 0;
    int total_order[100];
    int order_quantity[100];
    int order = 0;
    int uquantity;
    int citem;

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

    while (true)
    {
    mainmenu:
        br(1);
        main_menu();

        int main_menu_choice;
        br(1);
        pre(4);
        cin >> main_menu_choice;
        if (main_menu_choice == 1)
        {
        foodlist:

            cls();
            cout << "=> Bakery Item List ";
            foodlist();
        }

        else if (main_menu_choice == 2)
        {
        adminpanelchoice:
            cls();
            pre(4);
            cout << "1. Main Menu" << endl
                 << endl
                 << "\t";
            Sleep(300);
            cout << "Please Enter Password or (1 to Back in Main Menu): ";
            int admin_panel_choice;
            cin >> admin_panel_choice;

            if (admin_panel_choice == 1234567)
            {
            adminchoise:

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
                // Simulate other options with delays
                cout << "Enter Your Choice from 1-0: ";
                Sleep(250);
                int admin_choice;
                cin >> admin_choice;

                if (admin_choice == 1)
                {
                    cls();
                    middle1();
                    pre(4);
                    cout << "Todays Total Cash : " << fixed << setprecision(2) << totalmoney << '\n';
                    Sleep(2000);
                    goto adminchoise;
                }
                else if (admin_choice == 2)
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
                    goto adminchoise;
                }
                else if (admin_choice == 3)
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

                    goto adminchoise;
                }
                else if (admin_choice == 4)
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

                    goto adminchoise;
                }
                else if (admin_choice == 5)
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

                    goto adminchoise;
                }
                else if (admin_choice == 6)
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
                    goto adminchoise;
                }
                // Backup System
                else if (admin_choice == 7)
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
                        goto adminchoise;
                    }

                    fptr << "Total Cash Today : " << fixed << setprecision(2) << totalmoney << "\n\n\n";
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
                    goto adminchoise;
                }
                else if (admin_choice == 8)
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

                    goto adminchoise;
                }
                else if (admin_choice == 0)
                {

                    goto mainmenu;
                }

                else
                {
                    br(2);
                    pre(4);
                    cout << "Please Select From List :  ";
                    Sleep(500);
                    goto adminchoise;
                }
            }
            else if (admin_panel_choice == 1)
            {
                goto mainmenu;
            }
            else
            {
                br(2);
                pre(4);
                cout << "Please Enter Correct Choice";
                goto adminpanelchoice;
            }
        }
        else if (main_menu_choice == 3)
        {
            cls();
            middle1();
            pre(3);
            cout << "Thank You For Using Our System. \n\t\t\tBrought To You By TEAM: 'Ctrl C+Ctrl V'  with CHAT GPT 👀  \n\n\n\n\n\n\n";
            Sleep(1000);
            exit(1);
        }
        else
        {
            br(2);
            pre(4);
            cout << "Please Enter Correct Choice";
            Sleep(300);
            goto mainmenu;
        }

        // Rest of your logic for ordering, payments, etc.
        // ...

        int get_food_choice;

        br(2);
        pre(3);
        cin.ignore();
        cout << "Place Your Order: ";
        cin >> get_food_choice;

        if (get_food_choice == 0)
        {
            goto mainmenu;
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
                echo("Please Choice From List: ");
                br(2);
                Sleep(1000);
                goto foodlist;
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
                cout << "Quantity Can not be Zero ";
                Sleep(2000);
                cls();
                goto foodlist;
            }
            else if (fcquantity > temp->quantity)
            {
                cls();
                middle1();
                pre(3);
                cout << "Out of Stock ! ";
                Sleep(2000);

                goto foodlist;
            }

            middle1();
            pre(4);
            cout << "Choice item " << temp->foodname << " its price is " << fixed << setprecision(2) << temp->price * fcquantity << endl;
            pre(4);
            cout << "1. Confirm to buy this \n\n";
            pre(4);
            cout << "2. Item List \n\n";
            cout << "Press 1 to confirm and 2 to back to list :";

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

                    totalmoney += temp->price * fcquantity;
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
                psmenu:
                    int ps_menu;
                    cin.ignore();
                    cin >> ps_menu;

                    if (ps_menu == 1)
                    {
                        goto foodlist;
                    }
                    else if (ps_menu == 2)
                    {
                        goto mainmenu;
                    }
                    else
                    {
                        br(2);
                        pre(4);
                        cout << "Please Choice from list : ";
                        goto psmenu;
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

                    totalmoney += temp->price * fcquantity;
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
                    cout << "select: ";
                psmenu2:
                    int ps_menu2;
                    cin >> ps_menu2;
                    if (ps_menu2 == 1)
                    {
                        goto foodlist;
                    }
                    else if (ps_menu2 == 2)
                    {
                        goto mainmenu;
                    }
                    else
                    {
                        br(2);
                        pre(4);
                        cout << "Please Choice from list : ";
                        goto psmenu2;
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

                goto foodlist;
            }

            else
            {
                br(2);
                pre(4);
                cout << "Enter Choice from List : ";

                goto confirm;

            } /// end confirm;

        } /// end get food choice if line

        else
        {

            br(2);
            pre(4);
            echo("Please Choose From List ");
            br(2);
            Sleep(300);

            goto foodlist;

        } /// end get food choice
    }
    return 0;
}
