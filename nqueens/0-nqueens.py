#!/usr/bin/python3
import sys


def is_safe(board, row, col, N):
    """
    Check if it's safe to place a queen at the given position.

    Args:
        board (list): The chessboard represented as a 2D list.
        row (int): The row index to check.
        col (int): The column index to check.
        N (int): The size of the chessboard.

    Returns:
        bool: True if it's safe to place a queen, False otherwise.
    """
    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, N), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solve_nqueens_util(board, col, N, solutions):
    """
    Recursive utility function to solve the N-Queens problem.

    Args:
        board (list): The chessboard represented as a 2D list.
        col (int): The current column index.
        N (int): The size of the chessboard.
        solutions (list): A list to store the found solutions.

    Returns:
        bool: True if a solution is found, False otherwise.
    """
    if col >= N:
        solution = []
        for i in range(N):
            for j in range(N):
                if board[i][j] == 1:
                    solution.append([i, j])
        solutions.append(solution)
        return True

    res = False
    for i in range(N):
        if is_safe(board, i, col, N):
            board[i][col] = 1

            res = solve_nqueens_util(board, col + 1, N, solutions) or res

            board[i][col] = 0

    return res


def solve_nqueens(N):
    """
    Solve the N-Queens problem and print all solutions.

    Args:
        N (int): The size of the chessboard and the number of queens.

    Returns:
        None
    """
    if N < 4:
        return ("N must be at least 4")

    board = [[0 for _ in range(N)] for _ in range(N)]

    solutions = []

    solve_nqueens_util(board, 0, N, solutions)

    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
        solve_nqueens(N)
    except ValueError:
        print("N must be a number")
        sys.exit(1)
