import pygame
import sys
from bullet import Bullets
from alien import Alien
from random import randint
from scoreboard import Scoreboard
from time import sleep


def star_backgroud(ai_settings, screen, background):
    # clock = pygame.time.Clock()
    # running = True
    display_background = False
    if background and display_background:
        screen.blit(background, (0, 0))
    else:
        screen.fill((0, 0, 0))
        for _ in range(100):
            x = randint(0, ai_settings.screen_width)
            y = randint(0, ai_settings.screen_height)
            size = randint(1, 3)
            color = (255, 255, 255)
            pygame.draw.circle(screen, color, (x, y), size)


def check_keydown_events(event, ai_settings, screen, ship, bullets, scoreboard):
    if event.key == pygame.K_RIGHT:
        ship.moving_right = True
    elif event.key == pygame.K_LEFT:
        ship.moving_left = True
    elif event.key == pygame.K_UP:
        ship.moving_up = True
    elif event.key == pygame.K_DOWN:
        ship.moving_down = True
    elif event.key == pygame.K_SPACE:
        fire_bullet(
            ai_settings=ai_settings,
            screen=screen,
            ship=ship,
            bullets=bullets,
            scoreboard=scoreboard,
        )
    elif event.key == pygame.K_ESCAPE:
        sys.exit()


def check_play_button(
    ai_settings,
    screen,
    stats,
    play_button,
    ship,
    aliens,
    bullets,
    mouse_x,
    mouse_y,
    scoreboard,
):
    """make cursor invisible after click play button"""
    button_clicked = play_button.rect.collidepoint(mouse_x, mouse_y)
    if button_clicked and not stats.game_active:
        pygame.mouse.set_visible(False)
        stats.reset_stats()
        stats.game_active = True
        aliens.empty()
        bullets.empty()
        # make aliens and ship init
        create_fleet(ai_settings, screen, ship, aliens)
        ship.center_ship()
        scoreboard.hits, scoreboard.score, scoreboard.shots_fired = 0, 0, 0


def fire_bullet(ai_settings, screen, ship, bullets, scoreboard):
    if len(bullets) < ai_settings.bullets_allow:
        new_bullet = Bullets(ai_settings=ai_settings, screen=screen, ship=ship)
        bullets.add(new_bullet)
        scoreboard.shots_fired += 1
        scoreboard.update()
        scoreboard.draw()


def check_keyup_events(event, ship):
    if event.key == pygame.K_RIGHT:
        ship.moving_right = False
    elif event.key == pygame.K_LEFT:
        ship.moving_left = False
    elif event.key == pygame.K_UP:
        ship.moving_up = False
    elif event.key == pygame.K_DOWN:
        ship.moving_down = False


def check_events(
    ai_settings, screen, stats, play_button, ship, aliens, bullets, scoreboard
):
    """response for keyboard and mouse"""
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            check_keydown_events(
                event=event,
                ai_settings=ai_settings,
                screen=screen,
                ship=ship,
                bullets=bullets,
                scoreboard=scoreboard,
            )
        elif event.type == pygame.KEYUP:
            check_keyup_events(event=event, ship=ship)
        elif event.type == pygame.MOUSEBUTTONDOWN:
            mouse_x, mouse_y = pygame.mouse.get_pos()
            check_play_button(
                ai_settings,
                screen,
                stats,
                play_button,
                ship,
                aliens,
                bullets,
                mouse_x,
                mouse_y,
                scoreboard,
            )


def update_screen(
    ai_settings, screen, stats, ship, aliens, bullets, scoreboard, play_buttons
):
    screen.fill(ai_settings.bg_color)
    # background = pygame.image.load("python\\Alien_invasion\\images\\background.jpeg")
    # star_background(ai_settings,screen,background)
    for bullet in bullets.sprites():
        bullet.draw_bullet()
    if stats.game_active:
        ship.blitme()
        aliens.draw(screen)
        scoreboard.draw()
    else:
        play_buttons.draw_button()
    pygame.display.flip()


def update_bullets(ai_settings, screen, ship, aliens, bullets, scoreboard):
    bullets.update()
    for bullet in bullets.copy():
        if bullet.rect.bottom <= 0:
            bullets.remove(bullet)
    # print(f"activated bullet in screen : {len(bullets)}")


def check_bullet_alien_collision(
    ai_settings, screen, ship, aliens, bullets, scoreboard
):
    """response for collision events between bullets and aliens"""
    collisions = pygame.sprite.groupcollide(bullets, aliens, True, True)
    if collisions:
        for bullet, hit_aliens in collisions.items():
            scoreboard.hits += len(hit_aliens)
            scoreboard.score += len(hit_aliens)
        scoreboard.update()

    if len(aliens) == 0:
        # delete current magazine and create new fleet
        bullets.empty()
        create_fleet(ai_settings, screen, ship, aliens)


def get_number_alien_x(ai_settings, alien_width) -> int:
    available_space_x = ai_settings.screen_width - 2 * alien_width
    number_aliens_x = int(available_space_x / (2 * alien_width))
    return number_aliens_x


def get_number_row(ai_settings, ship_height, alien_height):
    available_space_y = ai_settings.screen_height - (3 * alien_height) - ship_height
    number_rows = int(available_space_y / (2 * alien_height))
    return number_rows


def create_alien(ai_settings, screen, aliens, alien_number, row_number):
    """create a alien and put in current row"""
    alien = Alien(ai_settings, screen)
    alien_width = alien.rect.width
    alien.x = alien_width + 2 * alien_width * alien_number
    alien.rect.x = alien.x
    alien.rect.y = alien.rect.height + 2 * alien.rect.height * row_number
    aliens.add(alien)


def create_fleet(ai_settings, screen, ship, aliens):
    alien = Alien(ai_settings, screen)
    number_alien_x = get_number_alien_x(ai_settings, alien.rect.width)
    number_rows = get_number_row(ai_settings, ship.rect.height, alien.rect.height)

    for row_number in range(number_rows):
        for alien_number in range(number_alien_x):
            create_alien(ai_settings, screen, aliens, alien_number, row_number)


def check_fleet_edges(ai_settings, aliens):
    for alien in aliens.sprites():
        if alien.check_edges():
            change_fleet_direction(ai_settings, aliens)
            break


def change_fleet_direction(ai_settings, aliens):
    for alien in aliens.sprites():
        alien.rect.y += ai_settings.fleet_drop_speed
    ai_settings.fleet_direction *= -1


def update_aliens(ai_settings, stats, screen, ship, aliens, bullets):
    """check up whether collision between alien and ship"""
    check_fleet_edges(ai_settings, aliens)
    aliens.update()
    if pygame.sprite.spritecollideany(ship, aliens):
        print("ship hit!")
        ship_hit(ai_settings, stats, screen, ship, aliens, bullets)


def ship_hit(ai_settings, stats, screen, ship, aliens, bullets):
    stats.ship_left -= 1
    aliens.empty()
    bullets.empty()
    create_fleet(ai_settings, screen, ship, aliens)
    sleep(1)

    ship.center_ship()
