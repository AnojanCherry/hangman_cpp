Based on the provided files (`runMe.cpp` and `supports.cpp`), I've created a README file in Markdown format for your Hangman game project.

---

# Hangman Game

Welcome to the Hangman game implemented in C++.

## Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Dependencies](#dependencies)
- [Configuration](#configuration)
- [Troubleshooting](#troubleshooting)
- [Contributors](#contributors)
- [License](#license)

## Introduction

This project is a simple console-based Hangman game written in C++. The game randomly selects a secret word from a file and challenges the player to guess it one letter at a time. Players have a limited number of incorrect guesses before they lose the game.

## Installation

To install and run the Hangman game, follow these steps:

1. **Clone the repository**:
    ```bash
    git clone https://github.com/AnojanCherry/hangman_cpp.git
    ```
   
2. **Navigate to the project directory**:
    ```bash
    cd hangman-game
    ```

3. **Compile the game**:
    ```bash
    g++ runMe.cpp -o hangman
    ```

4. **Run the game**:
    ```bash
    ./hangman
    ```

## Usage

When you run the game, it will display a welcome message and begin a new round. The game will randomly select a word from a file named `words.txt`. You must guess the word one letter at a time. After each guess, the game will update the display to show the correctly guessed letters, and the hangman drawing will progress with each incorrect guess.

## Features

- **Random Word Generation**: The game selects a random word from a file (`words.txt`).
- **Hangman Drawing**: The game visually represents incorrect guesses with a hangman drawing.
- **Guess Validation**: Ensures only valid letters are guessed and updates the word display accordingly.
- **Win/Lose Conditions**: The game checks for win/loss conditions after each guess.

## Dependencies

This project requires a C++ compiler to build and run. No external libraries are required.

## Configuration

- **Verbose Level**: The `dealer` class has a `verbose_level` variable to control the verbosity of the game's output. It is set to `2` by default.
- **Maximum Attempts**: The number of incorrect guesses allowed before the game ends is controlled by the `attempt_max` variable, set to `5` by default.

## Troubleshooting

- **Cannot open `words.txt`**: Ensure that the file `words.txt` is in the same directory as the executable and contains a list of words.
- **Segmentation fault**: Verify that the `words.txt` file is formatted correctly and accessible.

## Contributors

- [Your Name](https://github.com/your-github-profile) - Initial work

## License

This project is licensed under the MIT License - see the LICENSE file for details.

---

Feel free to customize and expand this README as needed!