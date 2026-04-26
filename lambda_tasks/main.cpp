#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

#include "Task.hpp"
#include "TaskUtils.hpp"

int main() {
  const std::vector<std::string> names{
    "Spec Rev", "Parser", "Roadmap",
    "Fix CI", "UI Proto", "Metrics",
    "Sec Audit", "DB Mig", "Docs"
  };
  const std::vector<int> priorities{ 6, 9, 7, 8, 5, 6, 9, 8, 4 };
  const std::vector<double> times{ 1.0, 5.5, 2.5, 1.2, 3.0, 2.0, 4.0, 6.0, 1.5 };
  const std::vector<std::string> depts{
    "Product", "Engineering", "Product",
    "Engineering", "Design", "Data",
    "Security", "Engineering", "Product"
  };

  std::vector<int> idx(names.size());
  for (int i = 0; i < idx.size(); ++i) idx[i] = i;

  std::vector<Task> tasks(idx.size());
 
  std::cout << "== All ==" << std::endl;

  std::transform(idx.begin(), idx.end(), tasks.begin(), [&] (int i) -> Task { return Task(names[i], priorities[i], times[i], depts[i]);});

  for (const Task& task : tasks) {
    task.print();
  }
  std::cout << std::endl << "== Eng >2h ==" << std::endl;

  auto engLong = TaskUtils::filter(tasks, [&](const Task& task) { return task.getDepartment() == "Engineering" && task.getEstimatedTimeHours() > 2.0; });

  for (const auto& task : engLong) {
    task.print();
  }


  double shortThreshold = 1.5;
  int newlyDoneCount = 0;
  std::cout << std::endl << "== Short Tasks Done ==" << std::endl;

  TaskUtils::forEach(tasks, [&](Task& task){
    if (task.getEstimatedTimeHours() <= shortThreshold && !task.isDone()) {
      task.setDone(true);
      ++newlyDoneCount;
    }
  });

  std::cout << "Marked " << newlyDoneCount << " short tasks done" << std::endl;


  std::cout << std::endl << "== Priority ↓ ==" << std::endl;

  TaskUtils::sort(tasks, [](const Task& a, const Task& b){
    return a.getPriority() > b.getPriority();
  });

  for (const auto& task : tasks) {
    task.print();
  }

  std::cout << std::endl << "== Renamed [HOT] ==" << std::endl;

  std::vector<Task> renamed = TaskUtils::apply(tasks, [](const Task& task) -> Task {
    
    std::string taskName = (task.getPriority() >= 8 ? "[HOT] " : "") + task.getName();
    
    return Task(taskName, task.getPriority(), task.getEstimatedTimeHours(), task.getDepartment(), task.isDone());
  });

  for (const auto& task : renamed) {
    task.print();
  }

  std::cout << std::endl << "== Summary ==" << std::endl;

  auto summarize = [](const auto& list) {
    int count = 0;
    int done = 0;
    double totalHours = 0.0;
    for (const auto& task : list) {
      ++count;
      if (task.isDone()) ++done;
      totalHours += task.getEstimatedTimeHours();
    }
    std::cout << "Summary: " << count << " tasks, " << done << " done, total est. time = " << totalHours << "h" << std::endl;
  };

  summarize(tasks);


  const std::string projectName = "Apollo";
  std::cout << std::endl << "== Project tag ==" << std::endl;

  auto showWithProjects = [projectName](const Task& task) {
    std::cout << "[" << projectName << "] ";
    task.print();
  };

  for (const auto& task : tasks) {
    showWithProjects(task);
  }

  int doneCount = 0;
  auto countDone = [&doneCount] (const Task& task) {
    if (task.isDone()) {
      ++doneCount;
    }
  };

  for (const auto& task : tasks) {
    countDone(task);
  }
  std::cout << "Done: " << doneCount << std::endl;

  int priorityThreshold = 7;
  int flaggedCount = 0;

  auto countAbove = [priorityThreshold, &flaggedCount] (const Task& task) {
    if (task.getPriority() > 7) {
      ++flaggedCount;
    }
  };

  for (const auto& task : tasks) {
    countAbove(task);
  };

  std::cout << "Flagged > 7: " << flaggedCount << std::endl;

  int batchId = 42;
  std::cout << std::endl << "== First 3 (batch) ==" << std::endl;

  auto showWithBatch = [msg = std::string("Batch-") + std::to_string(batchId)] (const Task& task) {
    std::cout << msg << " :: ";
    task.print();
  };

  int limit = (tasks.size() < 3) ? tasks.size() : 3;
  for (int i = 0; i < limit; ++i) {
    showWithBatch(tasks[i]);
  }

  return 0;
}
