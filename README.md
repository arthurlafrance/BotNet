# BotNet
A miscellaneous collection of (mostly game-playing) AI programs

## Current Status
This project is tentatively deprecated because I don't really have time to revisit it, but I'll un-archive it in the event that I ever come back to it. Although the prospect of ditching it is a bit sad considering the interesting things I wanted to pursue here, unfortunately I have other more pressing projects that need my attention for now.

## Overview
BotNet is a set of miscellaneous AI programs I felt inspired to write, either to gain experience, explore an idea I had, or purely for fun. To that end, they mostly take the form of game-playing intelligent agents (which in turn means that it includes playable bare-bones implementations of various games). Another important inspiration behind this project is a desire to sharpen my C++ skills, and to do so in a way that's fun, engaging, and open-source.

## Contents
Inside this repository, you'll find code that serves one of several main purposes:
* The (minimal) CLI implementation
* General implementations of various algorithmic concepts and techniques
* Implementations of each "subprogram", i.e. each specific application that I decide to write

## Installation & Use
In order to use BotNet, you have a few options. Either way, you should start by cloning the repository in a place that you're comfortable storing the code (at least temporarily).

If you'd like to make changes to the code while using BotNet, you can make the desired changes and run `./build` (from the root project directory) to build a new executable (for those curious, the build system uses CMake, which I'm sure is clearly visible in the code, but I've written scripts to automate the build process). After building, run `target/botnet [args]` to run BotNet using the specified arguments.

If you'd instead like to install the current cloned version of BotNet for more permanent use on your machine, run `./install` (note: you may need to run `sudo ./install`), which will install it at a standard system path that's accessible for normal terminal use. Note that the install script will (eventually) ask if you'd like to update the installed version of BotNet if a previous version is present. Note also that the provided uninstall script (`./uninstall`) does exactly what it sounds like; it uninstalls the current version of BotNet (if available).

The actual BotNet CLI is very simple; it contains only two commands:
* `botnet --version` or `botnet -v` returns the current BotNet version
* `botnet run [subprogram]` runs the specified subprogram
* `botnet --help` or `botnet -h` displays usage info about the BotNet CLI

## Still to Come
Below is a shortlist of subprograms I hope to complete eventually:
* An adversarial-search based mancala player
* Various agents capable of playing different variations of Tic Tac Toe
* A program capable of playing the puzzle game Threes (and potentially extended to other single-player puzzle games)
