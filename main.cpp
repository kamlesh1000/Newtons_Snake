#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>

#undef main

using namespace std;

string name;

TTF_Font *font = NULL;
SDL_Color textColor = { 250, 100, 50 };

const int FPS = 60;
int frameWidth, frameHeight,textureWidth, textureHeight,frameTime = 0,i=1,j=0,a=1,b=1,c=1,p=1,difficulty;

void init(void);
void logo(void);
void back_ground(void);

void mouse_action(void);
void cursor_newgame(void);
void cursor_loadgame(void);
void cursor_options(void);
void cursor_highscore(void);
void cursor_credits(void);
void cursor_exit(void);

void page_action1(void);
void page_action2(void);
void page_action3(void);
void page_action4(void);
void page_action5(void);
void page_action6(void);

void newgame(void);
void loadgame(void);
void options(void);
void highscore(void);
void credits(void);
void exit(void);

void newgame_difficulty(void);
void page_action1_action(void);
void main_game(int);
void game_description(void);


SDL_Window *window = NULL;
SDL_Surface *surface = NULL;
SDL_Surface *cursor_surface = NULL;
SDL_Renderer *renderTarget = NULL;
SDL_Texture *currentImage = NULL;
SDL_Texture *cursor_menu = NULL;
SDL_Surface *text;

SDL_Event event;
SDL_Event event1;
SDL_Event event2;
SDL_Event event3;
SDL_Event event4;
SDL_Event event5;
SDL_Event event6;
SDL_Event event7;
SDL_Event event8;
SDL_Event event9;

SDL_Rect logoRect;
SDL_Rect cursor_Rect;


Mix_Music *logo1;
Mix_Music *logo2;
Mix_Music *bgsound;
Mix_Music *maingame;
Mix_Music *over;
Mix_Chunk *click;
Mix_Chunk *bang;
Mix_Chunk *changedir;

bool isRunning = true;

SDL_Surface* trophy_image;
SDL_Surface* ground_image;
SDL_Surface* tail_image;
SDL_Surface* head_right;
SDL_Surface* head_left;
SDL_Surface* head_up;
SDL_Surface* head_down;
SDL_Surface* score_board;
SDL_Surface* currentlevel;
SDL_Surface* currentscore;
SDL_Surface* wrongfruit;
SDL_Surface* gameover;
SDL_Surface* scoresurface;
SDL_Surface* c_answer;
SDL_Surface* w_answer1;
SDL_Surface* w_answer2;
SDL_Surface* W_answer3;
SDL_Surface* squestion;
SDL_Surface* tail_up;
SDL_Surface* tail_down;
SDL_Surface* tail_right;
SDL_Surface* tail_left;

SDL_Texture* trophy;
SDL_Texture* score_display;
SDL_Texture* ground;
SDL_Texture* tailtex;
SDL_Texture* head_snake;
SDL_Texture* tquestion;
SDL_Texture* tc_answer;
SDL_Texture* tw_answer1;
SDL_Texture* tw_answer2;
SDL_Texture* tw_answer3;
SDL_Texture* current_score;
SDL_Texture* current_level;
SDL_Texture* scoretexture;

const int window_width = 1366;
const int window_height = 766;
const int innerw = 881;
const int innerh = 740;
int posx,posy;
int fruitx, fruity,wfruit1x,wfruit1y,wfruit2x,wfruit2y,wfruit3x,wfruit3y;
int score,speed,ntail;
int tailx[100], taily[100];
enum Direction {UP,LEFT,RIGHT,DOWN};
Direction dir;

void background();
void fruit();
void render_update();
void scoreboard();
void display_wrongfruit();
void eat_fruit();
void check_collision();
void input();
void levelboard();
void draw();
void logic();
void setup();
void game_over();
void question();

//highscore:

class high
{
private:
    int q;

public:

    void getscore(int sc)
    {
       q=sc;

    }

    int retScore()
    {
        return q;
    }
};

class high_name
{
private:
    string r;

public:

    void getname(string na)
    {
       r=na;

    }

    string retname()
    {
        return r;
    }
};

int e[11],temp;
string f[11],temp_nam;
void highscore_cal();
void create_score();
void create_name();
int show_score1();
int show_score2();
int show_score3();
int show_score4();
int show_score5();
int show_score6();
int show_score7();
int show_score8();
int show_score9();
int show_score10();
int show_score11();
string show_name1();
string show_name2();
string show_name3();
string show_name4();
string show_name5();
string show_name6();
string show_name7();
string show_name8();
string show_name9();
string show_name10();
string show_name11();



int main(int argc, char *argv[])
{
    init();
    logo();
    SDL_DestroyRenderer(renderTarget);
    SDL_DestroyTexture(currentImage);
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}



void init(void)
{
    window = SDL_CreateWindow("Newton's Snake",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1366,766,SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderTarget = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);

}

void logo(void)
{
    logo1 = Mix_LoadMUS("bg1.mp3");
    logo2 = Mix_LoadMUS("bg2.mp3");
    bgsound = Mix_LoadMUS("bg3.mp3");
    click = Mix_LoadWAV("click.wav");

    surface = SDL_LoadBMP("animation1.bmp");
    currentImage = SDL_CreateTextureFromSurface(renderTarget,surface);

    SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);

    frameWidth = textureWidth /3;
    frameHeight = textureHeight /4;

    logoRect.x = logoRect.y = 0;
    logoRect.w = frameWidth;
    logoRect.h = frameHeight;

    while(isRunning)
    {
        while (SDL_PollEvent(&event1))
        {
            if(event1.type==SDL_QUIT)
            {
                isRunning=false;
                break;
            }
        }

        frameTime++;

        if(FPS / frameTime == 12)
        {
            frameTime = 0;

            if(a==1)
            {
                Mix_PlayMusic(logo1,1);
                a++;
            }

            if(i<11 && ((i%3)!=0))
            {
                logoRect.x +=frameWidth;
                SDL_Delay(110);
            }

            if(i<11 && ((i%3)==0))
            {
                logoRect.x =0;
                logoRect.y +=frameHeight;
                SDL_Delay(110);
            }

            if(i==11)
            {
                surface = SDL_LoadBMP("animation2.bmp");
                currentImage =  SDL_CreateTextureFromSurface(renderTarget,surface);
                SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);
                frameWidth = textureWidth /3;
                frameHeight = textureHeight /3;

                logoRect.x = logoRect.y = 0;
                logoRect.w = frameWidth;
                logoRect.h = frameHeight;
            }

            if(i==12 || i==13 || i==15 || i==16)
            {
                logoRect.x +=frameWidth;
                SDL_Delay(20);
            }

            if(i==14 || i==17)
            {
                logoRect.x =0;
                logoRect.y +=frameHeight;
                SDL_Delay(20);
            }

            if(i==18)
            {
                SDL_Delay(20);

            }

            if(i==19)
            {
                logoRect.x =0;
                logoRect.y =0;
                SDL_Delay(20);
            }

            if (i==20 || i==21 || i==23 || i==24 || i==26)
            {
                logoRect.x +=frameWidth;
                SDL_Delay(20);
            }

            if(i==22 || i==25)
            {
                logoRect.x =0;
                logoRect.y +=frameHeight;
                SDL_Delay(20);
            }

            if(i>26 && i%2==0)
            {
                logoRect.x +=frameWidth;
                SDL_Delay(500);
            }

            if(i>26 && i%2!=0)
            {
                 if(b==1)
                {
                    Mix_PlayMusic(logo2,-1);
                    b++;
                }

                logoRect.x -=frameWidth;
                SDL_Delay(200);
            }

            if(i>26)
            {
                while(SDL_PollEvent(&event2)!= 0)
                {
                    if(event2.type == SDL_KEYDOWN)
                    {
                        if(c==1)
                        {
                            Mix_PlayMusic(bgsound,-1);
                            c++;
                        }
                        back_ground();
                    }
                }
            }

            i++;
        }

        SDL_RenderClear(renderTarget);
        SDL_RenderCopy(renderTarget, currentImage, &logoRect, NULL);
        SDL_RenderPresent(renderTarget);
    }
}




void back_ground(void)
{
    surface = SDL_LoadBMP("animation3.bmp");
    currentImage =  SDL_CreateTextureFromSurface(renderTarget,surface);
    SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);

    frameWidth = textureWidth /3;
    frameHeight = textureHeight;

    logoRect.x = logoRect.y = 0;
    logoRect.w = frameWidth;
    logoRect.h = frameHeight;

    while(isRunning)
    {
        while(SDL_PollEvent(&event3)!= 0)
        {
            if(event3.type == SDL_QUIT)
            {
                isRunning = false;
                break;
            }
        }
        SDL_RenderClear(renderTarget);
        SDL_RenderCopy(renderTarget, currentImage, &logoRect, NULL);
        SDL_RenderPresent(renderTarget);

        if((j%3) != 0)
        {
            logoRect.x +=frameWidth;
            SDL_Delay(300);
        }

        if((j%3) == 0)
        {
            logoRect.x = 0;
            SDL_Delay(300);
        }

        j++;


        mouse_action();

    }


}



