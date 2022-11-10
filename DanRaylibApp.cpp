// The libraries included - <..> = developed by C++ developers as a part of the "standard library" language and are included already. "...+.h" = external libraries such as raylib. 
#include <cstdio>
#include "raylib.h"

// "int main()" is the entry point of the program. It is the function from where the program will start to execute.
int main()
{

// Window Dimensions
const int WindowWidth{1500}; // "const int" variables once declared are never going to change for the duration of the program. They need to be initialised immeditately.
const int WindowHeight{800};

// Initialise the window
InitWindow (WindowWidth, WindowHeight, "Asteroid Dodger");

// Start audio device 
InitAudioDevice();

// Audio
// Sound explosionAudio = LoadSound("resources/explosion1.wav");

// Loads in 2d texture
Texture2D starfighter = LoadTexture("resources/StarFighter.png");
// Texture2D asteroid = LoadTexture("resources/Asteroid1.png");

// Random number generator
int randValue = GetRandomValue(1000, 2500);
int randValue2 = GetRandomValue(50, 750);
int randValue3 = GetRandomValue(40, 300);
// Variable used to count frames 
int framesCounter = 0;
int framesCounter2 = 0;
int framesCounter3 = 0;

// Starfighter Coordinates
int starfighter_x{750};
int starfighter_y{700};
int starfighter_length{40};


// Asteroid Coordinates
int asteroid_x{750};
int asteroid_y{-100};
// Asteroid Size
int asteroid_radius{50};
// Movement
int movement{10};

// Collision detection between asteroid and starfighter
int l_asteroid_x{asteroid_x - asteroid_radius};
int r_asteroid_x{asteroid_x + asteroid_radius};
int u_asteroid_y{asteroid_y - asteroid_radius};
int b_asteroid_y{asteroid_y + asteroid_radius};

int l_starfighter_x{starfighter_x};
int r_starfighter_x{starfighter_x + starfighter_length};
int u_starfighter_y{starfighter_y};
int b_starfighter_y{starfighter_y + starfighter_length};

 bool collision_with_asteroid = 
        (b_starfighter_y >= u_asteroid_y) && 
        (u_starfighter_y <= b_asteroid_y) && 
        (r_starfighter_x >= l_asteroid_x) && 
        (l_starfighter_x <= r_asteroid_x);


// This is to set the target value that the window updates to 60 frames per second. This stops the player sprite from moving too fast when being controlled.
SetTargetFPS(60);


while (WindowShouldClose() == false)
{
    if (collision_with_asteroid)
    {
        // PlaySound(explosionAudio);
        DrawText("Game Over", 250, 250, 100, RED);
        starfighter_y = 2000;
        
    }

    else
    {
        // Update the edges of the objects. Updates the edges every frame
        l_asteroid_x = asteroid_x - asteroid_radius;
        r_asteroid_x = asteroid_x + asteroid_radius;
        u_asteroid_y = asteroid_y - asteroid_radius;
        b_asteroid_y = asteroid_y + asteroid_radius;
        l_starfighter_x = starfighter_x;
        r_starfighter_x = starfighter_x + starfighter_length;
        u_starfighter_y = starfighter_y;
        b_starfighter_y = starfighter_y + starfighter_length;
        // Update the collision_with_axe
        collision_with_asteroid = 
            (b_starfighter_y >= u_asteroid_y) && 
            (u_starfighter_y <= b_asteroid_y) && 
            (r_starfighter_x >= l_asteroid_x) && 
            (l_starfighter_x <= r_asteroid_x);
    }

     // Every two seconds (120 frames) a new random value is generated
     framesCounter++;
    if (((framesCounter/120)%2) == 1)
    {
        randValue = GetRandomValue(-100, -200);
        framesCounter = 0;
    }
    
    framesCounter2++; 
    if (((framesCounter2/120)%2) == 1)
    {
        randValue2 = GetRandomValue(50, 1450);
        framesCounter2 = 0;
    }

    framesCounter3++; 
    if (((framesCounter2/120)%2) == 1)
    {
        randValue3 = GetRandomValue(40, 300);
        framesCounter3 = 0;
    }

    asteroid_y += movement;

    /* if (asteroid_y > randValue)
     {
        asteroid_radius = 0;
        movement = -movement;
     }
     */
     
     if (asteroid_y > WindowHeight + 400)
     {
        asteroid_y = randValue /*+= movement*/;
        asteroid_x = randValue2;
        asteroid_radius = randValue3;
     }

     /* if (asteroid_y < -200)
     {
        asteroid_radius = 100;
        movement = -movement;
        asteroid_x = randValue2;
     }
     */
    

    

    // The if statement checks to see if the key is depressed. If the "D" key is depressed then the sprite moves to the right on the "X" axis.
        if (IsKeyDown(KEY_D) && starfighter_x < 1450) /* && = An example of logical AND*/
    
        {
            starfighter_x = /*+= 10*/ starfighter_x + 20;
        }
    // This if statement checks to see if the "A" key is depressed.  
        if (IsKeyDown(KEY_A) && starfighter_x > 50)
    // If the "A" key is depressed then the sprite moves to the left on the "X" axis
        {
            starfighter_x = /*-= 10*/ starfighter_x - 20;
        }
     // This if statement checks to see if the key is depressed.
        if (IsKeyDown(KEY_S) && starfighter_y < 740)
    // If the "S" key is depressed and it is within less than 975 pixels then the sprite may move downwards on the "Y" axis
        {
            starfighter_y = /*+= 10*/ starfighter_y + 20;
        }
    // This if statement checks to see if the key is depressed.    
        if (IsKeyDown(KEY_W)  && starfighter_y > 150)
    // If the "W" key is depressed then the sprite moves upward on the "Y" axis
        {
            starfighter_y = /*-= 10*/ starfighter_y - 20;
        }
    
   /* DrawText("Every 2 seconds a new random value is generated:", 130, 100, 20, MAROON);

            DrawText(TextFormat("%i", randValue), 360, 180, 80, LIGHTGRAY);
    
    DrawText("Every 2 seconds a new random value is generated:", 130, 100, 20, MAROON);

            DrawText(TextFormat("%i", randValue2), 420, 240, 80, LIGHTGRAY);
    */

    // BeginDrawing sets up the canvas
    BeginDrawing();
    // Clear Background is used to set up the colour of the window
    ClearBackground(BLACK);

    // Starfighter Texture
    DrawTexture(starfighter, starfighter_x - starfighter.width/2, starfighter_y - starfighter.height/2, WHITE);
    
    // Asteroid Texture
   // DrawTexture(asteroid, asteroid_x - asteroid.width/2, asteroid_y - asteroid.height/2, WHITE);
    
    
    // DrawRectangle(starfighter_x, starfighter_y, 80, 80, WHITE);
    //Asteroid represented by circle
     DrawCircle(asteroid_x, asteroid_y, asteroid_radius, BROWN);
     DrawCircle(asteroid_x, asteroid_y, asteroid_radius, BROWN);
 


EndDrawing();

}

}




