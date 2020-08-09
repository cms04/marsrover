# Mars-Rover

## Ausführung

Das Programm wird kompiliert mit dem Befehl `make`. Anschließend wird das Programm mit `./marsrover` gestartet.

Optionale Parameter:

- `-b`: Eine Zeichenkette von Befehlen, bestehend aus den Zeichen `L` (nach links drehen), `R` (nach rechts drehen), `M` (nach vorne bewegen), `B` (Rückwärtsgang)
- `-w`: Eine positive Zahl, die die Breite des Feldes angibt
- `-h`: Eine positive Zahl, die die Höhe des Feldes angibt
- `-l`: Live-Eingabe aktivieren: Wird dieser Parameter gesetzt, wird die Befehlskette des Parameters `-b` (oder die Standard-Befehlsfolge) ignoriert. Statt dessen kann der Rover per Live-Eingabe direkt vom Nutzer gesteuert werden.

Werden keine Parameter angegeben, startet das Programm standardmäßig mit einer Breite von 80 Zeichen, einer Länge von 20 Zeichen und der Befehlsfolge `MMLBBBBRMM`.
