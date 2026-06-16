import bisect


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        print("hello")
        if not matrix or not matrix[0]:
            return False
        first_elems = [row[0] for row in matrix]
        row_idx = bisect.bisect_right(first_elems, target) - 1
        print("row_idx :", row_idx)
        if row_idx > len(matrix):
            return False

        col_idx = bisect.bisect_right(matrix[row_idx], target) - 1
        return (
            True
            if (col_idx < len(matrix[row_idx]) and matrix[row_idx][col_idx] == target)
            else False
        )
