#include<stdio.h>
#include<string.h>
#include<math.h>


void anybase(int q, int base);
void todec(char q[], int base);


int main()
{
    int a,choice=0;
    char q[50];
    printf("\n-----||  CONVERTER  ||-----\n\nOption 1: Decimal to Binary\nOption 2: Binary to Decimal\nOption 3: Decimal to Octal\nOption 4: Octal to Decimal\nOption 5: Decimal to Hexadecimal\nOption 6: Hexadecimal to Decimal\nOption 7: Quit");
   
    while(choice!=7)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{
                printf("Enter Decimal Number: ");
                scanf("%d",&a);
                printf("\nBinary Conversion: ");
                anybase(a,2);
                printf("\n------------------------");
                break;
            }
           
            case 2:{
                printf("Enter Binary Number: ");
                scanf("%s",q);
                printf("\nDecimal Conversion: ");
                todec(q,2);
                printf("\n------------------------");
                break;
            }
           
            case 3:{
                printf("Enter Decimal Number: ");
                scanf("%d",&a);
                printf("\nOctal Conversion: ");
                anybase(a,8);
                printf("\n------------------------");
                break;
            }
           
            case 4:{    
                printf("Enter Octal Number: ");
                scanf("%s",q);
                printf("\nDecimal Conversion: ");
                todec(q,8);
                printf("\n------------------------");
                break;
            }
           
            case 5:{
                printf("Enter Decimal Number: ");
                scanf("%d",&a);
                printf("HexaDecimal Conversion: ");
                anybase(a,16);
                printf("\n------------------------");
                break;
            }  
           
            case 6:{
                printf("Enter HexaDecimal Number: ");
                scanf("%s",q);
                printf("\nDecimal Conversion: ");
                todec(q,16);
                printf("\n------------------------");
                break;
            }  
            case 7:
                break;
               
            default:
                printf("\nNot an option:(");
                break;
        }
    }
    printf("_________\n");
    printf("Exit...");    
}


void anybase(int q, int base)
{
    int rem,i=0,j;
    char a[100];
    while(q!=0)
    {
        rem=q%base;
        if(rem<10)
        {
            a[i]=48+rem;
        }
        else
        {
            a[i]=55+rem;
        }
        q=q/base;
        i++;
    }
    printf("\n");
    for(int j=i-1;j>=0;j--){
        printf("%c",a[j]);
    }
}


void todec(char q[], int base)
{
    int z,rem=0,dec=0,i,j=0;


    int len;
    len=strlen(q);


    for(i=len-1;i>=0;i--)
    {
        if(q[i]>64)
        {
            rem=q[i]-55;
            dec+=rem*pow(base,j);
        }
        else
        {
            rem=q[i]-48;
            dec+=rem*pow(base,j);
        }
        j++;
        rem=0;
    }
    printf("%d",dec);
}
