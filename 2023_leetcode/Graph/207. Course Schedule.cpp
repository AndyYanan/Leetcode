class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Initialize a graph to represent courses and their dependencies.
        vector<vector<int>> courseGraph(numCourses, vector<int>());
        
        // Create an array to keep track of the number of prerequisites for each course.
        vector<int> prerequisitesCount(numCourses, 0);
        
        // Build the course graph and count prerequisites.
        for(auto &dependency : prerequisites){
            int course = dependency[0];
            int prerequisite = dependency[1];
            
            // Add the prerequisite to the course's list of dependencies.
            courseGraph[prerequisite].push_back(course);
            
            // Increment the prerequisite count for the course.
            prerequisitesCount[course]++;
        }
        
        // Initialize a queue to perform topological sorting.
        queue<int> courseQueue;
        
        // Add courses with no prerequisites to the queue.
        for(int i = 0; i < numCourses; ++i){
            if(prerequisitesCount[i] == 0){
                courseQueue.push(i);
            }
        }
        
        // Process courses and reduce prerequisites.
        while(!courseQueue.empty()){
            int course = courseQueue.front();
            courseQueue.pop();
            numCourses--;
            
            // Iterate through courses dependent on the current course.
            for(auto &dependentCourse : courseGraph[course]){
                prerequisitesCount[dependentCourse]--;
                
                // If the dependent course has no more prerequisites, add it to the queue.
                if(prerequisitesCount[dependentCourse] == 0){
                    courseQueue.push(dependentCourse);
                }
            }
        }
        
        // If all courses were taken (numCourses is 0), return true; otherwise, return false.
        return numCourses == 0;
    }
};
