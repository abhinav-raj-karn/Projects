#include "raylib.h"

#include <math.h>
#include <stddef.h>
#include <time.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600
#define BALL_COUNT 3

#define GRAVITY 1700.0f
#define BALL_RESTITUTION 1.0f   // perfectly elastic ball-to-ball collisions
#define WALL_RESTITUTION 0.96f  // a little energy lost on walls / floor
#define MIN_FLOOR_BOUNCE 540.0f // keeps the balls hopping forever
#define MAX_STEP (1.0f / 240.0f)

typedef struct Ball {
    Vector2 pos;
    Vector2 vel;
    float radius;
    float mass;
    Color color;
} Ball;

static void ResolveBallCollision(Ball *a, Ball *b)
{
    Vector2 delta = {b->pos.x - a->pos.x, b->pos.y - a->pos.y};
    float distSq = delta.x * delta.x + delta.y * delta.y;
    float minDist = a->radius + b->radius;

    if (distSq >= minDist * minDist) return;

    float dist = sqrtf(distSq);
    Vector2 normal = {1.0f, 0.0f};
    if (dist > 0.0001f) {
        normal.x = delta.x / dist;
        normal.y = delta.y / dist;
    }

    // Push the overlapping balls apart, weighted by mass.
    float overlap = minDist - dist;
    float totalMass = a->mass + b->mass;
    a->pos.x -= normal.x * overlap * (b->mass / totalMass);
    a->pos.y -= normal.y * overlap * (b->mass / totalMass);
    b->pos.x += normal.x * overlap * (a->mass / totalMass);
    b->pos.y += normal.y * overlap * (a->mass / totalMass);

    // Relative velocity along the collision normal.
    Vector2 relVel = {b->vel.x - a->vel.x, b->vel.y - a->vel.y};
    float velAlongNormal = relVel.x * normal.x + relVel.y * normal.y;

    // Already moving apart.
    if (velAlongNormal > 0.0f) return;

    float impulseMagnitude = -(1.0f + BALL_RESTITUTION) * velAlongNormal /
                             (1.0f / a->mass + 1.0f / b->mass);
    Vector2 impulse = {impulseMagnitude * normal.x, impulseMagnitude * normal.y};

    a->vel.x -= impulse.x / a->mass;
    a->vel.y -= impulse.y / a->mass;
    b->vel.x += impulse.x / b->mass;
    b->vel.y += impulse.y / b->mass;
}

static void UpdateBall(Ball *ball, float dt)
{
    ball->vel.y += GRAVITY * dt;
    ball->pos.x += ball->vel.x * dt;
    ball->pos.y += ball->vel.y * dt;

    if (ball->pos.x - ball->radius < 0.0f) {
        ball->pos.x = ball->radius;
        ball->vel.x = -ball->vel.x * WALL_RESTITUTION;
    } else if (ball->pos.x + ball->radius > SCREEN_WIDTH) {
        ball->pos.x = SCREEN_WIDTH - ball->radius;
        ball->vel.x = -ball->vel.x * WALL_RESTITUTION;
    }

    if (ball->pos.y - ball->radius < 0.0f) {
        ball->pos.y = ball->radius;
        ball->vel.y = -ball->vel.y * WALL_RESTITUTION;
    } else if (ball->pos.y + ball->radius > SCREEN_HEIGHT) {
        ball->pos.y = SCREEN_HEIGHT - ball->radius;
        float bounce = -ball->vel.y * WALL_RESTITUTION;
        ball->vel.y = -fmaxf(bounce, MIN_FLOOR_BOUNCE);
    }
}

static void UpdatePhysics(Ball balls[BALL_COUNT], float dt)
{
    for (int i = 0; i < BALL_COUNT; i++) UpdateBall(&balls[i], dt);

    // A couple of relaxation passes keep stacked collisions stable.
    for (int pass = 0; pass < 2; pass++) {
        for (int i = 0; i < BALL_COUNT; i++) {
            for (int j = i + 1; j < BALL_COUNT; j++) {
                ResolveBallCollision(&balls[i], &balls[j]);
            }
        }
    }
}

static void DrawBall(const Ball *ball)
{
    // Soft glow behind the ball.
    DrawCircleGradient((int)ball->pos.x, (int)ball->pos.y, ball->radius * 2.4f,
                       Fade(ball->color, 0.22f), BLANK);
    DrawCircleV(ball->pos, ball->radius, ball->color);

    // Small specular highlight to make the ball look glossy.
    Vector2 highlight = {
        ball->pos.x - ball->radius * 0.32f,
        ball->pos.y - ball->radius * 0.36f,
    };
    DrawCircleV(highlight, ball->radius * 0.22f, Fade(WHITE, 0.75f));
}

int main(void)
{
    SetRandomSeed((unsigned int)time(NULL));
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Elastic Balls");
    SetTargetFPS(120);

    Ball balls[BALL_COUNT] = {
        {{170.0f, 160.0f}, {260.0f, -90.0f}, 27.0f, 0.0f, {255, 64, 129, 255}},
        {{450.0f, 300.0f}, {-240.0f, 140.0f}, 22.0f, 0.0f, {255, 170, 40, 255}},
        {{730.0f, 210.0f}, {190.0f, 230.0f}, 31.0f, 0.0f, {45, 226, 210, 255}},
    };

    for (int i = 0; i < BALL_COUNT; i++) {
        balls[i].mass = balls[i].radius * balls[i].radius;
    }

    while (!WindowShouldClose()) {
        float frameTime = GetFrameTime();
        if (frameTime > 0.05f) frameTime = 0.05f;

        int steps = (int)ceilf(frameTime / MAX_STEP);
        if (steps < 1) steps = 1;
        float step = frameTime / (float)steps;
        for (int i = 0; i < steps; i++) UpdatePhysics(balls, step);

        BeginDrawing();
        ClearBackground(BLACK);
        for (int i = 0; i < BALL_COUNT; i++) DrawBall(&balls[i]);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
