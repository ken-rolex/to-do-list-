#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToDoList {
private:
    vector<string> tasks;
    vector<bool> completed;

public:
    // Function to add a task
    void addTask(string task) {
        tasks.push_back(task);
        completed.push_back(false); // Initially, task is not completed
        cout << "Task added: " << task << endl;
    }

    // Function to display tasks
    void displayTasks() {
        if (tasks.empty()) {
            cout << "Your to-do list is empty!" << endl;
            return;
        }

        cout << "\nYour To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i] << " [" << (completed[i] ? "Done" : "Not Done") << "]" << endl;
        }
    }

    // Function to mark a task as completed
    void markTaskDone(int taskIndex) {
        if (taskIndex <= 0 || taskIndex > tasks.size()) {
            cout << "Invalid task number!" << endl;
            return;
        }
        completed[taskIndex - 1] = true;
        cout << "Task marked as completed: " << tasks[taskIndex - 1] << endl;
    }

    // Function to delete a task
    void deleteTask(int taskIndex) {
        if (taskIndex <= 0 || taskIndex > tasks.size()) {
            cout << "Invalid task number!" << endl;
            return;
        }
        cout << "Task deleted: " << tasks[taskIndex - 1] << endl;
        tasks.erase(tasks.begin() + taskIndex - 1);
        completed.erase(completed.begin() + taskIndex - 1);
    }
};

void showMenu() {
    cout << "\n==== To-Do List Menu ====" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Mark task as done" << endl;
    cout << "4. Delete a task" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    ToDoList todoList;
    int choice;

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the input buffer

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter task description: ";
                getline(cin, task);
                todoList.addTask(task);
                break;
            }
            case 2:
                todoList.displayTasks();
                break;
            case 3: {
                int taskNumber;
                cout << "Enter task number to mark as done: ";
                cin >> taskNumber;
                todoList.markTaskDone(taskNumber);
                break;
            }
            case 4: {
                int taskNumber;
                cout << "Enter task number to delete: ";
                cin >> taskNumber;
                todoList.deleteTask(taskNumber);
                break;
            }
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
