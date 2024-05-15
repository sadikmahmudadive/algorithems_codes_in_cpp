//---------------------------------------------WELCOME to SocialNetConnect Project------------------------------------------------------//
//Project of Algorithm
//By group-1

//All the lib func here
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

// Simple Graph class to manage users and their friendships
class Graph
{
private:
    // Vector of vectors to store adjacency list
    vector<vector<int>> adjList;
    // Vector to store usernames
    vector<string> usernames;

    // Helper function to get the index of a user
    int getUserIndex(const string& user) 
    {
        for (int i = 0; i < usernames.size(); i++) 
        {
            if (usernames[i] == user) 
            {
                return i;
            }
        }
        return -1;
    }

public:
    // Add a new user to the graph
    void addUser(const string& user) 
    {
        usernames.push_back(user);
        adjList.push_back(vector<int>());
    }

    // Add a friendship (edge) between two users
    void addFriendship(const string& user, const string& friendUser) 
    {
        int userIndex = getUserIndex(user);
        int friendUserIndex = getUserIndex(friendUser);

        if (userIndex != -1 && friendUserIndex != -1) 
        {
            adjList[userIndex].push_back(friendUserIndex);
            adjList[friendUserIndex].push_back(userIndex);
        }
    }

    // Perform BFS traversal from a given starting user
    void BFS(const string& startUser) 
    {
        int startIndex = getUserIndex(startUser);
        if (startIndex == -1) return;

        vector<bool> visited(usernames.size(), false);
        queue<int> q;

        visited[startIndex] = true;
        q.push(startIndex);

        while (!q.empty()) {
            int userIndex = q.front();
            q.pop();
            cout << usernames[userIndex] << " ";

            for (int i = 0; i < adjList[userIndex].size(); i++) {
                int friendIndex = adjList[userIndex][i];
                if (!visited[friendIndex]) {
                    visited[friendIndex] = true;
                    q.push(friendIndex);
                }
            }
        }
        cout << endl;
    }

    // Perform DFS traversal from a given starting user
    void DFS(const string& startUser) {
        int startIndex = getUserIndex(startUser);
        if (startIndex == -1) return;

        vector<bool> visited(usernames.size(), false);
        stack<int> s;

        s.push(startIndex);

        while (!s.empty()) {
            int userIndex = s.top();
            s.pop();

            if (!visited[userIndex]) {
                visited[userIndex] = true;
                cout << usernames[userIndex] << " ";
            }

            for (int i = 0; i < adjList[userIndex].size(); i++) {
                int friendIndex = adjList[userIndex][i];
                if (!visited[friendIndex]) {
                    s.push(friendIndex);
                }
            }
        }
        cout << endl;
    }

    // Suggest friends for a user based on BFS
    vector<string> suggestFriends(const string& user) {
        vector<string> suggestions;
        int userIndex = getUserIndex(user);
        if (userIndex == -1) return suggestions;

        vector<bool> visited(usernames.size(), false);
        queue<int> q;

        visited[userIndex] = true;
        q.push(userIndex);

        while (!q.empty()) {
            int currentIndex = q.front();
            q.pop();

            for (int i = 0; i < adjList[currentIndex].size(); i++) {
                int friendIndex = adjList[currentIndex][i];
                if (!visited[friendIndex]) {
                    visited[friendIndex] = true;
                    suggestions.push_back(usernames[friendIndex]);
                    q.push(friendIndex);
                }
            }
        }

        return suggestions;
    }
};

int main() {
    Graph socialGraph;
    int numUsers;

    cout << "Enter the number of users: ";
    cin >> numUsers;

    // Add users to the graph
    for (int i = 0; i < numUsers; ++i) {
        string userName;
        cout << "Enter username: ";
        cin >> userName;
        socialGraph.addUser(userName);

        int numFriends;
        cout << "Enter the number of friends for " << userName << ": ";
        cin >> numFriends;

        // Add friendships to the graph
        for (int j = 0; j < numFriends; ++j) {
            string friendName;
            cout << "Enter friend's username: ";
            cin >> friendName;
            socialGraph.addFriendship(userName, friendName);
        }
    }

    // Prompt user to enter a username for friend suggestions
    string startUser;
    cout << "Enter a username to get friend suggestions: ";
    cin >> startUser;

    // Perform BFS and DFS traversals from the starting user
    cout << "BFS starting from " << startUser << ": ";
    socialGraph.BFS(startUser);

    cout << "DFS starting from " << startUser << ": ";
    socialGraph.DFS(startUser);

    // Suggest friends for the starting user
    vector<string> suggestions = socialGraph.suggestFriends(startUser);
    cout << "Friend suggestions for " << startUser << ": ";
    for (const auto& suggestion : suggestions) {
        cout << suggestion << " ";
    }
    cout << endl;

    return 0;
}
