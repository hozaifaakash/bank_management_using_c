#include<stdio.h>
#include<string.h>
//declare amount for deposit ,withdrow and transfer
int amount;
int Total_deposit=0,Total_withdrow=0,Total_transfer=0;
//structure use for customer informatuion
struct customer{
    int account_no;
    char name[80];
    int balance;
};
//search account number
int search(struct customer list[80], int s, int number){
    int i;
    //count customer
    for (i = 0; i < s; i++){
        if (list[i].account_no == number){
            return i;
        }
    }
    return  - 1;
}
//display customer name ,acc. no., balance
void display(struct customer list[80], int s){
    int i;
    printf("\n\nA/c No\tName\tBalance\n");
    for (i = 0; i < s; i++){
        printf("%d\t%s\t%d\n", list[i].account_no, list[i].name,list[i].balance);
    }
}
//account number verefication
void accept(struct customer list[80], int s){
    int i;
    for (i = 0; i < s; i++){
        printf("\nEnter data for Record #%d", i + 1);
        printf("\nEnter account_no : ");
        scanf("%d", &list[i].account_no);
        fflush(stdin);
        printf("Enter name : ");
        gets(list[i].name);
        list[i].balance = 0;
    }
}
//check abot depoite,transfer  and withdrow amount
void check_details(){
    //printf("\n\n\t\t\tTotal amount=%d",Total_amount);
    printf("\n\t\t\tTotal deposited amount=%d",Total_deposit);
    printf("\n\t\t\tTotal withdrawn amount=%d",Total_withdrow);
    printf("\n\t\t\tTotal transfer amount=%d",Total_transfer);
}
//funtion using for transfer amount
void transfer(struct customer list[80], int s, int number){
    int i = search(list, s, number);
    if (i ==  - 1){
        printf("Record not found\n");
    }
    else {
    printf("Enter amount to transfer : ");
    scanf("%d", &amount);
            if (list[i].balance < amount){
        printf("Insufficient balance\n");
    }
    else{
        list[i].balance -= amount;
        Total_transfer=amount;
    }
}
}
//funtion using for withdrow amount
void withdrow(struct customer list[80], int s, int number){
    int i = search(list, s, number);
    if (i ==  - 1){
        printf("Record not found\n");
    }

    else{
    printf("Enter amount withdraw : ");
    scanf("%d", &amount);
    if (list[i].balance < amount){
    printf("Insufficient balance\n");
    }
    else{
        list[i].balance -= amount;
        Total_withdrow=amount;
    }
}
}
//funtion using for diposit amount
void deposit(struct customer list[], int s, int number){
    int i = search(list, s, number);
    if (i ==  - 1){
        printf("Record not found");
    }
    else{

        printf("Enter amount to deposit : ");
        scanf("%d", &amount);
        list[i].balance += amount;
        Total_deposit=list[i].balance;
    }
}
//main menu list for this project
int list(){
    int choose;
    printf("\n\t\t\t*CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM*");
    printf("\n\n\n\t\t\t\ : WELCOME TO THE MAIN MENU :");
    printf("\n\t\t\t1.Deposit amount");
    printf("\n\t\t\t2.Withdrow amount");
    printf("\n\t\t\t3.Transfer amount");
    printf("\n\t\t\t4.check details about deposit,withdrawn and transfer taka");
    printf("\n\t\t\t5.Exit");
    printf("\n\t\t\t6.check total amount and customer information");
    printf("\n\t\t\tEnter your choose : ");
    scanf("%d",&choose);
    return(choose);
}
//main funtion of this project
void main(){
    struct customer data[80];
    int n,account_no;
    printf("welcome to Banking System:\n");
    printf("Number of customer records??? : ");
    scanf("%d", &n);
    accept(data, n);
    while(1){
            system("cls");
//using switch case
    switch(list()){
        case 1:
            printf("Enter account number : ");
            scanf("%d", &account_no);
            deposit(data, n, account_no);
            break;
        case 2:
            printf("Enter account number : ");
            scanf("%d", &account_no);
            withdrow(data, n, account_no);
            break;

        case 3:
            printf("Enter account number : ");
            scanf("%d", &account_no);
            transfer(data, n, account_no);
            break;
        case 4:
            check_details();
            break;
        case 5:
            system("cls");
            exit(0);
        case 6:
            display(data, n);
            break;
        default:
            printf("\nInvaid input choice");
    }
    getch();
    }
}



