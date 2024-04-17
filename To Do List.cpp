#include <iostream>
#include <string>
#include <list>
#include <ctime>


class TodoItem {  // declare a class named ToDoItem
private:  // make tasks private so they cannot be modified outside of their class - hides internal workings of program
    int id;
    std::string description;   // a string to represent a description of that particular task
    bool completed;  // creates a bool for completed, this will either be true or false (completed or uncompleted)

public: // these items are public as they are open to being changed and modified
    TodoItem() : id(0), description(""), completed(false) {}  // constructor of ToDoItem class - this initializes member values with default settings, 0, blank and false 
    ~TodoItem() = default;               // destructor for TodoItem, defines process for when an item is deleted or out of scope - we are using default for this compiler

    bool create(std::string new_description){  // bool that allows for creation of new todo items, particularly their description
        id = rand() % 100 + 1; // generates a random integer between 1 and 100 - giving it a random id
        description = new_description;
        return true;
    }

    int getId() { return id; }
    std::string getDescription() { return description; }
    bool isCompleted() { return completed; } // these member functions allow a way to access private class variables in a controlled manner and are used in later code

    void setCompleted(bool val) { completed = val; }
};

int main()
{
    // here we declare all user input values, using a char for the input option as it is just one character, 
    // int for id as it is a randomly generated number between 1 and 100 and an input description string, as the description will be longer than a single char
    char input_option; 
    int input_id;
    std::string input_description;
    std::list<TodoItem> todoItems;  // create a list for todoitems
    std::list<TodoItem>::iterator it;  // calls an iterator function - this points to values within our list and loops over them - this allows us to access and modify them

    srand(time(NULL)); // creates a seed based on current time which is used for our earlier random integer call

    todoItems.clear();   // ensure by default the list begins as a cleared list

    //TodoItem test;
    //test.create("this is a test");
    //todoItems.push_back(test);
    

    while(1) {         // creates an infinite loop for the list to operate within - data is always displayed unless stopped / cleared
        system("cls"); // between each loop, screen is cleared
        std::cout << "Todo List Creator" << std::endl;
        std::cout << std::endl << std::endl;
        
        for (it = todoItems.begin(); it != todoItems.end(); it++) { // iteration starts with first item in list, and it continues to move through the list as long as it has not reached the end
            
            std::string completed = it->isCompleted() ? "DONE" : "NOT DONE"; // calls 'isCompleted()' member function on current todo item 
         //and uses a ternary conditional operator to return either DONE or NOTDONE based on if the bool is true or false
         // in line 60 we call completed and use that to print the information to the user, meaning that whether the job is done or not will be shown in the console
            std::cout << it->getId() << " | " << it->getDescription() << " | "
                << completed << std::endl;  // this iteration will return to the user information regarding tasks in the list

        }

        if (todoItems.empty()) {                // if our list is empty the program prompts user to add an item
            std::cout << "Please add your first task:" << std::endl;
        }

        std::cout << "[A]dd a new Task" << std::endl;
        std::cout << "[C]omplete a Task" << std::endl;
        std::cout << "[Q]uit the Program" << std::endl; 
        // defines to the user the 3 button prompts used to interact with the Todo List

        std::cout << "Choice: ";

        std::cin >> input_option; 

        if (input_option == 'q') {
            std::cout << "Thank you for using the Todo List" << std::endl; 
            break; // if q is entered into the program the loop breaks and the program ends
        }
        else if (input_option == 'a') {
            std::cout << "Add a new description: ";
            std::cin.clear(); // start with fresh input buffer
            std::cin.ignore(); // ignore the first return
            std::getline(std::cin, input_description);   // using getline allows us to capture the entire input string rather than just one word
            // if user enters q they are then prompted into entering a new item into the list

            TodoItem newItem;       // declares new object of TodoItem named newItem which represents the new task being added to the list
            newItem.create(input_description); 
            todoItems.push_back(newItem);  // this line adds the new todo item to the std::list via push_back function

        }
        else if (input_option == 'c') {
            std::cout << "Enter id to mark task as completed:";
            std::cin >> input_id;
            
            for (it = todoItems.begin(); it != todoItems.end(); it++) {  // we re-use iteration through our todo items again

                if (input_id == it->getId()) { // if the id of the current todo item matches the one user has inputted then it is set to complete and it closes the loop
                    it->setCompleted(true);
                    break;
                }
              
             
            }

        }

     
    }
        
    return 0;

}