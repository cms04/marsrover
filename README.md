# Mars-Rover

## Compile and run

You can compile this program either with `make` or with `make marsrover`. Then you can start it with `./marsrover` or with `make run`. Without any parameters the programm will start with a width of 80 chars, a height of 20 chars and commands `MMLBBBBRMM`.

Optional parameters:

- `-b`: A string of rover commands made up of `L` (turn left), `R` (turn right), `M` (move forward) and `B` (move back). Other commands will be ignored.
- `-w`: The width of the mars map (unsigned int)
- `-h`: The height of the mars map (unsigned int)
- `-l`: Activates live input: If you set this parameter, the string of `-b` (or the default commands) will be ignored and you can enter commands (same commands as shown in Option `-b` plus `x` to terminate the program) in real time.
- `-o`: Output file where the mars map is saved in
- `-i`: Input file that was created by an program execution with `-o`
