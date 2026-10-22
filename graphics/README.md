# Elastic Balls

Three bright balls bouncing around a 900x600 black window, colliding elastically
with each other and the walls.

## Build & run

```sh
make
make run
```

The first `make` clones raylib 5.5 into `vendor/` and builds it locally, so no
system-wide raylib install is required. X11 development headers and OpenGL must
be available (they already are on this machine).

## Controls

- `Esc` — quit

## Physics

- Gravity pulls the balls down; the floor and walls bounce them back.
- Ball-to-ball collisions are perfectly elastic (restitution 1.0) with masses
  proportional to the square of each radius.
- A small minimum bounce speed keeps the animation running indefinitely.
- Fixed 240 Hz substeps keep the simulation stable regardless of frame rate.
