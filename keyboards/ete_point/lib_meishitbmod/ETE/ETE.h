/*
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)
Copyright 2023 kushima8 (@kushima8)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//////////////////////////////////////////////////////////////////////////////
// Configurations

#ifndef ETE_CPI_DEFAULT
#    define ETE_CPI_DEFAULT 500
#endif

#ifndef ETE_SCROLL_DIV_DEFAULT
#    define ETE_SCROLL_DIV_DEFAULT 4 // 4: 1/8 (1/2^(n-1))
#endif

#ifndef ETE_REPORTMOUSE_INTERVAL
#    define ETE_REPORTMOUSE_INTERVAL 8 // mouse report rate: 125Hz
#endif

#ifndef ETE_SCROLLBALL_INHIVITOR
#    define ETE_SCROLLBALL_INHIVITOR 50
#endif

#ifndef ETE_SCROLLSNAP_ENABLE
#    define ETE_SCROLLSNAP_ENABLE 1
#endif

#ifndef ETE_SCROLLSNAP_RESET_TIMER
#    define ETE_SCROLLSNAP_RESET_TIMER 100
#endif

#ifndef ETE_SCROLLSNAP_TENSION_THRESHOLD
#    define ETE_SCROLLSNAP_TENSION_THRESHOLD 12
#endif

//////////////////////////////////////////////////////////////////////////////
// Constants

#define ETE_TX_GETINFO_INTERVAL 500
#define ETE_TX_GETINFO_MAXTRY 10
#define ETE_TX_GETMOTION_INTERVAL 4


//////////////////////////////////////////////////////////////////////////////
// Types

enum ETE_keycodes {
    REC_RST  = QK_KB_0, // ETE configuration: reset to default
    REC_SAVE = QK_KB_1, // ETE configuration: save to EEPROM

    CPI_I100 = QK_KB_2, // CPI +100 CPI
    CPI_D100 = QK_KB_3, // CPI -100 CPI
    CPI_I1K  = QK_KB_4, // CPI +1000 CPI
    CPI_D1K  = QK_KB_5, // CPI -1000 CPI

    // In scroll mode, motion from primary trackball is treated as scroll
    // wheel.
    SCRL_TO  = QK_KB_6, // Toggle scroll mode
    SCRL_MO  = QK_KB_7, // Momentary scroll mode
    SCRL_DVI = QK_KB_8, // Increment scroll divider
    SCRL_DVD = QK_KB_9, // Decrement scroll divider

    // User customizable 32 keycodes.
    ETE_SAFE_RANGE = QK_KB_10,
};

typedef union {
    uint32_t raw;
    struct {
        uint8_t cpi : 7;
        uint8_t sdiv : 3; // scroll divider
    };
} ETE_config_t;

typedef struct {
    uint8_t ballcnt; // count of balls: support only 0 or 1, for now
} ETE_info_t;

typedef struct {
    int16_t x;
    int16_t y;
} ETE_motion_t;

typedef uint8_t ETE_cpi_t;

typedef struct {
    bool this_have_ball;
    bool that_enable;
    bool that_have_ball;
	bool negotiated;

    ETE_motion_t this_motion;
    ETE_motion_t that_motion;

    uint8_t cpi_value;
    bool    cpi_changed;

    bool     scroll_mode;
    uint32_t scroll_mode_changed;
    uint8_t  scroll_div;

    uint32_t scroll_snap_last;
    int8_t   scroll_snap_tension_h;

    uint16_t       last_kc;
    keypos_t       last_pos;
    report_mouse_t last_mouse;
} ETE_t;

typedef enum {
    ETE_ADJUST_PENDING   = 0,
    ETE_ADJUST_PRIMARY   = 1,
    ETE_ADJUST_SECONDARY = 2,
} ETE_adjust_t;

//////////////////////////////////////////////////////////////////////////////
// Exported values (touch carefully)

extern ETE_t ETE;

//////////////////////////////////////////////////////////////////////////////
// Public API functions

/// ETE_oled_render_ballinfo renders ball information to OLED.
/// It uses just 21 columns to show the info.
void ETE_oled_render_ballinfo(void);

/// ETE oled_render_keyinfo renders last processed key information to OLED.
/// It shows column, row, key code, and key name (if available).
void ETE_oled_render_keyinfo(void);

/// ETE oled_render_layerinfo renders current layer status information to OLED.
/// It shows layer mask with number (1~f) for active layers and '_' for inactive layers.
void ETE_oled_render_layerinfo(void);

/// ETE_get_scroll_mode gets current scroll mode.
bool ETE_get_scroll_mode(void);

/// ETE_set_scroll_mode modify scroll mode.
void ETE_set_scroll_mode(bool mode);

// TODO: document
uint8_t ETE_get_scroll_div(void);

// TODO: document
void ETE_set_scroll_div(uint8_t div);

// TODO: document
uint8_t ETE_get_cpi(void);

// TODO: document
void ETE_set_cpi(uint8_t cpi);
