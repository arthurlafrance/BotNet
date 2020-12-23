## BotNet: Mancala

### Overview

BotNet's Mancala implementation features a minimal implementation of the game, currently only playable in a "simple" terminal-based text view. It allows one user player to play against an adversarial search-based opposing agent. The game currently doesn't support either capture or avalanche rules, although they may be added in the future (see below).

### Contents

The source code for Mancala is comprised of:
* `CMakeLists.txt`: defines the `cmake` build for the Mancala library.
* `models/`: defines the Mancala game models.
* `views/`: defines the Mancala views.
* `main.cpp`: provides a main function for running Mancala from the BotNet CLI.

Also, in the root project directory, the `include/mancala` directory contains the headers exposed by the Mancala library; their corresponding source files are available in one of the above places.

Unit tests for Mancala are available in the `tests/mancala` directory in the root project directory.

### Use

To run Mancala using BotNet, run the BotNet CLI with the following command: `botnet run mancala`

This will run Mancala in the terminal.

### Future

In the future, Mancala may gain support for:
* Multiple adversarial search strategies (e.g. minimax, expectimax, etc)
* Multiple types of views (e.g. ncurses)
