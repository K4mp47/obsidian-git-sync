import tkinter as tk
from tkinter import ttk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
import numpy as np
from ttkthemes import ThemedTk


class GraphApp:
    def __init__(self, primary):
        self.root = primary
        self.root.title("Graph Creator")

        self.functions = []  # List of functions

        self.main_frame = ttk.Frame(self.root)  # Main frame
        self.main_frame.grid(row=0, column=0, sticky="nsew")  # Grid layout

        self.sidebar_frame = ttk.Frame(self.root)  # Sidebar frame
        self.sidebar_frame.grid(row=0, column=1, sticky="nsew")

        self.root.grid_rowconfigure(0, weight=1)
        self.root.grid_columnconfigure(0, weight=1)
        self.root.grid_columnconfigure(1, weight=1)

        plt.grid(True)
        plt.title("Graph")
        plt.figure(figsize=(10, 6))
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
        ttk.Separator(self.sidebar_frame, orient=tk.HORIZONTAL).pack(fill=tk.X, pady=10)
        #ttk.Button(self.sidebar_frame, text="Show Legend", command=self.show_function_legend).pack(pady=10)
        ttk.Button(self.sidebar_frame, text="Exit", command=self.root.quit).pack(pady=10) 
        #def show_function_legend(self):
        legend_text = (
            "You can input various mathematical expressions for functions.\n\n"
            "Examples:\n"
            "- Linear function: y = mx + b (e.g., 2*x + 3)\n"
            "- Quadratic function: y = ax^2 + bx + c (e.g., x**2 - 4*x + 4)\n"
            "- Sine function: y = A * sin(B * x + C) (e.g., 5 * np.sin(2 * x))\n"
            "- Exponential function: y = A * e^(Bx) (e.g., 2 * np.exp(0.5 * x))\n"
            "- Logarithmic function: y = A * log(Bx + C) (e.g., 2 * np.log(2*x + 1))\n"
            "- Square root: sqrt(x) (e.g., sqrt(x))\n"
            "- Logarithm: log(x) (e.g., log(x))\n"
            "- Fraction: frac(A, B) (e.g., frac(1, x))"
        )

        ttk.Label(self.sidebar_frame, text=legend_text).pack(pady=2)
        # popup = tk.Toplevel(self.root)
        # popup.title("Function Legend")
        # label = ttk.Label(popup, text=legend_text, wraplength=400, justify=tk.LEFT)
        # label.pack(padx=1, pady=1)
        # # add exit Button
        # ttk.Button(popup, text="Close", command=popup.destroy).pack(pady=10)
        #
    def add_function(self):
        function_text = self.function_entry.get()
        if function_text:
            self.functions.append(function_text)
            self.function_entry.delete(0, tk.END)
        print("Function added: ", self.functions)

    def plot_graph(self):
        self.ax.clear()
        # set x and y with the same size
        y = np.linspace(1, 50)
        x = np.linspace(1, 50)
        self.ax.set_ylim(0, 50)
        self.ax.set_xlim(0,50)
        for function_text in self.functions:
            try:
                function_text = function_text.replace("^", "**")
                function_text = function_text.replace("log", "np.log")
                function_text = function_text.replace("sin", "np.sin")
                function_text = function_text.replace("cos", "np.cos")
                function_text = function_text.replace("tan", "np.tan")
                function_text = function_text.replace("sqrt", "np.sqrt")
                function_text = function_text.replace("frac", "Rational")
                print(function_text)

                y = eval(function_text)
                # check if np. is inside function_text
                if("np.log" in function_text):
                    self.ax.scatter(0, y, label=function_text)
                else:
                    self.ax.plot(x, y, label=function_text)
            except Exception as e:
                print(f"Error plotting {function_text}: {e}")

        self.ax.legend()
        self.canvas.draw()

    def clear_graph(self):
        self.ax.clear()
        self.canvas.draw()
        self.functions = []


if __name__ == "__main__":
    root = ThemedTk(theme="equilux")
    app = GraphApp(root)
    root.mainloop()
