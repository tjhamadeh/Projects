#include <cstdlib>
#include <iostream>

#define SIZE 100

using namespace std;

// structure for stack
struct INFO_RC {
    char id[10];
    int major;
};

struct NODE;
typedef NODE * PT_NODE;

struct NODE {
       INFO_RC info;
       PT_NODE next;
       };

typedef PT_NODE STACK;

int isEmpty(STACK &); // function prototype - check if empty
void createStack(STACK &); // function prototype - create stack
void purge(STACK &); // function prototype - purge stack
void top(STACK & S, INFO_RC & L); // function prototype - display top
void pop(STACK & S, INFO_RC & L); // function prototype - pop top item
void push(STACK & S, const INFO_RC & L); // function prototype - push item on stack

int main()
{
    // define variables
    int choice; 
    INFO_RC item;
    bool didYouMakeIt = false;
    STACK S;
    STACK temp;
    
    do // begin do-while
    {
          cout << "YOU MUST CHOOSE!!\n"
               << "1) Create a Stack\n"
               << "2) Push Item\n"
               << "3) Pop Item\n"
               << "4) Top Item\n"
               << "5) Is Empty?\n"
               << "6) Purge the Stack\n"
               << "7) Quit\n";
          cin >> choice;
          
          // begin switch
          switch (choice)
          {
              // creates stack
              case 1:
                  createStack(S);
                  didYouMakeIt = true;
                  cout << "You made the stack.\n";
              break;
              
              // push item onto stack
              case 2:
                  if(!didYouMakeIt)
                  {
                      cout << "YOU MUST MAKE IT!!\n";
                      break;
                  }
                  
                  cout << "ID>>";
                  cin >> item.id;
                  cout << "MAJOR>>";
                  cin >> item.major;
             
                  push(S, item);
             break;
             
             // pop items off the stack
             case 3:
                  if(!didYouMakeIt)
                  {
                      cout << "YOU MUST MAKE IT!!\n";
                      break;
                  }
                  
                  if(!isEmpty(S))
                  {
                      pop(S, item);
                      cout << "The popped ID: " << item.id << endl;
                      createStack(temp);
                      cout << "The remaining ID's:\n\n";
                      
                      while(!isEmpty(S))
                      {
                          pop(S, item);
                          push(temp, item);
                          cout << "ID: " << item.id << endl
                               << "MAJOR: " << item.major << endl << endl;
                      }
                      while(!isEmpty(temp))
                      {
                          pop(temp, item);
                          push(S, item);
                      }
                  }
                  else
                  {
                      cout << "The stack is empty\n";
                  }
             break;
             
             // display top item on the stack
             case 4:
                  if(!didYouMakeIt)
                  {
                      cout << "YOU MUST MAKE IT!!\n";
                      break;
                  }
                  
                  if(!isEmpty(S))
                  {
                      top(S, item);
                      cout << "The top: " << endl << endl
                           << "ID: " << item.id << endl
                           << "MAJOR: " << item.major << endl;
                  }                  
                  else
                  {
                      cout << "The stack is empty\n";
                  }
             break;
             
             // check if stack is empty
             case 5:
                  if(!didYouMakeIt)
                  {
                      cout << "YOU MUST MAKE IT!!\n";
                      break;
                  }
                  
                  if(isEmpty(S))
                      cout << "it's empty\n";
                  else
                      cout << "it's not empty\n";
             break;
             
             // purge the stack
             case 6:
                  purge(S);
                  didYouMakeIt = false;
                  cout << "You killed the stack.\n";
             break;
             
             // exit switch
             case 7:
                  cout << "GET OUT!!!!!!\n";
             break;
             
             // default
             default:
                  cout << "YOU'RE A DUMMY, PICK ONE THAT MEANS SOMETHING, DUMMY\n";
             break;
             
             
             
          } //close switch
          
          system("PAUSE");
          system("CLS");
          
    }while (choice != 7); // end do while
                       
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

// function - create stack
void createStack(STACK &S)
{
     S = NULL;
}

// function - returns true if stack empty
int isEmpty(STACK &S)
{
     return (S == NULL);
}

// function - clear stack
void purge(STACK &S)
{
     INFO_RC temp;
     while(!isEmpty(S)) {
     pop(S, temp);
     }
}     

// function - display top item
void top(STACK & S, INFO_RC & L)
{
     L = S -> info;
}

// function - remove top item from stack
void pop(STACK & S, INFO_RC & L)
{
     PT_NODE P = S;
     L = S -> info;
     S = S -> next;
     delete P;
}

// function - place item on top of stack
void push(STACK & S, const INFO_RC & L)
{
     PT_NODE P = new NODE;
     P -> info = L;
     P -> next = S;
     S = P;
}
