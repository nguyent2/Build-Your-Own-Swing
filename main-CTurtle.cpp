/* File:   main_CTurtle.cpp
 * Original Author:  Jesse W. Walker with modifications by Jan Pearce, 2019
 * Project title: Build_Your_Own_Swing
 * Modified by: Thy H. Nguyen
 * References:
 * This repo uses [C-Turtle](https://github.com/walkerje/C-Turtle) by Jesse W. Walker
 * Original code in python by Thy H. Nguyen: https://github.com/nguyent2/Let-s-Swing
 */

#include <iostream>
using namespace std;

#include "CTurtle.hpp";   //This brings in the CTurtle library for use
namespace ct = cturtle;  //This makes it possible to use the CTurtle commands using ct::


double use_pythagore_triangle(int c, int b) {
	/*
	This function calculate the side of a right triangle using the Pythagore Theorem
	: param c : the hypothesis (the longest side)
	: param b : one of the two sides of the right sides
	: return : the size of the other right sides in a triangle
	*/
	return sqrt(c*c - b*b);
}

void draw_swing(ct::Turtle turtle) {
    /*
    This function draws a swing.
    param turtle: the turtle object
    param sides : the number of sides
    return : None
    */
    // Construct tne swing with nearly a trapezoid
    turtle.width(3);

    turtle.left(60);
    turtle.forward(80);

    turtle.right(60);
    turtle.forward(100);

    turtle.right(60);
    turtle.forward(80);

    turtle.penup();
    turtle.right(120);
    turtle.forward(180);

    turtle.right(180);
    turtle.forward(40);
    turtle.left(90);
    int sides = use_pythagore_triangle(80, 40);
    turtle.forward(sides / 4);

    turtle.pendown();
    turtle.forward(sides - sides / 4);
    turtle.penup();
    turtle.right(90);
    turtle.forward(100);

    turtle.pendown();
    turtle.right(90);
    turtle.forward(sides - sides / 4);
    turtle.begin_fill();
 
    for (int i = 0; i < 2; i++) {
        turtle.right(90);
        turtle.forward(100);
        turtle.right(90);
        turtle.forward(10);
    }

    turtle.end_fill();
 
}

void write_word(ct::Turtle turtle, string ask_color) {
    /*
    This function writes this is a swing
    param turtle : the turtle to draw with
    return : None
    */
    turtle.penup();
    turtle.forward(-50);
    turtle.left(90);
    turtle.forward(90);
    turtle.right(90);
    turtle.forward(95);
    turtle.pendown();
    turtle.width(10);
    turtle.write("This is a " + ask_color + " swing");
    //Print the color of the swing
}

int main() {
    ct::TurtleScreen scr;
    ct::Turtle turtle(scr);
    turtle.speed(0);
    turtle.hideturtle();
    int swings;
    string color;
    int count;
    cout << "How many swings do you want to make (maximum =7)." 
        <<" If you enter anything else beside from 1 to 7, the program will automatically draw 7 swings. \n";
    cin >> swings;

    //scr.setworldcoordinates(-5, -5, 200, 100);

    scr.bgcolor({ "AliceBlue" });

    string color_to_choose[] = { "green", "red", "chocolate","navy","deep sky blue","blue","dark_turquoise","brown","black","orange" };
    
    if (int(swings) == 1 || int(swings) == 2 || int(swings) == 3 || int(swings) == 4 || int(swings) == 5 || int(swings) == 6 || int(swings) == 7 ) 
    {
        count = int(swings);
    }
    else {
        count = 7;
    }

    for (int i = 0; i < count; i++) {

        color = color_to_choose[rand() % 10];
        
        turtle.pencolor({ color});
        turtle.fillcolor({color});
        turtle.penup();
        turtle.goTo(-320 + i * 95, -320 + i * 95);
        turtle.pendown();
        draw_swing(turtle);
        write_word(turtle, color);

    }
    scr.exitonclick();  //exists graphics screen
    return 0;

}