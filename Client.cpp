// client.cpp
//
// Liliia Pavlishin
//
// This program successfully solves and produces the solutions for Towers of Hanoi puzzle for up to 16 disks.
// Depending on your settings (how much memory your machine allocates to a program) and/or your machine, you may be able to do more.
// it takes about 4 minutes to run 16 disks on my machine

#include <iostream>
#include <fstream>
#include "queue_class.h"


int main()
{

    time_t start, end;
    time(&start);

    char moves[6][2] = {{'A', 'B'}, {'A', 'C'}, {'B', 'A'}, {'B', 'C'}, {'C', 'A'}, {'C', 'B'}};
    int N;
    bool unsolved = true;
    QUEUE _queue;                      // for the number of disks
    POSITION position, temp_position;
    POSITION* pos_ptr, *copy_pos_ptr = nullptr;
    std::ofstream output("Solution.txt");

    N = 16;
    position.InitPos(N);             // sets the initial position
    _queue.Enqueue(&position);
    pos_ptr = &position;

    while(unsolved)
    {
        if(!_queue.QueueEmpty())
        {
            pos_ptr = _queue.Dequeue();
        }

        for(int i = 0; i < 6; i++)
        {
            // check for legal moves
            // make a move
            // check if solved
            // yes - break out and print
            // no - enqueue and proceed checking for legal moves

            if(pos_ptr->IsLegal(moves[i][0], moves[i][1]) && unsolved)
            {
                copy_pos_ptr = new POSITION;                    // create a new position the position
                *copy_pos_ptr = *pos_ptr;                       // COPY
                copy_pos_ptr->Move(moves[i][0], moves[i][1]);   // make a move
                if((unsolved = (!copy_pos_ptr->IsSolved())))           // unsolved flag is false if solved
                {
                    _queue.Enqueue(copy_pos_ptr);               // enqueue
                }

            }
        }
    }
    output << "Solution for \"Towers of Hanoi\" puzzle for " << N << " disks." << std::endl;
    output << "Printing out the list of moves... " << std::endl;
    output << *copy_pos_ptr;
    output.close();
    delete copy_pos_ptr;

    time(&end);

    int t = end-start;
    std::cout << "This program ran for: " << (t/60) << " minutes and " << (t%60) << " seconds solving for " << N << " discs." << std::endl;
    return 0;
}