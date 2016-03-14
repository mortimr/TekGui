/*
** tekgui.h for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Feb  2 17:59:57 2016 Iulian Rotaru
** Last update Sun Mar 13 10:18:57 2016 Iulian Rotaru
*/

#ifndef TEKGUI_H_
# define TEKGUI_H_

# include <lapin.h>
# include <math.h>
# include <unistd.h>
# include <dlfcn.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>

typedef struct			s_bmp
{
  short				magic;
  unsigned int			file_size;
  unsigned int			unused;
  unsigned int			pos;
  unsigned int			head_size;
  unsigned int			bmp_width;
  unsigned int			bmp_height;
  short				ndpdb;
  short				ndbpp;
  unsigned int			zip;
  unsigned int			bmp_size;
  unsigned int			ppml;
  unsigned int			ppmh;
  unsigned int			chrom;
  unsigned int			nb_couleur;
} __attribute__((packed)) 	t_bmp;

typedef struct		s_body
{
  short			width;
  short			height;
  t_bunny_position	exit[2];
  char			*title;
}			t_body;

typedef struct		s_text
{
  int			police_size;
  unsigned int		fg;
  t_bunny_position	pos;
  int			x;
  int			y;
}			t_text;

typedef struct		s_button
{
  short			width;
  short			height;
  short			x;
  short			y;
  char			*para;
  char			*name;
}			t_button;

typedef struct		s_exit
{
  char			fade;
  char			*body;
  short			width;
  short			height;
  t_button		buttons[2];
}			t_exit;

typedef struct		s_theme
{
  t_color		one;
  t_color		two;
  t_color		text;
  char			*name;
}			t_theme;

typedef struct		s_bar
{
  short			x;
  short			y;
  short			width;
  short			height;
  char			search[1024];
  char			*auto_fill;
  char			focus;
}			t_bar;

typedef struct		s_displayer
{
  short			x;
  short			y;
  short			width;
  short			height;
  t_bar			bar;
  char			*fct;
  int			scroll;
}			t_displayer;

typedef struct		s_area
{
  t_bunny_position	pos;
  t_bunny_position	dim;
  char			*name;
  char			*fct;
  t_bunny_position	real_pos;
  t_bunny_position	real_dim;
}			t_area;

typedef struct		s_ani
{
  short			police;
  unsigned int		fg;
  unsigned int		bg;
  char			text[1024];
  t_text		text_data;
  char			move_speed;
  char			invert;
  char			epileptic;
}			t_ani;

typedef struct		s_texter
{
  t_bunny_position	pos;
  t_bunny_position	dim;
  char			text[1024];
  char			*fct;
}			t_texter;

typedef struct		s_radio
{
  t_bunny_position	pos;
  t_bunny_position	dim;
  char			*title;
  char			nb_butt;
  t_bunny_position	*butt_pos;
  t_bunny_position	*butt_realpos;
  t_bunny_position	*butt_dim;
  char			**butt_titles;
  char			**butt_fct;
  char			selected;
}			t_radio;

typedef struct		s_cases
{
  t_bunny_position	pos;
  t_bunny_position	real_pos;
  t_bunny_position	dim;
  char			*fct_on;
  char			*fct_off;
  char			*name;
  unsigned char		active;
}			t_cases;

typedef struct		s_tekgui
{
  char			nb_radio;
  char			nb_cases;
  char			nb_theme;
  char			nb_buttons;
  unsigned int		nb_files;
  char			nb_areas;
  char			nb_text;
  t_body		body;
  t_displayer		*displayer;
  t_area		*area;
  t_ani			*ani;
  t_button		*button;
  t_texter		*texter;
  t_cases		*cases;
  t_radio		*radio;
  char			disp;
  char			animation;
  char			actu_theme;
  t_bunny_pixelarray	*font;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*searcher[2];
  t_bunny_position	mouse;
  t_bunny_position	ex_button[2];
  t_bunny_position	ex_size[2];
  t_bunny_position	disp_butt;
  t_bunny_position	disp_dim;
  t_bunny_position	disp_bar;
  t_bunny_position	disp_bardim;
  t_bunny_window	*win;
  unsigned char		scroll;
  t_button		*main_buttons;
  t_theme		*theme;
  t_exit		exit;
  int			on;
  bool			l_click;
  char			search_select;
  char			move;
  char			*current;
  char			selection_done;
  char			focus_text;
}			t_tekgui;