void mouse_action(void)
{
    while(SDL_PollEvent(&event4))
    {
        if(event4.type == SDL_QUIT)
        {
            isRunning = false;
            break;
        }

        if(event4.motion.x >=1021 && event4.motion.x <=1251 && event4.motion.y >=204 && event4.motion.y <= 249)
        {
            cursor_newgame();
        }

        if(event4.motion.x >=1024 && event4.motion.x <=1250 && event4.motion.y >=300 && event4.motion.y <= 346)
        {
            cursor_loadgame();
        }

        if(event4.motion.x >=1021 && event4.motion.x <=1251 && event4.motion.y >=394 && event4.motion.y <= 440)
        {
            cursor_options();
        }

        if(event4.motion.x >=1023 && event4.motion.x <=1249 && event4.motion.y >=486 && event4.motion.y <= 531)
        {
            cursor_highscore();
        }

        if(event4.motion.x >=1022 && event4.motion.x <=1251 && event4.motion.y >=578 && event4.motion.y <= 625)
        {
            cursor_credits();
        }

        if(event4.motion.x >=1023 && event4.motion.x <=1252 && event4.motion.y >=670 && event4.motion.y <= 716)
        {
            cursor_exit();
        }

    }
}



void cursor_newgame(void)
{
    cursor_surface = SDL_LoadBMP("1a.bmp");
    cursor_menu = SDL_CreateTextureFromSurface(renderTarget,cursor_surface);

    cursor_Rect.x = 953;
    cursor_Rect.y = 189;
    cursor_Rect.w = 364;
    cursor_Rect.h = 69;

    while(isRunning)
    {
        while(SDL_PollEvent(&event5)!= 0)
        {

            SDL_RenderCopy(renderTarget,cursor_menu,NULL,&cursor_Rect);
            SDL_RenderPresent(renderTarget);

            if(event5.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event5.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    newgame();
                }
            }

            if((event5.motion.x <=1021 || event5.motion.x >=1259) || (event5.motion.y <=204 || event5.motion.y >= 249))
            {
                back_ground();
            }
        }
    }
}


void cursor_loadgame(void)
{
    cursor_surface = SDL_LoadBMP("2a.bmp");
    cursor_menu = SDL_CreateTextureFromSurface(renderTarget,cursor_surface);

    cursor_Rect.x = 956;
    cursor_Rect.y = 275;
    cursor_Rect.w = 360;
    cursor_Rect.h = 83;

    while(isRunning)
    {
        while(SDL_PollEvent(&event5)!= 0)
        {

            SDL_RenderCopy(renderTarget,cursor_menu,NULL,&cursor_Rect);
            SDL_RenderPresent(renderTarget);

            if(event5.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event5.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    loadgame();
                }
            }

            if((event5.motion.x <=1024 || event5.motion.x >=1250) || ( event5.motion.y <=300 || event5.motion.y >= 346))
            {
                back_ground();
            }
        }
    }

}

void cursor_options(void)
{
    cursor_surface = SDL_LoadBMP("3a.bmp");
    cursor_menu = SDL_CreateTextureFromSurface(renderTarget,cursor_surface);

    cursor_Rect.x = 956;
    cursor_Rect.y = 375;
    cursor_Rect.w = 363;
    cursor_Rect.h = 78;

    while(isRunning)
    {
        while(SDL_PollEvent(&event5)!= 0)
        {

            SDL_RenderCopy(renderTarget,cursor_menu,NULL,&cursor_Rect);
            SDL_RenderPresent(renderTarget);

            if(event5.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event5.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    options();
                }
            }

            if((event5.motion.x <=1021 || event5.motion.x >=1251) || (event5.motion.y <=394 || event5.motion.y >= 440))
            {
                back_ground();
            }
        }
    }
}

void cursor_highscore(void)
{
    cursor_surface = SDL_LoadBMP("4a.bmp");
    cursor_menu = SDL_CreateTextureFromSurface(renderTarget,cursor_surface);

    cursor_Rect.x = 956;
    cursor_Rect.y = 466;
    cursor_Rect.w = 365;
    cursor_Rect.h = 82;

    while(isRunning)
    {
        while(SDL_PollEvent(&event5)!= 0)
        {

            SDL_RenderCopy(renderTarget,cursor_menu,NULL,&cursor_Rect);
            SDL_RenderPresent(renderTarget);

            if(event5.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event5.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    highscore();
                }
            }

            if((event5.motion.x <=1023 || event5.motion.x >=1249) || (event5.motion.y <=486 || event5.motion.y >= 531))
            {
                back_ground();
            }
        }
    }
}

void cursor_credits(void)
{
    cursor_surface = SDL_LoadBMP("5a.bmp");
    cursor_menu = SDL_CreateTextureFromSurface(renderTarget,cursor_surface);

    cursor_Rect.x = 1021;
    cursor_Rect.y = 580;
    cursor_Rect.w = 231;
    cursor_Rect.h = 46;

    while(isRunning)
    {
        while(SDL_PollEvent(&event5)!= 0)
        {

            SDL_RenderCopy(renderTarget,cursor_menu,NULL,&cursor_Rect);
            SDL_RenderPresent(renderTarget);

            if(event5.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event5.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    credits();
                }
            }

            if((event5.motion.x <=1022 || event5.motion.x >=1251) || (event5.motion.y <=578 || event5.motion.y >= 625))
            {
                back_ground();
            }
        }
    }
}

void cursor_exit(void)
{
    cursor_surface = SDL_LoadBMP("6a.bmp");
    cursor_menu = SDL_CreateTextureFromSurface(renderTarget,cursor_surface);

    cursor_Rect.x = 953;
    cursor_Rect.y = 652;
    cursor_Rect.w = 373;
    cursor_Rect.h = 88;

    while(isRunning)
    {
        while(SDL_PollEvent(&event5)!= 0)
        {

            SDL_RenderCopy(renderTarget,cursor_menu,NULL,&cursor_Rect);
            SDL_RenderPresent(renderTarget);

            if(event5.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event5.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    exit();
                }
            }

            if((event5.motion.x <=1023 || event5.motion.x >=1252) || (event5.motion.y <=670 || event5.motion.y >= 716))
            {
                back_ground();
            }
        }
    }
}



void newgame()
{
    int x=0;
    SDL_RenderClear(renderTarget);
    surface = SDL_LoadBMP("new_game.bmp");
    logoRect.x = logoRect.y = 0;
    currentImage = SDL_CreateTextureFromSurface(renderTarget,surface);

    int nameEntered = 0;


    name = " ";
    text = NULL;

    TTF_Init();

    font = TTF_OpenFont( "melma.ttf", 50 );

    while( isRunning == true )
    {
        SDL_RenderCopy(renderTarget, currentImage, &logoRect, NULL);


        while( SDL_PollEvent( &event9 ) )
        {
             page_action1();
            if( nameEntered == 0 )
            {
                if( event9.type == SDL_KEYDOWN )
                {
                    string temp = name;

                    if( name.length() <= 9 )
                    {

                        if( event9.key.keysym.sym == (Uint16)' ' )
                        {
                            name += (char)event9.key.keysym.sym;
                            x=x+7;
                        }
                        else if( ( event9.key.keysym.sym >= (Uint16)'0' ) && ( event9.key.keysym.sym <= (Uint16)'9' ) )
                        {
                            name += (char)event9.key.keysym.sym;
                            x=x+27;
                        }
                        else if( ( event9.key.keysym.sym >= (Uint16)'A' ) && ( event9.key.keysym.sym <= (Uint16)'Z' ) )
                        {
                            name += (char)event9.key.keysym.sym;
                            x=x+27;
                        }
                        else if( ( event9.key.keysym.sym >= (Uint16)'a' ) && ( event9.key.keysym.sym <= (Uint16)'z' ) )
                        {
                            name += (char)event9.key.keysym.sym;
                            x=x+27;
                        }
                    }

                    if( ( event9.key.keysym.sym == SDLK_BACKSPACE ) && ( name.length() != 0 ) )
                    {
                    //Remove a character from the end
                        name.erase( name.length() - 1 );
                        x=x-27;
                    }

                    if( name != temp )
                    {
                        SDL_FreeSurface( text );
                        text = TTF_RenderText_Solid( font, name.c_str(), textColor );
                    }
                }
                if( ( event9.type == SDL_KEYDOWN ) && ( event9.key.keysym.sym == SDLK_RETURN ) )
                {
                    nameEntered = 1;
                    surface = SDL_LoadBMP("difficulty.bmp");
                    newgame_difficulty();
                }
            }
        }

        SDL_Texture *inpu = SDL_CreateTextureFromSurface(renderTarget,text);
        SDL_Rect blink;
        blink.x = 558;
        blink.y = 368;
        blink.w = x;
        blink.h = 30;

        SDL_RenderCopy(renderTarget,inpu,NULL,&blink);
        SDL_RenderPresent(renderTarget);

    }
    SDL_FreeSurface(text);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);

}

