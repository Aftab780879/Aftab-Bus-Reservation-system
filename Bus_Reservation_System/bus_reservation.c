#include <stdio.h>
#include <string.h>

int Login_Menu(int login_choise)
{
    printf("\n1. User Registration\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Please Enter Your Choise: ");
    scanf("%d", &login_choise);
    return login_choise;
}

int User_Menu(int user_menu_choise)
{
    printf("\n==== USER MENU ====\n");
    printf("1.Book a Ticket\n");
    printf("2.Cancel a Ticket\n");
    printf("3.Check Bus Status\n");
    printf("4.Logout\n");
    printf("Please enter Your Choise: ");
    scanf("%d", &user_menu_choise);
    return user_menu_choise;
}

int Bus_choise(int bus_choise)
{
    printf("\n=====  Bus Option With Routes  =====\n");
    printf("1.Delhi to Mumbai(101)\n");
    printf("2.Delhi to Shimla(201)\n");
    printf("3.Delhi to Bihar(301)\n");
    printf("4.Delhi to Jodhpur(401)\n");
    printf("5.Delhi to Ranchi(501)\n");
    printf("6.Delhi to Aligarh(601)\n");
    printf("Please Select Where you want To Go: ");
    scanf("%d", &bus_choise);
    return bus_choise;
}

int main()
{
    char full_name[20][50];
    int phone_number[20];
    char password[20][10];
    char password_confirm[20][10];
    int login_choise;
    int full_name_count = 0;
    int phone_input;
    char password_input[1][10];
    int login_match = 0;
    int user_menu_choise;
    int number_found = 0;
    int bus_choise;

    printf("@@@****  BUS RESERVATION  ****@@@\n\n");
    while (1)
    {
        login_choise = Login_Menu(login_choise);

        if (login_choise == 1)
        {
            printf("Please Enter Your Full Name: ");
            scanf(" %[^\n]", &full_name[full_name_count]);
            printf("Please Enter Your Phone Number: ");
            scanf("%d", &phone_number[full_name_count]);
            printf("Please Enter a Password Within 10 Elements: ");
            scanf(" %[^\n]", &password[full_name_count]);
            printf("Please Re-Enter Your Password: ");
            scanf(" %[^\n]", &password_confirm[full_name_count]);
            if (strcmp(password[full_name_count], password_confirm[full_name_count]) == 0)
            {
                printf("\nYour Registration is Successfull\n");
            }
            else
            {
                printf("Password do not match! - Please Re-Enter your password again: ");
                scanf(" %[^\n]", &password_confirm[full_name_count]);
                if (strcmp(password[full_name_count], password_confirm[full_name_count]) == 0)
                {
                    printf("\nYour Registration is Successfull\n");
                }
                else
                {
                    printf("Password Still do not match registration failed !");
                }
            }
            full_name_count++;
        }

        else if (login_choise == 2)
        {
            printf("PLease Enter The Registered Phone Number: ");
            scanf("%d", &phone_input);
            for (int i = 0; i < 20; i++)
            {
                if (phone_input == phone_number[i])
                {
                    number_found++;
                    login_match = i;
                    printf("Please Enter Your Password: ");
                    scanf(" %[^\n]", &password_input[1]);
                    if (strcmp(password_input[1], password[login_match]) == 0)
                    {
                        printf("\nLogin Successful. Welcome  %s\n", full_name[login_match]);
                        while (1)
                        {
                            user_menu_choise = User_Menu(user_menu_choise);
                            if (user_menu_choise == 1)
                            {
                                bus_choise = Bus_choise(bus_choise);
                            }
                            else if (user_menu_choise == 2)
                            {

                            }
                            else if (user_menu_choise == 3)
                            {
                                
                            }
                            else if (user_menu_choise == 4)
                            {
                                printf("Logout Successful .\n");
                                break;
                            }
                            else
                            {
                                printf("Invalid Input . Please Try Again");
                            }
                        }
                    }
                    else
                    {
                        printf("Wrong Password! - Please Login Again");
                    }
                }
                else if (number_found == 0)
                {
                    printf("\nNumber not registered . Please Register or Login Again");
                    break;
                }
            }
        }
        else if (login_choise == 3)
        {
            break;
        }
        else
        {
            printf("INVALID INPUT");
        }
    }
    return 0;
}