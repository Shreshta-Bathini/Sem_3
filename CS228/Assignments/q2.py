"""
Sokoban Solver using SAT (Boilerplate)
--------------------------------------
Instructions:
- Implement encoding of Sokoban into CNF.
- Use PySAT to solve the CNF and extract moves.
- Ensure constraints for player movement, box pushes, and goal conditions.

Grid Encoding:
- 'P' = Player
- 'B' = Box
- 'G' = Goal
- '#' = Wall
- '.' = Empty space
"""

from pysat.formula import CNF
from pysat.solvers import Solver


# Directions for movement
DIRS = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}


class SokobanEncoder:
    def __init__(self, grid, T):
        """
        Initialize encoder with grid and time limit.

        Args:
            grid (list[list[str]]): Sokoban grid.
            T (int): Max number of steps allowed.
        """
        self.grid = grid
        self.T = T
        self.N = len(grid)
        self.M = len(grid[0])

        self.goals = []
        self.boxes = []
        self.walls= []
        self.player_start = None

        # TODO: Parse grid to fill self.goals, self.boxes, self.player_start
        self._parse_grid()

        self.num_boxes = len(self.boxes)
        self.cnf = CNF()

    def _parse_grid(self):
        """Parse grid to find player, boxes, and goals."""
        # TODO: Implement parsing logic
        for i in range(self.N):
            for j in range(self.M):
                if self.grid[i][j]=='P':
                    self.player_start=[i,j]
                elif self.grid[i][j]=='B':
                    self.boxes.append([i,j])
                elif self.grid[i][j]=='G':
                    self.goals.append([i,j])
                elif self.grid[i][j]=='#':
                    self.walls.append([i,j])
        pass

    # ---------------- Variable Encoding ----------------
    def var_player(self, x, y, t):
        """
        Variable ID for player at (x, y) at time t.
        """
        # TODO: Implement encoding scheme
        if(x<0 or y<0 or x>=self.N or y>=self.M):
            return (self.N*self.M*(1+self.num_boxes)*(1+self.T)+1)
        return (x*self.M+y+t*self.N*self.M+1)
        pass

    def var_box(self, b, x, y, t):
        """
        Variable ID for box b at (x, y) at time t.
        """
        # TODO: Implement encoding scheme
        if(x<0 or y<0 or x>=self.N or y>=self.M):
            return (self.N*self.M*(1+self.num_boxes)*(1+self.T)+1)
        return ( (self.N*self.M*(self.T+1))*(b+1)+x*self.M+y+1+t*self.N*self.M)
        pass

    # ---------------- Encoding Logic ----------------
    def encode(self):
        """
        Build CNF constraints for Sokoban:
        - Initial state
        - Valid moves (player + box pushes)
        - Non-overlapping boxes
        - Goal condition at final timestep
        """
        # TODO: Add constraints for:
        # 1. Initial conditions
        # 2. Player movement
        # 3. Box movement (push rules)
        # 4. Non-overlap constraints
        # 5. Goal conditions
        # 6. Other conditions

        # Intial Conditions
        self.cnf.append([self.var_player(self.player_start[0],self.player_start[1],0)])

        for i in range(self.num_boxes):
            self.cnf.append([self.var_box(i,self.boxes[i][0],self.boxes[i][1],0)])
        
        #player and boxes should exist at some place at a particular time
        for t in range(self.T+1):
            self.cnf.append([self.var_player(i,j,t) for i in range(self.N) for j in range(self.M)])
        for t in range(self.T+1):
            for b in range(self.num_boxes):
                self.cnf.append([self.var_box(b,i,j,t) for i in range(self.N) for j in range(self.M)])
        
        #At a time t player or a particular box should exist at only one place 
        for t in range(self.T+1):
            for id1 in range(self.N*self.M):
                for id2 in range(id1+1,self.N*self.M):
                    self.cnf.append([-self.var_player(id1//self.M,id1%self.M,t),-self.var_player(id2//self.M,id2%self.M,t)])
        for t in range(self.T+1):
            for id1 in range(self.N*self.M):
                for id2 in range(id1+1,self.N*self.M):                    
                    for b in range(self.num_boxes):
                        self.cnf.append([-self.var_box(b,id1//self.M,id1%self.M,t),-self.var_box(b,id2//self.M,id2%self.M,t)])

        # Wall should not collide with player,box at any time
        for pos in self.walls:
            for t in range(self.T+1):
                self.cnf.append([-self.var_player(pos[0],pos[1],t)])
                for b in range(self.num_boxes):
                    self.cnf.append([-self.var_box(b,pos[0],pos[1],t)])

        # Box should not collide with player at any time
        for i in range(self.N):
            for j in range(self.M):
                for t in range(self.T+1):
                    for b in range(self.num_boxes):
                         self.cnf.append([-self.var_player(i,j,t),-self.var_box(b,i,j,t)])
        
        # Boxes shouldn't collide 
        for i in range(self.N):
            for j in range(self.M):
                for t in range(self.T+1):
                    for b1 in range(self.num_boxes):
                        for b2 in range(b1+1,self.num_boxes):
                            self.cnf.append([-self.var_box(b1,i,j,t),-self.var_box(b2,i,j,t)])
                
        #player movment possibilities
        for t in range(1,self.T+1):
            for i in range(self.N):
                for j in range(self.M):
                    self.cnf.append([-self.var_player(i,j,t),self.var_player(i,j,t-1),self.var_player(min(self.N-1,i+1),j,t-1),self.var_player(max(0,i-1),j,t-1),self.var_player(i,min(self.M-1,j+1),t-1),self.var_player(i,max(0,j-1),t-1)])
        
        #box movement
        for t in range(1,self.T+1):
            for i in range(self.N):
                for j in range(self.M):
                    for b in range(self.num_boxes):
                        self.cnf.append([-self.var_box(b,i,j,t),self.var_box(b,i,j,t-1),self.var_box(b,min(self.N-1,i+1),j,t-1),self.var_box(b,max(0,i-1),j,t-1),self.var_box(b,i,min(self.M-1,j+1),t-1),self.var_box(b,i,max(0,j-1),t-1)])

        # player must move if box moves 
        for t in range(1,self.T+1):
            for i in range(self.N):
                for j in range(self.M):
                    for b in range(self.num_boxes):
                        self.cnf.append([-self.var_box(b,i,j,t-1),-self.var_box(b,i+1,j,t),self.var_player(i,j,t)])
                        self.cnf.append([-self.var_box(b,i,j,t-1),-self.var_box(b,i+1,j,t),self.var_player(i-1,j,t-1)])
                        self.cnf.append([-self.var_box(b,i,j,t-1),-self.var_box(b,i-1,j,t),self.var_player(i,j,t)])
                        self.cnf.append([-self.var_box(b,i,j,t-1),-self.var_box(b,i-1,j,t),self.var_player(i+1,j,t-1)])
                        self.cnf.append([-self.var_box(b,i,j,t-1),-self.var_box(b,i,j+1,t),self.var_player(i,j,t)])
                        self.cnf.append([-self.var_box(b,i,j,t-1),-self.var_box(b,i,j+1,t),self.var_player(i,j-1,t-1)])
                        self.cnf.append([-self.var_box(b,i,j,t-1),-self.var_box(b,i,j-1,t),self.var_player(i,j,t)])
                        self.cnf.append([-self.var_box(b,i,j,t-1),-self.var_box(b,i,j-1,t),self.var_player(i,j+1,t-1)])

        # Goal condition
        for pos_g in self.goals:
            self.cnf.append([self.var_box(b,pos_g[0],pos_g[1],self.T) for b in range(self.num_boxes)])
        
        return self.cnf
        pass


def decode(model, encoder):
    """
    Decode SAT model into list of moves ('U', 'D', 'L', 'R').

    Args:
        model (list[int]): Satisfying assignment from SAT solver.
        encoder (SokobanEncoder): Encoder object with grid info.

    Returns:
        list[str]: Sequence of moves.
    """
    N, M, T = encoder.N, encoder.M, encoder.T

    # TODO: Map player positions at each timestep to movement directions
    Directions=[]
    positions=[]

    for t in range(T+1):
        for id in range(t*N*M,(t+1)*N*M):
            if(model[id]>0):
                positions.append([((model[id]-t*M*N)-1)//M,(model[id]-1)%M])

    for t in range(1,T+1):
        if((positions[t][0]-positions[t-1][0])==1):
            Directions.append('D')
        elif ((positions[t-1][0]-positions[t][0])==1):
            Directions.append('U')
        elif ((positions[t][1]-positions[t-1][1])==1):
            Directions.append('R')
        elif ((positions[t-1][1]-positions[t][1])==1):
            Directions.append('L')
    
    return Directions
    pass


def solve_sokoban(grid, T):
    """
    DO NOT MODIFY THIS FUNCTION.

    Solve Sokoban using SAT encoding.

    Args:
        grid (list[list[str]]): Sokoban grid.
        T (int): Max number of steps allowed.

    Returns:
        list[str] or "unsat": Move sequence or unsatisfiable.
    """
    encoder = SokobanEncoder(grid, T)
    cnf = encoder.encode()

    with Solver(name='g3') as solver:
        solver.append_formula(cnf)
        if not solver.solve():
            return -1

        model = solver.get_model()

        if not model:
            return -1
            
        return decode(model, encoder)