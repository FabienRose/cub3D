# Cub3D

A C implementation of a 3D raycasting engine inspired by Wolfenstein 3D, featuring texture mapping, collision detection, and real-time rendering using the MinilibX graphics library.

## Installation

Clone the repository and compile with make:

```bash
git clone https://github.com/FabienRose/cub3D.git
cd cub3D
make
```

## Usage

Run the program with a map file as argument:

```bash
# Basic usage with a valid map file
./cub3d maps/valid_map.cub

# Run with a custom map
./cub3d path/to/your/map.cub
```

### Controls

- **WASD** - Move forward/backward/left/right
- **Arrow Keys** - Rotate view left/right
- **ESC** - Exit the game

### Map File Format (.cub)

The map file must follow this format:

```
# Texture paths (required)
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm

# Colors (required)
F 220,100,0    # Floor color (RGB)
C 250,200,30   # Ceiling color (RGB)

# Map layout (required)
# 1 = wall, 0 = empty space, N/S/E/W = player spawn
# Must be surrounded by walls
        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Map Requirements

- **One player spawn**: Exactly one N, S, E, or W character
- **Closed map**: All walls must be connected
- **Valid textures**: All texture paths must be valid XPM files
- **Valid colors**: RGB values must be between 0-255

## Features

- **3D Raycasting Engine**: Real-time 3D rendering using raycasting algorithm
- **Texture Mapping**: Support for 4 directional wall textures
- **Collision Detection**: Walls prevent player movement
- **Smooth Movement**: WASD controls with rotation
- **Color Customization**: Configurable floor and ceiling colors
- **Map Validation**: Comprehensive map format checking
- **Cross-platform**: Works on Linux and macOS
- **Memory Management**: Proper cleanup and resource management

## Project Structure

```
cub3D/
├── main.c                 # Main program entry point
├── cub3d.h               # Main header file with structures
├── Makefile              # Build configuration
├── libft/                # Custom C library functions
├── minilibx-linux/       # Graphics library (Linux)
├── minilibx_macopen/     # Graphics library (macOS)
├── map/                  # Map parsing and validation
├── parsing/              # Configuration file parsing
├── player/               # Player movement and raycasting
├── render/               # 3D rendering and drawing
├── game/                 # Game loop and state management
├── hooks/                # Input handling and events
├── textures/             # Texture loading and management
├── conversion/           # Data structure conversions
└── cub/                  # Example map files
```

## Dependencies

- **MinilibX**: Graphics library for window management and rendering
- **libft**: Custom C library with utility functions
- **X11** (Linux): X Window System libraries
- **OpenGL/AppKit** (macOS): Graphics frameworks

## Building

The project uses a custom Makefile that automatically detects the operating system and links the appropriate libraries:

```bash
# Standard build
make

# Clean build artifacts
make clean

# Remove all build files
make fclean

# Rebuild everything
make re
```

## Error Handling

The program validates:
- Map file format and syntax
- Texture file existence and validity
- Map connectivity and closure
- Player spawn position
- Color format and range

## License

This project is part of the 42 curriculum and follows the 42 coding standards. 
