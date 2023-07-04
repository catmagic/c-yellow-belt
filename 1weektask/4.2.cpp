#include<iostream>
#include<map>
#include<tuple>
#include<string>
using namespace std;

// ������������ ��� ��� ������� ������
/*enum class TaskStatus {
  NEW,          // �����
  IN_PROGRESS,  // � ����������
  TESTING,      // �� ������������
  DONE          // ���������
};

// ��������� ���-������� ��� map<TaskStatus, int>,
// ������������ ������� ���������� ����� ������� �������
using TasksInfo = map<TaskStatus, int>;*/
class TeamTasks {
public:
  // �������� ���������� �� �������� ����� ����������� ������������
  const TasksInfo& GetPersonTasksInfo(const string& person) 
  {
      return team_task[person];
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
        TasksInfo update={{TaskStatus::NEW,0},{TaskStatus::IN_PROGRESS,0},{TaskStatus::TESTING,0},{TaskStatus::DONE,0}};
        if(team_task.find(person)==team_task.end())
        {
          return  make_pair(TasksInfo{},TasksInfo{});
        }
        TasksInfo untouche=team_task[person];
        untouche[TaskStatus::DONE]=0;
        while(task_count>0&&TaskExist(person))
        {
            --task_count;
            TaskStatus current_status=min_status_task(person);
            if(current_status!=TaskStatus::DONE)
            {
             /* cout<<"(untouche):";
              PrintTasksInfo(untouche);
               cout<<"(update):";
              PrintTasksInfo(update);*/
                if(untouche[current_status])
                {
                    --untouche[current_status];
                }
                else
                {
                    --update[current_status];
                }
                ++update[next(current_status)];
                --team_task[person][current_status];
                ++team_task[person][next(current_status)];
            }
        }
        return make_pair(simple(update),simple(untouche));
    }
private:
  TasksInfo simple(const TasksInfo tasks)
  {
    TasksInfo result;
    for(const auto task:tasks)
    {
      if(task.second)
      {
        result[task.first]=task.second;
      }
    }
    return result;
  }
    TaskStatus next(const TaskStatus& cur)
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
        for(const auto  tasksinfo:it->second)
        {
          if(tasksinfo.first!=TaskStatus::DONE){
            result|=tasksinfo.second;}
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
  for (int i = 0; i < 5; ++i) {
    tasks.AddNewTask("Alice");
  }
 

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 5);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 5);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 1);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  
  
  for (int i = 0; i < 5; ++i) {
    tasks.AddNewTask("Alice");
  }

   tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
           tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 4 );
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);    
                 
                   PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

  return 0;
}