typedef struct		s_area_text
{
  int			x;
  int			y;
  int			i;
  int			j;
  int			ratio;
  t_bunny_position	blit;
  unsigned int		*ptrr;
  unsigned int		*ptr;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*extract;
  t_bunny_position	*area;
  t_text		*text;
}			t_area_text;

extern void		ani_change_fg(t_tekgui *tekgui);
extern void		ani_change_bg(t_tekgui *tekgui);
extern void		disp_search_urandom(t_tekgui *tekgui);
extern void		disp_clear_search(t_tekgui *tekgui);
extern void		disp_scroll_down(t_tekgui *tekgui);
extern void		disp_scroll_up(t_tekgui *tekgui);
extern void		area_preview_ani(t_tekgui *tekgui, t_area *area);
extern void		ani_speed_down(t_tekgui *tekgui);
extern void		ani_speed_up(t_tekgui *tekgui);
extern void		ani_rand_color(t_tekgui *tekgui);
extern void		area_show_police(t_tekgui *tekgui, t_area *area);
extern void		area_show_speed(t_tekgui *tekgui, t_area *area);
extern void		ani_text_changer(t_tekgui *tekgui);
extern void		tektext(t_bunny_pixelarray *out,
				const char *str,
				t_bunny_pixelarray *font_png);
extern void		*tekfunction(const char *funcname);
t_bunny_pixelarray	*bmp_way(int fd);
t_bunny_pixelarray	*load_bitmap(char *file);
t_bunny_response	loop(void *data);
t_bunny_response	typing(uint32_t unicode,
			       void *data);
t_bunny_response	mouse_move(const t_bunny_position *move,
				   void *data);
t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    void *data);
t_bunny_response	gui_click(t_bunny_event_state state,
				  t_bunny_mousebutton sym,
				  void *info);
t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    void *data);
t_bunny_response	loop(void *data);
t_bunny_response	mouse_move(const t_bunny_position *move,
				   void *data);
t_bunny_response	typing(uint32_t unicode,
			       void *data);
unsigned int		invert_colors(unsigned int one, unsigned int two);
unsigned int		color_mixer(unsigned int, unsigned int);
unsigned int		color_mixer(unsigned int one, unsigned int add);
unsigned int		get_base_nb(char *base, char c);
unsigned int		my_get_hexa(char *nb);
unsigned int		color_mixer(unsigned int one, unsigned int add);
unsigned int		get_base_nb(char *base, char c);
unsigned int		my_get_hexa(char *nb);
unsigned int		get_mix_color(t_bunny_pixelarray *pix,
				      int idx,
				      unsigned int color);
t_tekgui		*tekgui_load(const char *file);
void			*tek_area_fct(const char *funcname);
void			swap_it(int y, unsigned int *color);
void			swap_it_x(int y, unsigned int *color);
void			background_manager(t_bunny_pixelarray *pix);
void			read_colors(t_bmp *bmp,
				    t_bunny_pixelarray *pix,
				    int fd);
void			my_bunny_blit_theme(t_bunny_pixelarray *big,
					    t_bunny_pixelarray *small,
					    t_bunny_position *pos,
					    t_tekgui *tekgui);
void			my_bunny_blit(t_bunny_pixelarray *big,
				      t_bunny_pixelarray *small,
				      t_bunny_position *pos,
				      int mode);
void			my_blitnbr(int nb,
				   t_bunny_pixelarray *pix,
				   t_bunny_pixelarray *text_pix,
				   t_text *text);
void			my_blitstr(char *str,
				   t_bunny_pixelarray *pix,
				   t_bunny_pixelarray *text_pix,
				   t_text *text);
void			tekgui_display(t_bunny_pixelarray *pix,
				       t_tekgui *tekgui);
void			display_text_field(t_tekgui *tekgui,
					   t_bunny_pixelarray *pix);