void loadgame(void)
{
    SDL_RenderClear(renderTarget);
    surface = SDL_LoadBMP("load_game.bmp");
    logoRect.x = logoRect.y = 0;
    currentImage = SDL_CreateTextureFromSurface(renderTarget,surface);
    while(isRunning)
    {
        SDL_RenderCopy(renderTarget, currentImage, &logoRect, NULL);
        SDL_RenderPresent(renderTarget);

    page_action2();
    }
}

void options(void)
{
    SDL_RenderClear(renderTarget);
    surface = SDL_LoadBMP("options.bmp");
    logoRect.x = logoRect.y = 0;
    currentImage = SDL_CreateTextureFromSurface(renderTarget,surface);
    while(isRunning)
    {
        SDL_RenderCopy(renderTarget, currentImage, &logoRect, NULL);
        SDL_RenderPresent(renderTarget);

    page_action3();
    }
}

void highscore()
{
    SDL_RenderClear(renderTarget);

    TTF_Init();
    TTF_Font *font= TTF_OpenFont( "melma.ttf",  50);
    SDL_Color textColor = { 255, 100, 20 };
    highscore_cal();
    stringstream ss0;
    ss0 << e[0];
    stringstream ss1;
    ss1 << e[1];
    stringstream ss2;
    ss2 << e[2];
     stringstream ss3;
    ss3 << e[3];
     stringstream ss4;
    ss4 << e[4];
     stringstream ss5;
    ss5 << e[5];
     stringstream ss6;
    ss6 << e[6];
     stringstream ss7;
    ss7 << e[7];
     stringstream ss8;
    ss8 << e[8];
     stringstream ss9;
    ss9 << e[9];


    SDL_Surface *text0 = TTF_RenderText_Solid( font, f[0].c_str(), textColor );
    SDL_Surface *text1 = TTF_RenderText_Solid( font, f[1].c_str(), textColor );
    SDL_Surface *text2 = TTF_RenderText_Solid( font, f[2].c_str(), textColor );
    SDL_Surface *text3 = TTF_RenderText_Solid( font, f[3].c_str(), textColor );
    SDL_Surface *text4 = TTF_RenderText_Solid( font, f[4].c_str(), textColor );
    SDL_Surface *text5 = TTF_RenderText_Solid( font, f[5].c_str(), textColor );
    SDL_Surface *text6 = TTF_RenderText_Solid( font, f[6].c_str(), textColor );
    SDL_Surface *text7 = TTF_RenderText_Solid( font, f[7].c_str(), textColor );
    SDL_Surface *text8 = TTF_RenderText_Solid( font, f[8].c_str(), textColor );
    SDL_Surface *text9 = TTF_RenderText_Solid( font, f[9].c_str(), textColor );

    SDL_Surface *number0 = TTF_RenderText_Solid( font, ss0.str().c_str(), textColor );
    SDL_Surface *number1 = TTF_RenderText_Solid( font, ss1.str().c_str(), textColor );
    SDL_Surface *number2 = TTF_RenderText_Solid( font, ss2.str().c_str(), textColor );
    SDL_Surface *number3 = TTF_RenderText_Solid( font, ss3.str().c_str(), textColor );
    SDL_Surface *number4 = TTF_RenderText_Solid( font, ss4.str().c_str(), textColor );
    SDL_Surface *number5 = TTF_RenderText_Solid( font, ss5.str().c_str(), textColor );
    SDL_Surface *number6 = TTF_RenderText_Solid( font, ss6.str().c_str(), textColor );
    SDL_Surface *number7 = TTF_RenderText_Solid( font, ss7.str().c_str(), textColor );
    SDL_Surface *number8 = TTF_RenderText_Solid( font, ss8.str().c_str(), textColor );
    SDL_Surface *number9 = TTF_RenderText_Solid( font, ss9.str().c_str(), textColor );


    surface = SDL_LoadBMP("highscore.bmp");
    currentImage = SDL_CreateTextureFromSurface(renderTarget,surface);

    SDL_Texture *inpu0  = SDL_CreateTextureFromSurface(renderTarget,text0);
    SDL_Texture *inpu1  = SDL_CreateTextureFromSurface(renderTarget,text1);
    SDL_Texture *inpu2  = SDL_CreateTextureFromSurface(renderTarget,text2);
    SDL_Texture *inpu3  = SDL_CreateTextureFromSurface(renderTarget,text3);
    SDL_Texture *inpu4  = SDL_CreateTextureFromSurface(renderTarget,text4);
    SDL_Texture *inpu5  = SDL_CreateTextureFromSurface(renderTarget,text5);
    SDL_Texture *inpu6  = SDL_CreateTextureFromSurface(renderTarget,text6);
    SDL_Texture *inpu7  = SDL_CreateTextureFromSurface(renderTarget,text7);
    SDL_Texture *inpu8  = SDL_CreateTextureFromSurface(renderTarget,text8);
    SDL_Texture *inpu9  = SDL_CreateTextureFromSurface(renderTarget,text9);

    SDL_Texture *highnum0  = SDL_CreateTextureFromSurface(renderTarget,number0);
    SDL_Texture *highnum1  = SDL_CreateTextureFromSurface(renderTarget,number1);
    SDL_Texture *highnum2  = SDL_CreateTextureFromSurface(renderTarget,number2);
    SDL_Texture *highnum3  = SDL_CreateTextureFromSurface(renderTarget,number3);
    SDL_Texture *highnum4  = SDL_CreateTextureFromSurface(renderTarget,number4);
    SDL_Texture *highnum5  = SDL_CreateTextureFromSurface(renderTarget,number5);
    SDL_Texture *highnum6  = SDL_CreateTextureFromSurface(renderTarget,number6);
    SDL_Texture *highnum7  = SDL_CreateTextureFromSurface(renderTarget,number7);
    SDL_Texture *highnum8  = SDL_CreateTextureFromSurface(renderTarget,number8);
    SDL_Texture *highnum9  = SDL_CreateTextureFromSurface(renderTarget,number9);



    SDL_Rect logoRect;
    logoRect.x = 0;
    logoRect.y = 0;
    logoRect.w = 1366;
    logoRect.h = 766;


    SDL_Rect score1;
    score1.x = 100;
    score1.y = 280;
    score1.w = 300;
    score1.h = 50;

    SDL_Rect score2;
    score2.x = 100;
    score2.y = 364;
    score2.w = 300;
    score2.h = 50;

    SDL_Rect score3;
    score3.x = 100;
    score3.y = 448;
    score3.w = 300;
    score3.h = 50;

    SDL_Rect score4;
    score4.x = 100;
    score4.y = 533;
    score4.w = 300;
    score4.h = 50;

    SDL_Rect score5;
    score5.x = 100;
    score5.y = 618;
    score5.w = 300;
    score5.h = 50;

    SDL_Rect score6;
    score6.x = 780;
    score6.y = 280;
    score6.w = 300;
    score6.h = 50;

    SDL_Rect score7;
    score7.x = 780;
    score7.y = 364;
    score7.w = 300;
    score7.h = 50;

    SDL_Rect score8;
    score8.x = 780;
    score8.y = 448;
    score8.w = 300;
    score8.h = 50;

    SDL_Rect score9;
    score9.x = 780;
    score9.y = 533;
    score9.w = 300;
    score9.h = 50;

    SDL_Rect score10;
    score10.x = 780;
    score10.y = 618;
    score10.w = 300;
    score10.h = 50;

    SDL_Rect scorenum1;
    scorenum1.x = 575;
    scorenum1.y = 280;
    scorenum1.w = 80;
    scorenum1.h = 50;

    SDL_Rect scorenum2;
    scorenum2.x = 575;
    scorenum2.y = 364;
    scorenum2.w = 80;
    scorenum2.h = 50;

    SDL_Rect scorenum3;
    scorenum3.x = 575;
    scorenum3.y = 448;
    scorenum3.w = 80;
    scorenum3.h = 50;

    SDL_Rect scorenum4;
    scorenum4.x = 575;
    scorenum4.y = 533;
    scorenum4.w = 80;
    scorenum4.h = 50;

    SDL_Rect scorenum5;
    scorenum5.x = 575;
    scorenum5.y = 618;
    scorenum5.w = 80;
    scorenum5.h = 50;

    SDL_Rect scorenum6;
    scorenum6.x = 1215;
    scorenum6.y = 280;
    scorenum6.w = 80;
    scorenum6.h = 50;

    SDL_Rect scorenum7;
    scorenum7.x = 1215;
    scorenum7.y = 364;
    scorenum7.w = 80;
    scorenum7.h = 50;

    SDL_Rect scorenum8;
    scorenum8.x = 1215;
    scorenum8.y = 448;
    scorenum8.w = 80;
    scorenum8.h = 50;

    SDL_Rect scorenum9;
    scorenum9.x = 1215;
    scorenum9.y = 533;
    scorenum9.w = 80;
    scorenum9.h = 50;

    SDL_Rect scorenum10;
    scorenum10.x = 1215;
    scorenum10.y = 618;
    scorenum10.w = 80;
    scorenum10.h = 50;

    while( isRunning )
    {
        while( SDL_PollEvent( &event ) )
        {

            if( event.type == SDL_QUIT )
            {
                isRunning = false;
            }
        }

        SDL_RenderCopy(renderTarget, currentImage, &logoRect, NULL);

        SDL_RenderCopy(renderTarget,inpu0,NULL,&score1);
        SDL_RenderCopy(renderTarget,inpu1,NULL,&score2);
        SDL_RenderCopy(renderTarget,inpu2,NULL,&score3);
        SDL_RenderCopy(renderTarget,inpu3,NULL,&score4);
        SDL_RenderCopy(renderTarget,inpu4,NULL,&score5);
        SDL_RenderCopy(renderTarget,inpu5,NULL,&score6);
        SDL_RenderCopy(renderTarget,inpu6,NULL,&score7);
        SDL_RenderCopy(renderTarget,inpu7,NULL,&score8);
        SDL_RenderCopy(renderTarget,inpu8,NULL,&score9);
        SDL_RenderCopy(renderTarget,inpu9,NULL,&score10);

        SDL_RenderCopy(renderTarget,highnum0,NULL,&scorenum1);
        SDL_RenderCopy(renderTarget,highnum1,NULL,&scorenum2);
        SDL_RenderCopy(renderTarget,highnum2,NULL,&scorenum3);
        SDL_RenderCopy(renderTarget,highnum3,NULL,&scorenum4);
        SDL_RenderCopy(renderTarget,highnum4,NULL,&scorenum5);
        SDL_RenderCopy(renderTarget,highnum5,NULL,&scorenum6);
        SDL_RenderCopy(renderTarget,highnum6,NULL,&scorenum7);
        SDL_RenderCopy(renderTarget,highnum7,NULL,&scorenum8);
        SDL_RenderCopy(renderTarget,highnum8,NULL,&scorenum9);
        SDL_RenderCopy(renderTarget,highnum9,NULL,&scorenum10);

        SDL_RenderPresent(renderTarget);
       page_action4();
    }

}

