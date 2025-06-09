import pygame


class Ship:
    def __init__(self, ai_settings, screen):
        self.screen = screen
        self.ai_settings = ai_settings
        self.image = pygame.image.load("python\\Alien_invasion\\images\\ship.bmp")
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()
        # make every ship locate at the bottom of the screen
        self.rect.centerx = self.screen_rect.centerx
        self.rect.centery = self.screen_rect.centery
        self.rect.bottom = self.screen_rect.bottom
        self.centerx = float(self.rect.centerx)
        self.centery = float(self.rect.centery)

        self.moving_right = False
        self.moving_left = False
        self.moving_up = False
        self.moving_down = False

    def update(self):
        """adjust position base on the move flag"""
        if self.moving_right and self.rect.right < self.screen_rect.right:
            self.centerx += self.ai_settings.ship_speed_factor
        if self.moving_left and self.rect.left > 0:
            self.centerx -= self.ai_settings.ship_speed_factor
        if self.moving_down and self.rect.bottom < self.screen_rect.bottom:
            self.centery += self.ai_settings.ship_speed_factor
        if self.moving_up and self.rect.top > 0:
            self.centery -= self.ai_settings.ship_speed_factor
        self.rect.centerx = self.centerx
        self.rect.centery = self.centery

    def blitme(self):
        """draw ship image in the certain position"""
        self.screen.blit(self.image, self.rect)

    def center_ship(self):
        self.centerx = float(self.screen_rect.centerx)
        self.centery = float(self.screen_rect.bottom - self.rect.height // 2)

        self.rect.centerx = self.centerx
        self.rect.centery = self.centery

