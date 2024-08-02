import matplotlib.pyplot as plt

# Read the segments from the file
with open('segments.txt', 'r') as f:
    segments = [list(map(int, line.split())) for line in f]

# Create a new figure with a larger size
plt.figure(figsize=(10, 10))

# Iterate over the segments and plot them
for segment in segments:
    x1, y1, x2, y2 = segment
    plt.plot([x1, x2], [y1, y2], 'b-')  # 'b-' for blue solid line

# Set the axis limits to fit the lines better
plt.xlim(0, 10)
plt.ylim(0, 10)

# Add grid and labels for better visualization
plt.grid(True)
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Segments Plot')

# Save the plot as an image file
plt.savefig('plot.png')

# Show the plot
plt.show()
