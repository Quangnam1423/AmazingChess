import pygame
from data.classes.Piece import piece

class pawn(piece):
	def __init__(self , pos_piece , color , name):
		super().__init__(pos_piece , color , name)
		img_path = 'data/imgs/' + name + '.png'
		self.img = pygame.transform.scale(pygame.image.load(img_path) , (80 , 80))
		self.notation = 'p'

	def get_possible_move(self , board_config , squares):
		output = []
		if self.color == 'w':
			if board_config[self.pos[0] - 1][self.pos[1]] == '--' and self.pos[0] - 1 >= 0:
				output.append((self.pos[0] - 1 , self.pos[1]))
			if self.has_move == False:
				if board_config[self.pos[0] - 2][self.pos[1]] == '--'and self.pos[0] - 1 >= 0:
					output.append((self.pos[0] - 2 , self.pos[1]))
			if self.pos[0] - 1 >= 0 and self.pos[1] - 1 >= 0 and board_config[self.pos[0] - 1][self.pos[1] - 1][0] == 'b':
				output.append((self.pos[0] - 1 , self.pos[1] - 1)) 
			if self.pos[0] - 1 >= 0 and self.pos[1] + 1 <= 7 and board_config[self.pos[0] - 1][self.pos[1] + 1][0] == 'b':
				output.append((self.pos[0] - 1 , self.pos[1] + 1)) 
		else:
			if board_config[self.pos[0] + 1][self.pos[1]] == '--' and self.pos[0] + 1 <= 7:
				output.append((self.pos[0] + 1 , self.pos[1]))
			if self.has_move == False:
				if board_config[self.pos[0] + 2][self.pos[1]] == '--'and self.pos[0] - 1 <= 7:
					output.append((self.pos[0] + 2 , self.pos[1]))
			if self.pos[0] + 1 <= 7 and self.pos[1] - 1 >= 0 and board_config[self.pos[0] + 1][self.pos[1] - 1][0] == 'w':
				output.append((self.pos[0] + 1 , self.pos[1] - 1)) 
			if self.pos[0] + 1 <= 7 and self.pos[1] + 1 <= 7 and board_config[self.pos[0] + 1][self.pos[1] + 1][0] == 'w':
				output.append((self.pos[0] + 1 , self.pos[1] + 1)) 
		Oput = []
		for pos in output:
			for square in squares:
				if square.pos == pos:
					Oput.append(square)
					break
		return Oput