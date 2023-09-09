#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include<windows.h>
// Maximum number of tasks
#define MAX_TASKS 100

// Task structure to represent a to-do item
struct Task {
    char description[256];
    bool completed;
};

// Function to add a new task
void addTask(struct Task tasks[], int* taskCount, const char* description) {
    if (*taskCount < MAX_TASKS) { // check if taskcount is less than limit
        struct Task newTask;// create a new obj
        strcpy(newTask.description, description); // copy desc in newobj
        newTask.completed = false;// set task to be completed as false
        tasks[*taskCount] = newTask; 
        (*taskCount)++;
        printf("Task added: %s\n", description);
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}

// Function to list all tasks
void listTasks(const struct Task tasks[], int taskCount) {
    printf("To-Do List:\n");
    for (int i = 0; i < taskCount; ++i) {
        const struct Task task = tasks[i];
        printf("[%c] %d. %s\n", (task.completed ? 'X' : ' '), i + 1, task.description);
    }
}

// Function to mark a task as completed
void markTaskComplete(struct Task tasks[], int taskCount, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskCount) {
        tasks[taskIndex - 1].completed = true;
        Beep(1000,100);
        printf("Task marked as completed: %s\n", tasks[taskIndex - 1].description);
        
    } else {
        printf("Invalid task index.\n");
        Beep(500,1000);
    }
}

int main() {
    system("color 50");
    struct Task t[MAX_TASKS]; // 100 tasks which contain descp and iscompltd.
    int taskCount = 0;

    system("cls");
    printf("----------------TO DO APPLICATION------------------\n");

    while (1) {
    printf("***************************************************\n"); 
        printf("Options:\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Quit\n");
    printf("***************************************************\n");    
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char description[256];
                printf("Enter task description: ");
                scanf(" %s", description);
                addTask(t, &taskCount, description);
                break;
            }
            case 2:
                listTasks(t, taskCount);
                break;
            case 3: {
                int taskIndex;
                printf("Enter the index of the task to mark as completed: ");
                scanf("%d", &taskIndex);
                markTaskComplete(t, taskCount, taskIndex);
                break;
            }
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
