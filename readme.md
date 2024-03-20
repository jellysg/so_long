# Introduction to 42's so_long
and thanks for the fish(???)  
![](https://github.com/jellysg/core/blob/main/02_so_long/img/img1.gif)  

#### Mandatory features
- WASD to move the player
- Should not be able to move into walls
- View has to be 2D (top-down or profile)
- Game doesn't have to be in real-time
- **There should be a valid path from Player to all collectibles and the exit**
- Collect all coins before escaping  
![](https://github.com/jellysg/core/blob/main/02_so_long/img/img3.gif)  

#### Bonus features
- Lose upon touching an enemy patrol
- Sprites have animations
- Movement count is shown directly on screen  
![](https://github.com/jellysg/core/blob/main/02_so_long/img/img2.gif)  


#### Compiling

After cloning, make sure you are in ./core/02_so_long/ directory, then make:
```
make
```

To test the game, run the following:
```
./so_long ./maps/(map name).ber
```
  

# Tutorial: Getting started on so_long
#### Disclaimer:
Due to unoptimized struct linking, I have to make extra frees before malloc. This is not only unnecessary line bloat, but also makes it harder to understand when reviewing the source code.  
I apologize for the messy linking and extra frees here and there, they were mostly a band-aid to passing valgrind and speed up the submission overall. It could definitely be done better and I will revisit this when I have more time in the future.  
  
## Short introduction to MiniLibX:
[MiniLibX (MLX)](https://harm-smits.github.io/42docs/libs/minilibx) is a beginner-friendly API for C, used mainly for a window system called [X11](https://tronche.com/gui/x/xlib/).  

### Installing MLX:
Install MLX by either downloading it directly from the project page or this command:
```
git clone https://github.com/42Paris/minilibx-linux.git mlx
```

### Dependencies:
MLX (and X11 itself) depends on certain packages to carry out some functions. They can be installed with the following command:
```
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

### Makefile additions:
These are some of the additions to your Makefile to ensure the X11 and MLX files are accessible:
```
...
INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
...
```

# Core MLX functions for so_long:
- mlx_init  
> Initializes the mlx library before anything else.
- mlx_new_window  
> Creates a new window instance.
- mlx_hook  
> "Hooks" or registers events onto the window or mlx pointer.
- mlx_loop  
> Loops across the mlx pointer, registering the hooks in the same order they are called.
- mlx_xpm_file_to_image  
> Converts XPM to a viewable image on an mlx pointer.
- mlx_put_image_to_window  
> Puts... image.. to window.. I don't know how else to explain this.  
  
The following have to be called **in the same order** or there will be memory leaks:  
- mlx_destroy_image  
> Frees image stored in 'mlx_xpm_file_to_image' pointers.
- mlx_destroy_window  
> Frees the window instance.
- mlx_destroy_display  
> Frees mlx.  
> (Note: This frees the mlx functions but you still have to free your own mlx pointer!)

# Here is an example for creating a window using MLX:
```
#include <stdlib.h>
#include "mlx/mlx.h"
 
int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
 
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 300, 300, "test");
	sleep(5); // 5 second sleep before closing the window
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}
```

# Hooks and Loops:
- Hooks are important for MLX as it allows the window to receive and process certain user-inputs like keypress, mouse-click, etc.  
- Loops will essentially "hold on" to the window and listen for any previously defined hooks.

### Here is a modified independant snippet of my source code:
```
#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
 
typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;
 
int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
 
int on_keypress(int keysym, t_data *data)
{
	// Casted (void) as it is declared but intentionally not being used, yet ;D
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}
 
int main(void)
{
	t_data data;
 
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 300, 300, "test");
 
	// Key Hook - when a key is pressed, it will call on_keypress
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
 
	// Destroy Hook - when the window is closed, it will call on_destroy
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
 
	// Loop the above hooks
	mlx_loop(data.mlx_ptr);
	return (0);
}
```
What happens is the window will wait for the user to input keypresses or close the window:  
- When a key is pressed, it will print the pressed key in the terminal.  
- When window is closed, it will carry out the function on_destroy.  

> Note: KeyPress and DestroyNotify are X11 events; accessible via importing the X11 headers.  

# Here are some pointers to take note of when tackling this project:
1. XPM has to be converted to image first before putting into window
2. The map has to have a valid path for the Player to navigate to all collectibles and the exit (if 1 collectible is walled off, it should be an error)
3. This project has a heavy focus on memory manipulation at all stages. Segmentation fault will be very common.
4. Linking structs without proper planning will often cause memory leaks. Plan your structs ahead of time, especially if they involve arrays!
5. Approximately 70% of the time will be spent on just handling data from reading the map. Do not be discouraged if you spend most of your time just fixing map reading, it is expected!
6. [itch.io](https://itch.io/game-assets) is a good platform for sourcing free assets
7. Blindly copy-pasting will only cause you more harm in the future. This project teaches you memory manipulation across multiple platforms, you will definitely be doing a lot of those in the next circle. Do not waste this fun learning opportunity over "an easy way out", you only lose out if you stop learning :D