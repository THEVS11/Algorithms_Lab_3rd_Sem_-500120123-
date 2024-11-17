import matplotlib.pyplot as plt
import matplotlib.patches as patches

def activity_selection(start, end):
    selected_activities = [0]  # Always select the first activity
    i = 0
    for j in range(1, len(start)):
        if start[j] >= end[i]:
            selected_activities.append(j)
            i = j
    return selected_activities

def plot_activities(start, end, selected_activities):
    fig, ax = plt.subplots(figsize=(10, 4))
    y = 0  # Vertical position for plotting each activity

    # Plot each activity as a block
    for i in range(len(start)):
        color = 'skyblue' if i in selected_activities else 'lightgrey'
        ax.add_patch(patches.Rectangle((start[i], y), end[i] - start[i], 0.5, color=color, edgecolor="black"))
        plt.text(start[i] + (end[i] - start[i]) / 2, y + 0.25, f"A{i+1}", ha="center", va="center")

    # Set plot limits and labels
    ax.set_xlim(0, max(end) + 1)
    ax.set_ylim(-1, 1)
    ax.set_xlabel("Time")
    ax.set_yticks([])
    plt.title("Activity Selection (Selected activities are highlighted)")
    plt.show()

# Sample activity times
start_times = [1, 3, 0, 5, 8, 5]
end_times = [2, 4, 6, 7, 9, 9]

# Get selected activities using the greedy algorithm
selected = activity_selection(start_times, end_times)

# Plot the activities with the selected ones highlighted
plot_activities(start_times, end_times, selected)