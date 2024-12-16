## Classes

### Parent class: ChessPiece

#### Shared Attributes:

- char color: 'w' | 'b'
- string icon: // From global struct icons
- char type: 'k' | 'q' | 'r' | 'b' | 'n' | 'p'
- int rank: 0-7
- int file: 0-7
- int value: 1 | 3 | 5 | 9
- bool isWhite
- bool isAlive: true
- list[set(int,int)] startPos: [(file,rank)]
- list[set(int,int)] validMoves: [(file,rank)]

#### Shared Methods:

- virtual list[set[int,int]] FindValidMoves()
- void MoveTo(file, rank)
- void MoveTo(filerank)
- void Die()

### Child piece classes:

- King
  - bool hasCastled: false
- Queen
- Rook
- Bishop
- Knight
- Pawn
  - bool canEnPassant: false

### Game/Board class

#### Attributes:

- list[list[Piece]] board: list[file[rank]]
- bool isWhiteTurn: true
- int turnNumber

#### Methods:

- string getUserMove
