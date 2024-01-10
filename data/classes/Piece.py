import pygame

class piece():
	def __init__(self , pos , color , name):
		self.pos = pos
		self.color = color
		self.name = name
		self.highlight = False
		self.highlight_color = (124 , 0 , 100)
		self.has_move = False


	def draw(self , display):
		display.blit(self.img , (self.pos[1] * 80 + 300, self.pos[0] * 80))