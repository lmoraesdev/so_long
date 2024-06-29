<h1 align=center>
	<b>so_long</b>
</h1>

<h2 align=center>
	 <i>42 São Paulo's project</i>
</h2>

<p align=center>
	`so_long` is a project developed as part of the 42 São Paulo curriculum. It focuses on creating a basic 2D game using the minilibx graphical library, where the player navigates through a map, collects items, and avoids enemies.
</p>

---

> The goal of `so_long` is to create a game that fits within the following constraints:
>
> - The game must take place on a single map.
> - The map must be rectangular, composed of walls, empty spaces, collectible items, and one exit.
> - The player must be able to move through the map using the keyboard arrows.
> - The player must be able to collect items and reach the exit to win the game.
> - The player must face enemies that move independently throughout the map.
> - The game must follow specific behavioral rules for the player and enemies.
> - The game must display the player's movements, actions, and any necessary information on the screen.
> - The project must manage memory appropriately and avoid leaks.

<h3 align=center>
Mandatory
</h3>

> - The game must be able to display an image of the player's character, enemies, collectible items, and map layout.
> - The player must interact with the game using keyboard inputs for movement and actions.
> - The game must handle player-enemy interactions, including collisions and game over scenarios.
> - The game must include visual and behavioral feedback for player actions and game state changes.
> - The project must be implemented in C language, using the minilibx graphical library provided.

---

<h2>
Overview
</h2>

In `so_long`, the player is placed within a defined map environment and must navigate through it to achieve specific objectives. The map consists of various elements such as walls, empty spaces, collectible items, enemies, and an exit. The player can move in four directions using the keyboard arrows, collecting items and avoiding enemies as they progress. The game ends when the player successfully navigates to the exit or encounters a game-over condition.

The project challenges the developer to implement interactive gameplay mechanics, handle graphical rendering using the minilibx library, manage game state transitions, and ensure smooth user interactions throughout the gameplay experience.

---

<h2>
Usage
</h2>

### Installation

Clone the `so_long` repository to your local machine:

```sh
$ git clone https://github.com/lmoraesdev/so_long.git path/to/so_long
```
Navigate to the project directory:
```sh
$ make
```

---

<h2>
Running the Game
</h2>

To start the so_long game, run the executable with a map file as an argument:
```sh
$ ./so_long maps/map.ber
```

---

<h2>
Controls
</h2>

-  Use the arrow keys (↑, ↓, ←, →) to move the player character.
-  Collect items (C) and reach the exit (E) to complete the game objectives.

---

<h2>
Features
</h2>

- Graphics: Utilizes the minilibx library for graphical rendering.
- Map Parsing: Reads and interprets map files in the .ber format.
- Player Interaction: Implements player movement, item collection, and game state handling.
- Enemy AI: Includes basic AI for enemy movement and interaction with the player.

---

<h2>
Requirements
</h2>

- Operating System: Compatible with Unix/Linux environments.
- Dependencies: Requires minilibx graphical library for rendering.
