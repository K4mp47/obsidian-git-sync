import tkinter as tk
from tkinter import ttk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
import numpy as np

class GraphApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Graph Creator")

        self.functions = [] # List of functions

        self.main_frame = ttk.Frame(self.root) # Main frame
        self.main_frame.grid(row=0, column=0, sticky="nsew") # Grid layout

        self.sidebar_frame = ttk.Frame(self.root) # Sidebar frame
        self.sidebar_frame.grid(row=0, column=1, sticky="nsew")

        self.root.grid_rowconfigure(0, weight=1)
        self.root.grid_columnconfigure(0, weight=1)
        self.root.grid_columnconfigure(1, weight=1)

        self.figure, self.ax = plt.subplots()
        self.canvas = FigureCanvasTkAgg(self.figure, master=self.main_frame)
        self.canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)
        self.canvas.draw()

        ttk.Label(self.sidebar_frame, text="Functions:").pack(pady=10)
        self.function_entry = ttk.Entry(self.sidebar_frame, width=20)
        self.function_entry.pack(pady=5)
        ttk.Button(self.sidebar_frame, text="Add", command=self.add_function).pack(pady=5)
        ttk.Button(self.sidebar_frame, text="Plot", command=self.plot_graph).pack(pady=10)
        ttk.Button(self.sidebar_frame, text="Clear", command=self.clear_graph).pack(pady=10)

    def add_function(self):
        function_text = self.function_entry.get()
        if function_text:
            self.functions.append(function_text)
            self.function_entry.delete(0, tk.END)
            print("Function added: ", function_text)

    def plot_graph(self):
        self.ax.clear()
        x = np.linspace(-10, 10, 400)
        for function_text in self.functions:
            try:
                function_text = function_text.replace("^", "**")
                function_text = function_text.replace("log", "np.log")
                function_text = function_text.replace("sin", "np.sin")
                function_text = function_text.replace("cos", "np.cos")
                function_text = function_text.replace("tan", "np.tan")
                function_text = function_text.replace("sqrt", "np.sqrt")
                function_text = function_text.replace("frac", "Rational")
                y = eval(function_text)
                self.ax.plot(x, y, label=function_text)
            except Exception as e:
                print(f"Error plotting {function_text}: {e}")

        self.ax.legend()
        self.ax.set_xlabel('X')
        self.ax.set_ylabel('Y')
        self.canvas.draw()

    def clear_graph(self):
        self.ax.clear()
        self.canvas.draw()
        self.functions = []

if __name__ == "__main__":
    root = tk.Tk()
    app = GraphApp(root)
    root.mainloop()