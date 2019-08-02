# CS50-assignments

This is a collection of assessments completed for the 2019 Harvard CS50 course on EDX.org

recover.c
---- 
This program opens and runs through a forensic image file to recover JPEG files, naming them sequentially starting from 000.

mario.py
----
This was my second program in Python, after "Hello, world!". mario.py asks the user for a number between 1 and 8 and then prints two pyramids built of hashes based on the number given. If the user does not give a valid number, the program will keep asking for one. For example, if the user enters 3, they should receive the following:

  #  #
 ##  ##
###  ###

I decided to try building a function with the number input, and decided that stylistically it looked better to build main() as well. The only problem I ran into with this was that on my screen, "__name__" looked like it had three underscores instead of two, so I got an undefined error when I first tried to run it!

For the spaces in between the two pyramids, I debated between having a single print("  ") that contained two spaces or using a for loop. I ended up deciding on the for loop because I was printing everything else a character at a time and it felt consistent to continue with that. It also means that it is easier to tell how many spaces are being printed between the pyramids, as well as to change the spacing later on.
