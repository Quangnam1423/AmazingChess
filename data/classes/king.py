import pygame
from data.classes.Piece import piece

class king(piece):
	def __init__(self , pos_piece , color , name):
		super().__init__(pos_piece , color , name)
		img_path = 'data/imgs/' + name + '.png'
		self.img = pygame.transform.scale(pygame.image.load(img_path) , (80 , 80))
		self.notation = 'k'

	def get_possible_move(self , board_config , squares):
		output = []
		moves = [
			(- 1 , -1) , (-1 , 0) , 
			(-1 , 1) , (0 , -1) , 
			(0 , 1) , (1 , -1) ,
			(1 , 0) , (1 , 1)
		]
		for move in moves:
			if self.pos[0] + move[0] > 7 or self.pos[0] + move[0] < 0 \
			or self.pos[1] + move[1] > 7 or self.pos[1] + move[1] < 0:
				continue
			if board_config[self.pos[0] + move[0]][self.pos[1] + move[1]][0] != self.color:
				output.append((self.pos[0] + move[0] , self.pos[1] + move[1]))
		Oput = []
		for pos in output:
			for square in squares:
				if square.pos == pos:
					Oput.append(square)
					break
		return Oput

	def can_castle(self , gs):
		output = []
		if self.has_move == True or gs.checkmate == True:
			return output
		else:
			x = self.pos[0]
			rook_left = gs.get_square_from_pos((x , 0))
			rook_right = gs.get_square_from_pos((x , 7))
			if rook_left.piece.notation == 'r' and rook_left.piece.has_move == False:
				lis = [gs.get_square_from_pos((x , i)) for i in range(2 , 4)]
				check = True
				for sq in lis:
					if any(i.pos == sq.pos for i in gs.can_check_mate):
						check = False
					if sq.piece != None:
						check = False
				if check:	
					output.append(gs.get_square_from_pos((x , 2)))

			if rook_left.piece.notation == 'r' and rook_left.piece.has_move == False:
				lis = [gs.get_square_from_pos((x , i)) for i in range(5 , 7)]
				check = True
				for sq in lis:
					if any(i.pos == sq.pos for i in gs.can_check_mate):
						check == False
					if sq.piece != None:
						check = False
				if check:	
					output.append(gs.get_square_from_pos((x , 6)))
		return output
