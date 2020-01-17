===========
Full Credit
===========

Your full credit solution always goes in the full_credit subdirectory - capitalization and underlines matters! *You must complete the full credit assignment to get any credit for the bonus assignment, and you must complete the bonus assignment to get any credit for the extreme bonus assignment!*

Step-by-step instructions
=========================

1. Create a **private** GitHub account, and post its name as your solution to Assignment P1 in Canvas. 
2. On GitHub, create a GitHub repository **named cse1325** (capitalization matters!),
3. Clone that GitHub repository to your Linux home directory using ``cd ; git clone https://github.com/<<your_user_name>>/cse1325``, replacing <<your_user_name>> with (you guessed it) your user name.
4. Create a P01/full_credit subdirectory, using e.g., ``mkcd P01/full_credit``.
5. In it, create your solution to the full credit assignment in file ``hello.cpp``.
6. Put hello.cpp into your GitHub repository. (I *know* it's not working yet. You get unlimited commits!) Try ``git add hello.cpp``, then ``git commit -m 'P01 fc My first commit!'``, then ``git push``.
7. Compile your program using e.g., ``g++ hello.cpp``. Fix any compiler errors.
8. Update hello.cpp in your GitHub repository. (I *know* you haven't run it yet. Did I mention you get unlimited commits?) Try ``git add -u`` (the -u means "update all existing files that have changed), then ``git commit -m 'P01 fc It compiles!'``, then ``git push``.
9. Run your program using e.g., ``./a.out``. Fix any runtime errors.
10. Update hello.cpp in your GitHub repository. Perhaps your commit message includes ``It runs!``?
11. Take a screenshot of your program running, and name it hello.png. Try ``scrot -s hello.png`` and click your terminal window.
12. Add hello.png to your GitHub repository. Can you guess the commands?  (Hint: ``git add hello.png`` and ``git commit -m 'P01 fc Adding screenshot'`` and ``git commit`` - or was that too subtle?)

