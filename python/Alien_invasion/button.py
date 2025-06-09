import pygame.font

class Button():

    class Base_button():

        def __init__(self, ai_settings, screen, msg):
            self.screen = screen
            self.screen_rect = screen.get_rect()
            self.w idth, self.height = 200,50
            self.button_color = (0,255,0)
            self.text_color = (255,255,255)
            self.font = pygame.font.SysFont(None,48)

            self.rect = pygame.Rect(0,0,self.width,self.height)
            self.rect.center = self.screen_rect.center

            self.prep_msg(msg)

        def prep_msg(self, msg):
            self.msg_image = self.font.render(msg,True,self.text_color)
            self.msg_image_rect = self.msg_image.get_rect()
            self.msg_image_rect.center = self.rect.center # put msg in the center of button instead of the screen
    
        def draw_button(self):
            # render background behead text
            self.screen.fill(self.button_color,self.rect)
            self.screen.blit(self.msg_image, self.msg_image_rect)


    class Play_button(Base_button):

        def __init__(self, ai_settings, screen, msg="Play"):
            super().__init__(ai_settings,screen,msg)
    

    class Setting_button():
        
        def __init__(self,):
            
