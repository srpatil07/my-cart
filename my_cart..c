//simple shopping cart
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//cart items,quantity and amount(per quantity) declaration
float data[10][3]={{1000,50,50},{1001,60,36.5},{1002,100,23.5},{1003,25,10},{1004,75,13.5},{1005,50,7},{1006,60,23},{1007,50,9},{1008,50,11},{1009,50,7.5}};

typedef struct //putting data into cart structure
{
    int code;
    int quntity;
    float amount;
}cart;
cart all_items[10];//initialization of array of all items in cart

typedef struct//structure declaration for login details
{
    char first_name[20];
    char last_name[20];
    long long int mobile_no;

}login;
login customer;//initialization of customer

typedef struct//structure declaration for my cart
{
    int item_code;
    int quantity;
    float amount;
}my_cart;
my_cart item[20];//initialization of array of my items

void login_details()//getting user details
{
    int n,i;
    long long int a;
    printf("Enter your first name : ");
    scanf(" %s",customer.first_name);
    printf("Enter your last name : ");
    scanf(" %s",customer.last_name);
    do  //checking 10 digit valid mobile number
    {
        n=0;
        printf("Enter your mobile : ");
        scanf(" %lld",&customer.mobile_no);
        a=customer.mobile_no;
        while(a >0)
        {
            n++;
            a = a/10;
        }
        if(n !=10) printf("Invalid number\n");
    }while(n!=10);
}

void all_item()//putting data into cart structure
{
    int i;
    for(i=0;i<10;i++)
    {
       all_items[i].code=data[i][0];
       all_items[i].quntity=data[i][1];
       all_items[i].amount=data[i][2];
    }
    return 0;
}
void display_available_items()//display available items in cart
{
    int i;
    printf("--------***** AVAILABLE ITEMS *****------------\n\n");
    printf("item_code\tAvailable_quantity\tRate\n");
    for(i=0;i<10;i++) printf("  %-20d %-16d %-20.2f\n",all_items[i].code,all_items[i].quntity,all_items[i].amount);
    return 0;
}

int add_item(int sl) //selection of item from cart and add to my cart
{
    int i,b,c,j,d;
    if(sl==0) //condition for my cart is empty
    {
    printf("Enter item code : ");
    scanf("%d",&d);
    for(i=0;i<10;i++)
    {
        if(d == all_items[i].code) // checking selected item code availability  in main cart
        {
           item[sl].item_code=d;
           printf("Enter item quntity : ");
           scanf("%d",&item[sl].quantity);
           // checking selected item quntity availability  in main cart
           if(item[sl].quantity ==all_items[i].quntity )
           {
               all_items[i].quntity=0;
               item[sl].amount=all_items[i].amount *item[sl].quantity;
           }
           else if(item[sl].quantity < all_items[i].quntity )
           {
               all_items[i].quntity=all_items[i].quntity-item[sl].quantity;
               item[sl].amount=all_items[i].amount *item[sl].quantity;
           }
           else printf("Quantity not exist....!");
           return 0;
        }
        else printf("Invalid item code\n");
        return 1;
    }

    }
    else //one or more items is their in my cart
    {
       printf("Enter item code : ");
       scanf("%d",&b);
       printf("Enter item quntity : ");
       scanf("%d",&c);

       //checking item code already exist in my
       for(i=0;i<10;i++)
       {
           if(b==all_items[i].code)   // checking selected item code availability  in main cart
           {
              for(j=0;j<sl;j++)
              {
                  if(b==item[j].item_code)  // checking selected item code availability  in my cart
                    {
                    // checking selected item quntity availability  in main cart and my cart
                        if(c==all_items[i].quntity)
                        {
                          item[j].quantity = item[j].quantity +c;// items added to my cart
                          item[j].amount=all_items[i].amount *item[j].quantity; // calculating total amount
                          all_items[i].quntity=0;//subtract items from main cart
                          return 1;
                        }
                       else if(c < all_items[i].quntity)
                       {
                           item[j].quantity = item[j].quantity +c;// items added to my cart
                           item[j].amount=all_items[i].amount *item[j].quantity;// calculating total amount
                           all_items[i].quntity=all_items[i].quntity-c;//subtract items from main cart
                           return 1;
                       }
                       else printf("Quantity not available ");//when we enter more than available
                       return 1;
                    }
              }
           }

       }
       //if item code does not exist in my cart
       for(i=0;i<10;i++)
       {
          if(b==all_items[i].code)  // checking selected item code availability  in main cart
          {
           // checking selected item quantity availability  in main cart and my cart
              if(c==all_items[i].quntity)
                        {
                          item[sl].item_code=b;    //upend item code to my cart
                          item[sl].quantity = c;   // items added to my cart
                          item[sl].amount=all_items[i].amount *item[sl].quantity;   // calculating total amount
                          all_items[i].quntity=0;  //subtract items from main cart
                          return 0;
                        }
                       else if(c < all_items[i].quntity)
                       {
                           item[sl].item_code=b;  //upend item code to my cart
                           item[sl].quantity = c;  // items added to my cart
                           item[sl].amount=all_items[i].amount *item[sl].quantity; // calculating total amount
                           all_items[i].quntity=all_items[i].quntity-c;  //subtract items from main cart
                           return 0;
                       }
                       else printf("Quantity not available "); //when we enter more than available
                       return 0;
          }
       }
    }
}
int delete_item(int sl) //for deleting items from my cart
{
   int i,a,b,j,k;
   if(sl==0)   //condition for my cart is empty
   {
       printf("No items in your cart.....!");
       return 0;
   }
   else
   {
     printf("Enter item code (for deleting) : ");
     scanf("%d",&a);
     for(k=0;k<10;k++)
     {
         if(a==all_items[k].code)
         {
             for(i=0;i<sl;i++)
             {
             // checking selected item code availability  in my cart
                if(a== item[i].item_code)
                {
                     printf("Enter number of quantity for deleting : ");
                     scanf("%d",&b);
                     // checking selected item quantity availability  in my cart
                     if(b==item[i].quantity)  //deleting entire row
                     {
                      for(j=i;j<sl;j++)
                      {
                         item[j].item_code=item[j+1].item_code;
                         item[j].quantity=item[j-1].quantity;
                      }
                      all_items[k].quntity=all_items[k].quntity+b;
                      return sl--;
                      }
                      else if(b < item[i].quantity)//deleting expected quantinty from our cart and add to main cart
                      {
                         item[i].quantity=item[i].quantity-b;
                         all_items[k].quntity=all_items[k].quntity+b;
                         return sl;
                      }
                     else //if quantity more tan available
                    {
                      printf("WRONG...quantity");
                      return sl;
                    }
                }
             }
         }
      }
   }
}

