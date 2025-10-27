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
    printf("\n\n==== USER MENU ====\n");
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
    printf("Bus no 111.Delhi to Mumbai\n");
    printf("Bus no 222.Delhi to Shimla\n");
    printf("Bus no 333.Delhi to Bihar\n");
    printf("\nPlease Enter the Bus number: ");
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
    int bus_capacity[3]={50,50,50};
    int book_tickets;
    int cancel_tickets;

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
                                if(bus_choise==111)
                                {
                                    printf("\nPlease Enter Number Of Tickets You Want to Book: ");
                                    scanf("%d",&book_tickets);
                                    bus_capacity[0]=bus_capacity[0]-book_tickets;
                                    printf("\nYour %d Tickets are Booked on Bus Number 111",book_tickets);
                                }
                                else if(bus_choise==222)
                                {
                                    printf("\nPlease Enter Number Of Tickets You Want to Book: ");
                                    scanf("%d",&book_tickets);
                                    bus_capacity[1]=bus_capacity[1]-book_tickets;
                                    printf("\nYour %d Tickets are Booked on Bus Number 222",book_tickets);
                                }
                                else if(bus_choise==333)
                                {
                                    printf("\nPlease Enter Number Of Tickets You Want to Book: ");
                                    scanf("%d",&book_tickets);
                                    bus_capacity[2]=bus_capacity[2]-book_tickets;
                                    printf("\nYour %d Tickets are Booked on Bus Number 333",book_tickets);
                                }
                                else
                                {
                                    printf("It is an Invalid Bus Number");
                                }
                             
                            }
                            else if (user_menu_choise == 2)
                            {
                                bus_choise = Bus_choise(bus_choise);
                                if(bus_choise==111)
                                {
                                    if(bus_capacity[0]<50)
                                    {
                                    printf("\nPlease Enter Number Of Tickets You Want to Cancel: ");
                                    scanf("%d",&cancel_tickets);
                                    bus_capacity[0]=bus_capacity[0]+cancel_tickets;
                                    printf("\nYour %d Tickets are Cancelled on Bus Number 111",cancel_tickets);
                                    }
                                    else
                                    {
                                        printf("You dont have any tickets to cancel");
                                    }
                                }
                                else if(bus_choise==222)
                                {
                                    if(bus_capacity[1]<50)
                                    {
                                    printf("\nPlease Enter Number Of Tickets You Want to Cancel: ");
                                    scanf("%d",&cancel_tickets);
                                    bus_capacity[1]=bus_capacity[1]+cancel_tickets;
                                    printf("\nYour %d Tickets are Cancelled on Bus Number 222",cancel_tickets);
                                    }
                                    else
                                    {
                                        printf("You dont have any tickets to cancel");
                                    }
                                }
                                else if(bus_choise==333)
                                {
                                    if(bus_capacity[2]<50)
                                    {
                                    printf("\nPlease Enter Number Of Tickets You Want to Cancel: ");
                                    scanf("%d",&cancel_tickets);
                                    bus_capacity[2]=bus_capacity[2]+cancel_tickets;
                                    printf("\nYour %d Tickets are Cancelled on Bus Number 333",cancel_tickets);
                                    }
                                    else
                                    {
                                        printf("You dont have any tickets to cancel");
                                    }
                                }
                                else
                                {
                                    printf("It is an Invalid Bus Number");
                                }

                            }
                            else if (user_menu_choise == 3)
                            {
                                bus_choise = Bus_choise(bus_choise);
                                if(bus_choise==111)
                                {
                                    printf("Status of bus Delhi to Mumbai\n");
                                    printf("Total capacity: 50\n");
                                    printf("Available Seats :%d\n",bus_capacity[0]);
                                }
                                else if(bus_choise==222)
                                {
                                    printf("Status of bus Delhi to Shimla\n");
                                    printf("Total capacity: 50\n");
                                    printf("Available Seats :%d\n",bus_capacity[1]);
                                }
                                else if(bus_choise==333)
                                {
                                    printf("Status of bus Delhi to Bihar\n");
                                    printf("Total capacity: 50\n");
                                    printf("Available Seats :%d\n",bus_capacity[2]);
                                }
                                else
                                {
                                    printf("It is an Invalid Bus Number");
                                }

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