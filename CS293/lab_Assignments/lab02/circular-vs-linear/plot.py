import matplotlib.pyplot as plt

# Load data from files
linear_x, linear_y = [], []
with open('linear.data') as f:
    for line in f:
        if line.strip():
            x, y = map(float, line.strip().split())
            linear_x.append(x)
            linear_y.append(y)

circular_x, circular_y = [], []
with open('circular.data') as f:
    for line in f:
        if line.strip():
            x, y = map(float, line.strip().split())
            circular_x.append(x)
            circular_y.append(y)

# Plotting
plt.figure(figsize=(8, 6))
plt.plot(linear_x, linear_y, label='linear', linewidth=3)
plt.plot(circular_x, circular_y, label='circular', linewidth=3)

plt.xlabel('X-axis(#operations in millions)')
plt.ylabel('Y-axis(time in microseconds)')
plt.title('Linear vs Circular')
plt.legend()
plt.grid(True)

# Save to file
plt.savefig('plot.png', dpi=100)
plt.close()
