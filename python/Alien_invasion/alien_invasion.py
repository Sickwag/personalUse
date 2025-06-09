import pygame
from pygame.sprite import Group
from settings import Settings
from ship import Ship
import game_functions as gf
from scoreboard import Scoreboard
from game_stats import GameStats
from button import Button


def run_game():
    pygame.init()
    pygame.display.set_caption("Alien Invasion")

    ai_settings = Settings()
    screen = pygame.display.set_mode(
        (ai_settings.screen_width, ai_settings.screen_height)
    )

    play_button = Button(ai_settings, screen, "Play")
    ship = Ship(ai_settings=ai_settings, screen=screen)
    scoreboard = Scoreboard(screen)
    stats = GameStats(ai_settings=ai_settings)

    bullets = Group()
    aliens = Group()

    gf.create_fleet(ai_settings, screen, ship, aliens=aliens)

    # main loop
    while True:
        gf.check_events(
            ai_settings,
            screen,
            stats,
            play_button,
            ship,
            aliens,
            bullets,
            scoreboard=scoreboard,
        )
        ship.update()
        gf.update_bullets(ai_settings, screen, ship, aliens, bullets, scoreboard)
        gf.update_screen(
            ai_settings, screen, stats, ship, aliens, bullets, scoreboard, play_button
        )
        gf.check_bullet_alien_collision(
            ai_settings, screen, ship, aliens, bullets, scoreboard
        )
        if stats.game_active:
            gf.update_aliens(ai_settings, stats, screen, ship, aliens, bullets)


run_game()
