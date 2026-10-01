
import curses
import time
import subprocess

WORK_MINUTES = 1
SHORT_BREAK = 1
LONG_BREAK = 2

def notify(title, message):
    subprocess.Popen([
        "notify-send",
        title,
        message
    ])

def main(stdscr):
    curses.curs_set(0)
    stdscr.nodelay(True)
    stdscr.keypad(True)

    session = 0
    mode = "FOCUS"

    while True:
        if mode == "FOCUS":
            duration = WORK_MINUTES * 60
        elif session % 4 == 0:
            duration = LONG_BREAK * 60
        else:
            duration = SHORT_BREAK * 60

        remaining = duration
        paused = False

        while remaining > 0:
            stdscr.clear()

            minutes, seconds = divmod(remaining, 60)

            stdscr.addstr(2, 4, "🍅 POMODORO TIMER")
            stdscr.addstr(4, 4, mode, curses.A_BOLD)
            stdscr.addstr(6, 4, f"{minutes:02d}:{seconds:02d}")
            stdscr.addstr(8, 4, f"Session: {session + 1}")
            stdscr.addstr(10, 4, "PAUSED" if paused else "RUNNING")
            stdscr.addstr(12, 4, "Space: Pause/Resume | Q: Quit")

            stdscr.refresh()

            key = stdscr.getch()

            if key in (ord("q"), ord("Q")):
                return

            if key == ord(" "):
                paused = not paused

            if not paused:
                time.sleep(1)
                remaining -= 1
            else:
                time.sleep(0.1)

        if mode == "FOCUS":
            session += 1

            if session % 4 == 0:
                notify("🍅 Pomodoro", "Focus complete! Time for a long break.")
            else:
                notify("🍅 Pomodoro", "Focus complete! Time for a short break.")

            mode = "BREAK"
        else:
            notify("🍅 Pomodoro", "Break is over. Ready to focus?")
            mode = "FOCUS"

curses.wrapper(main)
