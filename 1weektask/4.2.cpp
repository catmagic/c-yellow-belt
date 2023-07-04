#include<map>
// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const
  {
      return team_task.at(person);
  }

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person)
  {
      ++team_task[person][TaskStatus::NEW];
  }

  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count)
    {
        TasksInfo update={{TaskStatus::NEW,0},{TaskStatus::IN_PROGRESS,0},{TaskStatus::TESTING,0}{TaskStatus::DONE,0}};
        TasksInfo untouche=GetPersonTasksInfo(person);

        while(task_count!=0&&TaskExist(person))
        {
            --task_count;
            TaskStatus current_status=min_status_task(person);
            if(current_status!=TaskStatus::DONE)
            {
                if(untouche[current_status])
                {
                    --untouche[current_status];
                }
                else
                {
                    --update[current_status];
                }
                ++update[next(current_status)];
                ++team_task[person][next(current_status)];
            }
        }
        return make_pair(update,untouche);
    }
private:
    TaskStatus& next(const TaskStatus& cur)
    {
        switch (cur)
        {
            case TaskStatus::NEW:
                return TaskStatus::IN_PROGRESS;
            case TaskStatus::IN_PROGRESS:
                return TaskStatus::TESTING;
            default:
                return TaskStatus::DONE;
        }


    }
    map<string,TasksInfo> team_task;
    bool TaskExist(const string& person)const
    {
        auto it=team_task.find(person);
        if(it==team_task.end())
        {
            return false;
        }
        bool result=false;
        for(const auto tasksinfo:it)
        {
            result|=tasksinfo.second;
        }
        return result;
    }
    TaskStatus min_status_task(const string& person)const
    {
        auto it=team_task.at(person);
        for(const auto tasksinfo:it)
        {
            if(tasksinfo.second)
            {
                return tasksinfo.first;
            }
        }
        return TaskStatus::DONE;
    }

};
// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
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
