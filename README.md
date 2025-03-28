<div align="center">
	<h1>42-cub3D</h1>
</div>

### About
**42-cub3D** is a project developed as part of the 42 Network curriculum. It recreates a simple 3D game using raycasting, inspired by the classic *Wolfenstein 3D*. This project focuses on building a basic graphics engine in C, following the strict [Norminette](https://github.com/42School/norminette) coding style.

<div align="center">
	<h1>Demonstrating video</a></h1>
</div>

![Gameplay Demo](https://github.com/user-attachments/assets/6c0a9dda-04c4-4b79-89df-dab8e27967e3)


---

## How to Play

### Dependencies
To compile and run cub3D, you need the following dependencies:
- **required packages** (install via terminal):
    ```bash
    sudo apt-get install gcc make libxext-dev libx11-dev libbsd-dev libxrandr-dev libxi-dev libxinerama-dev
    ```

### How to Run
1. Clone this repository, compile and execute:
    ```bash
    git clone https://github.com/YourUsername/42-cub3D.git
    cd 42-cub3D
    make download
    make
    ./cub3D_bonus maps/good/map1.cub
    ```

## Controls
1. Use the following keys to control the player:
    | Key             | Action              |
    |-----------------|---------------------|
    | `W`             | Move forward        |
    | `S`             | Move backward       |
    | `A`             | Move left           |
    | `D`             | Move right          |
    | `← / →`         | Rotate camera       |
    | Mouse move      | Rotate camera       |
    | Mouse left click|Attack enemy         |
    | `ESC`           | Exit the game       |

---

<div align="center">
	<h1><a href="https://dot99.github.io/42-cub3D/">Documentation</a></h1>
</div>

## Disclaimer:
This project's source code adheres to the standards of 42 School and its norms and rigorous coding practices:
```
- We refrain from using 'for,' 'do while,' 'switch,' 'case,' or 'goto' constructs.
- Each function has no more than 25 lines of code. 
- There's a maximum of 5 functions per file.
- Assignments and declarations are kept on separate lines unless the variable is declared as static.
- We ensure that no single function has more than 5 variables, promoting code simplicity and readability.
```
