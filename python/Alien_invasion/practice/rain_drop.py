import pygame
import sys
from pygame.sprite import Sprite

class Settings():

    def __init__(self):
        self.screen_width = 1200
        self.screen_height = 800
        self.bg_color = (230,230,230)
        self.rain_drop_speed = 1
         
class Rain_drop(Sprite):

    def __init__(self, screen,):
        super().__init__()
        self.rain_drop_image = pygame.image.load("python\\Alien_invasion\\images\\rain_drop.png")
        self.rain_rect = self.rain_drop_image.get_rect()
        self.screen = screen

    def draw(self):
        self.screen.blit(self.rain_drop_image, self.rain_rect)

class Game_functions():

    def __init__(self, screen, settings, bg_color):
        self.screen = screen
        self.settings = settings
        self.bg_color = bg_color

    def update_screen(self):
        self.screen.fill(self.settings, self.bg_color)
        pygame.display.flip()


def rain_drop():
    pygame.init()
    pygame.display.set_caption("rain drop")
    settings = Settings()
    screen = pygame.display.set_mode((settings.screen_width,settings.screen_height))
    gf = Game_functions(screen,settings,settings.bg_color)
    while True:
        gf.update_screen()
        command = input("press any key to exit")
        if command:
            sys.exit()

rain_drop()