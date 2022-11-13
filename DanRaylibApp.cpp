// The libraries included
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
Music backgroundMusic = LoadMusicStream("resources/BackgroundMusic1.2.wav");
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

// Starfighter Coordinate variables. It's y and x axis and it's size(length).
int starfighter_x{750};
int starfighter_y{700};
int starfighter_length{40};

// Asteroids x and y coordinate variables.
int asteroid_x{750};
int asteroid_y{-100};
int asteroid2_x{1450};
int asteroid2_y{-1000};
int asteroid3_x{50};
int asteroid3_y{-2000};
int asteroid4_x{50};
int asteroid4_y{-2500};
int asteroid5_x{50};
int asteroid5_y{-2500};

// Each asteroids radius size variable.
int asteroid_radius{50};
int asteroid2_radius{30};
int asteroid3_radius{20};
int asteroid4_radius{60};
int asteroid5_radius{100};

// This is the asteroids basic movement speed.
int movement{10};

// This is establishing the sides of the starfighter so that it can be collided with.
int l_starfighter_x{starfighter_x};
int r_starfighter_x{starfighter_x + starfighter_length};
int u_starfighter_y{starfighter_y};
int b_starfighter_y{starfighter_y + starfighter_length};

// This is establishing the sides of the asteroid so that it can be collided with.
int l_asteroid_x{asteroid_x - asteroid_radius};
int r_asteroid_x{asteroid_x + asteroid_radius};
int u_asteroid_y{asteroid_y - asteroid_radius};
int b_asteroid_y{asteroid_y + asteroid_radius};

/* This boolean "collision_with_asteroid" will be made true when bottom of the starfighter touches the top of the asteroid,
 if the top of the startighter touches the bottom of the asteroid, if the right side of the starfighter touches the left side of the asteroid and
 if the left side of the starfighter touches the right side of the asteroid. I've repeated this for each asteroid. */
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

int l_asteroid5_x{asteroid5_x - asteroid5_radius};
int r_asteroid5_x{asteroid5_x + asteroid5_radius};
int u_asteroid5_y{asteroid5_y - asteroid5_radius};
int b_asteroid5_y{asteroid5_y + asteroid5_radius};

bool collision_with_asteroid5 =
        (b_starfighter_y >= u_asteroid5_y) && 
        (u_starfighter_y <= b_asteroid5_y) && 
        (r_starfighter_x >= l_asteroid5_x) && 
        (l_starfighter_x <= r_asteroid5_x);

 
// This is to set the target value that the window updates to 60 frames per second. This stops the player sprite from moving too fast when being controlled.
SetTargetFPS(60);

