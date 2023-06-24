#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
float PointsEarned(float TotalMovesAllowed, float MovesTaken, float IdealCount)
{
    float result;
    float differnce = MovesTaken - IdealCount;
    float percentage = (differnce) / (TotalMovesAllowed);
    result = 100 - (percentage * 100);
    return (result - 7);
}
void red()
{
    printf("\033[1;31m");
}
void yellow()
{
    printf("\033[1;33m");
}
void blue()
{
    printf("\033[1;34m");
}
void green()
{
    printf("\033[1;32m");
}
void reset()
{
    printf("\033[0m");
}
void insertdesign()
{
    printf("\n\n");
    blue();
    for (int design = 0; design < 162; design++)
    {

        printf("%c", 4);
    }
    reset();
}
int GameTermination(int *x)
{
    if ((*x) == 3)
    {
        red();
        printf("\n                     Due To Multiple Wrong Input,Game Needs A Reboot.\n\n");
        reset();
        insertdesign();
        exit(0);
    }
    return 0;
}
void RadiusOfGame(char *y, int *radius, int *Numberofmoves)
{
    int game = 1;
    int gamecount = 0;
    char easy[5] = "easy";
    char moderate[9] = "moderate";
    char difficult[10] = "difficult";
    while (game == 1)
    {
        if (strcmp(strlwr(y), easy) == 0)
        {
            *radius = 5;
            *Numberofmoves = 2;
            break;
        }
        else if (strcmp(strlwr(y), moderate) == 0)
        {
            *radius = 9;
            *Numberofmoves = 3;
            break;
        }
        else if (strcmp(strlwr(y), difficult) == 0)
        {
            *radius = 15;
            *Numberofmoves = 4;
            break;
        }
        else
        {
            gamecount++;
            GameTermination(&gamecount);
            red();
            printf("                     !!Invalid Input!!\n\n");
            reset();
            blue();
            printf("                     Choose Difficulty Level:\n");
            red();
            printf("                     1.EASY\n");
            printf("                     2.MODERATE\n");
            printf("                     3.DIFFICULT\n\n                     ");
            reset();

            scanf("%s", y);
        }
    }
}
int Co_OrdinateCalculator(int radius, int *x, int *y)
{
    srand(time(NULL));
    if (radius == 5)
    {
        *x = -(radius) + rand() % (2 * radius + 1);
        *y = -(radius) + rand() % (2 * radius + 1);
        if (-2 <= (*x) && (*x) <= 2 && -2 <= (*y) && (*y) <= 2)
        {
            while (-2 <= (*x) && (*x) <= 2)
            {
                *x = -(radius) + rand() % (2 * radius + 1);
            }
            while (-2 <= (*y) && (*y) <= 2)
            {
                *y = -(radius) + rand() % (2 * radius + 1);
            }
        }
    }
    else if (radius == 9)
    {
        *x = -(radius) + rand() % (2 * radius + 1);
        *y = -(radius) + rand() % (2 * radius + 1);
        if (-6 <= (*x) && (*x) <= 6 && -6 <= (*y) && (*y) <= 6)
        {
            while (-6 <= (*x) && (*x) <= 6)
            {
                *x = -(radius) + rand() % (2 * radius + 1);
            }
            while (-6 <= (*y) && (*y) <= 6)
            {
                *y = -(radius) + rand() % (2 * radius + 1);
            }
        }
    }
    else if (radius == 15)
    {
        *x = -(radius) + rand() % (2 * radius + 1);
        *y = -(radius) + rand() % (2 * radius + 1);
        if (-11 < (*x) && (*x) < 11 && -11 < (*y) && (*y) < 11)
        {
            while (-11 < (*x) && (*x) < 11)
            {
                *x = -(radius) + rand() % (2 * radius + 1);
            }
            while (-11 < (*y) && (*y) < 11)
            {
                *y = -(radius) + rand() % (2 * radius + 1);
            }
        }
    }
}
int NumberOfZeros(int combo, int moves)
{
    int result = combo % moves;
    return (result);
}
void Co_OrdinatesStored(int array[][2], int count, int x_user, int y_user)
{
    array[count][0] = x_user;
    array[count][1] = y_user;
}
void BoundaryCheck1()
{
    red();
    printf("\n                     You Are Already On The Boundary!!!!\n\n");
    blue();
    printf("                     Enter Your First Command Again\n\n                     ");
    reset();
}
void BoundaryCheck2()
{
    red();
    printf("\n                     You Are Already On The Boundary!!!!\n\n");
    blue();
    printf("                     Enter Your Second Command Again:\n\n");
    reset();
}
void BoundaryCheck3()
{
    red();
    printf("\n                     You Are Already On The Boundary!!!!\n\n");
    blue();
    printf("                     Enter Your Third Command Again:\n\n");
    reset();
}
void BoundaryCheck4()
{
    red();
    printf("\n                     You Are Already On The Boundary!!!!\n");
    blue();
    printf("                     Enter Your Fourth Command Again:\n\n");
    reset();
}
int MaximumMoves(int y, int *x)
{
    if (y == 5)
    {
        *x = 15;
    }
    else if (y == 9)
    {
        *x = 20;
    }
    else if (y == 15)
    {
        *x = 25;
    }
}
void PrintCoordintaes(int array[][2], int wcount)
{
    red();
    printf("\n                     Your Visited Co-Ordinates Are As Follows:\n\n");
    for (int i = 0; i < wcount; i++)
    {
        blue();
        printf("                     ");
        if (array[i][0] < 0)
        {
            printf("(%d", array[i][0]);
            red();
            printf(",");
            reset();
        }
        else
        {
            printf("(%d ", array[i][0]);
            red();
            printf(",");
            reset();
        }
        if (array[i][1] < 0)
        {
            blue();
            printf("%d)", array[i][1]);
        }
        else
        {
            blue();
            printf(" %d)", array[i][1]);
        }
        printf("\n");
    }
    reset();
}
int distance_calulator(int x, int x_user, int y, int y_user, float *distance)
{
    int difference = x - x_user, difference2 = y - y_user;
    int pow1 = pow(difference, 2), pow2 = pow(difference2, 2);
    int total = pow1 + pow2;
    *distance = pow(total, 0.5);
    return 0;
}
int FASTESTROUTE(int x, int *xp, int y, int *yp, char idealmoveslist[][20])
{
    if (x < 0)
    {
        *xp = (-1) * (x);
    }
    else
    {
        *xp = x;
    }
    if (y < 0)
    {
        *yp = (-1) * (y);
    }
    else
    {
        *yp = y;
    }
    if (x < 0)
    {
        for (int k = 0; k < (*xp); k++)
        {
            strcpy(idealmoveslist[k], "LEFT");
        }
    }
    else
    {
        for (int k = 0; k < (*xp); k++)
        {
            strcpy(idealmoveslist[k], "RIGHT");
        }
    }
    if (y < 0)
    {
        for (int z = (*xp); z < ((*yp) + (*xp)); z++)
        {
            strcpy(idealmoveslist[z], "DOWN");
        }
    }
    else
    {
        for (int z = (*xp); z < ((*yp) + (*xp)); z++)
        {
            strcpy(idealmoveslist[z], "UP");
        }
    }
    int combo = (*xp) + (*yp);
    strcpy(idealmoveslist[combo], "0");
    strcpy(idealmoveslist[combo + 1], "0");
    strcpy(idealmoveslist[combo + 2], "0");
    strcpy(idealmoveslist[combo + 3], "0");
    strcpy(idealmoveslist[combo + 4], "0");
    strcpy(idealmoveslist[combo + 5], "0");
    strcpy(idealmoveslist[combo + 6], "0");
}
int PrintingMixedElements(char idealmoveslist[][20], int x, int y, int moves)
{
    int g = 0, gg = 0, ggg = 0, mcount = 0;
    for (g = 0; g < x + y; g = g + 3)
    {
        if ((mcount + 1) % 8 == 0)
        {
            printf("\n                     ");
        }
        mcount++;
        if (g == 0)
        {
            printf("                     ");
        }
        blue();
        printf("%s ", idealmoveslist[g]);
        red();
        printf("--> ");
        reset();
    }
    for (gg = 1; gg < x + y; gg = gg + 3)
    {
        if (mcount % 8 == 0)
        {
            printf("\n                     ");
        }
        mcount++;

        blue();
        printf("%s ", idealmoveslist[gg]);
        red();
        printf("--> ");
        reset();
    }
    for (ggg = 2; ggg < x + y; ggg = ggg + 3)
    {
        if (mcount % 8 == 0)
        {
            printf("\n                     ");
        }
        mcount++;
        blue();
        printf("%s ", idealmoveslist[ggg]);

        if ((mcount) != (x + y))
        {
            red();
            printf("--> ");
            reset();
        }
    }
    int rem = NumberOfZeros((x + y), moves);
    int requiredzeroes = moves - rem;
    if (rem != 0)
    {
        for (int i = 0; i < requiredzeroes; i++)
        {
            if (mcount % 8 == 0)
            {
                printf("\n                     ");
            }
            mcount++;
            red();
            printf("--> ");

            blue();
            printf("%s ", idealmoveslist[x + y + i]);
        }
    }
}
int PrintingMixedElements2(FILE *fp, char idealmoveslist[][20], int x, int y, int moves)
{
    int g = 0, gg = 0, ggg = 0, mcount = 0;
    for (g = 0; g < x + y; g = g + 3)
    {
        if ((mcount + 1) % 8 == 0)
        {
            fprintf(fp, "\n");
        }
        mcount++;
        blue();
        fprintf(fp, "%s ", idealmoveslist[g]);
        red();
        fprintf(fp, "--> ");
        reset();
    }
    for (gg = 1; gg < x + y; gg = gg + 3)
    {
        if (mcount % 8 == 0)
        {
            fprintf(fp, "\n");
        }
        mcount++;

        blue();
        fprintf(fp, "%s ", idealmoveslist[gg]);
        red();
        fprintf(fp, "--> ");
        reset();
    }
    for (ggg = 2; ggg < x + y; ggg = ggg + 3)
    {
        if (mcount % 8 == 0)
        {
            fprintf(fp, "\n");
        }
        mcount++;
        blue();
        fprintf(fp, "%s ", idealmoveslist[ggg]);

        if ((mcount) != (x + y))
        {
            red();
            fprintf(fp, "--> ");
            reset();
        }
    }
    int rem = NumberOfZeros((x + y), moves);
    int requiredzeroes = moves - rem;
    if (rem != 0)
    {
        for (int i = 0; i < requiredzeroes; i++)
        {
            if (mcount % 8 == 0)
            {
                fprintf(fp, "\n");
            }
            mcount++;
            red();
            fprintf(fp, "--> ");

            blue();
            fprintf(fp, "%s ", idealmoveslist[x + y + i]);
        }
    }
}
void concat(char s1[], char s2[])
{
    int i, j;
    i = strlen(s1);
    for (j = 0; s2[j] != '\0'; i++, j++)
    {
        s1[i] = s2[j];
    }
    s1[i] = '\0';
}
int main()
{
    int NumberOfMoves = 0;
    int play2 = 1;
    char ex[5] = "exit";
    char gamedecider[100];
    char again[6] = "again";
    int gamedecidercount = 0;
    int gamedecidercount2 = 0;
    while (play2 == 1)
    {
        float PointsScored = 0;
        gamedecidercount = 0;
        gamedecidercount2 = 0;
        insertdesign();
        char blank;
        red();
        printf("\n\n\n\n\n                                                        WELCOME TO 'SEARCH SEARCH AND SEARCH....'                             \n\n\n\n");
        reset();
        char name1[100];
        blue();
        printf("                     Please Enter Your Name:\n                     ");
        reset();
        fflush(stdin);
        scanf("%[^\n]s", name1);
        reset();
        printf("\n");
        char LevelOfDifficulty[20];
        blue();
        printf("                     Choose Difficulty Level:\n");
        red();
        printf("                     1.EASY\n");
        printf("                     2.MODERATE\n");
        printf("                     3.DIFFICULT\n\n                     ");
        reset();
        scanf("%s", LevelOfDifficulty);
        reset();
        printf("\n");
        int radius = 0;
        int AllowedNumberOfMoves;
        RadiusOfGame(LevelOfDifficulty, &radius, &NumberOfMoves);
        MaximumMoves(radius, &AllowedNumberOfMoves);
        int x_co_ordinate = 0, y_co_ordinate = 0;
        Co_OrdinateCalculator(radius, &x_co_ordinate, &y_co_ordinate);
        int differnce1 = 0;
        int differnce2 = 0;
        printf("%d\n", x_co_ordinate);
        printf("%d\n\n\n", y_co_ordinate);
        int xpositive = 0;
        int ypositive = 0;
        int idealpath = 0;
        char movelist[300][30];
        int mcount = 0;
        char idealmoveslist[200][20];
        FASTESTROUTE(x_co_ordinate, &xpositive, y_co_ordinate, &ypositive, idealmoveslist);
        if (radius == 5)
        {
            idealpath = (xpositive + ypositive + 1) / 2;
        }
        else if (radius == 9)
        {
            idealpath = (xpositive + ypositive + 2) / 3;
        }
        else if (radius == 15)
        {
            idealpath = (xpositive + ypositive + 3) / 4;
        }
        blue();
        printf("                     Hello , ");
        red();
        printf("%s", strupr(name1));
        reset();
        blue();
        printf("\n                     This Is How The Game Goes:\n\n\n");
        red();
        printf("                     SITUATION\n");
        blue();
        printf("                     On The Way To Home One Of Our Crew Members Misplaced A Confidential Document\n                     Unfortunately He Only Remembers That It Is In A Square Of Side");
        red();
        printf(" %d ", 2 * radius);
        blue();
        printf("METER\n                     From Our Workplace Being The Center.\n\n", 2 * radius);
        printf("                     You Will Be Given");
        red();
        printf(" %d ", AllowedNumberOfMoves);
        blue();
        printf("Trials To Find The Co-Ordinates\n\n");
        red();
        printf("                     CLUE\n");
        blue();
        printf("                     Given That The Workplace Is At");
        red();
        printf(" (0,0) ");
        blue();
        printf("Co-Ordinate,Find The Co-Ordinates Of The Documents.\n\n");
        red();
        printf("                     CONDITION TO WIN\n");
        blue();
        printf("                     The One Who Finds Co-Ordinate Will Win The Game.\n\n");
        scanf("%c", &blank);
        if (blank == '\n')
        {
            red();
            printf("                     RULES\n");
            blue();
            printf("                     1)You Are Only Allowed To Move Horizontally And Verically.\n\n");
            if (radius == 5)
            {
                printf("                     2)You Can Move Maximum");
                red();
                printf(" 2 ");
                blue();
                printf("Moves In One Chance.\n\n");
            }
            if (radius == 9)
            {
                printf("                     2)You Can Move Maximum");
                red();
                printf(" 3 ");
                blue();
                printf("Moves In One Chance.\n\n");
            }
            if (radius == 15)
            {
                printf("                     2)You Can Move Maximum");
                red();
                printf(" 4 ");
                blue();
                printf("Moves In One Chance.\n\n");
            }
            printf("                     3)Enter ");
            red();
            printf("'UP' ");
            blue();
            printf("To Move 1 Unit In +y Direction.\n\n");
            printf("                     4)Enter ");
            red();
            printf("'DOWN' ");
            blue();
            printf("To Move 1 Unit In -y Direction.\n\n");
            printf("                     5)Enter ");
            red();
            printf("'RIGHT' ");
            blue();
            printf("To Move 1 Unit In +x Direction.\n\n");
            printf("                     6)Enter ");
            red();
            printf("'LEFT' ");
            blue();
            printf("To Move 1 Unit In -y Direction.\n\n");
            printf("                     7)Enter ");
            red();
            printf("'0' ");
            blue();
            printf("In Case Of No Move.\n\n                     ");
        }
        scanf("%c", &blank);
        if (blank == '\n')
        {
            if (radius == 5 || radius == 9)
            {
                printf("                     8)By Entering");
                red();
                printf(" 'LIFELINE' ");
                blue();
                printf("You Will Be Given List Of 3 Lifeline Out Of Which You Can Use 2 During The Game.\n\n                       i)");
                red();
                printf("'ZERO' ");
                blue();
                printf("--> By Choosing This Your Location Will Be Reset To (0,0) But Trials \n                          Will Be Increased By 2.\n\n                      ii)");
                red();
                printf("'SEND ME NEAR'");
                blue();
                printf(" --> By Choosing This You Will Be Send To 3 METER Near\n                          To The Co-Ordinates Of Documents But Your Trials Will Be Increased By 3.\n\n                     iii)");
                red();
                printf("'KNOW YOUR QUADRANT'");
                blue();
                printf("--> By Choosing This You Will Be Able To Know Quadrant Of Document.\n");
                printf("                          But Your Trials Will Be Increased By 4.\n\n");
                printf("                          If The Co-Ordinates Of Documents Is On +ve x Or +ve y It Will Considered In 1st Quadrant.\n");
                printf("                          If The Co-Ordinates Of Documents Is On -ve x Or -ve y It Will Considered In 3rd Quadrant.\n\n");
            }
            if (radius == 15)
            {
                printf("                     8)By Entering ");
                red();
                printf("'LIFELINE'");
                blue();
                printf(" You Will Be Given List Of 3 Lifeline Which You Can Use During The Game:\n\n                       i)");
                red();
                printf("'ZERO' ");
                blue();
                printf("--> By Choosing This Your Location Will Be Reset To (0,0) But Trials \n                     Will Be Increased By 2.\n\n                      ii)");
                red();
                printf("'SEND ME NEAR' ");
                blue();
                printf("--> By Choosing This You Will Be Send To 4 METER Near\n                     To The Co-Ordinates Of Documents But Your Trials Will Be Increased By 3.\n\n                     iii)");
                red();
                printf("'KNOW YOUR QUADRANT' ");
                blue();
                printf("--> By Choosing This You Will Be Able To Know Quadrant Of Document.\n");
                printf("                          But Your Trials Will Be Increased By 4.\n\n");
                printf("                          If The Co-Ordinates Of Documents Is On +ve x Or +ve Y It Will Considered In 1st Quadrant.\n");
                printf("                          If The Co-Ordinates Of Documents Is On -ve x Or -ve Y It Will Considered In 3rd Quadrant.\n");
            }
        }
        fflush(stdin);
        printf("                     ");
        scanf("%c", &blank);
        if (blank == '\n')
        {
            printf("                      9)Enter ");
            red();
            printf("'HISTORY' ");
            blue();
            printf("To View All Your Visited Co-Ordinates.\n\n");
            printf("                     10)Enter ");
            red();
            printf("'INSTRUCTIONS'");
            blue();
            printf(" To View All The Instructions In Case Needed.\n\n");
            printf("                     11)Enter");
            red();
            printf(" 'QUIT' ");
            blue();
            printf("To Leave The Game.\n\n");
            printf("                     12)To Avail Any Of The Above Feature Enter It In The First Move.\n\n");
            printf("                     13)Three Consective Wrong Inputs Will Lead To Termination Of Game.\n\n");
            printf("                     14)Game Is Not Case-Sensitive.\n\n");
            printf("\n                     Enter ");
            red();
            printf("'PLAY'");
            blue();
            printf(" To Start The Game.\n                     ");
        }
        reset();
        int x_user1 = 0, y_user1 = 0;
        char array1[6];
        char array2[5] = "play";
        scanf("%s", array1);
        reset();
        strlwr(array1);
        int program_starter = 0;
        int XY_History[250][2];
        int wcount = 0;
        int dir, dir2, dir_count, dir2_count, dir3_count, dir4_count, dir3, dir4;
        int play = 1;
        float distance;
        float powercal;
        char rules[6] = "rules";
        char rule[5] = "rule";
        char up[3] = "up";
        char down[5] = "down";
        char left[5] = "left";
        char right[6] = "right";
        char direction[100];
        char direction2[100];
        char direction3[100];
        char direction4[100];
        char KnowYourQuadrant[19] = "know your quadrant";
        char history[8] = "history";
        char z[2] = "0";
        char quit[5] = "quit";
        int controlprintf = 1;
        char lifeline[9] = "lifeline";
        char help[100];
        char zero[6] = "zero";
        char performance[12] = "performance";
        char SMN[13] = "send me near";
        int lifeline1 = 0;
        int lifeline2 = 0;
        int lifeline3 = 0;
        int totallifeline = 0;
        int count = 0;
        while (strcmp(array1, array2) != 0)
        {
            program_starter++;
            GameTermination(&program_starter);
            red();
            printf("                     Invalid Input!!!\n\n");
            blue();
            printf("                     Enter ");
            red();
            printf("'PLAY'");
            blue();
            printf(" To Start The Game.\n                     ");
            reset();
            scanf("%s", array1);
            strlwr(array1);
        }
        printf("\n\n\n\n\n\n\n");
        insertdesign();
        red();
        printf("\n\n                                                                       !! All The Best !!\n");
        printf("                                                                     Let The Search Begin\n\n\n\n\n\n\n");
        reset();
        while (play == 1 && count < (AllowedNumberOfMoves + 1))
        {
            blue();
            controlprintf = 1;
            printf("                     Enter Your Command:\n                     ");
            reset();
            strlwr(direction);
            strlwr(direction2);
            dir = 1;
            dir2 = 1;
            dir3 = 1;
            dir4 = 1;
            dir_count = 0;
            dir2_count = 0;
            dir3_count = 0;
            dir4_count = 0;
            while (dir == 1)
            {
                if (dir_count == 0)
                {
                    scanf("%s", direction);
                }
                if (dir_count >= 1)
                {
                    blue();
                    printf("                     Enter Your First Command Again\n                     ");
                    fflush(stdin);
                    reset();
                    scanf("%s", direction);
                }
                if (strcmp(strlwr(direction), quit) == 0)
                {
                    red();
                    printf("\n                     Co-Ordinates Of Document Were (%d,%d) But ", x_co_ordinate, y_co_ordinate);
                    printf("Unfortunately,You Were Not Able To Find Co-Ordinate Of Documents\n");
                    printf("                     Better Luck Next Time %c.", 2);
                    insertdesign();
                    return 0;
                }
                if (strcmp(strlwr(direction), lifeline) == 0)
                {
                    green();
                    printf("\n                     Which Lifeline Do You Want To Choose?\n\n");
                    printf("                     1.ZERO\n");
                    printf("                     2.SEND ME NEAR\n");
                    printf("                     3.KNOW YOUR QUADRANT\n\n                     ");
                    reset();
                    fflush(stdin);
                    scanf("%[^\n]s", help);
                    strlwr(help);
                    if (radius == 15)
                    {
                        if (strcmp(strlwr(help), zero) == 0 && lifeline1 < 1 && totallifeline < 3)
                        {
                            x_user1 = 0;
                            y_user1 = 0;
                            lifeline1++;
                            count = count + 2;
                            totallifeline++;
                            break;
                        }
                        if (strcmp(strlwr(help), SMN) == 0 && lifeline2 < 1 && totallifeline < 3)
                        {
                            if (x_co_ordinate > 0)
                            {
                                x_user1 = x_co_ordinate - 4;
                            }
                            else
                            {
                                x_user1 = x_co_ordinate + 4;
                            }
                            if (y_co_ordinate > 0)
                            {
                                y_user1 = y_co_ordinate - 0;
                            }
                            else
                            {
                                y_user1 = y_co_ordinate + 0;
                            }
                            count = count + 3;
                            lifeline2++;
                            totallifeline++;
                            break;
                        }
                        if (strcmp(strlwr(help), KnowYourQuadrant) == 0 && lifeline3 < 1 && totallifeline < 3)
                        {
                            if (x_co_ordinate >= 0 && y_co_ordinate >= 0)
                            {
                                green();
                                printf("\n                     Co-Ordinates of Documents Are In 1st Quadrant.\n");
                                reset();
                            }
                            if (x_co_ordinate < 0 && y_co_ordinate > 0)
                            {
                                green();
                                printf("\n                     Co-Ordinates of Documents Are In 2nd Quadrant.\n");
                                reset();
                            }
                            if (x_co_ordinate <= 0 && y_co_ordinate <= 0)
                            {
                                green();
                                printf("\n                     Co-Ordinates of Documents Are In 3rd Quadrant.\n");
                                reset();
                            }
                            if (x_co_ordinate > 0 && y_co_ordinate < 0)
                            {
                                green();
                                printf("\n                     Co-Ordinates of Documents Are In 4th Quadrant.\n");
                                reset();
                            }
                            count = count + 3;
                            lifeline3++;
                            totallifeline++;
                            break;
                        }
                        if (strcmp(strlwr(help), SMN) != 0 && strcmp(strlwr(help), zero) != 0 && strcmp(strlwr(help), KnowYourQuadrant) != 0)
                        {
                            red();
                            controlprintf = 0;
                            printf("                     !!Invalid Input!!\n");
                            printf("                     Try Again By Entering 'Lifeline'\n\n");
                            reset();
                            count--;
                            break;
                        }
                        else if (lifeline1 == 0 && lifeline2 == 1 && lifeline3 == 0)
                        {
                            blue();
                            controlprintf = 0;
                            printf("\n                     You Have Already Used 'SEND ME NEAR',Try Either 'KNOW YOUR QUADRANT' or 'ZERO' Lifeline.\n\n");
                            reset();
                            count--;
                            break;
                        }
                        else if (lifeline1 == 1 && lifeline2 == 0 && lifeline3 == 0)
                        {
                            blue();
                            controlprintf = 0;
                            printf("\n                     You Have Already Used 'ZERO',Try Either 'SEND ME NEAR' or 'KNOW YOUR QUADRANT' Lifeline.\n\n");
                            reset();
                            count--;
                            break;
                        }
                        else if (lifeline1 == 0 && lifeline2 == 0 && lifeline3 == 1)
                        {
                            blue();
                            controlprintf = 0;
                            printf("\n                     You Have Already Used 'KNOW YOUR QUADRANT',Try Either 'SEND ME NEAR' or 'ZERO' Lifeline.\n\n");
                            reset();
                            count--;
                            break;
                        }
                        else if (lifeline1 == 1 && lifeline2 == 1 && lifeline3 == 0)
                        {
                            blue();
                            controlprintf = 0;
                            printf("\n                     You Have Already Used 'ZERO' And 'SEND ME NEAR' , Try 'KNOW YOUR QUADRANT' Lifeline.\n\n");
                            reset();
                            count--;
                            break;
                        }
                        else if (lifeline1 == 1 && lifeline2 == 0 && lifeline3 == 1)
                        {
                            blue();
                            controlprintf = 0;
                            printf("\n                     You Have Already Used 'ZERO' And 'KNOW YOUR QUADRANT' , Try 'SEND ME NEAR' Lifeline.\n\n");
                            reset();
                            count--;
                            break;
                        }
                        else if (lifeline1 == 0 && lifeline2 == 1 && lifeline3 == 1)
                        {
                            blue();
                            controlprintf = 0;
                            printf("\n                     You Have Already Used 'SEND ME NEAR' And 'KNOW YOUR QUADRANT' , Try 'ZERO' Lifeline.\n\n");
                            reset();
                            count--;
                            break;
                        }

                        else
                        {
                            blue();
                            controlprintf = 0;
                            printf("\n                     Sorry,But You Have Already Used All The Liflines.\n\n");
                            reset();
                            count--;
                            break;
                        }
                    }
                    if (radius == 5 || radius == 9)
                    {
                        if (strcmp(strlwr(help), zero) == 0 && lifeline1 < 1 && totallifeline < 2)
                        {
                            x_user1 = 0;
                            y_user1 = 0;
                            lifeline1++;
                            count = count + 2;
                            totallifeline++;
                            break;
                        }
                        if (strcmp(strlwr(help), SMN) == 0 && lifeline2 < 1 && totallifeline < 2)
                        {
                            if (x_co_ordinate > 0)
                            {
                                x_user1 = x_co_ordinate - 2;
                            }
                            else
                            {
                                x_user1 = x_co_ordinate + 2;
                            }
                            if (y_co_ordinate > 0)
                            {
                                y_user1 = y_co_ordinate - 2;
                            }
                            else
                            {
                                y_user1 = y_co_ordinate + 2;
                            }
                            count = count + 2;
                            lifeline2++;
                            totallifeline++;
                            break;
                        }
                        if (strcmp(strlwr(help), KnowYourQuadrant) == 0 && lifeline3 < 1 && totallifeline < 2)
                        {
                            if (x_co_ordinate >= 0 && y_co_ordinate >= 0)
                            {
                                green();
                                printf("\n                     Co-Ordinates of Documents Are In 1st Quadrant.\n");
                                reset();
                            }
                            if (x_co_ordinate < 0 && y_co_ordinate > 0)
                            {
                                green();
                                printf("\n                     Co-Ordinates of Documents Are In 2nd Quadrant.\n");
                                reset();
                            }
                            if (x_co_ordinate <= 0 && y_co_ordinate <= 0)
                            {
                                green();
                                printf("\n                     Co-Ordinates of Documents Are In 3rd Quadrant.\n");
                                reset();
                            }
                            if (x_co_ordinate > 0 && y_co_ordinate < 0)
                            {
                                green();
                                printf("\n                     Co-Ordinates of Documents Are In 4th Quadrant.\n");
                                reset();
                            }
                            count = count + 4;
                            lifeline3++;
                            totallifeline++;
                            break;
                        }
                        if (strcmp(strlwr(help), SMN) != 0 && strcmp(strlwr(help), zero) != 0 && strcmp(strlwr(help), KnowYourQuadrant) != 0)
                        {
                            red();
                            controlprintf = 0;
                            printf("\n                     !!Invalid Input!!\n");
                            printf("                     Try Again By Entering 'Lifeline'\n\n");
                            reset();
                            count--;
                            break;
                        }
                        else if (lifeline1 == 0 && lifeline2 == 1 && lifeline3 == 0)
                        {
                            blue();
                            controlprintf = 0;
                            printf("\n                     You Have Already Used 'SEND ME NEAR',Try Either 'KNOW YOUR QUADRANT' or 'ZERO' Lifeline.\n\n");
                            reset();
                            count--;
                            break;
                        }
                        else if (lifeline1 == 1 && lifeline2 == 0 && lifeline3 == 0)
                        {
                            blue();
                            controlprintf = 0;
                            printf("\n                     You Have Already Used 'ZERO',Try Either 'SEND ME NEAR' or 'KNOW YOUR QUADRANT' Lifeline.\n\n");
                            reset();
                            count--;
                            break;
                        }
                        else if (lifeline1 == 0 && lifeline2 == 0 && lifeline3 == 1)
                        {
                            blue();
                            controlprintf = 0;
                            printf("\n                     You Have Already Used 'KNOW YOUR QUADRANT',Try Either 'SEND ME NEAR' or 'ZERO' Lifeline.\n\n");
                            reset();
                            count--;
                            break;
                        }
                        else
                        {
                            blue();
                            controlprintf = 0;
                            printf("\n                     Sorry,But You Have Already Used Two Liflines.\n\n");
                            reset();
                            count--;
                            break;
                        }
                    }
                }
if (strcmp(strlwr(direction), history) == 0)
                {
                    controlprintf = 0;
                    if (wcount == 0)
                    {
                        blue();
                        printf("\n                     No Move Made Yet.\n\n");
                        reset();
                        count--;
                        break;
                    }
                    else
                    {
                        PrintCoordintaes(XY_History, wcount);
                        printf("\n");
                        count--;
                        break;
                    }
                }
                if (strcmp(strlwr(direction), rules) == 0 || strcmp(strlwr(direction), rule) == 0)
                {
                    controlprintf = 0;
                    red();
                    printf("                     \n");
                    blue();
                    printf("                     1)You Are Only Allowed To Move Horizontally And Verically.\n\n");
                    if (radius == 5)
                    {
                        printf("                     2)You Can Move Maximum");
                        red();
                        printf(" 2 ");
                        blue();
                        printf("Moves In One Chance.\n\n");
                    }
                    if (radius == 9)
                    {
                        printf("                     2)You Can Move Maximum");
                        red();
                        printf(" 3 ");
                        blue();
                        printf("Moves In One Chance.\n\n");
                    }
                    if (radius == 15)
                    {
                        printf("                     2)You Can Move Maximum");
                        red();
                        printf(" 4 ");
                        blue();
                        printf("Moves In One Chance.\n\n");
                    }
                    printf("                     3)Enter ");
                    red();
                    printf("'UP' ");
                    blue();
                    printf("To Move 1 Unit In +y Direction.\n\n");
                    printf("                     4)Enter ");
                    red();
                    printf("'DOWN' ");
                    blue();
                    printf("To Move 1 Unit In -y Direction.\n\n");
                    printf("                     5)Enter ");
                    red();
                    printf("'RIGHT' ");
                    blue();
                    printf("To Move 1 Unit In +x Direction.\n\n");
                    printf("                     6)Enter ");
                    red();
                    printf("'LEFT' ");
                    blue();
                    printf("To Move 1 Unit In -y Direction.\n\n");
                    printf("                     7)Enter ");
                    red();
                    printf("'0' ");
                    blue();
                    printf("In Case Of No Move.\n\n");

                    if (radius == 5 || radius == 9)
                    {
                        printf("                     8)By Entering");
                        red();
                        printf(" 'LIFELINE' ");
                        blue();
                        printf("You Will Be Given List Of 3 Lifeline Out Of Which You Can Use 2 During The Game.\n\n                       i)");
                        red();
                        printf("'ZERO' ");
                        blue();
                        printf("--> By Choosing This Your Location Will Be Reset To (0,0) But Trials \n                          Will Be Increased By 2.\n\n                      ii)");
                        red();
                        printf("'SEND ME NEAR'");
                        blue();
                        printf(" --> By Choosing This You Will Be Send To 3 METER Near\n                          To The Co-Ordinates Of Documents But Your Trials Will Be Increased By 3.\n\n                     iii)");
                        red();
                        printf("'KNOW YOUR QUADRANT'");
                        blue();
                        printf("--> By Choosing This You Will Be Able To Know Quadrant Of Document.\n");
                        printf("                          But Your Trials Will Be Increased By 4.\n\n");
                        printf("                          If The Co-Ordinates Of Documents Is On +ve x Or +ve y It Will Considered In 1st Quadrant.\n");
                        printf("                          If The Co-Ordinates Of Documents Is On -ve x Or -ve y It Will Considered In 3rd Quadrant.\n\n");
                    }
                    if (radius == 15)
                    {
                        printf("                     8)By Entering ");
                        red();
                        printf("'LIFELINE'");
                        blue();
                        printf(" You Will Be Given List Of 3 Lifeline Which You Can Use During The Game:\n\n                       i)");
                        red();
                        printf("'ZERO' ");
                        blue();
                        printf("--> By Choosing This Your Location Will Be Reset To (0,0) But Trials \n                          Will Be Increased By 2.\n\n                      ii)");
                        printf("'SEND ME NEAR' ");
                        printf("--> By Choosing This You Will Be Send To 4 METER Near\n                          To The Co-Ordinates Of Documents But Your Trials Will Be Increased By 3.\n\n                     iii)");
                        red();
                        printf("'KNOW YOUR QUADRANT' ");
                        blue();
                        printf("--> By Choosing This You Will Be Able To Know Quadrant Of Document.\n");
                        printf("                          But Your Trials Will Be Increased By 4.\n\n");
                        printf("                          If The Co-Ordinates Of Documents Is On +ve x Or +ve Y It Will Considered In 1st Quadrant.\n");
                        printf("                          If The Co-Ordinates Of Documents Is On -ve x Or -ve Y It Will Considered In 3rd Quadrant.\n");
                    }

                    printf("                     ");

                    printf("9)Enter ");
                    red();
                    printf("'HISTORY' ");
                    blue();
                    printf("To View All Your Visited Co-Ordinates.\n\n");
                    printf("                     10)Enter ");
                    red();
                    printf("'INSTRUCTIONS'");
                    blue();
                    printf(" To View All The Instructions In Case Needed.\n\n");
                    printf("                     11)Enter");
                    red();
                    printf(" 'QUIT' ");
                    blue();
                    printf("To Leave The Game.\n\n");
                    printf("                     12)To Avail Any Of The Above Feature Enter It In The First Move.\n\n");
                    printf("                     13)Three Consective Wrong Inputs Will Lead To Termination Of Game.\n\n");
                    printf("                     14)Game Is Not Case-Sensitive.\n\n");
                    reset();
                    count--;
                    break;
                }
                else if (strcmp(strlwr(direction), up) == 0 && y_user1 < radius)
                {
                    y_user1++;
                    break;
                }
                else if (strcmp(strlwr(direction), up) == 0 && y_user1 == radius)
                {
                    BoundaryCheck1();
                }
                else if (strcmp(strlwr(direction), down) == 0 && y_user1 > (-radius))
                {
                    y_user1--;
                    break;
                }
                else if (strcmp(strlwr(direction), down) == 0 && y_user1 == (-radius))
                {
                    BoundaryCheck1();
                }
                else if (strcmp(strlwr(direction), left) == 0 && x_user1 > (-radius))
                {
                    x_user1--;
                    break;
                }
                else if (strcmp(strlwr(direction), left) == 0 && x_user1 == (-radius))
                {
                    BoundaryCheck1();
                }
                else if (strcmp(strlwr(direction), right) == 0 && x_user1 < radius)
                {
                    x_user1++;
                    break;
                }
                else if (strcmp(strlwr(direction), right) == 0 && x_user1 == radius)
                {
                    BoundaryCheck1();
                }
                else if (strcmp(strlwr(direction), z) == 0)
                {
                    x_user1 = x_user1 + 0;
                    break;
                }
                else
                {
                    red();
                    printf("\n                     !!Invalid Input!!\n\n");
                    reset();
                    dir_count++;
                    GameTermination(&dir_count);
                }
            }
            while (dir2 == 1)
            {
                if (strcmp(strlwr(direction), lifeline) == 0 || strcmp(strlwr(direction), history) == 0 || strcmp(strlwr(direction), rules) == 0 || strcmp(strlwr(direction), rule) == 0)
                {
                    break;
                }
                if (dir2_count == 0)
                {
                    printf("                     ");
                    scanf("%s", direction2);
                }
                if (dir2_count >= 1)
                {
                    blue();
                    printf("                     ");
                    printf("Enter Your Second Command Again\n                     ");
                    reset();
                    scanf("%s", direction2);
                }
                if (strcmp(strlwr(direction2), up) == 0 && y_user1 < radius)
                {
                    y_user1++;
                    break;
                }
                else if (strcmp(strlwr(direction2), up) == 0 && y_user1 == radius)
                {
                    BoundaryCheck2();
                }
                else if (strcmp(strlwr(direction2), down) == 0 && y_user1 > (-radius))
                {
                    y_user1--;
                    break;
                }
                else if (strcmp(strlwr(direction2), down) == 0 && y_user1 == (-radius))
                {
                    BoundaryCheck2();
                }
                else if (strcmp(strlwr(direction2), left) == 0 && x_user1 > (-radius))
                {
                    x_user1--;
                    break;
                }
                else if (strcmp(strlwr(direction2), left) == 0 && x_user1 == (-radius))
                {
                    BoundaryCheck2();
                }
                else if (strcmp(strlwr(direction2), right) == 0 && x_user1 < radius)
                {
                    x_user1++;
                    break;
                }
                else if (strcmp(strlwr(direction2), right) == 0 && x_user1 == radius)
                {
                    BoundaryCheck2();
                }
                else if (strcmp(strlwr(direction2), z) == 0)
                {
                    x_user1 = x_user1 + 0;
                    break;
                }
                else
                {
                    red();
                    printf("\n                     !!Invalid Input!!\n\n");
                    reset();
                    dir2_count++;
                    GameTermination(&dir2_count);
                }
            }
            if (radius == 9 || radius == 15)
            {
                while (dir3 == 1)
                {
                    if (strcmp(strlwr(direction), lifeline) == 0 || strcmp(strlwr(direction), history) == 0 || strcmp(strlwr(direction), rules) == 0 || strcmp(strlwr(direction), rule) == 0)
                    {
                        break;
                    }
                    if (dir3_count == 0)
                    {
                        printf("                     ");
                        scanf("%s", direction3);
                    }
                    if (dir3_count >= 1)
                    {
                        blue();
                        printf("                     Enter Your Third Command Again\n                     ");
                        reset();
                        scanf("%s", direction3);
                    }
                    if (strcmp(strlwr(direction3), up) == 0 && y_user1 < radius)
                    {
                        y_user1++;
                        break;
                    }
                    else if (strcmp(strlwr(direction3), up) == 0 && y_user1 == radius)
                    {
                        BoundaryCheck3();
                    }
                    else if (strcmp(strlwr(direction3), down) == 0 && y_user1 > (-radius))
                    {
                        y_user1--;
                        break;
                    }
                    else if (strcmp(strlwr(direction3), down) == 0 && y_user1 == (-radius))
                    {
                        BoundaryCheck3();
                    }
                    else if (strcmp(strlwr(direction3), left) == 0 && x_user1 > (-radius))
                    {
                        x_user1--;
                        break;
                    }
                    else if (strcmp(strlwr(direction3), left) == 0 && x_user1 == (-radius))
                    {
                        BoundaryCheck3();
                    }
                    else if (strcmp(strlwr(direction3), right) == 0 && x_user1 < radius)
                    {
                        x_user1++;
                        break;
                    }
                    else if (strcmp(strlwr(direction3), right) == 0 && x_user1 == radius)
                    {
                        BoundaryCheck3();
                    }
                    else if (strcmp(strlwr(direction3), z) == 0)
                    {
                        x_user1 = x_user1 + 0;
                        break;
                    }
                    else
                    {
                        red();
                        printf("\n                     !!Invalid Input!!\n\n");
                        reset();
                        dir3_count++;
                        GameTermination(&dir3_count);
                    }
                }
            }
            if (radius == 15)
            {
                while (dir4 == 1)
                {
                    if (strcmp(strlwr(direction), lifeline) == 0 || strcmp(strlwr(direction), history) == 0 || strcmp(strlwr(direction), rules) == 0 || strcmp(strlwr(direction), rule) == 0)
                    {
                        break;
                    }
                    if (dir4_count == 0)
                    {
                        printf("                     ");
                        scanf("%s", direction4);
                    }
                    if (dir4_count >= 1)
                    {
                        blue();
                        printf("                     Enter Your Fourth Command Again\n                     ");
                        reset();
                        scanf("%s", direction4);
                    }
                    if (strcmp(strlwr(direction4), up) == 0 && y_user1 < radius)
                    {
                        y_user1++;
                        break;
                    }
                    else if (strcmp(strlwr(direction4), up) == 0 && y_user1 == radius)
                    {
                        BoundaryCheck4();
                    }
                    else if (strcmp(strlwr(direction4), down) == 0 && y_user1 > (-radius))
                    {
                        y_user1--;
                        break;
                    }
                    else if (strcmp(strlwr(direction4), down) == 0 && y_user1 == (-radius))
                    {
                        BoundaryCheck4();
                    }
                    else if (strcmp(strlwr(direction4), left) == 0 && x_user1 > (-radius))
                    {
                        x_user1--;
                        break;
                    }
                    else if (strcmp(strlwr(direction4), left) == 0 && x_user1 == (-radius))
                    {
                        BoundaryCheck4();
                    }
                    else if (strcmp(strlwr(direction4), right) == 0 && x_user1 < radius)
                    {
                        x_user1++;
                        break;
                    }
                    else if (strcmp(strlwr(direction4), right) == 0 && x_user1 == radius)
                    {
                        BoundaryCheck4();
                    }
                    else if (strcmp(strlwr(direction4), z) == 0)
                    {
                        x_user1 = x_user1 + 0;
                        break;
                    }
                    else
                    {
                        red();
                        printf("\n                     !!Invalid Input!!\n\n");
                        reset();
                        dir4_count++;
                        GameTermination(&dir4_count);
                    }
                }
            }
            PointsScored = PointsEarned(AllowedNumberOfMoves, count, idealpath);
            dir_count = 0;
            dir2_count = 0;
            dir3_count = 0;
            dir4_count = 0;
            count++;
            distance_calulator(x_co_ordinate, x_user1, y_co_ordinate, y_user1, &distance);
            if (controlprintf == 1)
            {
                Co_OrdinatesStored(XY_History, wcount, x_user1, y_user1);
                wcount++;
                if (radius == 5)
                {
                    if (strcmp(strlwr(direction), lifeline) != 0)
                    {
                        strcpy(movelist[mcount], strupr(direction));
                        strcpy(movelist[mcount + 1], strupr(direction2));
                        mcount += 2;
                    }
                    else
                    {
                        strupr(direction);
                        strcat(direction, "(");
                        concat(direction, strupr(help));
                        strcat(direction, ")");
                        strcpy(movelist[mcount], strupr(direction));
                        mcount += 1;
                    }
                }
                if (radius == 9)
                {
                    if (strcmp(strlwr(direction), lifeline) != 0)
                    {
                        strcpy(movelist[mcount], strupr(direction));
                        strcpy(movelist[mcount + 1], strupr(direction2));
                        strcpy(movelist[mcount + 2], strupr(direction3));
                        mcount += 3;
                    }
                    else
                    {
                        strupr(direction);
                        strcat(direction, "(");
                        concat(direction, strupr(help));
                        strcat(direction, ")");
                        strcpy(movelist[mcount], strupr(direction));
                        mcount += 1;
                    }
                }
                if (radius == 15)
                {
                    if (strcmp(strlwr(direction), lifeline) != 0)
                    {
                        strcpy(movelist[mcount], strupr(direction));
                        strcpy(movelist[mcount + 1], strupr(direction2));
                        strcpy(movelist[mcount + 2], strupr(direction3));
                        strcpy(movelist[mcount + 3], strupr(direction4));
                        mcount += 4;
                    }
                    else
                    {
                        strupr(direction);
                        strcat(direction, "(");
                        concat(direction, strupr(help));
                        strcat(direction, ")");
                        strcpy(movelist[mcount], strupr(direction));
                        mcount += 1;
                    }
                }
                red();
                printf("\n                     Your Current Co-Ordintaes Are ");
                blue();
                printf("(%d,%d)", x_user1, y_user1);
                red();
                printf("                                                                                      Remaining Trials:\n");
                printf("                     Your Distance From Documents Is ");
                blue();
                printf("%0.1f", distance);
                printf("                                                                                               %d\n\n", (AllowedNumberOfMoves - count));
                reset();
            }

            if (x_user1 == x_co_ordinate && y_user1 == y_co_ordinate)
            {
                printf("\n\n\n");
                insertdesign();
                red();
                printf("\n\n\n\n\n");
                printf("                                                           !!!   %c %c %c Congratulations %s %c %c %c   !!!\n", 3, 3, 3, strupr(name1), 3, 3, 3);
                printf("                                                      You Have Found Out The Co-ordinates Of Documents (%d,%d).\n", x_co_ordinate, y_co_ordinate);
                reset();
                play = 0;
            }
        }
        if (count > AllowedNumberOfMoves && x_user1 != x_co_ordinate )
        {
            red();
            printf("\n                     Co-Ordinates Of Document Were (%d,%d) But ", x_co_ordinate, y_co_ordinate);
            printf("Unfortunately,You Were Not Able To Find Co-Ordinate Of Documents\n");
            printf("                     Better Luck Next Time %c.", 2);
            goto sos;
        }
        blue();
        printf("\n\n\n                                                             Here Is Your Performance Report\n\n");
        red();
        printf("                     Ideal Number Of Trials = ");
        blue();
        printf("%d\n", idealpath);
        red();
        printf("                     Number Of Trials Taken By You = ");
        blue();
        printf("%d\n\n", count);
        red();
        printf("                     Fastest Path To Reach Th Co-Ordinates Is As Follows:\n");
        scanf("%c", &blank);
        if (blank == '\n')
        {
            printf("\n");
            PrintingMixedElements(idealmoveslist, xpositive, ypositive, NumberOfMoves);
        }
        fflush(stdin);
        scanf("%c", &blank);
        red();
        if (blank == '\n')
        {
            printf("\n                     Path Followed By You Is As Follows:\n\n");
            for (int k = 0; k < mcount; k++)
            {
                if ((k + 1) % 8 == 0)
                {
                    printf("\n");
                    printf("                     ");
                }
                if (k == 0)
                {
                    printf("                     ");
                }
                if (k != mcount - 1)
                {
                    blue();
                    printf("%s ", movelist[k]);
                    red();
                    printf("--> ");
                }
                if (k == mcount - 1)
                {
                    blue();
                    printf("%s", movelist[k]);
                    reset();
                }
            }
            printf("\n");
        }
        scanf("%c", &blank);
        if (blank == '\n')
        {
            PrintCoordintaes(XY_History, wcount);
        }
        red();
        printf("\n                     Points scored = ");
        blue();
        printf("%0.0f", PointsScored);
        printf("\n\n                     By Looking At Your Performance Report:\n\n");
        red();
        if (0 <= (count - idealpath) && (count - idealpath) <= 5 && NumberOfMoves == 2)
        {
            printf("                     1.Your Performance Was Excellent.\n");
            printf("                     2.Your Moves Were Well Calculated.\n");
            printf("                     3.Try Moderate or Difficult Level Game.\n");
        }
        else if (0 <= (count - idealpath) && (count - idealpath) <= 7 && NumberOfMoves == 3)
        {
            printf("                     1.Your Performance Was Excellent.\n");
            printf("                     2.Your Moves Were Well Calculated.\n");
            printf("                     3.Try Difficult Level Game.\n");
        }
        else if (0 <= (count - idealpath) && (count - idealpath) <= 8 && NumberOfMoves == 4)
        {
            printf("                     1.Your Performance Was Excellent.\n");
            printf("                     2.Your Moves Were Well Calculated.\n");
            printf("                     3.You Are In The Pro League.\n");
        }
        else if (6 <= (count - idealpath) && (count - idealpath) <= 10 && NumberOfMoves == 2)
        {
            printf("                     1.Your Performance Was Above Par.\n");
            printf("                     2.Your Moves Were Well Calculated But Still There Is Scope Of Improvement.\n");
            printf("                     3.Try Moderate Level Game.\n");
        }
        else if (8 <= (count - idealpath) && (count - idealpath) <= 14 && NumberOfMoves == 3)
        {
            printf("                     1.Your Performance Was Par.\n");
            printf("                     2.Your Moves Were Well Calculated But Still There Is Scope Of Improvement.\n");
            printf("                     3.Try Difficult Level Game.\n");
        }
        else if (9 <= (count - idealpath) && (count - idealpath) <= 17 && NumberOfMoves == 4)
        {
            printf("                     1.Your Performance Was Above Par.\n");
            printf("                     2.Your Moves Were Well Calculated But Still There Is Scope Of Improvement.\n");
            printf("                     3.Try This Level Again For Better Performance\n");
        }
        else if (11 <= (count - idealpath) && NumberOfMoves == 2)
        {
            printf("                     1.Your Performance Was Below Par.\n");
            printf("                     2.Your Moves Could Have Been Planned In A Better Way.\n");
            printf("                     3.Try This Level Again.\n");
        }
        else if (15 <= (count - idealpath) && NumberOfMoves == 3)
        {
            printf("                     1.Your Performance Was Below Par.\n");
            printf("                     2.Your Moves Could Have Been Planned In A Better Way.\n");
            printf("                     3.Try Easy Level Of Game.\n");
        }
        else if (18 <= (count - idealpath) && NumberOfMoves == 4)
        {
            printf("                     1.Your Performance Was Below Par.\n");
            printf("                     2.Your Moves Could Have Been Planned In A Better Way.\n");
            printf("                     3.Try Moderate Or Easy Level Of Game.\n");
        }
        char *filename = "C:/Users/HP/Desktop/RECORD.txt";
        FILE *fp = fopen(filename, "a");
        if (fp == NULL)
        {
            printf("Error Opening The File %s", filename);
            return -1;
        }
        fprintf(fp, "NAME : %s \n", name1);
        fprintf(fp, "DIFFICULTY LEVEL : %s \n", strupr(LevelOfDifficulty));
        fprintf(fp, "Co-Ordinates:( %d , %d )\n", x_co_ordinate, y_co_ordinate);
        fprintf(fp, "Ideal Number Of Trials = %d\n", idealpath);
        fprintf(fp, "Number Of Trials Taken By User = %d\n", count);
        fprintf(fp, "Fastest Path To Reach :\n");
        if (count > AllowedNumberOfMoves)
        {
        sos:
        {
            fprintf(fp, "NAME : %s \n", name1);
            fprintf(fp, "DIFFICULTY LEVEL : %s \n", strupr(LevelOfDifficulty));
            fprintf(fp, "Co-Ordinates:( %d , %d )\n", x_co_ordinate, y_co_ordinate);
            fprintf(fp, "Could Not Find Co-Ordinates.\n\n");
            goto sos2;
        }
        }
        PrintingMixedElements2(fp, idealmoveslist, xpositive, ypositive, NumberOfMoves);
        fprintf(fp, "\nPath Followed By User:\n");
        for (int k = 0; k < mcount; k++)
        {
            if ((k + 1) % 8 == 0)
            {
                fprintf(fp, "\n");
            }
            if (k != mcount - 1)
            {
                blue();
                fprintf(fp, "%s ", movelist[k]);
                red();
                fprintf(fp, "--> ");
            }
            if (k == mcount - 1)
            {
                blue();
                fprintf(fp, "%s", movelist[k]);
                reset();
            }
        }
        fprintf(fp, "\n");
        fprintf(fp, "Points Scored : %0.0f \n", PointsScored);
        if (0 <= (count - idealpath) && (count - idealpath) <= 5 && NumberOfMoves == 2)
        {
            fprintf(fp, "Performance Was Excellent.\n");
        }
        else if (0 <= (count - idealpath) && (count - idealpath) <= 7 && NumberOfMoves == 3)
        {
            fprintf(fp, "Performance Was Excellent.\n");
        }
        else if (0 <= (count - idealpath) && (count - idealpath) <= 8 && NumberOfMoves == 4)
        {
            fprintf(fp, "Performance Was Excellent.\n");
        }
        else if (6 <= (count - idealpath) && (count - idealpath) <= 10 && NumberOfMoves == 2)
        {
            fprintf(fp, "Performance Was Above Par.\n");
        }
        else if (8 <= (count - idealpath) && (count - idealpath) <= 14 && NumberOfMoves == 3)
        {
            fprintf(fp, "Performance Was Par.\n");
        }
        else if (9 <= (count - idealpath) && (count - idealpath) <= 17 && NumberOfMoves == 4)
        {
            fprintf(fp, "Performance Was Above Par.\n");
        }
        else if (11 <= (count - idealpath) && NumberOfMoves == 2)
        {
            fprintf(fp, "Performance Was Below Par.\n");
        }
        else if (15 <= (count - idealpath) && NumberOfMoves == 3)
        {
            fprintf(fp, "Performance Was Below Par.\n");
        }
        else if (18 <= (count - idealpath) && NumberOfMoves == 4)
        {
            fprintf(fp, "Performance Was Below Par.\n");
        }
        fprintf(fp, "\n\n\n");
        fclose(fp);
        char filename3[100] = "C:/Users/HP/Desktop/";
        strcat(filename3, strupr(name1));
        strcat(filename3, ".txt");
        char *filename2 = filename3;
        FILE *fpp = fopen(filename2, "a");
        if (fpp == NULL)
        {
            printf("Error Opening The File %s", filename2);
            return -1;
        }
        fprintf(fpp, "NAME : %s \n", name1);
        fprintf(fpp, "DIFFICULTY LEVEL : %s \n", strupr(LevelOfDifficulty));
        fprintf(fpp, "Co-Ordinates:( %d , %d )\n", x_co_ordinate, y_co_ordinate);
        fprintf(fpp, "Ideal Number Of Trials = %d\n", idealpath);
        fprintf(fpp, "Number Of Trials Taken By User = %d\n", count);
        fprintf(fpp, "Fastest Path To Reach :\n");
        if (count > AllowedNumberOfMoves)
        {
        sos2:
        {
            fprintf(fpp, "NAME : %s \n", name1);
            fprintf(fpp, "DIFFICULTY LEVEL : %s \n", strupr(LevelOfDifficulty));
            fprintf(fpp, "Co-Ordinates:( %d , %d )\n", x_co_ordinate, y_co_ordinate);
            fprintf(fpp, "Could Not Find Co-Ordinates.\n\n");
            return 0 ;
        }
        }
        PrintingMixedElements2(fpp, idealmoveslist, xpositive, ypositive, NumberOfMoves);
        fprintf(fpp, "\nPath Followed By User:\n");
        for (int k = 0; k < mcount; k++)
        {
            if ((k + 1) % 8 == 0)
            {
                fprintf(fpp, "\n");
            }
            if (k != mcount - 1)
            {
                blue();
                fprintf(fpp, "%s ", movelist[k]);
                red();
                fprintf(fpp, "--> ");
            }
            if (k == mcount - 1)
            {
                blue();
                fprintf(fpp, "%s", movelist[k]);
                reset();
            }
        }
        fprintf(fpp, "\n");
        fprintf(fpp, "Points Scored : %0.0f \n", PointsScored);
        if (0 <= (count - idealpath) && (count - idealpath) <= 5 && NumberOfMoves == 2)
        {
            fprintf(fpp, "Performance Was Excellent.\n");
        }
        else if (0 <= (count - idealpath) && (count - idealpath) <= 7 && NumberOfMoves == 3)
        {
            fprintf(fpp, "Performance Was Excellent.\n");
        }
        else if (0 <= (count - idealpath) && (count - idealpath) <= 8 && NumberOfMoves == 4)
        {
            fprintf(fpp, "Performance Was Excellent.\n");
        }
        else if (6 <= (count - idealpath) && (count - idealpath) <= 10 && NumberOfMoves == 2)
        {
            fprintf(fpp, "Performance Was Above Par.\n");
        }
        else if (8 <= (count - idealpath) && (count - idealpath) <= 14 && NumberOfMoves == 3)
        {
            fprintf(fpp, "Performance Was Par.\n");
        }
        else if (9 <= (count - idealpath) && (count - idealpath) <= 17 && NumberOfMoves == 4)
        {
            fprintf(fpp, "Performance Was Above Par.\n");
        }
        else if (11 <= (count - idealpath) && NumberOfMoves == 2)
        {
            fprintf(fpp, "Performance Was Below Par.\n");
        }
        else if (15 <= (count - idealpath) && NumberOfMoves == 3)
        {
            fprintf(fpp, "Performance Was Below Par.\n");
        }
        else if (18 <= (count - idealpath) && NumberOfMoves == 4)
        {
            fprintf(fpp, "Performance Was Below Par.\n");
        }
        fprintf(fpp, "\n\n\n");
        fclose(fpp);
        printf("\n");
        blue();
        printf("                     Enter ");
        red();
        printf("'AGAIN' ");
        blue();
        printf("To Play Again Or ");
        red();
        printf("'EXIT' ");
        blue();
        printf("To Leave The Game\n");
        fflush(stdin);
        reset();
        while (gamedecidercount != 1)
        {
            fflush(stdin);
            printf("                     ");
            scanf("%s", gamedecider);
            if (strcmp(strlwr(gamedecider), again) == 0)
            {
                play2 = 1;
                gamedecidercount = 1;
            }
            else if (strcmp(strlwr(gamedecider), ex) == 0)
            {
                blue();
                printf("\n                     I Hope You Liked The Game.\n");
                printf("                     Enjoy Your Day   ");
                red();
                printf("%c.\n", 2);
                insertdesign();
                return 0;
            }
            else
            {
                gamedecidercount2++;
                GameTermination(&gamedecidercount2);
                red();
                printf("\n                     !!!Invalid Input!!!\n\n");
                printf("                     Enter ");
                red();
                printf("'AGAIN' ");
                blue();
                printf("To Play Again Or ");
                red();
                printf("'EXIT' ");
                blue();
                printf("To Leave The Game\n");
            }
        }
        printf("\n\n");
    }
    return 0;
}

