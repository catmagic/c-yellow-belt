#include<iostream>
#include<map>
#include<tuple>
#include<string>
#include"test_runner.h"
using namespace std;


/*enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};


using TasksInfo = map<TaskStatus, int>;*/
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
class TeamTasks {
public:
   void Set(std::string p, TasksInfo info) {
        team_task[p] = info;
    }
    size_t size()
    {
        return team_task.size();
    }
  const TasksInfo& GetPersonTasksInfo(const string& person)
  {
      return team_task[person];
  }

  void AddNewTask(const string& person)
  {
      ++team_task[person][TaskStatus::NEW];
  }


  tuple<TasksInfo, TasksInfo>  PerformPersonTasks(
      const string& person, int task_count)
    {
        TasksInfo update={{TaskStatus::NEW,0},{TaskStatus::IN_PROGRESS,0},{TaskStatus::TESTING,0},{TaskStatus::DONE,0}};
        if(team_task.find(person)==team_task.end())
        {
          return  make_pair(TasksInfo{},TasksInfo{});
        }
        TasksInfo untouche=team_task[person];
        untouche[TaskStatus::DONE]=0;
        while(task_count>0&&TaskExist(untouche))
        {
            --task_count;
            TaskStatus current_status=min_status_task(untouche);
            if(current_status!=TaskStatus::DONE)
            {


                --untouche[current_status];
                untouche=simple(untouche);
                ++update[next(current_status)];
                --team_task[person][current_status];
                ++team_task[person][next(current_status)];
            }
        }
        team_task[person]=simple(team_task[person]);
        return make_pair(simple(update),simple(untouche));
    }
private:

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
    bool TaskExist(const TasksInfo& info)const
    {

        bool result=false;
        for(const auto  tasksinfo:info)
        {
          if(tasksinfo.first!=TaskStatus::DONE){
            result|=tasksinfo.second;}
        }
        return result;
    }
    TaskStatus min_status_task(const TasksInfo& info)const
    {

        for(const auto tasksinfo:info)
        {
            if(tasksinfo.second)
            {
                return tasksinfo.first;
            }
        }
        return TaskStatus::DONE;
    }

};