void			display_single_text_field(t_tekgui *tekgui,
						  t_bunny_pixelarray *pix,
						  int x);
void			display_area(t_tekgui *tekgui,
				     t_bunny_pixelarray *pix);
void			single_area_displayer(t_tekgui *tekgui,
					      t_area *area,
					      t_bunny_pixelarray *pix);
void			display_buttons(t_tekgui *tekgui,
					t_bunny_pixelarray *pix);
void			display_one_button(t_button *button,
					   t_tekgui *tekgui,
					   t_bunny_pixelarray *pix);
void			display_img_text(t_tekgui *tekgui,
					 t_bunny_pixelarray *pix);
void			fade_body(t_tekgui *tekgui,
				  t_bunny_pixelarray *pix,
				  int mode);
void			display_exit_box(t_tekgui *tekgui,
					 t_bunny_pixelarray *pix,
					 int mode);
void			display_displayer(t_tekgui *tekgui,
					  t_bunny_pixelarray *pix);
void			display_search_dispbar(t_tekgui *tekgui,
					       t_bunny_pixelarray *pix);
void			display_body(t_tekgui *tekgui,
				     t_bunny_pixelarray *pix);
void			make_square_transpa(t_bunny_pixelarray *pix,
					    t_bunny_position *start,
					    t_bunny_position *dim,
					    unsigned int color);
void			make_square(t_bunny_pixelarray *pix,
				    t_bunny_position *start,
				    t_bunny_position *dim,
				    unsigned int color);
void			fill_pix(t_bunny_pixelarray *pix,
				 unsigned int color);
void			ani_police_down(t_tekgui *tekgui);
void			ani_police_up(t_tekgui *tekgui);
void			multi_key(t_tekgui *tekgui);
void			animation_setup(t_tekgui *tekgui);
void			display_radio_boucle(void **sender, int i);
void			display_radio_sec(void **sender, int i);
void			get_selection_dispbar_next(DIR *current,
						   t_tekgui *tekgui);
void			display_radio_first(void **sender,
					    int i,
					    unsigned int *color);
void			set_single_text_first(void **sender,
					      int x,
					      unsigned int *color);
void			set_single_text_third(void **sender);
void			set_single_text_sec(void **sender,
					    int x,
					    unsigned int *color);
void			set_ratio_stuff(t_bmp *bmp,
					t_tekgui *tekgui,
					int *ratio,
					int *final);
void			jump_to_pix(t_bmp *bmp, int fd);
void			set_live_load_pos(t_bunny_pixelarray *pix,
					  t_bunny_position *pos,
					  t_tekgui *tekgui);
void			tekcircle(t_bunny_pixelarray *pix,
				  double radius,
				  t_bunny_position *pos,
				  unsigned int color);
void			tekcircle_full(t_bunny_pixelarray *pix,
				       double radius,
				       t_bunny_position *pos,
				       unsigned int color);
void			set_disp_search_pos(t_bunny_position *dim,
					    t_bunny_position *start,
					    t_bunny_pixelarray *pix,
					    t_tekgui *tekgui);
void			set_disp_save_pos(t_tekgui *tekgui,
					  t_bunny_position *start,
					  t_bunny_position *dim);
void			display_cases_set_frist(void **sender,
						unsigned int *color,
						int i);
void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);
void			copy_area_tek(t_bunny_pixelarray *pix,
				      t_bunny_pixelarray *extract,
				      t_bunny_position *area);
void			copy_area(t_bunny_pixelarray *pix,
				  t_bunny_pixelarray *extract,
				  t_bunny_position *area, t_text *text);
void			text_dispobar_set(t_text *text,
					  t_tekgui *tekgui,
					  t_bunny_position *start);
void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *coord,
				t_color *color);
void			make_square_empty(t_bunny_pixelarray *pix,
					  t_bunny_position *start,
					  t_bunny_position *dim,
					  unsigned int color);
void			make_square_cross(t_bunny_pixelarray *pix,
					  t_bunny_position *start,
					  t_bunny_position *dim,
					  unsigned int color);
void			live_load_first(void **sender,
					t_bunny_pixelarray *pix,
					int final,
					t_bmp *bmp);
