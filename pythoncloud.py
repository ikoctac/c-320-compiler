class ChessBoard:
    def __init__(self):
        # Initialize the board with pieces
        self.board = [
            ['r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'],
            ['p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'],
            ['.', '.', '.', '.', '.', '.', '.', '.'],
            ['.', '.', '.', '.', '.', '.', '.', '.'],
            ['.', '.', '.', '.', '.', '.', '.', '.'],
            ['.', '.', '.', '.', '.', '.', '.', '.'],
            ['P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'],
            ['R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R']
        ]

    def print_board(self):
        for row in self.board:
            print(' '.join(row))
        print()

    def move_piece(self, start_pos, end_pos):
        start_x, start_y = start_pos
        end_x, end_y = end_pos

        # Check if the start position has a piece
        if self.board[start_x][start_y] == '.':
            print("No piece at the start position.")
            return False

        # Move the piece
        self.board[end_x][end_y] = self.board[start_x][start_y]
        self.board[start_x][start_y] = '.'
        return True

def main():
    board = ChessBoard()
    board.print_board()

    while True:
        try:
            start_input = input("Enter the start position (e.g., e2): ")
            end_input = input("Enter the end position (e.g., e4): ")

            # Convert algebraic notation to board coordinates
            start_x = 8 - int(start_input[1])
            start_y = ord(start_input[0]) - ord('a')
            end_x = 8 - int(end_input[1])
            end_y = ord(end_input[0]) - ord('a')

            if not (0 <= start_x < 8 and 0 <= start_y < 8 and 0 <= end_x < 8 and 0 <= end_y < 8):
                print("Invalid position. Please enter positions in the format a1-h8.")
                continue

            if board.move_piece((start_x, start_y), (end_x, end_y)):
                board.print_board()
            else:
                continue

        except (IndexError, ValueError):
            print("Invalid input. Please enter positions in the format a1-h8.")

if __name__ == "__main__":
    main()