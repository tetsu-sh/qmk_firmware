BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = no
AUDIO_ENABLE = no
MOUSEKEY_ENABLE = yes
TRACK_BALL_ENABLE = yes
POINTING_DEVICE_ENABLE = no
PIMORONI_TRACKBALL_ENABLE = yes
POINTING_DEVICE_DRIVER = pimoroni_trackball
# SRC += pimoroni_trackball.c
# SPLIT_KEYBOARD = yes

# ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
#     # SRC += pimoroni_trackball.c
#     POINTING_DEVICE_ENABLE := yes
# endif