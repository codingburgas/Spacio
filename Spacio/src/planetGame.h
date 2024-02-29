#pragma once
#include "pch.h"

extern int chosenPlanetIndex;

struct PlanetGame {
    Rectangle left;
    Rectangle right;
    Texture2D rocket;
    Texture2D badGuysLeft;
    Texture2D badGuysRight;
    Texture2D sun;
    Texture2D mercury;
    Texture2D venus;
    Texture2D earth;
    Texture2D mars;
    Texture2D jupiter;
    Texture2D saturn;
    Texture2D uranus;
    Texture2D neptune;
    Texture2D starsRocket[3];
    Texture2D starsBadGuys[3];
    Texture2D deadStar;
    Texture2D fireLeft;
    Texture2D fireRight;
    Texture2D fireLeftWin;
    Texture2D fireRightWin;

    int rocketY;
    int badGuysLeftX;
    int badGuysRightX;
    int badGuysSpeed;
    int firstTextDuration;
    int frameCounter;
    int posY;
    int wrongAnswerCounter;
    int rightAnswerCounter;
    int currentQuestionIndex;
    int stoppingY;

    bool firstTextShown = false;
    bool dialogShown = false;
    bool dialogShown2 = false;
    bool okTextShown = false;
    bool givenAnwerOne = false;
    bool givenAnwerTwo = false;
    bool givenAnwerThree = false;
    bool givenAnwerFour = false;
    bool givenAnwerFive = false;
    bool givenAnwerSix = false;
    bool quizGame = false;
    bool correctAnswer = false;
    bool wrongAnswer = false;
    bool lostGame = false;
    bool wonGame = false;

