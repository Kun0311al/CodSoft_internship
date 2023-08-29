#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string aboutTask;
    bool completed;
    Task(const std::string& desc) : aboutTask(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& desc) {
        tasks.push_back(Task(desc));
        std::cout << "Task added: " << desc << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks to display." << std::endl;
            return;
        }

        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << "[" << (i + 1) << "] " << (tasks[i].completed ? "[X]" : "[ ]") << " " << tasks[i].aboutTask << std::endl;
        }
    }

    void markCompleted(int index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed: " << tasks[index - 1].aboutTask << std::endl;
        }
        else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(int index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task removed." << std::endl;
        }
        else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    
    system("cls");
    while (true) {
        std::cout << "\n\n\t\t\tToDo List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1: {
                std::string desc;
                std::cout << "Enter task description: ";
                std::cin.ignore();  // Clear newline from the buffer
                std::getline(std::cin, desc);
                todo.addTask(desc);
                break;
            }
            case 2:
                todo.viewTasks();
                break;
            case 3: {
                int index;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> index;
                todo.markCompleted(index);
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
                todo.removeTask(index);
                break;
            }
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;
    return 0;
}
