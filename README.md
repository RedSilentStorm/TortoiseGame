# Tortoise Game

## Overview
The Tortoise Game is a console-based grid game coded in **C**, where the player controls a tortoise and moves it around a grid. The objective is to collect berries and avoid pits while managing the energy levels.

## Features
- Tortoise represented by the symbol `@`.
- Berries represented by `*` that the player collects for energy.
- Pits represented by `0` that cause the player to lose the game when stepped on.
- A grid where the tortoise moves and interacts with berries and pits.
- Dynamic energy system where each movement costs energy.
- The game ends when the player runs out of energy or collects all berries.

## How to Play
1. The game starts by displaying a grid populated with the tortoise (`@`), berries (`*`), and pits (`0`).
2. You control the tortoise (`@`) using the following controls:
    - **w**: Move up
    - **a**: Move left
    - **s**: Move down
    - **d**: Move right
3. The goal is to collect all berries (`*`) and avoid stepping on pits (`0`).
4. Each move costs energy (starting at 20). Collecting a berry adds energy.
5. The game ends when:
    - All berries are collected (***You win***).
    - You step on a pit (***Game over***).
    - You run out of energy (***Game over***)
