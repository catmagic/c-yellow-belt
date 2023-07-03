#include<map>
// ������������ ��� ��� ������� ������
enum class TaskStatus {
  NEW,          // �����
  IN_PROGRESS,  // � ����������
  TESTING,      // �� ������������
  DONE          // ���������
};

// ��������� ���-������� ��� map<TaskStatus, int>,
// ������������ ������� ���������� ����� ������� �������
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // �������� ���������� �� �������� ����� ����������� ������������
  const TasksInfo& GetPersonTasksInfo(const string& person) const
  {
      return team_task.at(person);
  }

  // �������� ����� ������ (� ������� NEW) ��� ����������� �������������
  void AddNewTask(const string& person)
  {
      ++team_task[person][TaskStatus::NEW];
  }

  // �������� ������� �� ������� ���������� ����� ����������� ������������,
  // ����������� ��. ����
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count)
    {
        TasksInfo update={{TaskStatus::NEW,0},{TaskStatus::IN_PROGRESS,0},{TaskStatus::TESTING,0}{TaskStatus::DONE,0}};
        TasksInfo untouche={{TaskStatus::NEW,0},{TaskStatus::IN_PROGRESS,0},{TaskStatus::TESTING,0}{TaskStatus::DONE,0}};
        if(TaskExist(person))
        {
            for(const auto task:GetPersonTasksInfo(person))
            {
                untouche[task.first]=task.second;
            }
        }
        while(task_count!=0&&TaskExist(person))
        {
            cu
        }
    }
private:
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
// ��������� ������� �� ��������, ����� ����� �����������
// ���������� � ������������� ������ � ������� [] � �������� 0,
// �� ����� ��� ���� �������� �������
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