void show_my_items(int sl) // display of my cart
{
     int i;
     printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
     printf("sl  item_code  quantity\n");
     for(i=0;i<sl;i++)
     {
         printf("%-5d %-10d %-10d ",i+1,item[i].item_code,item[i].quantity);
         printf("\n");
     }
     return 0;
}

void bill(int sl) //final bill display
{
    int i,j;
    float total=0;
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\n\n******************** BILL *********************");
    printf("\nCustomer Name : %s %s\n    Mobile No : %lld ",customer.first_name,customer.last_name,customer.mobile_no);
    printf("\n_______________________________________________");
    printf("\nSl      Item_code      Quantity      Amount\n");
    for(i=0;i<sl;i++)
    {
         printf("%-7d %-14d %-13d %-10.2f",i+1,item[i].item_code,item[i].quantity,item[i].amount);
         printf("\n");
         total =total+item[i].amount;// total amount calculation
    }
    for(j=i;j<10;j++) printf("\n");
    printf("\n_______________________________________________");
    printf("\n                              total= %.2f",total);
    printf("\n_______________________________________________\n\n");
}

void main()
{
    int choice;
    int item_sl=0,a;

    printf("\t     WELCOME TO SHOPING CART \n");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd LOGIN DETAILS \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    login_details(); // getting login details
    printf("\n\n\n");
    all_item();  // putting all main cart data into cart structure
    display_available_items();//display the available items and quantity in main cart
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t     ......MENU....... \n");
    printf("\n [1] Add item \n [2] Delete item  \n [3] show my cart \n [4] Bill \n [5] Main cark\n [6] Exit\n\n");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    while(1)
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                a=add_item(item_sl);
                if(a==0) item_sl++;
                break;
            }

        case 2:item_sl=delete_item(item_sl);
               break;

        case 3:show_my_items(item_sl);
               break;

        case 4:
            {
                bill(item_sl);
                exit(0);
            }
        case 5:display_available_items();
               break;
        case 6:exit(0);

        default : printf("Enter invalid choice.....!");
        }
    }
}
