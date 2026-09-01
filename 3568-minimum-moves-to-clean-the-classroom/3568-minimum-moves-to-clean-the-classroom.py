from collections import deque
from typing import List

class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:
        m, n = len(classroom), len(classroom[0])
        start_r = start_c = -1;
        litter_coords = []
        for r in range(m):
            for c in range(n):
                if classroom[r][c] == 'S':
                    start_r, start_c = r, c
                elif classroom[r][c] == 'L':
                    litter_coords.append((r, c))
        total_litter = len(litter_coords)
        if total_litter == 0:
            return 0
        litter_map = {coords: i for i, coords in enumerate(litter_coords)}
        initial_mask = (1<<total_litter)-1
        if(start_r, start_c) in litter_map:
            bit_idx = litter_map[(start_r, start_c)]
            initial_mask &= ~(1<<bit_idx)
        queue = deque([(start_r, start_c, energy, initial_mask, 0)])
        visited = set([(start_r, start_c, energy, initial_mask)])
        directions = [(-1,0),(1,0),(0,-1),(0,1)]
        while queue:
            r, c, curr_e, mask, moves = queue.popleft()
            if mask==0:
                return moves
            if curr_e==0:
                continue
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0<=nr<m and 0<=nc<n and classroom[nr][nc] != 'X':
                    cell_type=classroom[nr][nc]
                    next_e = energy if cell_type == 'R' else curr_e-1
                    next_mask = mask
                    if cell_type == 'L' and (nr, nc) in litter_map:
                        bit_idx = litter_map[(nr, nc)]
                        next_mask &= ~(1 << bit_idx)
                    state = (nr, nc, next_e, next_mask)
                    if state not in visited:
                        visited.add(state)
                        queue.append((nr, nc, next_e, next_mask, moves+1))
        return -1