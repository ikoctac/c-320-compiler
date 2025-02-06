class ChessGame:
    def __init__(self):
        self.board = self.create_board()
        self.current_player = 'w'

    def create_board(self):
        # Initialize the board with pieces in starting positions
        return [
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

    def is_valid_move(self, start_pos, end_pos):
        # Basic move validation
        sx, sy = start_pos
        ex, ey = end_pos

        piece = self.board[sx][sy]
        if piece == '.':
            return False

        # Check if the player is moving their own piece
        if (self.current_player == 'w' and piece.islower()) or (self.current_player == 'b' and piece.isupper()):
            return False

        # Simple pawn move validation
        if piece.lower() == 'p':
            direction = -1 if self.current_player == 'w' else 1
            if ex == sx + direction and ey == sy and self.board[ex][ey] == '.':
                return True
            elif ex == sx + direction and abs(ey - sy) == 1 and self.board[ex][ey] != '.':
                return True

        # Simple rook move validation
        if piece.lower() == 'r':
            if sx == ex or sy == ey:
                return True

        # Simple knight move validation
        if piece.lower() == 'n':
            if abs(sx - ex) == 2 and abs(sy - ey) == 1 or abs(sx - ex) == 1 and abs(sy - ey) == 2:
                return True

        # Simple bishop move validation
        if piece.lower() == 'b':
            if abs(sx - ex) == abs(sy - ey):
                return True

        # Simple queen move validation
        if piece.lower() == 'q':
            if sx == ex or sy == ey or abs(sx - ex) == abs(sy - ey):
                return True

        # Simple king move validation
        if piece.lower() == 'k':
            if abs(sx - ex) <= 1 and abs(sy - ey) <= 1:
                return True

        return False

    def move_piece(self, start_pos, end_pos):
        sx, sy = start_pos
        ex, ey = end_pos

        piece = self.board[sx][sy]
        if not self.is_valid_move(start_pos, end_pos):
            print("Invalid move!")
            return

        self.board[ex][ey] = piece
        self.board[sx][sy] = '.'
        self.current_player = 'b' if self.current_player == 'w' else 'w'

    def play(self):
        while True:
            self.print_board()
            print(f"Player {self.current_player}'s turn")
            move = input("Enter your move (e.g., e2 e4): ")
            if move.lower() in ['exit', 'quit']:
                break

            start_pos, end_pos = move.split()
            sx, sy = 8 - int(start_pos[1]), ord(start_pos[0]) - ord('a')
            ex, ey = 8 - int(end_pos[1]), ord(end_pos[0]) - ord('a')

            self.move_piece((sx, sy), (ex, ey))

if __name__ == "__main__":
    game = ChessGame()
    game.play()