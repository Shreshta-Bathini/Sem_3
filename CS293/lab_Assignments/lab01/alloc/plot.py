import matplotlib.pyplot as plt
import csv
import sys

if len(sys.argv) < 2:
    print('No file name')

filenames = sys.argv[1:]

for filename in filenames:
    X = []
    Y = [] 
    with open(filename, 'r') as datafile:
        plotting = csv.reader(datafile, delimiter=' ')
        for ROWS in plotting:
            X.append(float(ROWS[0]))
            Y.append(float(ROWS[1])) 
    plt.plot(X, Y,label=filename)

plt.legend(loc="upper right")
plt.title('Tasks vs Time')
plt.xlabel('X')
plt.ylabel('Clock cycles')
plt.show()
