class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        first_row_sum = sum(grid[0])
        second_row_sum = 0
        minimum_sum = float("inf")
        for turn_index in range(len(grid[0])):
            first_row_sum -= grid[0][turn_index]
            # Find the minimum maximum value out of first_row_sum and
            # second_row_sum.
            minimum_sum = min(minimum_sum, max(first_row_sum, second_row_sum))
            second_row_sum += grid[1][turn_index]
        return minimum_sum