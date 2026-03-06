#!/usr/bin/python3
import sys

def is_safe(positions, row, col):
    """
    Vérifie si on peut placer une reine à (row, col)
    sans qu'elle attaque les reines déjà placées
    """
    for position in positions:
        prev_row = position[0]
        prev_col = position[1]

        if prev_col == col:
            return False
        if row - col == prev_row - prev_col:
            return False
        if row + col == prev_row + prev_col:
            return False
    return True


def solve_nqueens(row, positions, N):
    """
    Essaie de placer une reine à la ligne 'row'
    positions contient les reines déjà placées
    """
    if row == N:
        print(positions)
        return

    for col in range(N):
        if is_safe(positions, row, col):
            positions.append([row, col])
            solve_nqueens(row + 1, positions, N)
            positions.pop()


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)

    if N < 4:
        print("N must be at least 4")
        exit(1)

    solve_nqueens(0, [], N)