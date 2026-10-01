import json
from datetime import date
from pathlib import Path
import curses
import time
import subprocess

WORK_MINUTES = 1
SHORT_BREAK = 1
LONG_BREAK = 2

STATS_FILE = Path.home() / ".pomodoro_stats.json"


def load_stats():
    if STATS_FILE.exists():
        with open(STATS_FILE, "r") as f:
            return json.load(f)

    return {}


def save_stats(stats):
    with open(STATS_FILE, "w") as f:
        json.dump(stats, f, indent=4)


def record_focus_session(minutes):
    stats = load_stats()

    today = str(date.today())

    if today not in stats:
        stats[today] = {
            "sessions": 0,
            "focus_minutes": 0
        }

    stats[today]["sessions"] += 1
    stats[today]["focus_minutes"] += minutes

    save_stats(stats)

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
            duration = WORK_MINUTES * 10
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
            record_focus_session(WORK_MINUTES)

            if session % 4 == 0:
                notify("🍅 Pomodoro", "Focus complete! Time for a long break.")
            else:
                notify("🍅 Pomodoro", "Focus complete! Time for a short break.")

            mode = "BREAK"
        else:
            notify("🍅 Pomodoro", "Break is over. Ready to focus?")
            mode = "FOCUS"

curses.wrapper(main)
