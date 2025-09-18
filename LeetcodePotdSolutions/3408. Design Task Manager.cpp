class TaskManager
{
public:
    map<pair<int, int>, int, greater<>> mp1;
    map<int, int> mp2;
    TaskManager(vector<vector<int>> &tasks)
    {
        for (int i = 0; i < tasks.size(); i++)
        {
            mp1[{tasks[i][2], tasks[i][1]}] = tasks[i][0];
            mp2[tasks[i][1]] = tasks[i][2];
        }
    }

    void add(int userId, int taskId, int priority)
    {
        mp1[{priority, taskId}] = userId;
        mp2[taskId] = priority;
    }

    void edit(int taskId, int newPriority)
    {
        int oldp = mp2[taskId];
        int user = mp1[{oldp, taskId}];
        mp1.erase({oldp, taskId});
        mp1[{newPriority, taskId}] = user;
        mp2[taskId] = newPriority;
    }

    void rmv(int taskId)
    {
        int pri = mp2[taskId];
        mp2.erase(taskId);
        mp1.erase({pri, taskId});
    }

    int execTop()
    {
        if (mp1.empty())
            return -1;
        auto it = mp1.begin();
        int taskId = it->first.second;
        int user = it->second;
        rmv(taskId);
        return user;
    }
};
