# Define the board and pieces using Unicode characters for simplicity
board = [
    ["♜", "♞", "♝", "♛", "♚", "♝", "♞", "♜"],
    ["♟", "♟", "♟", "♟", "♟", "♟", "♟", "♟"],
    ["⬤", "⬤", "⬤", "⬤", "⬤", "⬤", "⬤", "⬤"],
    ["⬡", "⬡", "⬡", "⬡", "⬡", "⬡", "⬡", "⬡"],
    ["⬣", "⬣", "⬣", "♕", "♔", "♗", "⬣", "⬣"],
    ["⬣", "⬣", "⬣", "♖", "♘", "♗", "⬣", "⬣"],
    ["⬤", "⬤", "⬤", "⬤", "⬤", "⬤", "⬤", "⬤"],
    ["♝", "♞", "♝", "♛", "♚", "♝", "♞", "♜"]
]

white_pieces = ['♖', '♘', '♗', '♕', '♔', '♗', '♘', '♖']
black_pieces = ['⬤', '⬤', '⬤', '⬤', '⬤', '⬤', '⬤', '⬤']

# Initialize the game state
captured_white = 0
captured_black = 0
current_color = 'white'
king_white = True
king_black = True

def print_board():
    for row in board:
        print(" ".join(row))

def get_piece_color(piece):
    if piece in white_pieces:
        return 'white'
    elif piece in black_pieces:
        return 'black'
    else:
        return None

def is_valid_move(start, end, piece_type):
    # Basic move validation (can be expanded for more complex rules)
    start_row, start_col = start
    end_row, end_col = end
    
    if piece_type == '♟':
        if get_piece_color(piece) == 'white':
            direction = -1
        else:
            direction = 1
        
        # Pawn can move forward one square
        if abs(end_col - start_col) > 1:
            return False
        # Can move two squares on first move
        if end_row - start_row == 2 and (end_col - start_col == 0 or end_col - start_col == 1):
            return True
        # Regular movement
        return (end_row - start_row) == direction * 1
        
    elif piece_type == '♜':
        # Rook moves in straight lines
        if start_row != end_row and start_col != end_col:
            return False
        return True
    
    elif piece_type == '♞':
        # Knight moves in L-shape
        delta_row = abs(end_row - start_row)
        delta_col = abs(end_col - start_col)
        return (delta_row == 2 and delta_col == 1) or (delta_row == 1 and delta_col == 2)
    
    elif piece_type == '♝':
        # Bishop moves diagonally any number of squares
        if start_row != end_row and start_col != end_col:
            return False
        return True
    
    elif piece_type == '♛':
        # Queen moves like rook or bishop
        if start_row != end_row and start_col != end_col:
            return False
        return True
    
    elif piece_type == '♚':
        # King moves one square in any direction
        delta_row = abs(end_row - start_row)
        delta_col = abs(end_col - start_col)
        return delta_row <= 1 and delta_col <= 1
    
    else:
        return False

def move_piece(start, end):
    piece = board[start[0]][start[1]]  # Ensure 'piece' is defined here
    if piece == None:  # Check if the position is valid and contains a piece
        return False
    
    # Check if the target square is occupied by a friendly piece
    target_piece = board[end[0]][end[1]]
    if get_piece_color(target_piece) == get_piece_color(current_color):
        return False
    
    # Check if the move is valid
    piece_type = piece
    if not is_valid_move(start, end, piece_type):
        return False
    
    # Handle pawn promotion (simplistic implementation)
    if piece == '♟':
        promoting_to = {'white': '♔', 'black': '♚'}
        promoted_piece = promoting_to[get_piece_color(piece)]
        board[end[0]][end[1]] = promoted_piece
        captured_white += 1 if promoted_piece in white_pieces else 0
        captured_black += 1 if promoted_piece in black_pieces else 0
        
    # Move the piece
    board[end[0]][end[1]] = piece
    board[start[0]][start[1]] = None
    
    # Check for king capture (simplistic check)
    if piece_type == '♔' and target_piece != None:
        captured_white += 1 if get_piece_color(target_piece) == 'white' else 0
        return False
    
    # Switch colors
    global current_color
    if current_color == 'white':
        current_color = 'black'
    else:
        current_color = 'white'
    
    return True

def is_game_over():
    if not king_white or not king_black:
        return True
    if (current_color == 'white' and len([cell for row in board for cell in row if cell in white_pieces]) < 1) or \
       (current_color == 'black' and len([cell for row in board for cell in row if cell in black_pieces]) < 1):
        return True
    return False

# Game loop
game_over = False
while not game_over:
    print_board()
    
    # Get current player's pieces
    start_pos = None
    end_pos = None
    piece_to_move = None
    for i in range(8):
        for j in range(8):
            if board[i][j] != None and get_piece_color(board[i][j]) == current_color:
                if start_pos is None:
                    start_pos = (i, j)
                    piece_to_move = board[i][j]
                else:
                    end_pos = (i, j)
    
    # If no pieces to move, check for game over
    if start_pos is None and not is_game_over():
        print("Stalemate! You have no moves.")
        break
    
    if move_piece(start_pos, end_pos):
        continue
    else:
        print("Invalid move. Try again.")
    
    if is_game_over():
        print("Game Over!")
        break

# Example of how to end the game (if needed)
# print("Checkmate! White wins!")