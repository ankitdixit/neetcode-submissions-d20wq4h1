
from collections import deque
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        dependents :dict[int, list[int]] = {i:[] for i in range(numCourses)}
        indegree  :dict[int, int] = {i:0 for i in range(numCourses)}
        
        for dep in prerequisites:
            dependents[dep[1]].append(dep[0])
            indegree[dep[0]] += 1

        candidates = deque(i for i in range(numCourses) if indegree[i] == 0)
        
        final_order = []
        
        while candidates:
            popped = candidates.popleft()
            for dependent in dependents[popped]:
                indegree[dependent] -= 1
                if indegree[dependent] == 0:
                    candidates.append(dependent)
            final_order.append(popped)
        
        if len(final_order) != numCourses:
            return []
        return final_order

        