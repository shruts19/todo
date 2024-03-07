#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

void addTask(std::vector<Task> &tasks, const std::string &description) {
    Task newTask = {description, false};
    tasks.push_back(newTask);
    std::cout << "Task added successfully!\n";
}

void viewTasks(const std::vector<Task> &tasks) {
    std::cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            std::cout << " [Completed]";
        } else {
            std::cout << " [Pending]";
        }
        std::cout << std::endl;
    }
}

void markTaskAsCompleted(std::vector<Task> &tasks, size_t index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        std::cout << "Task marked as completed!\n";
    } else {
        std::cout << "Invalid task number!\n";
    }
}

void removeTask(std::vector<Task> &tasks, size_t index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task removed successfully!\n";
    } else {
        std::cout << "Invalid task number!\n";
    }
}

int main() {
    std::vector<Task> tasks;
    char choice;

    do {
        std::cout << "\n===== To-Do List Manager =====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;
            }
            case '2':
                viewTasks(tasks);
                break;
            case '3': {
                size_t index;
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> index;
                markTaskAsCompleted(tasks, index);
                break;
            }
            case '4': {
                size_t index;
                std::cout << "Enter task number to remove: ";
                std::cin >> index;
                removeTask(tasks, index);
                break;
            }
            case '5':
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != '5');

    return 0;
}
