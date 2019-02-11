/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:58:57 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 23:49:27 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <sys/time.h>
# include <math.h>
# include "libft.h"

# define FRAMERATE_H	(1666666666 * 0.25)
# define FRAMERATE_V	(1666666666 * 0.30)

# define K_UP		4283163
# define K_LEFT		4479771
# define K_RIGHT	4414235
# define K_DOWN		4348699
# define K_ENTER	10

# define GM_NEWGAME		0
# define GM_INGAME		1
# define GM_GAMEOVER	2

# define INPUT_EXIT			1
# define INPUT_CONTINUE		0

# define HSCORE				"HIGHSCORE"

# define TC_CLEAR			"cl"
# define TC_DEL				"dc"
# define TC_DELTOEND		"cd"
# define TC_DELTOENDL		"ce"
# define TC_LEFT			"le"
# define TC_RIGHT			"nd"
# define TC_SCROLLDO		"sf"
# define TC_SCROLLUP		"sr"
# define TC_CARRET			"cr"
# define TC_INTE			"te"
# define TC_INTI			"ti"
# define TC_CURSOR_MOVE		"cm"
# define TC_CURSOR_HIDE		"vi"
# define TC_CURSOR_SHOW		"ve"

# define SNK_MIN_X			30
# define SNK_MIN_Y			23
# define SNK_PADDING		3

# define SNK_BDR_UP_L		"╔"
# define SNK_BDR_UP_R		"╗"
# define SNK_BDR_DO_L		"╚"
# define SNK_BDR_DO_R		"╝"
# define SNK_BDR_TOP		"═"
# define SNK_BDR_SIDE		"║"

typedef struct s_tc_win			t_tc_win;
typedef struct termios			t_term_attr;
typedef struct winsize			t_term_ws;
typedef struct s_game_data		t_game_data;
typedef struct s_snk_part		t_snk_part;
typedef struct s_vec2			t_vec2;
typedef struct s_canvas			t_canvas;
typedef struct s_framerate		t_framerate;

struct				s_tc_win
{
	t_term_attr		attr_backup;
	t_term_attr		attr_snk;
	t_term_ws		windows_attr;
	char			resised;
};

struct				s_vec2
{
	int x;
	int y;
};

struct				s_canvas
{
	t_vec2	size;
	t_vec2	anchor;
};

struct				s_framerate
{
	struct timespec		start;
	struct timespec		end;
};

struct				s_snk_part
{
	t_vec2	pos;
};

struct				s_game_data
{
	t_framerate		frame;
	t_canvas		screen;
	t_list			*snk;
	t_snk_part		food;
	t_vec2			dir;
	double			speed;
	int				status;
	int				curr_screen;
	int				score;
	int				highscore;
	int				last_dir;
	int				force_update;
	long			last_key;
};

t_tc_win			*new_tc_win(void);
t_tc_win			*gs_tc_win(int gs, t_tc_win *windows);
int					exec_tc_cap(char *cap);
int					get_term_attr(t_term_attr *attr);
int					restore_tc_attr(t_tc_win *win);
int					move_cursor(int x, int y);
int					tc_clear_screen(int nbline);
void				write_to_pos(t_vec2 v2, char *c, short color);

void				intercept_sigwinch(int sig);
int					reset_sigwinch_handler(void);

int					init_snk(t_tc_win *win);
void				init_gamedata(t_game_data *gdata, t_tc_win *win);
void				exit_snk(t_game_data *game_data, t_tc_win *win);

void				set_newgame(t_game_data *gdata);

void				input_update(t_tc_win *win, t_game_data *gdata);
void				draw_update(t_tc_win *win, t_game_data *gdata);

void				draw_canvas(t_canvas *canvas);
void				draw_quit(t_canvas *screen);
void				draw_highscore(t_game_data *gdata);
void				draw_score(t_canvas *screen, int gscore);
void				draw_snk(t_list *snk, int pcount, int curr_screen, \
							t_vec2 anchor);
void				draw_words2_center(t_canvas *screen, char *word1, \
									char *word2, short c);

void				update_snk(t_game_data *gdata);
void				update_speed(t_game_data *gdata);

t_snk_part			*snk_part(t_list *snk);

void				eat_food(t_game_data *gdata);
void				spawn_food(t_game_data *gdata);

t_vec2				vec2_left(void);
t_vec2				vec2_right(void);
t_vec2				vec2_up(void);
t_vec2				vec2_down(void);

t_vec2				vec2_div(t_vec2 v2, int div);
t_vec2				vec2_add(t_vec2 a, t_vec2 b);
t_vec2				vec2_addint(t_vec2 v2, int i);

int					vec2_to_linear(t_vec2 v2, int max_x);
t_vec2				linear2vec2(int linear_pos, int max_x);
t_vec2				new_vec2(int x, int y);

t_bool				vec2_isopposite(t_vec2 v1, t_vec2 v2);
t_bool				vec2_isequ(t_vec2 v1, t_vec2 v2);
t_bool				vec2_isinside(t_vec2 check, t_vec2 inside);

#endif
