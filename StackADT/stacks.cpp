#include <cstdlib>
#include <iostream>

#define SIZE 100

using namespace std;

/*****************************************************************************
* Toufic Hamadeh, Brennan Jordan, Michael Szwed, Chris Montagna, Shady Salaheldin
* This program demonstrates how stack operations work.
* CIS-277-601
*****************************************************************************/

// structure for type
struct type
{
    int number;
};

// structure for stack
struct stack
{
    type items[SIZE];
    int top;
};

int g_count;
stack s;

void createStack(stack &); // function prototype - create stack

bool isEmpty(stack &); // function prototype - check if empty

void purge(stack &); // function prototype - purge stack

void top(type &, stack &); // function prototype - display top

void pop(type &, stack &); // function prototype - pop top item

void push(type, stack &); // function prototype - push item on stack

int main(int argc, char *argv[])
{
    // define variables
    int choice; 
    type item;
    bool didYouMakeIt = false;
    stack temp;
    
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
                  createStack(s);
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
                  
                  cout << "Item>>";
                  cin >> item.number;
             
                  push(item, s);
             break;
             
             // pop items off the stack
             case 3:
                  if(!didYouMakeIt)
                  {
                      cout << "YOU MUST MAKE IT!!\n";
                      break;
                  }
                  
                  if(!isEmpty(s))
                  {
                      pop(item, s);
                      cout << "The popped item: " << item.number << endl;
                      createStack(temp);
                      cout << "The remaining items:\n";
                      
                      while(!isEmpty(s))
                      {
                          pop(item, s);
                          push(item, temp);
                          cout << item.number << endl;
                      }
                      while(!isEmpty(temp))
                      {
                          pop(item, temp);
                          push(item, s);
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
                  
                  if(!isEmpty(s))
                  {
                      top(item, s);
                      cout << "The top item: " << item.number << endl;
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
                  
                  if(isEmpty(s))
                      cout << "it's empty\n";
                  else
                      cout << "it's not empty\n";
             break;
             
             // purge the stack
             case 6:
                  purge(s);
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
void createStack(stack &s)
{
     s.top = -1;
     g_count = 0;
}

// function - returns true if stack empty
bool isEmpty(stack &s)
{
     return (s.top == -1);
}

// function - clear stack
void purge(stack &s)
{
     s.top = -1;
     g_count = 0;
}     

// function - display top item
void top(type &t, stack &s)
{
     if(!isEmpty(s))
        t = s.items[s.top];
}

// function - remove top item from stack
void pop(type &t, stack &s)
{
     if(!isEmpty(s))
     {
          t = s.items[s.top];
          s.top--;
          g_count--;
     }
}

// function - place item on top of stack
void push(type t, stack &s)
{
     s.top++;
     g_count++;
     s.items[s.top] = t;
}
     
