import numpy as np
import matplotlib.pyplot as plt

N = 10000 # simulation number
U = np.random.rand(3, N)
Y = (U < 0.5).astype(int)
X = np.sum(Y, axis=0)

plt.hist(X, bins=np.arange(5)-0.5, edgecolor='black', density=True)
plt.xticks([0, 1, 2, 3])
plt.xlabel("Number of Heads")
plt.ylabel("Frequency")
plt.title("Histogram of X (Number of Heads in 3 Coin Tosses)")
plt.show()
