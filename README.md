# GuessTheCard_CPP
# Guess The Card — C++ Edition

A console-based card guessing game written in C++.  
This project demonstrates clean gameplay logic, simple class design, randomization, and user input handling.

## Overview

This is a pure-logic version of my C# WinForms card game.  
The original C# version uses a sprite sheet to render card graphics.  
For this C++ sample, I intentionally focused on gameplay logic to keep the code portable, readable, and easy to review.

## Features

- Guess suit, value, or both
- Random card generation from a 40-card deck (Ace–10 in four suits)
- Replay loop
- Simple `Card` and `Deck` classes
- No external libraries or graphics

## Build Instructions

Compile with any modern C++ compiler.

### Windows (MinGW example)

```bash
g++ src/main.cpp -o GuessTheCard