#ifndef RAYCAST_H
# define RAYCAST_H

typedef struct s_raycast
{
    double  delta_x;
    double  delta_y;
    double  perp_wall_dist;
    double  sidedist_x;
    double  sidedist_y;
    int     side;
    int     step_x;
    int     step_y;
    int     wall_start;
    int     wall_end;
} t_raycast;

#endif