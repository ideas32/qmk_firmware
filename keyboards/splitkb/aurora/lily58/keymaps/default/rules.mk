# Copyright 2022 splitkb.com <support@splitkb.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Although no rules are defined,
# presence of this file is required for QMK to compile it.

CONVERT_TO=rp2040_ce # liatris/other rp2040 boards
ENCODER_ENABLE = yes
RGB_MATRIX_ENABLE = no
BOOTMAGIC_ENABLE = yes
MAGIC_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes
NKRO_ENABLE = yes
LEADER_ENABLE = yes
UNICODE_ENABLE = yes
SPLIT_KEYBOARD = yes
DEFERRED_EXEC_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
RGBLIGHT_ENABLE = yes
OLED_ENABLE = yes     # Enables the use of OLED displays
OLED_DRIVER = SSD1306 # Selects the right driver
WS2812_DRIVER = vendor
SERIAL_DRIVER = vendor