void			read_one_color(t_color *color, int fd);
void			display_exit_box_pos(t_bunny_position *start,
					     t_bunny_position *dim,
					     t_tekgui *tekgui,
					     t_bunny_pixelarray *pix);
void			display_exit_pos_again(t_bunny_position *start,
					       t_bunny_position *dim,
					       t_tekgui *tekgui,
					       unsigned int *col);
void			set_exit_message(t_text *text,
					 t_tekgui *tekgui,
					 t_bunny_position *dim,
					 t_bunny_position *start);
void			display_exit_second_pos(t_bunny_position *start,
						t_bunny_position *dim,
						unsigned int *col,
						t_tekgui *tekgui);
void			display_exit_box_pos_next(t_bunny_position *start,
						  t_bunny_position *dim,
						  t_tekgui *tekgui,
						  unsigned int *col);
void			ani_play(t_tekgui *tekgui);
void			display_body_next(t_tekgui *tekgui,
					  t_bunny_position *start,
					  t_bunny_position *dim,
					  t_bunny_pixelarray *pix);
void			display_body_next_next(t_tekgui *tekgui,
					       t_bunny_position *start,
					       t_bunny_position *dim,
					       t_bunny_pixelarray *pix);
void			display_body_text(t_tekgui *tekgui,
					  t_text *text,
					  t_bunny_pixelarray *pix);
void			display_body_text_next(t_tekgui *tekgui,
					       t_text *text,
					       t_bunny_pixelarray *pix,
					       t_bunny_position *start);
void			display_faded_theme(int *fade,
					    t_text *text,
					    t_bunny_pixelarray *pix,
					    t_tekgui *tekgui);
void			tekgui_display_first(t_bunny_pixelarray *pix,
					     t_tekgui *tekgui);
void			set_start_nb(t_bunny_position *pos,
				     t_text *text,
				     int ratio,
				     int j);
void			display_cases_button(t_tekgui *tekgui,
					     t_bunny_pixelarray *pix);
void			display_radio_button(t_tekgui *tekgui,
					     t_bunny_pixelarray *pix);
void			ani_play_else(t_text *text, t_tekgui *tekgui);
void			ani_play_core(t_text *text,
				      int *call,
				      int *increm,
				      t_tekgui *tekgui);
void			check_if_disp_on(t_tekgui *data);
void			check_if_exit_exit(t_tekgui *data);
void			check_if_exit_body(t_tekgui *data);
void			disp_search_urandom(t_tekgui *tekgui);
void			disp_clear_search(t_tekgui *tekgui);
void			check_disp_select(t_tekgui *data);
void			check_button_on(t_tekgui *data);
void			check_text_focus(t_tekgui *data);
void			check_radio_on(t_tekgui *data);
void			check_cases_on(t_tekgui *data);
void			set_max_heap_size(size_t s);
void			multi_key(t_tekgui *tekgui);
void			*tek_area_fct(const char *funcname);
void			ani_invert_colors_on(t_tekgui *tekgui);
void			ani_invert_colors_off(t_tekgui *tekgui);
void			ani_epileptic_off(t_tekgui *tekgui);
void			ani_epileptic_on(t_tekgui *tekgui);
void			ani_text_changer(t_tekgui *tekgui);
void			ani_change_fg(t_tekgui *tekgui);
void			ani_change_bg(t_tekgui *tekgui);
void			typing_next(uint32_t unicode,
				    t_tekgui *tekgui,
				    int i);
char			*my_strdup(char *test);
int			my_getnbr(const char *nb);
int			load_text(t_bunny_ini *ini, t_tekgui *tekgui);
int			get_text_data(t_bunny_ini *ini, t_tekgui *tekgui);
int			fill_text(const char *extract,
				  t_tekgui *tekgui,
				  int i);
int			load_area(t_bunny_ini *ini, t_tekgui *tekgui);
int			get_area_data(t_bunny_ini *ini, t_tekgui *tekgui);
int			fill_area(const char *extract,
				  t_tekgui *tekgui,
				  int i);