void credits(void)
{
    SDL_RenderClear(renderTarget);
    surface = SDL_LoadBMP("credits.bmp");
    logoRect.x = logoRect.y = 0;
    currentImage = SDL_CreateTextureFromSurface(renderTarget,surface);
    while(isRunning)
    {
        SDL_RenderCopy(renderTarget, currentImage, &logoRect, NULL);
        SDL_RenderPresent(renderTarget);

    page_action5();
    }
}

void exit(void)
{
    SDL_RenderClear(renderTarget);
    surface = SDL_LoadBMP("exit.bmp");
    logoRect.x = logoRect.y = 0;
    currentImage = SDL_CreateTextureFromSurface(renderTarget,surface);
    while(isRunning)
    {
        SDL_RenderCopy(renderTarget, currentImage, &logoRect, NULL);
        SDL_RenderPresent(renderTarget);

    page_action6();
    }
}

void page_action1(void)
{

    if(event9.motion.x >=14 && event9.motion.x <=96 && event9.motion.y >=717 && event9.motion.y <= 749)     //back tab clicked
    {
        if(event9.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event9.button.button == SDL_BUTTON_LEFT)
            {
                Mix_PlayChannel(-1,click,0);
                back_ground();

            }
        }
    }
     if(event9.motion.x >=609 && event9.motion.x <=754 && event9.motion.y >=404 && event9.motion.y <= 435)     //OK tab clicked
    {
        if(event9.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event9.button.button == SDL_BUTTON_LEFT)
            {
                Mix_PlayChannel(-1,click,0);
                newgame_difficulty();

            }
        }
    }

}

void page_action2(void)
{
    while(SDL_PollEvent(&event6))
    {
        if(event6.motion.x >=553 && event6.motion.x <=809 && event6.motion.y >=597 && event6.motion.y <= 664)     //back tab clicked
        {
            if(event6.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event6.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    back_ground();

                }
            }
        }
    }
}

void page_action3(void)
{
    while(SDL_PollEvent(&event6))
    {
        if(event6.motion.x >=613 && event6.motion.x <=715 && event6.motion.y >=248 && event6.motion.y <=284)            // MUSIC ON TAB CLICKED
        {
            if(event6.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event6.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    Mix_ResumeMusic();

                }
            }
        }

        if(event6.motion.x >=878 && event6.motion.x <=979 && event6.motion.y >=251 && event6.motion.y <=286)            //MUSIC OFF TAB CLICKED
        {
            if(event6.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event6.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    Mix_PauseMusic();

                }
            }
        }

        if(event6.motion.x >=768 && event6.motion.x <=883 && event6.motion.y >=410 && event6.motion.y <=450)            //CLICK HERE TAB CLICKED
        {
            if(event6.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event6.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    game_description();

                }
            }
        }

        if(event6.motion.x >=312 && event6.motion.x <=413 && event6.motion.y >=655 && event6.motion.y <=695)            //BACK TAB CLICKED
        {
            if(event6.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event6.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    back_ground();

                }
            }
        }


    }
}

void page_action4(void)
{
    while(SDL_PollEvent(&event6))
    {
        if(event6.motion.x >=45 && event6.motion.x <=191 && event6.motion.y >=688 && event6.motion.y <= 733)
        {
            if(event6.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event6.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    back_ground();

                }
            }
        }
    }
}

void page_action5(void)
{
    while(SDL_PollEvent(&event6))
    {
        if(event6.motion.x >=192 && event6.motion.x <=293 && event6.motion.y >=696 && event6.motion.y <= 736)          //BACK TAB CLICKED
        {
            if(event6.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event6.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    back_ground();

                }
            }
        }
    }
}

void page_action6(void)
{
    while(SDL_PollEvent(&event6))
    {
        if(event6.motion.x >=566 && event6.motion.x <=672 && event6.motion.y >=444 && event6.motion.y <= 469)         //YES TAB CLICKED
        {
            if(event6.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event6.button.button == SDL_BUTTON_LEFT)
                {

                    isRunning = false;

                }
            }
        }

        if((event6.motion.x >=691 && event6.motion.x <=798 && event6.motion.y >=444 && event6.motion.y <= 469) ||
           (event6.motion.x >=818 && event6.motion.x <=922 && event6.motion.y >=444 && event6.motion.y <= 469)  )    //NO or CANCEL TAB CLICKED
        {
            if(event6.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event6.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    back_ground();

                }
            }
        }

    }
}



void game_description(void)
{
    SDL_RenderClear(renderTarget);
    surface = SDL_LoadBMP("game_description.bmp");
    logoRect.x = logoRect.y = 0;
    currentImage = SDL_CreateTextureFromSurface(renderTarget,surface);

    while(isRunning)
    {
        SDL_RenderCopy(renderTarget, currentImage, &logoRect, NULL);
        SDL_RenderPresent(renderTarget);
        while(SDL_PollEvent(&event6))
        {
            if(event6.motion.x >=182 && event6.motion.x <=281 && event6.motion.y >=584 && event6.motion.y <= 618)
            {
                if(event6.type == SDL_MOUSEBUTTONDOWN)
                {
                    if(event6.button.button == SDL_BUTTON_LEFT)
                    {
                        Mix_PlayChannel(-1,click,0);
                        options();

                    }
                }
            }
        }
    }

}


void newgame_difficulty(void)
{
    SDL_RenderClear(renderTarget);
    surface = SDL_LoadBMP("difficulty.bmp");
    logoRect.x = logoRect.y = 0;
    currentImage = SDL_CreateTextureFromSurface(renderTarget,surface);

    while(isRunning)
    {
        SDL_RenderCopy(renderTarget, currentImage, &logoRect, NULL);
        SDL_RenderPresent(renderTarget);

        page_action1_action();
    }

}

void page_action1_action(void)
{
    while(SDL_PollEvent(&event7))
    {
        if(event7.motion.x >=573 && event7.motion.x <=794 && event7.motion.y >=534 && event7.motion.y <= 562) //easy tab clicked
        {
            if(event7.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event7.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    difficulty = 110;
                    main_game(difficulty);

                }
            }
        }

        if(event7.motion.x >=573 && event7.motion.x <=794 && event7.motion.y >=573 && event7.motion.y <= 600) //Medium tab clicked
        {
            if(event7.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event7.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    difficulty = 85;
                    main_game(difficulty);
                }
            }
        }

        if(event7.motion.x >=573 && event7.motion.x <=794 && event7.motion.y >=610 && event7.motion.y <= 637) //hard tab clicked
        {
            if(event7.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event7.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    difficulty = 60;
                    main_game(difficulty);
                }
            }
        }

          if(event7.motion.x >=14 && event7.motion.x <=96 && event7.motion.y >=717 && event7.motion.y <= 749) //back tab clicked
        {
            if(event7.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event7.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PlayChannel(-1,click,0);
                    back_ground();

                }
            }
        }
    }
}



