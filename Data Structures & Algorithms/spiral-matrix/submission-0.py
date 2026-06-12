class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        directions = [(0, 1),(1,0),(0,-1), (-1, 0)]
        left , right, top, bottom = 0,  n -1, 0, m-1
        x , y = 0, 0
        res = []
        dir = 0
        while((left <= right) and (top <= bottom)):
            res.append(matrix[x][y])
            print("printing: " + str(matrix[x][y]))
            new_x = x + directions[dir][0] 
            new_y = y + directions[dir][1]
            print (new_x, new_y, left, right, top, bottom)
            if ((new_x < top) | (new_x > bottom) | (new_y < left) | (new_y > right)):  
                print ("dir change")
                if dir == 0:
                    top += 1
                elif dir == 1:
                    right -= 1
                elif dir == 2:
                    bottom -= 1
                elif dir == 3:
                    left += 1
                dir = (dir +1) %4;
                
                    
            print ("dir is: " + str(dir))
            x += directions[dir][0] 
            y += directions[dir][1]
            print ("x: " + str(x), "y: " + str(y))
        return res
                
