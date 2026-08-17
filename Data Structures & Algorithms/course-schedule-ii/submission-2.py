
from collections import deque
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        dependents :dict[int, list[int]] = defaultdict(list)
        indegree  :list[int] = [0] * numCourses
        
        for dep in prerequisites:
            dependents[dep[1]].append(dep[0])
            indegree[dep[0]] += 1
        queue = deque()
        for i, degree in enumerate(indegree):
            if degree == 0:
                queue.append(i)
        
        final_order = []
        
        while queue:
            popped = queue.popleft()
            final_order.append(popped)
            for dependent in dependents[popped]:
                indegree[dependent] -= 1
                if indegree[dependent] == 0:
                    queue.append(dependent)
            
        if len(final_order) != numCourses:
            return []
        return final_order

        