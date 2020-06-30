"""
Jared Jacobowitz
June 2020

Approximates Pi using random "darts" and computing the ratio of the number
of darts that land within the circle compared to how many were thrown
"""
import numpy as np

darts = 80000001  # number of "darts" thrown; ends in 1 for > != 0 decimals

r = 10  # radius/sidelength of circle/square

recordDiff = 0.0
bestPi = 0.0

iterations = 20

for i in range(iterations):
    # Creating an array of random x and y values
    array_of_rand_x = np.random.uniform(-r, r, darts)
    array_of_rand_y = np.random.uniform(-r, r, darts)
    
    # Sum the number of points that land within the circle
    inCircle = np.sum(array_of_rand_x**2 + array_of_rand_y**2 < r**2)
    
    # Computes pi
    pi = 4.0 * float(inCircle) / darts
    
    # Keeps track of the best approximation
    recordDiff = abs(np.pi - bestPi)
    currDiff = abs(np.pi - pi)
    if currDiff < recordDiff:
        recordDiff = currDiff
        bestPi = pi

# Returns the results
percentDiff = recordDiff/np.pi * 100

print(f"{darts} Thrown")
print(f"Approx Pi = {bestPi:.15f}")
print(f"Actual Pi = {np.pi}")
print(f"Diff. = {recordDiff}")
print(f"Percent  Diff. = {round(percentDiff, 6)}%" )