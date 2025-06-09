import pygame
from pygame.sprite import Sprite

class Bullets(Sprite):
    """manage all bullets shoot out by ship"""
    def __init__(self, ai_settings, screen, ship):
        super(Bullets, self).__init__() # python 2.7
        # super().__init__() # python 3
        self.screen = screen

        # create a bullet in (0,0) and adjust more details  after then
        self.rect = pygame.Rect(0,0,ai_settings.bullet_width, ai_settings.bullet_height)
        self.rect.centerx = ship.rect.centerx
        self.rect.top = ship.rect.top

        # store position of bullet in floaty var y
        self.y = float(self.rect.y)
        self.color = ai_settings.bullet_color
        self.speed_factor = ai_settings.bullet_speed_factor

    def update(self):
        # manage a midden val instead of sub self.rect.y directly, same as movement code
        self.y -= self.speed_factor
        self.rect.y = self.y

    def draw_bullet(self):
        # draw a rect(self.rect) in self.screen, in self.color
        pygame.draw.rect(self.screen,self.color,self.rect)