// The WindowShouldClose function detects the window close button and ESC key. Pressing either will close the window as it will change the boolean to true. The "while" loop is the beginning of the game loop.
while (WindowShouldClose() == false)
{   // The "if" statement will execute if it is true. If the space bar is pressed successively then the game will pause and unpause.
    if (IsKeyPressed(KEY_SPACE))
        Paused = !Paused;
    
    // This "if" statement states that if the game is not paused then carry out the functions within the braces.
    if (!Paused)
    {   
        // The "UpdateMusicStream" function plays the background music.
        UpdateMusicStream(backgroundMusic);
        
        
        /* If the ship has a collision with an asteroid then "Game Over" text will be
         drawn onscreen and the starfighter will disappear far out of the window. */
        if (collision_with_asteroid || collision_with_asteroid2 ||
             collision_with_asteroid3 || collision_with_asteroid4 ||
              collision_with_asteroid5)
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
            // Below are the coordinates on the asteroids sides where it can be collided with by the starfighter. 
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

            l_asteroid5_x = asteroid5_x - asteroid5_radius;
            r_asteroid5_x = asteroid5_x + asteroid5_radius;
            u_asteroid5_y = asteroid5_y - asteroid5_radius;
            b_asteroid5_y = asteroid5_y + asteroid5_radius;
        
            l_starfighter_x = starfighter_x;
            r_starfighter_x = starfighter_x + starfighter_length;
            u_starfighter_y = starfighter_y;
            b_starfighter_y = starfighter_y + starfighter_length;
            
            // Below shows all the sides where the starfighter can collide with the asteroids. It also updates collision_with_asteroid each frame.
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

            collision_with_asteroid5 = 
                (b_starfighter_y >= u_asteroid5_y) && 
                (u_starfighter_y <= b_asteroid5_y) && 
                (r_starfighter_x >= l_asteroid5_x) && 
                (l_starfighter_x <= r_asteroid5_x);
                 
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
            randValue3 = GetRandomValue(50, 200);
            framesCounter3 = 0;
        }

        // These lines of code start the movement of the asteroids downwards on the y-axis.
        asteroid_y += movement;
        asteroid2_y += movement;
        asteroid3_y += movement;
        asteroid4_y += movement;
        asteroid5_y += movement;
   
        /* The condition below is if the asteroid is greater than the window height + 400 pixels then the
         asteroids position and size will be modified by the below instructions in the "if" statement. */
        if (asteroid_y > WindowHeight + 400)
        {   // The asteroids position on the y-axis will change when above the window to a random number chosen by the randValue function.
            asteroid_y = randValue;
            // The asteroids position on the x-axis will change when above the window to a random number chosen by the randValue2 function.
            asteroid_x = randValue2;
            // The asteroids radius will change when above the window to a random number chosen by the randValue3 function.
            asteroid_radius = randValue3;
        }
        /* The condition below is if the asteroid is greater than the window height + 500 pixels then the
         asteroids position and size will be modified by the below instructions in the "if" statement. */
        if (asteroid2_y > WindowHeight + 500)
        {   // The asteroids position on the y-axis will change when above the window to a random number chosen by the randValue function.
            asteroid2_y = randValue;
            // The asteroids position on the x-axis will change when above the window to a random number chosen by the randValue2 function.
            asteroid2_x = randValue2;
            // The asteroids radius will change when above the window to a random number chosen by the randValue3 function.
            asteroid2_radius = randValue3;
        }
        /* The condition below is if the asteroid is greater than the window height + 600 pixels then the
         asteroids position and size will be modified by the below instructions in the "if" statement. */
        if (asteroid3_y > WindowHeight + 600)
        {   // The asteroids position on the y-axis will change when above the window to a random number chosen by the randValue function.
            asteroid3_y = randValue;
            // The asteroids position on the x-axis will change when above the window to a random number chosen by the randValue2 function.
            asteroid3_x = randValue2;
            // The asteroids radius will change when above the window to a random number chosen by the randValue3 function.
            asteroid3_radius = randValue3;
        }
        /* The condition below is if the asteroid is greater than the window height + 700 pixels then the
         asteroids position and size will be modified by the below instructions in the "if" statement. */
        if (asteroid4_y > WindowHeight + 700)
        {   // The asteroids position on the y-axis will change when above the window to a random number chosen by the randValue function.
            asteroid4_y = randValue;
            // The asteroids position on the x-axis will change when above the window to a random number chosen by the randValue2 function.
            asteroid4_x = randValue2;
            // The asteroids radius will change when above the window to a random number chosen by the randValue3 function.
            asteroid4_radius = randValue3;
        }
        /* The condition below is if the asteroid is greater than the window height + 800 pixels then the
         asteroids position and size will be modified by the below instructions in the "if" statement. */
        if (asteroid5_y > WindowHeight + 800)
        {   // The asteroids position on the y-axis will change when above the window to a random number chosen by the randValue function.
            asteroid5_y = randValue;
            // The asteroids position on the x-axis will change when above the window to a random number chosen by the randValue2 function.
            asteroid5_x = randValue2;
            // The asteroids radius will change when above the window to a random number chosen by the randValue3 function.
            asteroid5_radius = randValue3;
        }

        // This if statement checks to see if the "D" key is depressed. 
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

    //I am drawing circles as to represent the asteroids.
     DrawCircle(asteroid_x, asteroid_y, asteroid_radius, BROWN);
     DrawCircle(asteroid2_x, asteroid2_y, asteroid2_radius, GRAY);
     DrawCircle(asteroid3_x, asteroid3_y, asteroid3_radius, DARKGRAY);
     DrawCircle(asteroid4_x, asteroid4_y, asteroid4_radius, BEIGE);
     DrawCircle(asteroid5_x, asteroid5_y, asteroid5_radius, DARKBROWN);
 
    /* If the game is paused then I make the window display the name of the game,
     the word "Paused" and the controls for the game. */
    if (Paused)
    {
       
        DrawText("DODGE THE ASTEROIDS", 200, 100, 90, RED);
        DrawText("Paused", 650, 500, 60, RED);
        DrawText("CONTROLS:", 200, 360, 60, WHITE);
        DrawText("Move Left = A   Move Right = D", 550, 360, 20, RED);  
        DrawText("Move Up   = W   Move Down = S", 550, 380, 20, RED);
        DrawText("Pause = SPACE", 590, 420, 20, RED);
    }
        
// Enddrawing finalises the render instructions and sends them off to the GPU.
EndDrawing();

}

// CloseAudioDevice shuts down the audio device.
CloseAudioDevice();

// Closes the window and unloads the OpenGL context.
CloseWindow();
}