/*
 Texture2D background = LoadTexture("resources/starfield1.png");
 Texture2D midground = LoadTexture("resources/starfield2.png");
 Texture2D foreground = LoadTexture("resources/starfield3.png");

    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;
*/

// =====================================================================================================PARALLAX EXPERIMENT BELOW
 /*   // Parallax Scrolling Starfield Background
        scrollingBack += 0.1f;
        scrollingMid += 0.5f;
        scrollingFore += 1.0f;
    
     // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
        if (scrollingBack <= -background.height*2) scrollingBack = 0;
        if (scrollingMid <= -midground.height*2) scrollingMid = 0;
        if (scrollingFore <= -foreground.height*2) scrollingFore = 0;
    
    

 // Draw background image twice
            // NOTE: Texture is scaled twice its size
            DrawTextureEx(background, (Vector2){ -20, scrollingBack }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(background, (Vector2){ -20, background.height*2 + scrollingBack }, 0.0f, 2.0f, WHITE);

            // Draw midground image twice
            DrawTextureEx(midground, (Vector2){ -20, scrollingMid }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(midground, (Vector2){ -20, midground.height*2 + scrollingMid }, 0.0f, 2.0f, WHITE);

            // Draw foreground image twice
            DrawTextureEx(foreground, (Vector2){ -70, scrollingFore }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(foreground, (Vector2){ -70, foreground.height*2 + scrollingFore }, 0.0f, 2.0f, WHITE);
*/

 // Update
       /* //----------------------------------------------------------------------------------
        scrollingBack += 0.1f;
        scrollingMid -= 0.5f;
        scrollingFore -= 1.0f;

        // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
        if (scrollingBack <= -background.height*2) scrollingBack = 0;
        if (scrollingMid <= -midground.width*2) scrollingMid = 0;
        if (scrollingFore <= -foreground.width*2) scrollingFore = 0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------

            
        

            // Draw background image twice
            // NOTE: Texture is scaled twice its size
            DrawTextureEx(background, (Vector2){ 20, scrollingBack }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(background, (Vector2){ 20, background.height*2 + scrollingBack }, 0.0f, 2.0f, WHITE);

            // Draw midground image twice
            DrawTextureEx(midground, (Vector2){ scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(midground, (Vector2){ midground.width*2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE);

            // Draw foreground image twice
            DrawTextureEx(foreground, (Vector2){ scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(foreground, (Vector2){ foreground.width*2 + scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
*/
// =====================================================================================================PARALLAX EXPERIMENT ABOVE
