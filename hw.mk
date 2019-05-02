run : main.cpp graph.py
    g++ main.cpp
    ./a.out >> datos.dat 
    python3 graph.py