    const char* leftInformation[9] = {
    "Mass: 1.989 * 10^30 kilograms\nDiameter: Approximately 1.4 million km\nSurface temperature: Around 5,500 C",
    "Mass: 3.285 * 10^23 kilograms\nDiameter: Approximately 4,880 km\nSurface temperature: Between -173°C to 427 C",
    "Mass: 4.8675 * 10^24 kilograms\nDiameter: Approximately 12,104 km\nSurface temperature: Around 462 C",
    "Mass: 5.972 * 10^24 kilograms\nDiameter: Approximately 12,742 km\nSurface temperature: Around 15 C",
    "Mass: 6.4171 * 10^23 kilograms\nDiameter: Approximately 6,779 km\nSurface temperature: Around -63 C",
    "Mass: 1.898 * 10^27 kilograms\nDiameter: Approximately 139,820 km\nSurface temperature: Around -145 C",
    "Mass: 5.683 * 10^26 kilograms\nDiameter: Approximately 116,460 km\nSurface temperature: Around -178 C",
    "Mass: 8.681 * 10^25 kilograms\nDiameter: Approximately 50,724 km\nSurface temperature: Around -197 C",
    "Mass: 1.024 * 10^26 kilograms\nDiameter: Approximately 49,244 km\nSurface temperature: Around -201 C"
    };
    const char* rightInformation[9] = {
    "Energy production: Converting hydrogen\ninto helium\nAge: Approximately 4.6 billion years\nComposition: Hydrogen(74 %) and helium (24 %)",
    "Energy production: Primarily reflects\nsunlight\nAge: Approximately 4.5 billion years\nComposition: Mostly silicate\nrock and metals",
    "Energy production: Reflects and\nabsorbs sunlight\nAge: Approximately 4.5 billion years\nComposition: Carbon dioxide\n(96.5%), nitrogen (3.5%)",
    "Energy production: Various sources,\nincluding solar radiation\nAge: Approximately 4.5 billion years\nComposition: Iron\n(32.1%), oxygen (30.1%), silicon (15.1%), magnesium (13.9%)",
    "Energy production: Receives sunlight\nAge: Approximately 4.6 billion years\nComposition: Iron oxide (88.8%),\nsilicon dioxide (7.2%)",
    "Energy production: Releases more heat\nthan it receives from the Sun\nAge: Approximately 4.5 billion years\nComposition: Hydrogen\n(89.8%), helium (10.2%)",
    "Energy production: Primarily reflects\nsunlight\nAge: Approximately 4.5 billion years\nComposition: Hydrogen (96.3%),\nhelium (3.3%)",
    "Energy production: Absorbs and\nreflects sunlight\nAge: Approximately 4.5 billion years\nComposition: Hydrogen (83%),\nhelium (15%), methane (2%)",
    "Energy production: Absorbs and\nreflects sunlight\nAge: Approximately 4.5 billion years\nComposition: Hydrogen (80%),\nhelium (19%), methane (1.5%)"
    };
    const char* firstQuestion[9] = {
    "What is the mass of the Sun?",
    "What is the mass of Mercury?",
    "What is the mass of Venus?",
    "What is the mass of Earth?",
    "What is the mass of Mars?",
    "What is the mass of Jupiter?",
    "What is the mass of Saturn?",
    "What is the mass of Uranus?",
    "What is the mass of Neptune?",
    };
    const char* secondQuestion[9] = {
    "What is the approximate diameter of the Sun?",
    "What is the approximate diameter of Mercury?",
    "What is the approximate diameter of Venus?",
    "What is the approximate diameter of Earth?",
    "What is the approximate diameter of Mars?",
    "What is the approximate diameter of Jupiter?",
    "What is the approximate diameter of Saturn?",
    "What is the approximate diameter of Uranus?",
    "What is the approximate diameter of Neptune?",
    };
    const char* thirdQuestion[9] = {
    "What is the surface temperature of the Sun?",
    "What is the surface temperature of Mercury?",
    "What is the surface temperature of Venus?",
    "What is the surface temperature of Earth?",
    "What is the surface temperature of Mars?",
    "What is the surface temperature of Jupiter?",
    "What is the surface temperature of Saturn?",
    "What is the surface temperature of Uranus?",
    "What is the surface temperature of Neptune?",
    };
    const char* forthQuestion[9] = {
    "How old is the Sun?",
    "How old is Mercury?",
    "How old is Venus?",
    "How old is Earth?",
    "How old is Mars?",
    "How old is Jupiter?",
    "How old is Saturn?",
    "How old is Uranus?",
    "How old is Neptune?",
    };
    const char* fifthQuestion[9] = {
    "What is the composition of the Sun?",
    "What is the composition of Mercury?",
    "What is the composition of Venus?",
    "What is the composition of Earth?",
    "What is the composition of Mars?",
    "What is the composition of Jupiter?",
    "What is the composition of Saturn?",
    "What is the composition of Uranus?",
    "What is the composition of Neptune?",
    };
    const char* sixthQuestion[9] = {
    "What is the primary process of energy production in the Sun?",
    "What is the primary process of energy production in Mercury?",
    "What is the primary process of energy production in Venus?",
    "What is the primary process of energy production in Earth?",
    "What is the primary process of energy production in Mars?",
    "What is the primary process of energy production in Jupiter?",
    "What is the primary process of energy production in Saturn?",
    "What is the primary process of energy production in Uranus?",
    "What is the primary process of energy production in Neptune?",
    };
    const char* rightAnswer1[9] = {
    "1.989 * 10^30 kilograms",
    "3.285 × 10^23 kilograms",
    "4.8675 × 10^24 kilograms",
    "5.972 × 10^24 kilograms",
    "6.4171 × 10^23 kilograms",
    "1.898 × 10^27 kilograms",
    "5.683 × 10^26 kilograms",
    "8.681 × 10^25 kilograms",
    "1.024 × 10^26 kilograms",
    };
    const char* rightAnswer2[9] = {
    "Approximately 1.4 million km",
    "Approximately 4,880 km",
    "Approximately 12,104 km",
    "Approximately 12,742 km",
    "Approximately 6,779 km",
    "Approximately 139,820 km",
    "Approximately 116,460 km",
    "Approximately 50,724 km",
    "Approximately 49,244 km",
    };
    const char* rightAnswer3[9] = {
    "Around 5,500 C",
    "Between -173°C to 427 C",
    "Around 462 C",
    "Around 15 C",
    "Around -63 C",
    "Around -145 C",
    "Around -178 C",
    "Around -197 C",
    "Around -201 C",
    };
    const char* rightAnswer4[9] = {
    "4.6 billion years",
    "Approximately 4.5 billion years",
    "Approximately 4.5 billion years",
    "Approximately 4.5 billion years",
    "Approximately 4.6 billion years",
    "Approximately 4.5 billion years",
    "Approximately 4.5 billion years",
    "Approximately 4.5 billion years",
    "Approximately 4.5 billion years",
    };
    const char* rightAnswer5[9] = {
    "Hydrogen(74 %) and helium (24 %)",
    "Mostly silicate rock and metals",
    "Carbon dioxide (96.5%), nitrogen (3.5%)",
    "Iron (32.1%), oxygen (30.1%), silicon (15.1%), magnesium (13.9%)",
    "Iron oxide (88.8%), silicon dioxide (7.2%)",
    "Hydrogen (89.8%), helium (10.2%)",
    "Hydrogen (96.3%), helium (3.3%)",
    "Hydrogen (83%), helium (15%), methane (2%)",
    "Hydrogen (80%), helium (19%), methane (1.5%)",
    };
    const char* rightAnswer6[9] = {
    "Converting hydrogen into helium",
    "Primarily reflects sunlight",
    "Reflects and absorbs sunlight",
    "Various sources, including solar radiation",
    "Receives sunlight",
    "Releases more heat than it receives from the Sun",
    "Primarily reflects sunlight",
    "Absorbs and reflects sunlight",
    "Absorbs and reflects sunlight",
    };
    const char* wrongAnswer1[9] = {
    "1.989 * 10^29 kilograms",
    "3.285 × 10^22 kilograms",
    "4.8675 × 10^23 kilograms",
    "5.972 × 10^23 kilograms",
    "6.4171 × 10^22 kilograms",
    "1.898 × 10^26 kilograms",
    "5.683 × 10^25 kilograms",
    "8.681 × 10^24 kilograms",
    "1.024 × 10^25 kilograms",
    };
    const char* wrongAnswer2[9] = {
    "Approximately 1.2 million km",
    "Approximately 5,000 km",
    "Approximately 10,000 km",
    "Approximately 10,000 km",
    "Approximately 7,000 km",
    "Approximately 150,000 km",
    "Approximately 110,000 km",
    "Approximately 60,000 km",
    "Approximately 45,000 km",
    };
    const char* wrongAnswer3[9] = {
    "Around 7,000 C",
    "Between -200C to 500C",
    "Around 500 C",
    "Around 20 C",
    "Around -50 C",
    "Around -200 C",
    "Around -200 C",
    "Around -180 C",
    "Around -210 C",
    };
    const char* wrongAnswer4[9] = {
    "3.8 billion years",
    "Approximately 4 billion years",
    "Approximately 4 billion years",
    "Approximately 4 billion years",
    "Approximately 4.5 billion years",
    "Approximately 5 billion years",
    "Approximately 5 billion years",
    "Approximately 4.6 billion years",
    "Approximately 4.6 billion years",
    };
    const char* wrongAnswer5[9] = {
    "Hydrogen(80 %) and helium (20 %)",
    "Primarily gases",
    "Primarily carbon dioxide (95%) with traces of nitrogen",
    "Primarily nitrogen and oxygen",
    "Primarily iron and nickel",
    "Primarily hydrogen (70%) and helium (30%)",
    "Primarily helium (96.3%), hydrogen (3.7%)",
    "Primarily hydrogen (85%), helium (10%), methane (5%)",
    "Primarily hydrogen (82%), helium (17%), methane (1%)",
    };
    const char* wrongAnswer6[9] = {
    "Converting helium into hydrogen",
    "Primarily generates heat internally",
    "Primarily releases radiation",
    "Mainly nuclear fusion",
    "Primarily produces methane",
    "Absorbs sunlight for energy production",
    "Primarily absorbs sunlight",
    "Absorbs and releases sunlight",
    "Absorbs and releases sunlight",
    };
};

static PlanetGame planetGameData;

void planetGame();
