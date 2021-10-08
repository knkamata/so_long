/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:33:21 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 10:29:14 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

// +------------------------------------------+ //
//   Const definition                           //
// +------------------------------------------+ //

# define GAME_NAME "so_long"
# define TILE_SIZE 64

# define BER_EXTENSION ".ber"
# define XPM_EXTENSION ".xpm"

# define MAP_ELEMENTS "01CEP"

# define SPRITE_NUM 5
# define SPRITE_PATH "./sprites/"
# define SPRITE_EMPT "./sprites/grass.xpm"
# define SPRITE_WALL "./sprites/rock.xpm"
# define SPRITE_CLCT "./sprites/key.xpm"
# define SPRITE_EXIT "./sprites/chest.xpm"
# define SPRITE_PLYR "./sprites/hero_down.xpm"

// # ifdef __MACH__
// #  define MACH 1
// #  define LINUX 0
// # endif
// # ifdef __linux__
// #  define MACH 0
// #  define LINUX 1
// # endif

// +------------------------------------------+ //
//   Enum definition                            //
// +------------------------------------------+ //

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef enum e_exit
{
	SUCCESS,
	FAILURE,
}	t_exit;

typedef enum e_matrix
{
	ROW,
	COL,
}	t_matrix;

typedef enum e_size
{
	WIDTH,
	HEIGHT,
}	t_size;

typedef enum e_position
{
	X,
	Y,
}	t_position;

typedef enum e_element
{
	EMPT,
	WALL,
	CLCT,
	EXIT,
	PLYR,
}	t_element;

typedef enum e_elemchar
{
	CHAR_EMPT = '0',
	CHAR_WALL = '1',
	CHAR_CLCT = 'C',
	CHAR_EXIT = 'E',
	CHAR_PLYR = 'P',
}	t_elemchar;

# ifdef __MACH__
typedef enum e_keycode
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_RIGHT = 123,
	KEY_LEFT = 124,
	KEY_ESC = 53,
}	t_keycode;
# endif
# ifdef __linux__
typedef enum e_keycode
{
	KEY_A = 0x61,
	KEY_S = 0x73,
	KEY_D = 0x64,
	KEY_W = 0x77,
	KEY_RIGHT = 0xff53,
	KEY_LEFT = 0xff51,
	KEY_ESC = 0xff1b,
}	t_keycode;
# endif

# ifdef __MACH__
typedef enum e_keyevent
{
	X_KEY_PRESS = 2,
	X_KEY_RELEASE = 3,
	X_KEY_EXIT = 17,
}	t_keyevent;
# endif
# ifdef __linux__
typedef enum e_keyevent
{
	X_KEY_PRESS = 2,
	X_KEY_RELEASE = 3,
	X_KEY_EXIT = 33,
}	t_keyevent;
# endif

typedef enum e_mask
{
	X_NO_EVENT_MASK = 0L,
	X_KEY_PRESS_MASK = 1L << 0,
	X_KEY_RELEASE_MASK = 1L << 1,
	X_STRUCTURE_NOTIFY_MASK = 1L << 17,
}	t_mask;

typedef enum e_color
{
	BLACK = 0x00000000,
	RED   = 0x00ff0000,
	GRAY  = 0x00b3b3b3,
	WHITE = 0x00ffffff,
	ALPHA = 0xff000000,
}	t_color;

// +------------------------------------------+ //
//   Type definition                            //
// +------------------------------------------+ //

typedef struct s_player
{
	size_t	position[2];
	size_t	move_count;
}	t_player;

typedef struct s_map
{
	char	*map;
	char	*submap;
	char	*path_to_file;
	size_t	matrix[2];
	size_t	size[2];
	size_t	collectables;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_sprite
{
	void	*sprite;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		size[2];
}	t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_player	player;
	t_sprite	sprites[SPRITE_NUM];
}	t_game;

#endif