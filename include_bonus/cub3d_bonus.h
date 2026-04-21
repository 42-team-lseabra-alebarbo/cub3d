#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "structs_bonus.h"
# include "macros_bonus.h"

void	ft_put_pixel_minimap(t_data *dt, int x, int y, t_rgb rgb);
void	ft_render_mm_pixel(t_data *dt, t_minimap *mm);
void	ft_render_minimap(t_data *dt);
void	ft_game_loop_bonus(t_data *dt);

#endif