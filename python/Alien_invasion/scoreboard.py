import pygame


class Scoreboard:
    def __init__(self, screen):
        self.screen = screen
        self.screen_rect = screen.get_rect()

        self.text_color = (0, 0, 0)  # black
        self.font = pygame.font.SysFont(None, 36)
        self.score = 0
        self.shots_fired = 0
        self.hits = 0

        self.prep_score()
        self.prep_accuracy()

    def prep_score(self):
        """rendering text to image"""
        score_str = f"Score : {self.score}"
        self.score_image = self.font.render(score_str, True, self.text_color)
        self.score_rect = self.score_image.get_rect()
        self.score_rect.right = self.screen_rect.right - 20
        self.score_rect.top = 20

    def prep_accuracy(self):
        accuracy = 0 if self.shots_fired == 0 else (self.hits / self.shots_fired) * 100
        accuracy_str = f"Accuracy : {accuracy:.2f} %"
        self.accuracy_image = self.font.render(accuracy_str, True, self.text_color)
        self.accuracy_rect = self.accuracy_image.get_rect()
        self.accuracy_rect.right = self.screen_rect.right - 20
        self.accuracy_rect.top = self.score_rect.bottom + 10

    def update(self):
        """update scoreboard""" 
        self.prep_accuracy()
        self.prep_score()

    def draw(self):
        self.screen.blit(self.score_image, self.score_rect)
        self.screen.blit(self.accuracy_image, self.accuracy_rect)
