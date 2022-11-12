// The libraries included - Any packages contained within <..> are developed by C++ developers as a part of the "standard library" language and are included already. Any libraries contained within "...+.h" are external libraries such as raylib. 
#include <cstdio>
#include "raylib.h"

// This is the boolean to set up the capability of pausing the game. The game starts as paused as the boolean is set to true.
bool Paused = true;

// "int main()" is the entry point of the program. It is the function from where the program will start to execute.
int main()
{


// These are the window dimensions const ints. "const int" variables once declared are never going to change for the duration of the program. They need to be initialised immeditately. 
const int WindowWidth{1500};
const int WindowHeight{800};

// This initialises the window with its width, height and name.
InitWindow (WindowWidth, WindowHeight, "Asteroid Dodger");

// This starts the audio device in order to play audio.
InitAudioDevice();

// This is the setup for the background music using the Raylib LoadMusicStream function.
Music backgroundMusic = LoadMusicStream("resources/BackgroundMusic1.wav");
PlayMusicStream(backgroundMusic);

// This loads in the 2d texture.
Texture2D starfighter = LoadTexture("resources/StarFighter.png");


// These are random number generator functions.
int randValue = GetRandomValue(1000, 1500);
int randValue2 = GetRandomValue(50, 750);
int randValue3 = GetRandomValue(20, 200);

// Variable used to count frames.
int framesCounter = 0;
int framesCounter2 = 0;
int framesCounter3 = 0;

// Starfighter Coordinates. It's y and x axis and it's size(length).
int starfighter_x{750};
int starfighter_y{700};
int starfighter_length{40};

// Asteroids x and y coordinates.
int asteroid_x{750};
int asteroid_y{-100};
int asteroid2_x{1450};
int asteroid2_y{-1000};
int asteroid3_x{50};
int asteroid3_y{-2000};
int asteroid4_x{50};
int asteroid4_y{-2500};

// Each asteroids Size.
int asteroid_radius{50};
int asteroid2_radius{30};
int asteroid3_radius{20};
int asteroid4_radius{60};

// This is the asteroids basic movement speed.
int movement{10};

// Collision detection between asteroid and starfighter.
int l_starfighter_x{starfighter_x};
int r_starfighter_x{starfighter_x + starfighter_length};
int u_starfighter_y{starfighter_y};
int b_starfighter_y{starfighter_y + starfighter_length};

int l_asteroid_x{asteroid_x - asteroid_radius};
int r_asteroid_x{asteroid_x + asteroid_radius};
int u_asteroid_y{asteroid_y - asteroid_radius};
int b_asteroid_y{asteroid_y + asteroid_radius};

bool collision_with_asteroid = 
        (b_starfighter_y >= u_asteroid_y) && 
        (u_starfighter_y <= b_asteroid_y) && 
        (r_starfighter_x >= l_asteroid_x) && 
        (l_starfighter_x <= r_asteroid_x);

int l_asteroid2_x{asteroid2_x - asteroid2_radius};
int r_asteroid2_x{asteroid2_x + asteroid2_radius};
int u_asteroid2_y{asteroid2_y - asteroid2_radius};
int b_asteroid2_y{asteroid2_y + asteroid2_radius};

bool collision_with_asteroid2 = 
        (b_starfighter_y >= u_asteroid2_y) && 
        (u_starfighter_y <= b_asteroid2_y) && 
        (r_starfighter_x >= l_asteroid2_x) && 
        (l_starfighter_x <= r_asteroid2_x);

int l_asteroid3_x{asteroid3_x - asteroid3_radius};
int r_asteroid3_x{asteroid3_x + asteroid3_radius};
int u_asteroid3_y{asteroid3_y - asteroid3_radius};
int b_asteroid3_y{asteroid3_y + asteroid3_radius};

bool collision_with_asteroid3 = 
        (b_starfighter_y >= u_asteroid3_y) && 
        (u_starfighter_y <= b_asteroid3_y) && 
        (r_starfighter_x >= l_asteroid3_x) && 
        (l_starfighter_x <= r_asteroid3_x);

int l_asteroid4_x{asteroid4_x - asteroid4_radius};
int r_asteroid4_x{asteroid4_x + asteroid4_radius};
int u_asteroid4_y{asteroid4_y - asteroid4_radius};
int b_asteroid4_y{asteroid4_y + asteroid4_radius};

bool collision_with_asteroid4 =
        (b_starfighter_y >= u_asteroid4_y) && 
        (u_starfighter_y <= b_asteroid4_y) && 
        (r_starfighter_x >= l_asteroid4_x) && 
        (l_starfighter_x <= r_asteroid4_x);



 
        


// This is to set the target value that the window updates to 60 frames per second. This stops the player sprite from moving too fast when being controlled.
SetTargetFPS(60);

// The WindowShouldClose function detects the window close button and ESC key. Pressing either will close the window as it will change the boolean to true. The "while" loop is the beginning of the game loop.
while (WindowShouldClose() == false)
{   // The "if" statement will execute if it is true. If the space bar is pressed successively then the game will pause and unpause.
    if (IsKeyPressed(KEY_SPACE))
        Paused = !Paused;

    // This "if" statement states that if the game is not paused then carry out the functions within the braces.
    if (!Paused)
    {   // The "UpdateMusicStream" function plays the background music.
        UpdateMusicStream(backgroundMusic);
        
        
        // If the ship has a collision with an asteroid then "Game Over" text will be drawn onscreen and the starfighter will disappear far out of the window.
        if (collision_with_asteroid || collision_with_asteroid2 || collision_with_asteroid3 || collision_with_asteroid4)
        {
            // Game over text.
            DrawText("Game Over", 250, 250, 100, RED);
            // Starfighter disappears off screen.
            starfighter_y = 2000;    
        }

        // If there is no collision with the asteroid then the "else" statement will activate.
        else
        {
            // Update the edges of the objects. Updates the edges every frame.
            // Below are the coordinates on the asteroid where it can be collided with by the starfighter. 
            l_asteroid_x = asteroid_x - asteroid_radius;
            r_asteroid_x = asteroid_x + asteroid_radius;
            u_asteroid_y = asteroid_y - asteroid_radius;
            b_asteroid_y = asteroid_y + asteroid_radius;
            
            l_asteroid2_x = asteroid2_x - asteroid2_radius;
            r_asteroid2_x = asteroid2_x + asteroid2_radius;
            u_asteroid2_y = asteroid2_y - asteroid2_radius;
            b_asteroid2_y = asteroid2_y + asteroid2_radius;
            
            l_asteroid3_x = asteroid3_x - asteroid3_radius;
            r_asteroid3_x = asteroid3_x + asteroid3_radius;
            u_asteroid3_y = asteroid3_y - asteroid3_radius;
            b_asteroid3_y = asteroid3_y + asteroid3_radius;
            
            l_asteroid4_x = asteroid4_x - asteroid4_radius;
            r_asteroid4_x = asteroid4_x + asteroid4_radius;
            u_asteroid4_y = asteroid4_y - asteroid4_radius;
            b_asteroid4_y = asteroid4_y + asteroid4_radius;
        
            l_starfighter_x = starfighter_x;
            r_starfighter_x = starfighter_x + starfighter_length;
            u_starfighter_y = starfighter_y;
            b_starfighter_y = starfighter_y + starfighter_length;
            
            // Below shows all the sides where the starfighter can collide with the asteroid. Updates the collision_with_asteroid
            
            collision_with_asteroid = 
                (b_starfighter_y >= u_asteroid_y) && 
                (u_starfighter_y <= b_asteroid_y) && 
                (r_starfighter_x >= l_asteroid_x) && 
                (l_starfighter_x <= r_asteroid_x) ;
            
            collision_with_asteroid2 =
                (b_starfighter_y >= u_asteroid2_y) &&
                (u_starfighter_y <= b_asteroid2_y) && 
                (r_starfighter_x >= l_asteroid2_x) && 
                (l_starfighter_x <= r_asteroid2_x);
            
            collision_with_asteroid3 = 
                (b_starfighter_y >= u_asteroid3_y) && 
                (u_starfighter_y <= b_asteroid3_y) && 
                (r_starfighter_x >= l_asteroid3_x) && 
                (l_starfighter_x <= r_asteroid3_x);
            
            collision_with_asteroid4 = 
                (b_starfighter_y >= u_asteroid4_y) && 
                (u_starfighter_y <= b_asteroid4_y) && 
                (r_starfighter_x >= l_asteroid4_x) && 
                (l_starfighter_x <= r_asteroid4_x);
            
           
        }

        // Every two seconds (120 frames) a new random value is generated in the three "if" statements below.
        framesCounter++;
        if (((framesCounter/10)%2) == 1)
        {   // I created three random number generators below. The first one generates random numbers for placement of the asteroids on the y-axis.
            randValue = GetRandomValue(-100, -500);
            framesCounter = 0;
        }
        
        framesCounter2++; 
        if (((framesCounter2/10)%2) == 1)
        {   // This random number generator generates numbers to dictate where the asteroid will be placed on the x-axis when it comes down for another pass.
            randValue2 = GetRandomValue(50, 1450);
            framesCounter2 = 0;
        }

        framesCounter3++; 
        if (((framesCounter3/10)%2) == 1)
        {   // This random number generator generates numbers which will be used to dictate the radius of an asteroid when it comes back down again.
            randValue3 = GetRandomValue(20, 200);
            framesCounter3 = 0;
        }

        // This line of code starts the movement of the asteroids downwards on the y-axis.
        asteroid_y += movement;
        asteroid2_y += movement;
        asteroid3_y += movement;
        asteroid4_y += movement;
   
        // The condition below is if the asteroid is greater than the window height + 400 pixels then the asteroids position and size will be modified by the below instructions in the "if" statement.
        if (asteroid_y > WindowHeight + 400)
        {   // The asteroids position on the y-axis will change when above the window to a random number chosen by the randValue function.
            asteroid_y = randValue;
            // The asteroids position on the x-axis will change when above the window to a random number chosen by the randValue2 function.
            asteroid_x = randValue2;
            // The asteroids radius will change when above the window to a random number chosen by the randValue3 function.
            asteroid_radius = randValue3;
        }

        if (asteroid2_y > WindowHeight + 400)
        {   // The asteroids position on the y-axis will change when above the window to a random number chosen by the randValue function.
            asteroid2_y = randValue;
            // The asteroids position on the x-axis will change when above the window to a random number chosen by the randValue2 function.
            asteroid2_x = randValue2;
            // The asteroids radius will change when above the window to a random number chosen by the randValue3 function.
            asteroid2_radius = randValue3;
        }
        
        if (asteroid3_y > WindowHeight + 400)
        {   // The asteroids position on the y-axis will change when above the window to a random number chosen by the randValue function.
            asteroid3_y = randValue;
            // The asteroids position on the x-axis will change when above the window to a random number chosen by the randValue2 function.
            asteroid3_x = randValue2;
            // The asteroids radius will change when above the window to a random number chosen by the randValue3 function.
            asteroid3_radius = randValue3;
        }
        
        if (asteroid4_y > WindowHeight + 400)
        {   // The asteroids position on the y-axis will change when above the window to a random number chosen by the randValue function.
            asteroid4_y = randValue;
            // The asteroids position on the x-axis will change when above the window to a random number chosen by the randValue2 function.
            asteroid4_x = randValue2;
            // The asteroids radius will change when above the window to a random number chosen by the randValue3 function.
            asteroid4_radius = randValue3;
        }

        

        // The if statement checks to see if the "D" key is depressed. 
            if (IsKeyDown(KEY_D) && starfighter_x < 1450) /* "&&" is a logical AND*/
        // If the "D" key is depressed and it is within less than 1450 pixels on the x-axis then the sprite moves to the right on the "X" axis.
            {
                starfighter_x = starfighter_x + 20;
            }
        // This if statement checks to see if the "A" key is depressed.
            if (IsKeyDown(KEY_A) && starfighter_x > 50)
        // If the "A" key is depressed and it is within greater than 50 pixels on the x-axis then the sprite moves to the left on the "X" axis.
            {
                starfighter_x = starfighter_x - 20;
            }
        // This if statement checks to see if the "S" key is depressed.
            if (IsKeyDown(KEY_S) && starfighter_y < 740)
        // If the "S" key is depressed and it is within less than 740 pixels on the y-axis then the sprite may move downwards on the "Y" axis
            {
                starfighter_y = starfighter_y + 20;
            }
        // This if statement checks to see if the "W" key is depressed.    
            if (IsKeyDown(KEY_W)  && starfighter_y > 150)
        // If the "W" key is depressed and it is within greater than 150 pixels on the y-axis then the sprite moves upwards on the "Y" axis.
            {
                starfighter_y = starfighter_y - 20;
            }  
    }
    
    // BeginDrawing sets up the canvas.
    BeginDrawing();
    // Clear Background is used to set up the colour of the window.
    ClearBackground(BLACK);

    // Starfighter Texture
    DrawTexture(starfighter, starfighter_x - starfighter.width/2, starfighter_y - starfighter.height/2, WHITE);
     
    //Asteroids represented by circles
     DrawCircle(asteroid_x, asteroid_y, asteroid_radius, BROWN);
     DrawCircle(asteroid2_x, asteroid2_y, asteroid2_radius, ORANGE);
     DrawCircle(asteroid3_x, asteroid3_y, asteroid3_radius, PURPLE);
     DrawCircle(asteroid4_x, asteroid4_y, asteroid4_radius, BLUE);
 
    if (Paused)
    {
        // DrawText
        DrawText("DODGE ALL ASTEROIDS", 200, 100, 90, RED);
        DrawText("Paused", 650, 500, 60, RED);
        DrawText("CONTROLS:", 200, 360, 60, WHITE);
        DrawText("Move Left = A   Move Right = D", 550, 360, 20, RED);  
        DrawText("Move Up   = W   Move Down = S", 550, 380, 20, RED);
        DrawText("Pause = SPACE", 590, 420, 20, RED);
    }
        
       


EndDrawing();

}

CloseAudioDevice();
CloseWindow();
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

            
        

            Draw background image twice
            // NOTE: Texture is scaled twice its size
            DrawTextureEx(background, (Vector2){ 20, scrollingBack }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(background, (Vector2){ 20, background.height*2 + scrollingBack }, 0.0f, 2.0f, WHITE);

            Draw midground image twice
            DrawTextureEx(midground, (Vector2){ scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(midground, (Vector2){ midground.width*2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE);

            Draw foreground image twice
            DrawTextureEx(foreground, (Vector2){ scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(foreground, (Vector2){ foreground.width*2 + scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
*/
// =====================================================================================================PARALLAX EXPERIMENT ABOVE
