/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2014 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2015 - Daniel De Matteis
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __RARCH_CHEEVOS_H
#define __RARCH_CHEEVOS_H

typedef struct
{
  unsigned char enable;
  unsigned char test_unofficial;
  const char*   username;
  const char*   password;
  /* These are used by the implementation, do not touch. */
  char          token[ 20 ];
  unsigned      game_id;
}
cheevos_config_t;

enum
{
  CHEEVOS_FLAGS_IS_SNES = 1 << 0, /* forces * mb padded with zeroes */
};

extern cheevos_config_t cheevos_config;

int  cheevos_load( const char* json );
void cheevos_test( void );
void cheevos_unload( void );
int  cheevos_get_by_game_id( const char** json, unsigned game_id );
int  cheevos_get_by_content( const char** json, const void* data, size_t size, unsigned flags );

#endif /* __RARCH_CHEEVOS_H */
