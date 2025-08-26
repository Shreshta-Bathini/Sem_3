"""
sudoku_solver.py

Implement the function `solve_sudoku(grid: List[List[int]]) -> List[List[int]]` using a SAT solver from PySAT.
"""

from pysat.formula import CNF
from pysat.solvers import Solver
from typing import List

def literal(i :int , j:int , num:int)  ->int:
    return (i*81+j*9+num)

def position(lit):
    
    num=9-(9-lit%9)%9
    lit-=num
    i=lit//81
    lit%=81
    j=lit//9
    return [i,j,num]


def solve_sudoku(grid: List[List[int]]) -> List[List[int]]:
    """Solves a Sudoku puzzle using a SAT solver. Input is a 2D grid with 0s for blanks."""
    # TODO: implement encoding and solving using PySAT

    s=Solver(name='glucose3')
    clauses=CNF()

    for i in range(9):
        for j in range(9):
            clauses.append([literal(i,j,num) for num in range(1,10)])
            for x in range(1,10):
                for y in range(x+1,10):
                    clauses.append([-literal(i,j,x),-literal(i,j,y)])

            if(grid[i][j]!=0):
                clauses.append([literal(i,j,grid[i][j])])
    
    for i in range(9):
         for num in range(1,10):
            clauses.append([literal(i,j,num) for j in range(9)])
    
    for j in range(9):
        for num in range(1,10):
            clauses.append([literal(i,j,num) for i in range(9)])
    
    for i in range(0,9,3):
        for j in range(0,9,3):
            for num in range(1,10):
                clauses.append([])
                for p in range(3):
                    for q in range(3):
                        clauses[-1].append(literal(i+p,j+q,num))

    for c in clauses:
        s.add_clause(c)
    
    sol=[]
    if s.solve():
        sol=s.get_model()
    else:
        new_grid=[[]]
    
    new_grid=[[0]*9 for _ in range(9)]
    for x in sol:
        if x>0:
            pos=position(x)
            new_grid[pos[0]][pos[1]]=pos[2]
    return new_grid

    pass