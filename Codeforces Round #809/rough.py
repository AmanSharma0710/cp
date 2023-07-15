#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue May 18 16:32:19 2021

@author: ramanathanmuthuganapathy
"""
from matplotlib.figure import Figure
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np

#plotting y = x^2
t = np.arange(-2.0, 2.0, 0.01)
s = t ** 2

fig, ax = plt.subplots()
ax.plot(t, s)

ax.set(xlabel='x vlues', ylabel='y values',
       title='Explicit function y = f(x)')
ax.grid()

# fig.savefig("test.png")
plt.show()

# Parametric space curve t, t**2, t**3

t = np.arange(-2.0, 2.0, 0.1)
x = t
y = t ** 2
z = t ** 3

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.plot(x, y, z)

ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')
ax.set_title('Parametric space curve t, t**2, t**3')

plt.show()

# Parametric curve - https://matplotlib.org/stable/gallery/mplot3d/lines3d.html
# Parametric space curve helix

ax = plt.figure().add_subplot(projection='3d')


# fig.savefig("test.png")


# The following will print a 3D surface
# X,Y=np.meshgrid(x,y) #Forming MeshGrid
# Z = X**3
# fig = plt.figure()
# ax = fig.add_subplot(111, projection='3d')

# ax.plot_surface(X, Y, Z)

# ax.set_xlabel('X Label')
# ax.set_ylabel('Y Label')
# ax.set_zlabel('Z Label')

# plt.show()

# fig.savefig("test.png")

def find_point(control_points, t):
    if control_points.shape[0] == 1:
       return control_points
    new_points = []
    for i in range(control_points.shape[0] - 1):
        new_points.append(control_points[i]*(1-t) + control_points[i+1]*t)
    control_points = np.empty(0)
    return find_point(np.array(new_points), t)


def bezier(control_points, n_points=100):
    t_range = np.linspace(0, 1, n_points)
    curve = np.zeros((n_points, 3))
    for i in range(3):
       for t in range(n_points):
           curve[t, i] = find_point(control_points[:, i], t_range[t])
    return curve

control_polygon = np.array([[100, 0, 0], [0, 0, 0], [0, 100, 0]])
curve = bezier(control_polygon, 5000)
x = curve[:, 0]
y = curve[:, 1]
z = curve[:, 2]

ax.plot(x, y, z, label='bezier curve')
ax.legend()

plt.show()