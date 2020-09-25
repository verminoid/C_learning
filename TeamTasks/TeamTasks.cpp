/******************************************
**
**      File: TeamTasks.cpp
**      Project: Learning
**      Created By VERMIN
**      Date: 24/09/2020
**      Description: 
**
******************************************/

// Includes
#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;

// Classes and function
// Перечислимый тип для статуса задачи
enum class TaskStatus
{
    NEW,         // новая
    IN_PROGRESS, // в разработке
    TESTING,     // на тестировании
    DONE         // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks
{
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo &GetPersonTasksInfo(const string &person) const
    {
        return team.at(person);
    };

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string &person)
    {
        TasksInfo &pers_task = team[person];
        pers_task[TaskStatus::NEW]++;
    };

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    /*Метод PerformPersonTasks должен реализовывать следующий алгоритм:
Рассмотрим все невыполненные задачи разработчика person.
Упорядочим их по статусам: сначала все задачи в статусе NEW, затем все задачи в статусе IN_PROGRESS и, наконец, задачи в статусе TESTING.
Рассмотрим первые task_count задач и переведём каждую из них в следующий статус в соответствии с естественным порядком: NEW → IN_PROGRESS → TESTING → DONE.
Вернём кортеж из двух элементов: информацию о статусах обновившихся задач (включая те, которые оказались в статусе DONE) и информацию о статусах остальных не выполненных задач.
В случае отсутствия разработчика с именем person метод PerformPersonTasks должен вернуть кортеж из двух пустых TasksInfo
Гарантируется, что task_count является положительным числом. Если task_count превышает текущее количество невыполненных задач разработчика, достаточно считать, что task_count равен количеству невыполненных задач: дважды обновлять статус какой-либо задачи в этом случае не нужно.
*/
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string &person, int task_count)
    {
        
        if (team.count(person)==0)
        {
            return tuple<TasksInfo, TasksInfo>{};
        }
        TasksInfo &pers_task = team[person];
        //заполнение выходного кортежа
        TasksInfo unchange_task = team[person];
        TasksInfo change_task = {
            {TaskStatus::IN_PROGRESS, 0},
            {TaskStatus::TESTING, 0},
            {TaskStatus::DONE, 0},
        };

        for (int i = 0; i < task_count; i++)
        {
            if (!pers_task[TaskStatus::NEW] == 0)
            {
                pers_task[TaskStatus::NEW]--;
                unchange_task[TaskStatus::NEW]--;
                pers_task[TaskStatus::IN_PROGRESS]++;
                change_task[TaskStatus::IN_PROGRESS]++;
            }
            else if (!pers_task[TaskStatus::IN_PROGRESS] == 0)
            {
                pers_task[TaskStatus::IN_PROGRESS]--;
                pers_task[TaskStatus::TESTING]++;
                unchange_task[TaskStatus::IN_PROGRESS]--;
                change_task[TaskStatus::TESTING]++;

            } else if (!pers_task[TaskStatus::TESTING] == 0)
            {
                pers_task[TaskStatus::TESTING]--;
                pers_task[TaskStatus::DONE]++;
                unchange_task[TaskStatus::TESTING]--;
                change_task[TaskStatus::DONE]++;
            }
        }
        //очистка выходного кортежа от пустых задач
        unchange_task.erase(TaskStatus::DONE); // очистка неизмененных DONE
        for(auto items : unchange_task) // очистка пустых задач в неизмененных
        {
            if (items.second == 0){ unchange_task.erase(items.first);};
        }
        for(auto items : change_task) // очистка пустых задач в измененных
        {
            if (items.second == 0){ change_task.erase(items.first);};
        }
        return make_tuple(change_task, unchange_task);
    };

private:
    map<string, TasksInfo> team;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info)
{
    cout << tasks_info[TaskStatus::NEW] << " new tasks"
         << ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress"
         << ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested"
         << ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}
// Main Code
int main(int argc, char const *argv[])
{
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i)
    {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
}