ostream& operator<<(ostream& out,TasksInfo tasks_info) {
  return out  << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

void one_TeamTasks()
{
    TeamTasks oneTeamTasks;
    TasksInfo updated_tasks, untouched_tasks;
    TasksInfo update={{TaskStatus::NEW,1},{TaskStatus::IN_PROGRESS,0},{TaskStatus::TESTING,0},{TaskStatus::DONE,0}};
    oneTeamTasks.AddNewTask("ann");
  tie(updated_tasks, untouched_tasks)=oneTeamTasks.PerformPersonTasks("ann",0);
    ASSERT_EQUAL(updated_tasks, TasksInfo{});
    ASSERT_EQUAL(untouched_tasks, simple(update));
    ASSERT_EQUAL(oneTeamTasks.size(),1u);
    update[TaskStatus::NEW]=0;
    update[TaskStatus::IN_PROGRESS]=1;
    tie(updated_tasks, untouched_tasks)=oneTeamTasks.PerformPersonTasks("ann",1);
    ASSERT_EQUAL(updated_tasks, simple(update));
    ASSERT_EQUAL(untouched_tasks, TasksInfo{});
    ASSERT_EQUAL(oneTeamTasks.size(),1u);
    tie(updated_tasks, untouched_tasks)=oneTeamTasks.PerformPersonTasks("ann",0);
    ASSERT_EQUAL(updated_tasks, TasksInfo{});
    ASSERT_EQUAL(untouched_tasks, simple(update));
    ASSERT_EQUAL(oneTeamTasks.size(),1u);
     update[TaskStatus::IN_PROGRESS]=0;
    update[TaskStatus::TESTING]=1;
    tie(updated_tasks, untouched_tasks)=oneTeamTasks.PerformPersonTasks("ann",1);
    ASSERT_EQUAL(updated_tasks, simple(update));
    ASSERT_EQUAL(untouched_tasks, TasksInfo{});
    ASSERT_EQUAL(oneTeamTasks.size(),1u);
    tie(updated_tasks, untouched_tasks)=oneTeamTasks.PerformPersonTasks("ann",0);
    ASSERT_EQUAL(updated_tasks, TasksInfo{});
    ASSERT_EQUAL(untouched_tasks, simple(update));
    ASSERT_EQUAL(oneTeamTasks.size(),1u);
    update[TaskStatus::TESTING]=0;
    update[TaskStatus::DONE]=1;
    tie(updated_tasks, untouched_tasks)=oneTeamTasks.PerformPersonTasks("ann",1);
    ASSERT_EQUAL(updated_tasks, simple(update));
    ASSERT_EQUAL(untouched_tasks, TasksInfo{});
    ASSERT_EQUAL(oneTeamTasks.size(),1u);
    tie(updated_tasks, untouched_tasks)=oneTeamTasks.PerformPersonTasks("ann",0);
    ASSERT_EQUAL(updated_tasks, TasksInfo{});
    update[TaskStatus::DONE]=0;
    ASSERT_EQUAL(untouched_tasks, simple(update));
    ASSERT_EQUAL(oneTeamTasks.size(),1u)

}void onepefrorm()
{
    TeamTasks oneTeamTasks;
    TasksInfo updated_tasks, untouched_tasks;
    TasksInfo update={{TaskStatus::NEW,0},{TaskStatus::IN_PROGRESS,0},{TaskStatus::TESTING,0},{TaskStatus::DONE,1}};
    oneTeamTasks.AddNewTask("ann");
    tie(updated_tasks, untouched_tasks)=oneTeamTasks.PerformPersonTasks("ann",4);
    ASSERT_EQUAL(updated_tasks, simple(update));
    ASSERT_EQUAL(untouched_tasks, TasksInfo{});
    oneTeamTasks.AddNewTask("annn");
    tie(updated_tasks, untouched_tasks)=oneTeamTasks.PerformPersonTasks("annn",3);
    ASSERT_EQUAL(updated_tasks, simple(update));
    ASSERT_EQUAL(untouched_tasks, TasksInfo{});
    update={{TaskStatus::NEW,0},{TaskStatus::IN_PROGRESS,0},{TaskStatus::TESTING,1},{TaskStatus::DONE,0}};
    oneTeamTasks.AddNewTask("annnn");
    tie(updated_tasks, untouched_tasks)=oneTeamTasks.PerformPersonTasks("annnn",2);
    ASSERT_EQUAL(updated_tasks, simple(update));
    ASSERT_EQUAL(untouched_tasks, TasksInfo{});

}

void empty_TeamTasks()
{
    TeamTasks emptyTeamTasks;
    TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks)=emptyTeamTasks.PerformPersonTasks("ann",0);
    ASSERT_EQUAL(updated_tasks, TasksInfo{});
    ASSERT_EQUAL(untouched_tasks, TasksInfo{});
    ASSERT_EQUAL(emptyTeamTasks.size(),0u);
    tie(updated_tasks, untouched_tasks)=emptyTeamTasks.PerformPersonTasks("ann",1);
    ASSERT_EQUAL(updated_tasks, TasksInfo{});
    ASSERT_EQUAL(untouched_tasks, TasksInfo{});
    ASSERT_EQUAL(emptyTeamTasks.size(),0u);
    tie(updated_tasks, untouched_tasks)=emptyTeamTasks.PerformPersonTasks("ann",2);
    ASSERT_EQUAL(updated_tasks, TasksInfo{});
     ASSERT_EQUAL(untouched_tasks, TasksInfo{});
    ASSERT_EQUAL(emptyTeamTasks.size(),0u);
    tie(updated_tasks, untouched_tasks)=emptyTeamTasks.PerformPersonTasks("ann",3);
    ASSERT_EQUAL(updated_tasks, TasksInfo{});
    ASSERT_EQUAL(untouched_tasks, TasksInfo{});
    ASSERT_EQUAL(emptyTeamTasks.size(),0u);

}
void testexample()
{
    TeamTasks testTeamTasks;
     TasksInfo updated_tasks, untouched_tasks;
     TasksInfo startann={{TaskStatus::NEW,3},{TaskStatus::IN_PROGRESS,2},{TaskStatus::TESTING,4},{TaskStatus::DONE,1}};
    testTeamTasks.Set("ann",startann);
    tie(updated_tasks, untouched_tasks)=testTeamTasks.PerformPersonTasks("ann",4);
    TasksInfo update= {{TaskStatus::IN_PROGRESS,3},{TaskStatus::TESTING,1}};
    TasksInfo untouche={ {TaskStatus::IN_PROGRESS,1},{TaskStatus::TESTING,4}};
     ASSERT_EQUAL(updated_tasks,update);
    ASSERT_EQUAL(untouched_tasks, untouche);
    ASSERT_EQUAL(testTeamTasks.size(),1u);
}
void PrintTasksInfo(const TasksInfo& tasks_info) {
    if (tasks_info.count(TaskStatus::NEW)) {
        std::cout << "NEW: " << tasks_info.at(TaskStatus::NEW) << " ";
    }
    if (tasks_info.count(TaskStatus::IN_PROGRESS)) {
        std::cout << "IN_PROGRESS: " << tasks_info.at(TaskStatus::IN_PROGRESS) << " ";
    }
    if (tasks_info.count(TaskStatus::TESTING)) {
        std::cout << "TESTING: " << tasks_info.at(TaskStatus::TESTING) << " ";
    }
    if (tasks_info.count(TaskStatus::DONE)) {
        std::cout << "DONE: " << tasks_info.at(TaskStatus::DONE) << " ";
    }
}

