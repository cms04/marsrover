# Mars-Rover

## Ausführung

Das Programm wird kompiliert mit dem Befehl `make`. Anschließend wird das Programm mit `./marsrover` gestartet. Werden keine Parameter angegeben, startet das Programm standardmäßig mit einer Breite von 80 Zeichen, einer Länge von 20 Zeichen und der Befehlsfolge `MMLBBBBRMM`.

Optionale Parameter:

- `-b`: Eine Zeichenkette von Befehlen, bestehend aus den Zeichen `L` (nach links drehen), `R` (nach rechts drehen), `M` (nach vorne bewegen), `B` (Rückwärtsgang)
- `-w`: Eine positive Zahl, die die Breite des Feldes angibt
- `-h`: Eine positive Zahl, die die Höhe des Feldes angibt
- `-l`: Live-Eingabe aktivieren: Wird dieser Parameter gesetzt, kann der Rover per Live-Eingabe direkt vom Nutzer gesteuert werden.
- `-m`: Hilfe

Die Parameter `-b` und `-l` dürfen nicht gemeinsam benutzt werden!

## Execution

You can compile this program either with `make` or with `make marsrover`. Then you can start it with `./marsrover`. Without any parameters the programm will start with a width of 80 chars, a height of 20 chars and commands `MMLBBBBRMM`.

Optional parameters:

- `-b`: A string of rover commands made up of `L` (turn left), `R` (turn right), `M` (move forward) and `B` (move back)
- `-w`: The width of the mars map (unsigned int)
- `-h`: The height of the mars map (unsigned int)
- `-l`: Activates live input: If you set this parameter, the string of `-b` (or the default commands) will be ignored and you can enter commands (same commands as above plus `x` to terminate the program) in real time.
- `-m`: Help

You must not use `-l` and `-b` together!