int			load_plugins(t_bunny_ini *ini, t_tekgui *tekgui);
int			my_strcmp(const char *one, const char *two);
int			load_buttons(t_bunny_ini *ini, t_tekgui *tekgui);
int			fill_button(const char *extract,
				    t_tekgui *tekgui,
				    int i);
int			load_builtins(t_bunny_ini *ini, t_tekgui *tekgui);
int			get_displayer_data(t_bunny_ini *ini, t_tekgui *tekgui);
int			empty_displayer_data(t_bunny_ini *ini,
					     t_tekgui *tekgui);
int			read_displayer_data(t_bunny_ini *ini,
					    t_tekgui *tekgui);
int			fill_displayer_fct(const char *extract,
					   t_tekgui *tekgui);
int			fill_displayer_barpos(const char *extract,
					      t_tekgui *tekgui);
int			fill_displayer_bar(const char *extract,
					   t_tekgui *tekgui);
int			fill_displayer_pos(const char *extract,
					   t_tekgui *tekgui);
int			fill_displayer_size(const char *extract,
					    t_tekgui *tekgui);
int			load_body(t_bunny_ini *ini, t_tekgui *tekgui);
int			load_theme_data(t_bunny_ini *ini, t_tekgui *tekgui);
int			get_themes(t_bunny_ini *ini, t_tekgui *tekgui, int i);
int			fill_theme(const char *extract,
				   t_tekgui *tekgui,
				   int x);
int			default_theming(t_bunny_ini *ini, t_tekgui *tekgui);
int			load_body_data(t_bunny_ini *ini, t_tekgui *tekgui);
int			get_title_body(const char *extract, t_tekgui *tekgui);
int			get_exit_body(const char *extract, t_tekgui *tekgui);
int			get_size_body(const char *extract, t_tekgui *tekgui);
int			check_body(t_bunny_ini *ini);
int			check_body_exit(t_bunny_ini *ini);
int			check_body_title(t_bunny_ini *ini);
int			my_strcmp_start(const char *small, const char *big);
int			my_strlen(const char *str);
int			live_load_bitmap(t_tekgui *tekgui,
					 t_bunny_pixelarray *pix,
					 int fd);
int			aff_file_text(t_tekgui *tekgui,
				      t_bunny_pixelarray *pix,
				      int fd);
int			my_strcmp_end(char *end, char *str);
int			assembling_dispbar(t_tekgui *tekgui);
int			search_box(t_tekgui *tekgui, t_bunny_pixelarray *pix);
int			get_selection_dispbar(t_tekgui *tekgui);
int			display_text(t_tekgui *tekgui,
				     t_bunny_pixelarray *pix);
int			load_menu_bmp(t_tekgui *tekgui);
int			is_there_path(char *str);
int			check_key(t_tekgui *tekgui, t_bunny_pixelarray *pix);
int			check_exit(t_tekgui *tekgui, t_bunny_pixelarray *pix);
int			check_file_nb(t_tekgui *tekgui);
int			my_getunbr(const char *nb);
int			load_radio(t_bunny_ini *ini, t_tekgui *tekgui);
int			get_cases_data(t_bunny_ini *ini, t_tekgui *tekgui);
int			fill_button_radio(const char *extract,
					  int x,
					  t_tekgui *tekgui,
					  int i);
int			fill_button_next(int x,
					 const char *extract,
					 t_tekgui *tekgui,
					 int i);
int			fill_displayer_barpos_next(t_tekgui *tekgui);
int			load_objects(t_bunny_ini *ini, t_tekgui *tekgui);
int			load_config();
int			key_next_next(t_bunny_event_state state,
				      t_bunny_keysym sym,
				      t_tekgui *tekgui);
int			key_next(t_bunny_event_state state,
				 t_bunny_keysym sym,
				 t_tekgui *tekgui);
int			check_file_nb(t_tekgui *tekgui);
int			loop_next_next(t_tekgui *tekgui);
int			loop_next(t_tekgui *tekgui);
int			tekgui_loop(t_bunny_window *win,
				    t_bunny_pixelarray *pix,
				    t_tekgui *tekgui);

#endif /* !TEKGUI_H_ */
