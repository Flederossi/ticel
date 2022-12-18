# ticel
A simple simulation engine for life-like cellular automata.

It supports both B/S notation and S/B notation, and is thus capable of simulating any lifelike cellular automaton.

## Usage
```
ticel [optional: rulestring]
```

### Mouseevents
|Button|Function|
|------|--------|
|Left|Set the cell the mouse is on to alive|
|Right|Set the cell the mouse is on to dead|
|Middle|Set all cells to dead|

### Keystrokes
|Key|Function|
|---|--------|
|S|Start the simulation|
|R|Start the simulation with a random board|
|Esc|Exit the simulation|

## Installation
There are to ways to use the engine:
### 1. Compile it from source
> To compile the source code you need to install [SDL](https://www.libsdl.org) and put it into the src/include and src/lib folder.
> Then you can use in the root of the project:
> ```
> make run
> ```
> Now a window should open with the B2/S1 cellular automaton.
### 2. Use prebuilt binary:
> You can also go to the releases tab and download the latest executable of ticle to get started.
