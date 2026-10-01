
import curses
import time

WORK_MINUTES = 1

def main(stdscr):
    curses.curs_set(0)
    stdscr.nodelay(True)
    stdscr.keypad(True)

    total_seconds = WORK_MINUTES * 60
    remaining = total_seconds
    paused = False

    while remaining > 0:
        stdscr.clear()

        minutes, seconds = divmod(remaining, 60)

        stdscr.addstr(2, 4, "🍅 POMODORO TIMER")
        stdscr.addstr(4, 4, "FOCUS SESSION", curses.A_BOLD)
        stdscr.addstr(6, 4, f"{minutes:02d}:{seconds:02d}")
        stdscr.addstr(8, 4, "PAUSED" if paused else "FOCUSING")
        stdscr.addstr(10, 4, "Space: Pause/Resume | Q: Quit")

        stdscr.refresh()

        key = stdscr.getch()

        if key in (ord("q"), ord("Q")):
            break

        if key == ord(" "):
            paused = not paused

        if not paused:
            time.sleep(1)
            remaining -= 1
        else:
            time.sleep(0.1)

    if remaining <= 0:
        stdscr.clear()
        stdscr.addstr(4, 4, "Focus session complete!")
        stdscr.addstr(6, 4, "Press any key to exit.")
        stdscr.nodelay(False)
        stdscr.getch()

curses.wrapper(main)
