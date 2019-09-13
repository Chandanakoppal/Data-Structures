#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.c"

int main () {
   int input,data,value,val,min,position,head;
   struct node* p;
   for (;;) {
      printf("enter your choice\n");
      printf("1. Insert an element at beginning of linked list.\n");
      printf("2. Insert an element at end of linked list.\n");
      printf("3. Traverse linked list.\n");
      printf("4. Delete element from beginning.\n");
      printf("5. Delete element from end.\n");
      printf("6. Total number of elements\n");
      printf("7. Search an element\n");
      printf("8. Exit\n");
      printf("9. Min element in the list \n");
      printf("10. Maximum element in the list\n");
      printf("11. Insertion at specific position\n");
      printf("12. Deletion at specific position\n");
      printf("13. Reverse\n");

      scanf("%d", &input);

      if (input == 1) 
      {
         printf("Enter value of element\n");
         scanf("%d", &data);
         insert_at_begin(data);

      }
      else if (input == 2)
       {
         printf("Enter value of element\n");
         scanf("%d", &data);
         insert_at_end(data);
       }
      else if (input == 3)
         traverse();
      else if (input == 4)
         delete_from_begin();
      else if (input == 5)
         delete_from_end();
      else if (input == 8)
         break;
        else if (input==7)
        {
            printf("Enter elementto be searched\n");
            scanf("%d",&value);
            search_item( value);
        }
        else if (input==6)
            count_list();
            else if(input==9){
                printf("The minimum element in the linked list is %d\n",findmin(start));
                findmin(start);
            }
            else if(input==10)
            {
                 printf("The maximum element in the linked list is %d\n",findmax(start));
            }
            else if(input==11)
            {
                 printf("Enter data to insert at middle of the list: ");
                scanf("%d", &data);
                printf("Enter the position to insert new node: " );
                scanf("%d", &position);
                insertNodeAtMiddle(data, position);
            }
              else if(input==12)
              {
                 printf("\nEnter the node position you want to delete: ");
                 scanf("%d", &position);
                deleteMiddleNode(position);

              }
            else if (input==13)
            {
                 reverseList();
               
            }

            else
         printf("Please enter valid input.\n");
   }

   return 0;
}