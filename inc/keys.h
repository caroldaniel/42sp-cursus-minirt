/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:12:43 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/06 23:25:28 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

/*
** Key numbers
*/

# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

# define NUMPAD_1	65436
# define NUMPAD_2	65433
# define NUMPAD_3	65435
# define NUMPAD_4	65430
# define NUMPAD_5	65437
# define NUMPAD_6	65432
# define NUMPAD_7	65429
# define NUMPAD_8	65431
# define NUMPAD_9	65434

# define NUMKEY_1	49
# define NUMKEY_2	50
# define NUMKEY_3	51
# define NUMKEY_4	52
# define NUMKEY_5	53
# define NUMKEY_6	54
# define NUMKEY_7	55
# define NUMKEY_8	56
# define NUMKEY_9	57

# define KEY_PLUS	61
# define KEY_MINUS	45
# define KEY_SPACE	32

# define KEY_Z		122
# define KEY_X		120
# define KEY_P		112
# define KEY_I		105
# define KEY_O		111
# define KEY_L		108
# define KEY_R		114
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_Q		113
# define KEY_W		119
# define KEY_E		101
# define KEY_ESC    65307

/*
** Mouse hook events
*/

# define MOUSE_LEFT_CLICK	1
# define MOUSE_MIDDLE_CLICK	2
# define MOUSE_RIGHT_CLICK	3
# define MOUSE_WHEEL_UP		4
# define MOUSE_WHEEL_DOWN	5

/*
** Events on X Window System
*/

# define KEY_PRESS		2
# define KEY_RELEASE	3
# define BUTTON_PRESS	4
# define BUTTON_RELEASE	5
# define MOUSE_MOVE		6
# define EXPOSE			12
# define DESTROY_NOTIFY	17
# define WINDOW_CLOSE	33

#endif