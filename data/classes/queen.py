import pygame
from data.classes.Piece import piece

class queen(piece):
	def __init__(self , pos_piece , color , name):
		super().__init__(pos_piece , color , name)
		img_path = 'data/imgs/' + name + '.png'
		self.img = pygame.transform.scale(pygame.image.load(img_path) , (80 , 80))
		self.notation = 'q'

	def get_possible_move(self , board_config , squares):
		output = []
		for i in range(1 , 8):
			if self.pos[0] - i < 0 or self.pos[1] + i > 7:
				break
			if board_config[self.pos[0] - i][self.pos[1] + i][0] != self.color:
				output.append((self.pos[0] - i , self.pos[1] + i))
			if board_config[self.pos[0] - i][self.pos[1] + i] != '--':
				break

		for i in range(1 , 8):
			if self.pos[0] - i < 0 or self.pos[1] - i < 0:
				break
			if board_config[self.pos[0] - i][self.pos[1] - i][0] != self.color:
				output.append((self.pos[0] - i , self.pos[1] - i))
			if board_config[self.pos[0] - i][self.pos[1] - i] != '--':
				break

		for i in range(1 , 8):
			if self.pos[0] + i > 7 or self.pos[1] - i < 0:
				break
			if board_config[self.pos[0] + i][self.pos[1] - i][0] != self.color:
				output.append((self.pos[0] + i , self.pos[1] - i))
			if board_config[self.pos[0] + i][self.pos[1] - i] != '--':
				break

		for i in range(1 , 8):
			if self.pos[0] + i > 7 or self.pos[1] + i > 7:
				break
			if board_config[self.pos[0] + i][self.pos[1] + i][0] != self.color:
				output.append((self.pos[0] + i , self.pos[1] + i))
			if board_config[self.pos[0] + i][self.pos[1] + i] != '--':
				break

		for i in range(1 , 8):
			if self.pos[0] + i > 7:
				break
			if board_config[self.pos[0] + i][self.pos[1]][0] != self.color:
				output.append((self.pos[0] + i , self.pos[1]))
			if board_config[self.pos[0] + i][self.pos[1]] != '--':
				break

		for i in range(1 , 8):
			if self.pos[0] - i < 0:
				break
			if board_config[self.pos[0] - i][self.pos[1]][0] != self.color:
				output.append((self.pos[0] - i , self.pos[1]))
			if board_config[self.pos[0] - i][self.pos[1]] != '--':
				break

		for i in range(1 , 8):
			if self.pos[1] + i > 7:
				break
			if board_config[self.pos[0]][self.pos[1] + i][0] != self.color:
				output.append((self.pos[0] , self.pos[1] + i))
			if board_config[self.pos[0]][self.pos[1] + i] != '--':
				break


		for i in range(1 , 8):
			if self.pos[1] - i < 0:
				break	
			if board_config[self.pos[0]][self.pos[1] - i][0] != self.color:
				output.append((self.pos[0] , self.pos[1] - i))
			if board_config[self.pos[0]][self.pos[1] - i] != '--':
				break

		Oput = []
		for pos in output:
			for square in squares:
				if square.pos == pos:
					Oput.append(square)
					break

		return Oput