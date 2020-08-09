# Mars-Rover

ProPra-Marsrover in C

Vorbereitungsprojekt für das C-Praktikum

## Ausführung

Das Programm wird kompiliert mit dem Befehl `make`. Anschließend wird das Programm mit `./marsrover` gestartet.

Optionale Parameter:

- `-b`: Eine Zeichenkette von Befehlen, bestehend aus den Zeichen `L` (nach links drehen), `R` (nach rechts drehen), `M` (nach vorne bewegen), `B` (Rückwärtsgang)
- `-w`: Eine positive Zahl, die die Breite des Feldes angibt
- `-h`: Eine positive Zahl, die die Höhe des Feldes angibt
- `-l`: Live-Eingabe aktivieren: Wird dieser Parameter gesetzt, wird die Befehlskette des Parameters `-b` (oder die Standard-Befehlsfolge) ignoriert. Statt dessen kann der Rover per Live-Eingabe direkt vom Nutzer gesteuert werden.

Werden keine Parameter angegeben, startet das Programm standardmäßig mit einer Breite von 80 Zeichen, einer Länge von 20 Zeichen und der Befehlsfolge `MMLBBBBRMM`.

## Funktionen

Wichtige Funktionen der Programmiersprache C, die verwendet werden sollten (schon verwendete sind mit (✔) markiert):

- Zeiger (✔)
- Eingabe von der Kommandozeile (✔)
- Eingabe während der Ausführung (✔)
- Strings, insbesondere wesentliche Funktionen der `string.h`-Bibliothek (✔)
- Unit-Tests mit dem check-Framework (✔)
- Arrays, insbesondere 2D-Arrays (✔)
- Dateihandling (öffnen, lesen, schreiben und schließen)
- optionale und verpflichende Kommendozeilenargumente (✔)
- Funktion `getopt` (✔)
- `grep` auf Dateien und in `stdin`
- einfache `make`-Skripte (✔)
- Headerdateien definieren und einbinden (✔)
- Verlinken mehrerer C-Dateien (✔)
- Debuggen mit `gdb`
- Eigene Datentypen definieren (✔)
- Kurznamen für Datentypen vergeben (✔)
- Punkt- und Pfeiloperator (✔)
- Enums, Unions und Bitfelder (✔)
- Rekursive Structs (✔)
- Verkettete Listen (✔)
- Manuelle Speicherverwaltung mit `malloc`, `realloc` und `free` (✔)
- Verwendung von `valgrind` (✔)
