import pygame

class square():
	def __init__(self , x , y):
		self.piece = None
		self.pos = (x , y)
		self.x = x
		self.y = y
		self.size = 80
		self.abs_x = y * 80 + 300
		self.abs_y = x * 80

		self.rect = pygame.Rect(
			self.abs_x,
			self.abs_y,
			self.size - 5,
			self.size - 5
		)
		self.rect.center = self.abs_x + 40 , self.abs_y + 40
		self.highlight = False
		self.highlight_color = (91 , 175 , 82)
		self.coord = self.get_coord()
		self.click = False
		self.attacked = False
		self.attacked_color = (230 , 20 , 0)

	def get_coord(self):
		columns = 'abcdefgh'
		return columns[self.pos[0]] + str(self.pos[1] + 1)

	def check_collidepoint(self , e_pos):
		if self.rect.collidepoint(e_pos):
			return True
		return False

	def draw(self , display):
		if self.attacked == True:
			pygame.draw.rect(display , self.attacked_color , self.rect)
		elif self.highlight == True:
			pygame.draw.rect(display , self.highlight_color , self.rect)
		if self.piece != None and not self.click:
			self.piece.draw(display)