void PrintTasksInfo(const TasksInfo& updated_tasks, const TasksInfo& untouched_tasks) {
    std::cout << "Updated: [";
    PrintTasksInfo(updated_tasks);
    std::cout << "] ";

    std::cout << "Untouched: [";
    PrintTasksInfo(untouched_tasks);
    std::cout << "] ";

    std::cout << std::endl;
}

int main() {
    TeamTasks tasks;
    TasksInfo updated_tasks;
    TasksInfo untouched_tasks;

    /* TEST 1 */
    std::cout << "Alice" << std::endl;

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 1);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 1}, {"TESTING": 4}]

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice",
                                                                   2);  // [{"IN_PROGRESS": 2}, {"NEW": 3, "TESTING": 4}]
    PrintTasksInfo(updated_tasks, untouched_tasks);

    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));  // {"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4, "DONE": 1}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 4);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 3, "TESTING": 1}, {"IN_PROGRESS": 1, "TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));  // {"IN_PROGRESS": 4, "TESTING": 5, "DONE": 1}
    std::cout << std::endl;

    /* TEST 2 */
    std::cout << "\nJack" << std::endl;

    tasks.AddNewTask("Jack");

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Jack", 1);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1}, {}]

    tasks.AddNewTask("Jack");

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Jack", 2);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1, "TESTING": 1}, {}]

    tasks.AddNewTask("Jack");

    PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));  // {"NEW": 1, "IN_PROGRESS": 1, "TESTING": 1, "DONE": 0}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Jack", 3);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1, "TESTING": 1, "DONE": 1}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));  // {"IN_PROGRESS": 1, "TESTING": 1, "DONE": 1}
    std::cout << std::endl;

    /* TEST 3 */
    std::cout << "\nLisa" << std::endl;

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Lisa");
    }

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 1);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 1}, {"TESTING": 4}]

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Lisa");
    }

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 2);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 2}, {"NEW": 3, "TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4, "DONE": 1}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 4);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 3, "TESTING": 1}, {"IN_PROGRESS": 1, "TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"IN_PROGRESS": 4, "TESTING": 5, "DONE": 1}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 4, "DONE": 1}, {"TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"TESTING": 8, "DONE": 2}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 10);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 8}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"DONE": 10}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 10);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"DONE": 10}
    std::cout << std::endl;

    tasks.AddNewTask("Lisa");

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"NEW": 1, "DONE": 10}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 2);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"IN_PROGRESS": 1, "DONE": 10}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Bob", 3);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{}, {}]

    return 0;
}
