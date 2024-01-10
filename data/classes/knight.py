import pygame
from data.classes.Piece import piece

class knight(piece):
	def __init__(self , pos_piece , color , name):
		super().__init__(pos_piece , color , name)
		img_path = 'data/imgs/' + name + '.png'
		self.img = pygame.transform.scale(pygame.image.load(img_path) , (80 , 80))
		self.notation = 'n'

	def get_possible_move(self , board_config , squares):
		output = []
		moves = [
			(-1 , -2),
			(-2 , -1),
			(-2 , 1),
			(-1 , 2),
			(1 , 2),
			(2 , 1),
			(2 , -1),
			(1 , -2)
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