void setup()
{
    posx = 300;
    posy = 300;
    score = 0;
    ntail = 5;
    speed = 100;

    fruitx = rand()%(innerw-30);
    fruity=rand()%(innerh-30);
    wfruit1x = rand()%(innerw-30);
    wfruit1y=rand()%(innerh-30);
    wfruit2x = rand()%(innerw-30);
    wfruit2y=rand()%(innerh-30);
    wfruit3x = rand()%(innerw-30);
    wfruit3y=rand()%(innerh-30);

    if(fruitx< 20)
    {
        fruitx = fruitx +60;
    }
    if(fruity < 20)
    {
        fruity = fruity +40;
    }
    if(wfruit1x < 20)
    {
        wfruit1x = wfruit1x +20;
    }
    if(wfruit1y < 20)
    {
        wfruit1y = wfruit1y +35;
    }
    if(wfruit2x < 20)
    {
        wfruit2x = wfruit2x +30;
    }
    if(wfruit2y < 20)
    {
        wfruit2y = wfruit2y +45;
    }
    if(wfruit3x < 20)
    {
        wfruit3x = wfruit3x +20;
    }
    if(wfruit3y < 20)
    {
        wfruit3y= wfruit3y+50;
    }
}


void main_game(int difficulty)
{
    maingame= Mix_LoadMUS("snake.mp3");
    over = Mix_LoadMUS("over.mp3");
    bang = Mix_LoadWAV("bang.wav");
    changedir = Mix_LoadWAV("changedir.wav");

    trophy_image = SDL_LoadBMP("trophy.bmp");
    ground_image = SDL_LoadBMP("ground.bmp");
    tail_image = SDL_LoadBMP("tail.bmp");
    head_right = SDL_LoadBMP("headright.bmp");
    head_left =SDL_LoadBMP("headleft.bmp");
    head_up = SDL_LoadBMP("headup.bmp");
    head_down = SDL_LoadBMP("headdown.bmp");
    score_board =SDL_LoadBMP("score.bmp");
    tail_down =SDL_LoadBMP("ltaildown.bmp");
tail_up =SDL_LoadBMP("ltailup.bmp");
tail_right =SDL_LoadBMP("ltailright.bmp");
tail_left =SDL_LoadBMP("ltailleft.bmp");

    trophy = SDL_CreateTextureFromSurface(renderTarget,trophy_image);
    ground = SDL_CreateTextureFromSurface(renderTarget,ground_image);
    tailtex = SDL_CreateTextureFromSurface(renderTarget, tail_image);
    score_display =SDL_CreateTextureFromSurface(renderTarget,score_board);

    Mix_PlayMusic(maingame,-1);

    setup();

    while(isRunning)
    {
        draw();
        input();
        logic();
    }
}


void eat_fruit()
{
    int distance;
    int *x, *y,*w1x,*w1y,*w2x,*w2y,*w3x,*w3y;
    int d1 = pow((fruitx - posx),2);
    int d2 = pow((fruity - posy),2);
    distance = pow(d1+d2,0.5);

    if (distance <=15)
    {
        x=&fruitx;
        y=&fruity;
        w1x =&wfruit1x;
        w1y=&wfruit1y;
        w2x =&wfruit2x;
        w2y=&wfruit2y;
        w3x =&wfruit2x;
        w3y=&wfruit3y;

        *x = rand()%(innerw-30);
        *w1x = rand()%(innerw-30);
        *w2x = rand()%(innerw-30);
        *w3x = rand()%(innerw-30);
        *w1y = rand()%(innerh-30);
        *w2y = rand()%(innerh-30);
        *y = rand()%(innerh-30);
        *w3y = rand()%(innerh-30);

        if(*x < 20)
        {
            *x = *x +60;
        }
        if(*y < 20)
        {
            *y = *y +40;
        }
        if(*w1x < 20)
        {
            *w1x = *w1x +20;
        }
        if(*w1y < 20)
        {
            *w1y = *w1y +35;
        }
        if(*w2x < 20)
        {
            *w2x = *w2x +30;
        }
        if(*w2y < 20)
        {
            *w2y = *w2y +45;
        }
        if(*w3x < 20)
        {
            *w3x = *w3x +20;
        }
        if(*w3y < 20)
        {
            *w3y = *w3y +50;
        }

        system("cls");
        ++score;
        ++ntail;
    }
}
void check_collision()
{
    if(posx==20 || posy == 20 || posx >= innerw || posy >= innerh)
    {
        Mix_PlayChannel(-1,bang,0);
        game_over();
    }
    for(int m = 0; m < ntail;++m)
    {
        if(posx == tailx[m] && posy == taily[m])
        {
            Mix_PlayChannel(-1,bang,0);
            game_over();
        }
    }

    int distance;
    int d1 = pow((wfruit1x - posx),2);
    int d2 = pow((wfruit1y - posy),2);
    distance = pow(d1+d2,0.5);

    if (distance <=15)
    {
        Mix_PlayChannel(-1,bang,0);
        game_over();
    }

    d1 = pow((wfruit2x - posx),2);
    d2 = pow((wfruit2y - posy),2);
    distance = pow(d1+d2,0.5);

    if (distance <=15)
    {
        Mix_PlayChannel(-1,bang,0);
        game_over();
    }

    d1 = pow((wfruit3x - posx),2);
    d2 = pow((wfruit3y - posy),2);
    distance = pow(d1+d2,0.5);

    if (distance <=15)
    {
        Mix_PlayChannel(-1,bang,0);
        game_over();
    }
}


void input()
{

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    SDL_PumpEvents();

    if(state[SDL_SCANCODE_UP])
    {
        if(dir == RIGHT || dir == LEFT)
        dir = UP;
         if(p==2 || p==3 || p==4)
        {
           Mix_PlayChannel(-1,changedir,0);
           p=1;
        }
    }
    else if(state[SDL_SCANCODE_DOWN])
    {
        if(dir == RIGHT || dir == LEFT)
        dir = DOWN;
        if(p==1 || p==3 || p==4)
        {
           Mix_PlayChannel(-1,changedir,0);
           p=2;
        }

    }
    else if(state[SDL_SCANCODE_RIGHT])
    {
        if(dir == UP || dir == DOWN)
        dir = RIGHT;
        if(p==1 || p==2 || p==4)
        {
           Mix_PlayChannel(-1,changedir,0);
           p=3;
        }
    }
    else if (state[SDL_SCANCODE_LEFT])
    {
        if(dir == UP || dir == DOWN)
        dir = LEFT;
         if(p==1 || p==2 || p==3)
        {
           Mix_PlayChannel(-1,changedir,0);
           p=4;
        }
    }
    else if(state[SDL_SCANCODE_ESCAPE])
    {
        game_over();
    }
}

