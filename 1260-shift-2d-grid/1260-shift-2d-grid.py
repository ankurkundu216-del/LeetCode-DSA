class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        total = m*n
        k %= total

        res = [[0]*n for _ in range(m)]

        for r in range(m):
            for c in range(n):
                old_index = r*n+c
                
                new_index = (old_index+k)%total

                new_r = new_index // n;
                new_c = new_index % n

                res[new_r][new_c] = grid[r][c]
                
        return res