void logic()
{
    int prevX = tailx[0];
    int prevY = taily[0];
    int prev2X, prev2Y;
    tailx[0] = posx;
    taily[0] = posy;

    for (int i = 1; i < ntail; i++)
    {
        prev2X = tailx[i];
        prev2Y = taily[i];
        tailx[i] = prevX;
        taily[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    if(dir == UP)
    {
        posy = posy - 20;
        head_snake =SDL_CreateTextureFromSurface(renderTarget,head_up);
    }
    else if(dir == DOWN)
    {
        posy=posy+20;
        head_snake =SDL_CreateTextureFromSurface(renderTarget,head_down);
    }
    else if(dir == RIGHT)
    {
        posx=posx+20;
        head_snake =SDL_CreateTextureFromSurface(renderTarget,head_right);
    }
    else if(dir == LEFT)
    {
        posx = posx -20;
        head_snake =SDL_CreateTextureFromSurface(renderTarget,head_left);
    }
}

void draw()
{
    background();

    for(int i = 0;i < innerw; i = i +20)
    {
        for(int j = 0; j< innerh; j= j + 20)
        {
            if(i == posx && j == posy)
            {
                SDL_Rect snake;
                snake.x = posx;
                snake.y = posy;
                snake.w = 20;
                snake.h = 20;
                SDL_RenderCopy(renderTarget,head_snake,NULL,&snake);
            }
            else
            {
                for(int k = 0; k< ntail;++k){
                    if(tailx[k] == i && taily[k] == j){
                    if(k == ntail-1){
                        if ((tailx[k]-tailx[k-1])==20)
                            tailtex = SDL_CreateTextureFromSurface(renderTarget,tail_left);
                        if ((tailx[k]-tailx[k-1])==-20)
                            tailtex = SDL_CreateTextureFromSurface(renderTarget,tail_right);
                        if ((taily[k]-taily[k-1])==20)
                            tailtex = SDL_CreateTextureFromSurface(renderTarget,tail_up);
                        if ((taily[k]-taily[k-1])==-20)
                            tailtex = SDL_CreateTextureFromSurface(renderTarget,tail_down);
                        }
                        else {
                            tailtex = SDL_CreateTextureFromSurface(renderTarget,tail_image);
                        }
                    SDL_Rect tail;
                    tail.x = tailx[k];
                    tail.y = taily[k];
                    tail.w = 20;
                    tail.h = 20;
                    SDL_RenderCopy(renderTarget,tailtex,NULL,&tail);

                }
            }
        }
    }
}


    fruit();
    display_wrongfruit();
    scoreboard();
    render_update();
}

void background()
{
    SDL_Rect wall;
    wall.x = 0;
    wall.y = 0;
    wall.w = window_width;
    wall.h = window_height;

    SDL_RenderCopy(renderTarget,ground,NULL,&wall);
}

void fruit()
{
    if (score == 0)
    {
        squestion = SDL_LoadBMP("q1.bmp");
        c_answer = SDL_LoadBMP("Numbers/a0.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a-1.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a1.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a2.bmp");
    }
    else if(score == 1)
    {
        squestion = SDL_LoadBMP("q2.bmp");
        c_answer = SDL_LoadBMP("Numbers/a1.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a3.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a2.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a4.bmp");
    }
    else if(score == 2){
        squestion = SDL_LoadBMP("q3.bmp");
        c_answer = SDL_LoadBMP("Numbers/a2.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a3.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a4.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a5.bmp");
    }
    else if(score == 3)
    {
        squestion = SDL_LoadBMP("q4.bmp");
        c_answer = SDL_LoadBMP("Numbers/a18.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a16.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a17.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a19.bmp");
    }
    else if(score == 4)
    {
        squestion = SDL_LoadBMP("q5.bmp");
        c_answer = SDL_LoadBMP("Numbers/a0.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a-3.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a-1.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a-2.bmp");
    }
    else if(score == 5)
    {
        squestion = SDL_LoadBMP("q6.bmp");
        c_answer = SDL_LoadBMP("Numbers/a4.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a2.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a5.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a3.bmp");
    }
    else if(score == 6)
    {
        squestion = SDL_LoadBMP("q7.bmp");
        c_answer = SDL_LoadBMP("Numbers/a-9.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a-7.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a-10.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a-6.bmp");
    }
    else if(score == 7)
    {
        squestion = SDL_LoadBMP("q8.bmp");
        c_answer = SDL_LoadBMP("Numbers/a21.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a19.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a20.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a18.bmp");
    }
    else if(score == 8)
    {
        squestion = SDL_LoadBMP("q9.bmp");
        c_answer = SDL_LoadBMP("Numbers/a0.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a2.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a-1.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a1.bmp");
    }
    else if(score == 9)
    {
        squestion = SDL_LoadBMP("q10.bmp");
        c_answer = SDL_LoadBMP("Numbers/a6.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a4.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a5.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a7.bmp");
    }
    else if(score == 10)
    {
        squestion = SDL_LoadBMP("q11.bmp");
        c_answer = SDL_LoadBMP("Numbers/a11.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a14.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a13.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a12.bmp");
    }
    else if(score == 11)
    {
        squestion = SDL_LoadBMP("q12.bmp");
        c_answer = SDL_LoadBMP("Numbers/a4.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a5.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a6.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a7.bmp");
    }
    else if(score == 12)
    {
        squestion = SDL_LoadBMP("q13.bmp");
        c_answer = SDL_LoadBMP("Numbers/a9.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a8.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a7.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a10.bmp");
    }
    else if(score == 13)
    {
        squestion = SDL_LoadBMP("q14.bmp");
        c_answer = SDL_LoadBMP("Numbers/a-6.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a-5.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a-7.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a-4.bmp");
    }
    else if(score == 14)
    {
        squestion = SDL_LoadBMP("q15.bmp");
        c_answer = SDL_LoadBMP("Numbers/a7.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a6.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a9.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a8.bmp");
    }
    else if(score == 15)
    {
        squestion = SDL_LoadBMP("q16.bmp");
        c_answer = SDL_LoadBMP("Numbers/a5.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a8.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a6.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a7.bmp");
    }
    else if(score == 16)
    {
        squestion = SDL_LoadBMP("q17.bmp");
        c_answer = SDL_LoadBMP("Numbers/a7.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a6.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a9.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a8.bmp");
    }
    else if(score == 17)
    {
        squestion = SDL_LoadBMP("q18.bmp");
        c_answer = SDL_LoadBMP("Numbers/a15.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a18.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a17.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a16.bmp");
    }
    else if(score == 18)
    {
        squestion = SDL_LoadBMP("q19.bmp");
        c_answer = SDL_LoadBMP("Numbers/a8.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a9.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a10.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a11.bmp");
    }
    else if(score == 19)
    {
        squestion = SDL_LoadBMP("q20.bmp");
        c_answer = SDL_LoadBMP("Numbers/a9.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a8.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a7.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a10.bmp");
    }
    else if(score == 20)
    {
        squestion = SDL_LoadBMP("q21.bmp");
        c_answer = SDL_LoadBMP("Numbers/a2.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a0.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a1.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a-1.bmp");
    }
    else if(score == 21)
    {
        squestion = SDL_LoadBMP("q22.bmp");
        c_answer = SDL_LoadBMP("Numbers/a7.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a4.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a5.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a3.bmp");
    }
    else if(score == 22)
    {
        squestion = SDL_LoadBMP("q23.bmp");
        c_answer = SDL_LoadBMP("Numbers/a4.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a5.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a3.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a6.bmp");
    }
    else if(score == 23)
    {
        squestion = SDL_LoadBMP("q24.bmp");
        c_answer = SDL_LoadBMP("Numbers/a8.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a10.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a9.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a11.bmp");
    }
    else if(score == 24)
    {
        squestion = SDL_LoadBMP("q25.bmp");
        c_answer = SDL_LoadBMP("Numbers/a13.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a12.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a11.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a14.bmp");
    }
    else if(score == 25)
    {
        squestion = SDL_LoadBMP("q26.bmp");
        c_answer = SDL_LoadBMP("Numbers/a5.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a4.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a6.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a3.bmp");
    }
    else if(score == 26)
    {
        squestion = SDL_LoadBMP("q27.bmp");
        c_answer = SDL_LoadBMP("Numbers/a1.bmp");
        c_answer = SDL_LoadBMP("Numbers/a-2.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a0.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a-1.bmp");
    }
    else if(score == 27)
    {
        squestion = SDL_LoadBMP("q28.bmp");
        c_answer = SDL_LoadBMP("Numbers/a20.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a23.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a22.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a21.bmp");
    }
    else if(score == 28)
    {
        squestion = SDL_LoadBMP("q29.bmp");
        c_answer = SDL_LoadBMP("Numbers/a5.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a2.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a3.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a4.bmp");
    }
    else if(score == 29)
    {
        squestion = SDL_LoadBMP("q30.bmp");
        c_answer = SDL_LoadBMP("Numbers/a2.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a0.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a1.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a-1.bmp");
    }
    else if(score == 30)
    {
        squestion = SDL_LoadBMP("q31.bmp");
        c_answer = SDL_LoadBMP("Numbers/a24.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a23.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a22.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a25.bmp");
    }
    else if(score == 31)
    {
        squestion = SDL_LoadBMP("q32.bmp");
        c_answer = SDL_LoadBMP("Numbers/a16.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a14.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a15.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a17.bmp");
    }
    else if(score == 32)
    {
        squestion = SDL_LoadBMP("q33.bmp");
        c_answer = SDL_LoadBMP("Numbers/a6.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a7.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a8.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a9.bmp");
    }
    else if(score == 33)
    {
        squestion = SDL_LoadBMP("q34.bmp");
        c_answer = SDL_LoadBMP("Numbers/a18.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a20.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a19.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a21.bmp");
    }
    else if(score == 34)
    {
        squestion = SDL_LoadBMP("q35.bmp");
        c_answer = SDL_LoadBMP("Numbers/a13.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a11.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a10.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a12.bmp");
    }
    else if(score == 35)
    {
        squestion = SDL_LoadBMP("q36.bmp");
        c_answer = SDL_LoadBMP("Numbers/a1.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a-2.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a0.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a-1.bmp");
    }
    else if(score == 36)
    {
        squestion = SDL_LoadBMP("q37.bmp");
        c_answer = SDL_LoadBMP("Numbers/a24.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a25.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a23.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a22.bmp");
    }
    else if(score == 37)
    {
        squestion = SDL_LoadBMP("q38.bmp");
        c_answer = SDL_LoadBMP("Numbers/a10.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a9.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a8.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a12.bmp");
    }
    else if(score == 38)
    {
        squestion = SDL_LoadBMP("q39.bmp");
        c_answer = SDL_LoadBMP("Numbers/a13.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a14.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a15.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a11.bmp");
    }
    else if(score == 39)
    {
        squestion = SDL_LoadBMP("q40.bmp");
        c_answer = SDL_LoadBMP("Numbers/a-2.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a-3.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a-4.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a-5.bmp");
    }
    else if(score == 40)
    {
        squestion = SDL_LoadBMP("q41.bmp");
        c_answer = SDL_LoadBMP("Numbers/a5.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a6.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a7.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a4.bmp");
    }
    else if(score == 41)
    {
        squestion = SDL_LoadBMP("q42.bmp");
        c_answer = SDL_LoadBMP("Numbers/a-1.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a1.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a0.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a-2.bmp");
    }
    else if(score == 42)
    {
        squestion = SDL_LoadBMP("q43.bmp");
        c_answer = SDL_LoadBMP("Numbers/a-1.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a2.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a1.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a0.bmp");
    }
    else if(score == 43)
    {
        squestion = SDL_LoadBMP("q44.bmp");
        c_answer = SDL_LoadBMP("Numbers/a-7.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a-6.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a-5.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a-9.bmp");
    }
    else if(score == 44)
    {
        squestion = SDL_LoadBMP("q45.bmp");
        c_answer = SDL_LoadBMP("Numbers/a12.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a11.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a10.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a13.bmp");
    }
    else if(score == 45)
    {
        squestion = SDL_LoadBMP("q46.bmp");
        c_answer = SDL_LoadBMP("Numbers/a23.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a25.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a24.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a22.bmp");
    }
    else if(score == 46)
    {
        squestion = SDL_LoadBMP("q47.bmp");
        c_answer = SDL_LoadBMP("Numbers/a17.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a16.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a14.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a15.bmp");
    }
    else if(score == 47)
    {
        squestion = SDL_LoadBMP("q48.bmp");
        c_answer = SDL_LoadBMP("Numbers/a4.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a5.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a6.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a3.bmp");
    }
    else if(score == 48)
    {
        squestion = SDL_LoadBMP("q49.bmp");
        c_answer = SDL_LoadBMP("Numbers/a6.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a7.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a5.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a8.bmp");
    }
    else if(score == 49)
    {
        squestion = SDL_LoadBMP("q50.bmp");
        c_answer = SDL_LoadBMP("Numbers/a1732.bmp");
        w_answer1 = SDL_LoadBMP("Numbers/a1777.bmp");
        w_answer2 = SDL_LoadBMP("Numbers/a1731.bmp");
        W_answer3 = SDL_LoadBMP("Numbers/a1723.bmp");
    }

    SDL_Rect fruitt;
    fruitt.x = fruitx;
    fruitt.y = fruity;
    fruitt.w = 20;
    fruitt.h = 20;

    tc_answer =SDL_CreateTextureFromSurface(renderTarget,c_answer);
    SDL_RenderCopy(renderTarget,tc_answer,NULL,&fruitt);
}

void scoreboard()
{
    levelboard();

    if (score == 0)
    {
        currentscore = SDL_LoadBMP("0.bmp");
    }
    else if (score ==1)
    {
        currentscore = SDL_LoadBMP("1.bmp");
    }
    else if(score == 2)
    {
        currentscore = SDL_LoadBMP("2.bmp");
    }
    else if(score == 3)
    {
        currentscore = SDL_LoadBMP("3.bmp");
    }
    else if(score == 4)
    {
        currentscore = SDL_LoadBMP("4.bmp");
    }
    else if(score == 5)
    {
        currentscore = SDL_LoadBMP("5.bmp");
    }
    else if(score == 6)
    {
        currentscore = SDL_LoadBMP("6.bmp");
    }
    else if(score == 7)
    {
        currentscore = SDL_LoadBMP("7.bmp");
    }
    else if(score == 8)
    {
        currentscore = SDL_LoadBMP("8.bmp");
    }
    else if(score == 9)
    {
        currentscore = SDL_LoadBMP("9.bmp");
    }
    else if(score == 10)
    {
        currentscore = SDL_LoadBMP("10.bmp");
    }
    else if (score ==11)
    {
        currentscore = SDL_LoadBMP("11.bmp");
    }
    else if(score == 12)
    {
        currentscore = SDL_LoadBMP("12.bmp");
    }
    else if(score == 13)
    {
        currentscore = SDL_LoadBMP("13.bmp");
    }
    else if(score == 14)
    {
        currentscore = SDL_LoadBMP("14.bmp");
    }
    else if(score == 15)
    {
        currentscore = SDL_LoadBMP("15.bmp");
    }
    else if(score == 16)
    {
        currentscore = SDL_LoadBMP("16.bmp");
    }
    else if(score == 17)
    {
        currentscore = SDL_LoadBMP("17.bmp");
    }
    else if(score == 18)
    {
        currentscore = SDL_LoadBMP("18.bmp");
    }
    else if(score == 19)
    {
        currentscore = SDL_LoadBMP("19.bmp");
    }
    else if(score == 20)
    {
        currentscore = SDL_LoadBMP("20.bmp");
    }
    else if (score ==21)
    {
        currentscore = SDL_LoadBMP("21.bmp");
    }
    else if(score == 22)
    {
        currentscore = SDL_LoadBMP("22.bmp");
    }
    else if(score == 23)
    {
        currentscore = SDL_LoadBMP("23.bmp");
    }
    else if(score == 24)
    {
        currentscore = SDL_LoadBMP("24.bmp");
    }
    else if(score == 25)
    {
        currentscore = SDL_LoadBMP("25.bmp");
    }
    else if(score == 26)
    {
        currentscore = SDL_LoadBMP("26.bmp");
    }
    else if(score == 27)
    {
        currentscore = SDL_LoadBMP("27.bmp");
    }
    else if(score == 28)
    {
        currentscore = SDL_LoadBMP("28.bmp");
    }
    else if(score == 29)
    {
        currentscore = SDL_LoadBMP("29.bmp");
    }
    else if(score == 30)
    {
        currentscore = SDL_LoadBMP("30.bmp");
    }
    else if (score ==31)
    {
        currentscore = SDL_LoadBMP("31.bmp");
    }
    else if(score == 32)
    {
        currentscore = SDL_LoadBMP("32.bmp");
    }
    else if(score == 33)
    {
        currentscore = SDL_LoadBMP("33.bmp");
    }
    else if(score == 34)
    {
        currentscore = SDL_LoadBMP("34.bmp");
    }
    else if(score == 35)
    {
        currentscore = SDL_LoadBMP("35.bmp");
    }
    else if(score == 36)
    {
        currentscore = SDL_LoadBMP("36.bmp");
    }
    else if(score == 37)
    {
        currentscore = SDL_LoadBMP("37.bmp");
    }
    else if(score == 38)
    {
        currentscore = SDL_LoadBMP("38.bmp");
    }
    else if(score == 39)
    {
        currentscore = SDL_LoadBMP("39.bmp");
    }
    else if(score == 40)
    {
        currentscore = SDL_LoadBMP("40.bmp");
    }
    else if (score ==41)
    {
        currentscore = SDL_LoadBMP("41.bmp");
    }
    else if(score == 42)
    {
        currentscore = SDL_LoadBMP("42.bmp");
    }
    else if(score == 43)
    {
        currentscore = SDL_LoadBMP("43.bmp");
    }
    else if(score == 44)
    {
        currentscore = SDL_LoadBMP("44.bmp");
    }
    else if(score == 45)
    {
        currentscore = SDL_LoadBMP("45.bmp");
    }
    else if(score == 46)
    {
        currentscore = SDL_LoadBMP("46.bmp");
    }
    else if(score == 47)
    {
        currentscore = SDL_LoadBMP("47.bmp");
    }
    else if(score == 48)
    {
        currentscore = SDL_LoadBMP("48.bmp");
    }
    else if(score == 49)
    {
        currentscore = SDL_LoadBMP("49.bmp");
    }
    else if(score == 50)
    {
        currentscore = SDL_LoadBMP("50.bmp");
    }

    levelboard();

    SDL_Rect scorenum;
    scorenum.x = 1200;
    scorenum.y = 575;
    scorenum.w = 100;
    scorenum.h = 100;

    current_score = SDL_CreateTextureFromSurface(renderTarget,currentscore);
    SDL_RenderCopy(renderTarget,current_score,NULL,&scorenum);

    question();
}

void display_wrongfruit()
{
    SDL_Rect wfruit1;
    wfruit1.x = wfruit1x;
    wfruit1.y = wfruit1y;
    wfruit1.w = 20;
    wfruit1.h = 20;
    tw_answer1=SDL_CreateTextureFromSurface(renderTarget,w_answer1);
    SDL_RenderCopy(renderTarget,tw_answer1,NULL,&wfruit1);

    SDL_Rect wfruit2;
    wfruit2.x = wfruit2x;
    wfruit2.y = wfruit2y;
    wfruit2.w = 20;
    wfruit2.h = 20;
    tw_answer2 = SDL_CreateTextureFromSurface(renderTarget,w_answer2);
    SDL_RenderCopy(renderTarget,tw_answer2,NULL,&wfruit2);

    SDL_Rect wfruit3;
    wfruit3.x = wfruit3x;
    wfruit3.y = wfruit3y;
    wfruit3.w = 20;
    wfruit3.h = 20;
    tw_answer3 = SDL_CreateTextureFromSurface(renderTarget,W_answer3);
    SDL_RenderCopy(renderTarget,tw_answer3,NULL,&wfruit3);
}

void question()
{
    SDL_Rect qns;
    qns.x = 930;
    qns.y = 100;
    qns.w = 400;
    qns.h = 100;

    tquestion =SDL_CreateTextureFromSurface(renderTarget,squestion);
    SDL_RenderCopy(renderTarget,tquestion,NULL,&qns);
}

void levelboard()
{
    SDL_Rect level;
    level.x = 1200;
    level.y = 325;
    level.w = 100;
    level.h = 100;

    if(score >=0 && score< 10)
    {
        currentlevel = SDL_LoadBMP("1.bmp") ;
    }
    else if(score >= 10 && score < 20)
    {
        currentlevel = SDL_LoadBMP("2.bmp");
    }
    else if(score >=20 && score <30)
    {
        currentlevel = SDL_LoadBMP("3.bmp");
    }
    else if(score >= 30 && score < 40)
    {
        currentlevel = SDL_LoadBMP("4.bmp");
    }
    else if(score >=40 && score <50)
    {
        currentlevel = SDL_LoadBMP("5.bmp");
    }

    current_level = SDL_CreateTextureFromSurface(renderTarget,currentlevel);
    SDL_RenderCopy(renderTarget,current_level,NULL,&level);
}

void render_update()
{
    SDL_RenderPresent(renderTarget);

    SDL_SetRenderDrawColor(renderTarget,0,0,0,0);
    SDL_RenderClear(renderTarget);

    check_collision();
    eat_fruit();

    SDL_Delay(difficulty);
    SDL_UpdateWindowSurface(window);
}
            //game over page

void game_over()
{
    gameover = SDL_LoadBMP("game_over.bmp");
    currentImage = SDL_CreateTextureFromSurface(renderTarget,gameover);

    SDL_Rect showscore;
    showscore.x = 675;
    showscore.y = 470;
    showscore.w = 50;
    showscore.h = 50;

    SDL_RenderCopy(renderTarget, currentImage, NULL, NULL);
    SDL_RenderCopy(renderTarget,current_score,NULL,&showscore);

    SDL_RenderPresent(renderTarget);

    over = Mix_LoadMUS("over.wav");
    SDL_Delay(400);
    Mix_PlayMusic(over,0);

    highscore_cal();

    cout << "Name:" << name;
    cout << "\nScore: " << score<<"\n";

    while(isRunning)
    {
        while(SDL_PollEvent(&event8))
        {
            if(event8.motion.x >=593 && event8.motion.x <=829 && event8.motion.y >=652 && event8.motion.y <= 693)
            {
                if(event8.type == SDL_MOUSEBUTTONDOWN)
                {
                    if(event8.button.button == SDL_BUTTON_LEFT)         //return to main menu
                    {
                        Mix_PlayChannel(-1,click,0);
                        Mix_PlayMusic(bgsound,-1);
                        back_ground();

                    }
                }
            }
            if(event8.motion.x >=592 && event8.motion.x <=829 && event8.motion.y >=596 && event8.motion.y <= 637)
            {
                if(event8.type == SDL_MOUSEBUTTONDOWN)
                {
                    if(event8.button.button == SDL_BUTTON_LEFT)         //play again
                    {
                        Mix_PlayChannel(-1,click,0);
                        main_game(difficulty);

                    }
                }
            }
        }
    }
}





void highscore_cal()
{
     create_score();
     create_name();

        e[0] = show_score1();
        e[1] = show_score2();
        e[2] = show_score3();
        e[3] = show_score4();
        e[4] = show_score5();
        e[5] = show_score6();
        e[6] = show_score7();
        e[7] = show_score8();
        e[8] = show_score9();
        e[9] = show_score10();
        e[10] = show_score11();

        f[0] = "kamlesh";
        f[1] = "karu";
        f[2] = "kamlesh";
        f[3] = "physic";
        f[4] = "rajan";
        f[5] = "ganesh";
        f[6] = "ram";
        f[7] = "sima";
        f[8] = "bibash";
        f[9] = "rima";
        f[10] = "sunil";


        for(i=0;i<=9;++i)
        {
            for(j=i;j<=10;++j)
            {
                if(e[i]<e[j])
                {
                    temp = e[i];
                    e[i] = e[j];
                    e[j] = temp;



                    temp_nam = f[i];
                    f[i] = f[j];
                    f[j] = temp_nam;
                }
            }
        }
}


void create_score()
{
    high s;
    ofstream outFile("highscore/score11.txt");
    s.getscore(score);
    outFile.write((char *) &s, sizeof(s));
    outFile.close();
}

void create_name()
{
    high_name h;
    ofstream outFile("highscore/name11.txt");
    h.getname(name);
    outFile.write((char *) &h, sizeof(h));
    outFile.close();
}

int show_score1()
{
    int a1;
    high s;
    ifstream inFile("highscore/score1.txt");

    while(inFile.read((char *) & s, sizeof(s)))
    {

        a1 = s.retScore();

    }


    inFile.close();
     return a1;
}


int show_score2()
{
    int a2;
    high s;
    ifstream inFile("highscore/score2.txt");

    while(inFile.read((char *) & s, sizeof(s)))
    {

        a2 = s.retScore();

    }

    inFile.close();
     return a2;
}

int show_score3()
{
    int a3;
    high s;
    ifstream inFile("highscore/score3.txt",ios::binary|ios::in);

    while(inFile.read((char *) & s, sizeof(s)))
    {

        a3 = s.retScore();

    }


    inFile.close();
    return a3;
}

int show_score4()
{
    int a4;
    high s;
    ifstream inFile("highscore/score4.txt");

    while(inFile.read((char *) & s, sizeof(s)))
    {

        a4 = s.retScore();

    }


    inFile.close();
    return a4;
}

int show_score5()
{
    int a5;
    high s;
    ifstream inFile("highscore/score5.txt");

    while(inFile.read((char *) & s, sizeof(s)))
    {

        a5 = s.retScore();

    }


    inFile.close();
    return a5;
}

int show_score6()
{
    int a6;
    high s;
    ifstream inFile("highscore/score6.txt");

    while(inFile.read((char *) & s, sizeof(s)))
    {

        a6 = s.retScore();

    }


    inFile.close();
     return a6;
}

int show_score7()
{
    int a7;
    high s;
    ifstream inFile("highscore/score7.txt");

    while(inFile.read((char *) & s, sizeof(s)))
    {

        a7 = s.retScore();

    }


    inFile.close();
    return a7;
}

int show_score8()
{
    int a8;
    high s;
    ifstream inFile("highscore/score8.txt");

    while(inFile.read((char *) & s, sizeof(s)))
    {

        a8 = s.retScore();

    }


    inFile.close();
    return a8;
}

int show_score9()
{
    int a9;
    high s;
    ifstream inFile("highscore/score9.txt");

    while(inFile.read((char *) & s, sizeof(s)))
    {

        a9 = s.retScore();

    }


    inFile.close();
    return a9;
}

int show_score10()
{
    int a10;
    high s;
    ifstream inFile("highscore/score10.txt");

    while(inFile.read((char *) & s, sizeof(s)))
    {

        a10 = s.retScore();

    }


    inFile.close();
    return a10;
}

int show_score11()
{
    int a11;
    high s;
    ifstream inFile("highscore/score11.txt");

    while(inFile.read((char *) & s, sizeof(s)))
    {

        a11 = s.retScore();

    }

    inFile.close();
    return a11;
}


string show_name1()
{
    string b1;
    high_name h;
    ifstream inFile("highscore/name4.txt");

    while(inFile.read((char *) & h, sizeof(h)))
    {

        b1 = h.retname();

    }
     return b1;

    inFile.close();

}


string show_name2()
{
    string b2;
    high_name h;
    ifstream inFile("highscore/name2.txt");

    while(inFile.read((char *) & h, sizeof(h)))
    {

        b2 = h.retname();

    }


    inFile.close();
     return b2;
}


string show_name3()
{
    string b3;
    high_name h;
    ifstream inFile("highscore/name3.txt");

    while(inFile.read((char *) & h, sizeof(h)))
    {

        b3 = h.retname();

    }


    inFile.close();
     return b3;
}


string show_name4()
{
    string b4;
    high_name h;
    ifstream inFile("highscore/name4.txt");

    while(inFile.read((char *) & h, sizeof(h)))
    {

        b4 = h.retname();

    }


    inFile.close();
     return b4;
}


string show_name5()
{
    string b5;

    high_name h;
    ifstream inFile("highscore/name5.txt");

    while(inFile.read((char *) & h, sizeof(h)))
    {

        b5 = h.retname();

    }


    inFile.close();
     return b5;
}


string show_name6()
{
    string b6;
    high_name h;
    ifstream inFile("highscore/name6.txt");

    while(inFile.read((char *) & h, sizeof(h)))
    {

        b6 = h.retname();

    }


    inFile.close();
     return b6;
}


string show_name7()
{
    string b7;
    high_name h;
    ifstream inFile("highscore/name7.txt");

    while(inFile.read((char *) & h, sizeof(h)))
    {

        b7 = h.retname();

    }


    inFile.close();
     return b7;
}


string show_name8()
{
    string b8;
    high_name h;
    ifstream inFile("highscore/name8.txt");

    while(inFile.read((char *) & h, sizeof(h)))
    {

        b8 = h.retname();

    }


    inFile.close();
     return b8;
}


string show_name9()
{
    string b9;
    high_name h;
    ifstream inFile("highscore/name1.txt");

    while(inFile.read((char *) & h, sizeof(h)))
    {

        b9 = h.retname();

    }


    inFile.close();
     return b9;
}


string show_name10()
{
    string b10;
    high_name h;
    ifstream inFile("highscore/name10.txt");

    while(inFile.read((char *) & h, sizeof(h)))
    {

        b10 = h.retname();

    }


    inFile.close();
     return b10;
}


string show_name11()
{
    string b11;
    high_name h;
    ifstream inFile("highscore/name11.txt");

    while(inFile.read((char *) & h, sizeof(h)))
    {

        b11 = h.retname();

    }


    inFile.close();
     return b11;
}
