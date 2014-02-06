"""Modified version of the example code from Janert,
Feedback Control For Computer Systems

This modified version requires pandas, numpy, and matplotlib.

If you use apt:

sudo apt-get install python-pandas python-numpy python-matplotlib
"""

import numpy
import pandas
import random
import matplotlib.pyplot as pyplot
import math

class Buffer:
    def __init__( self, max_wip, max_flow ):
        """Initializes the buffer:

        max_wip: maximum work in progress
        max_flow: maximum work completed per time step
        """
        self.queued = 0
        self.wip = 0             # work-in-progress ("ready pool")

        self.max_wip = max_wip
        self.max_flow = max_flow # avg outflow is max_flow/2

    def work( self, u ):
        # Add to ready pool
        u = max( 0, int(round(u)) )
        u = min( u, self.max_wip )
        self.wip += u

        # Transfer from ready pool to queue
        r = int( round( random.uniform( 0, self.wip ) ) )
        self.wip -= r
        self.queued += r

        # Release from queue to downstream process
        r = int( round( random.uniform( 0, self.max_flow ) ) )
        r = min( r, self.queued )
        self.queued -= r

        return self.queued

class Controller:
    def __init__( self, kp, ki, kd ):
        """Initializes the controller.

        kp: proportional gain
        ki: integral gain
        """
        self.kp, self.ki, self.kd = kp, ki, kd
        self.eprev, self.tprev, self.i, self.k = 0, 0, 0, 0

    def work( self, e, t ):
        """Computes the number of jobs to be added to the ready queue.

        e: error

        returns: float number of jobs
        """
        self.i += e
        self.d = (e - self.eprev)

        self.k

        self.eprev = e
        self.tprev = t

        return self.kp*e + self.ki*self.i + self.kd*self.d

# ============================================================

def closed_loop( c, p, tm=5000 ):
    """Simulates a closed loop control system.

    c: Controller object
    p: Buffer object
    tm: number of time steps

    returns: tuple of sequences (times, targets, errors)
    """

    def setpoint( t ):
        return (1 - math.exp(t*-1/100.0))*100.0

        #Stop funciton
        '''if t < 100: return 0
        if t < 300: return 50
        return 10'''
    
    y = 0
    res = []
    for t in range( tm ):
        r = setpoint(t)
        e = r - y
        u = c.work(e,t)
        y = p.work(u)

        #print t, r, e, u, y
        res.append((t, r, e, u, y))

    return zip(*res)

# ============================================================
ki = .001
ki = .001
kd = .5
values = []

averages = []

smallestAvg = 1000000

for i in range(200):

    kd += .01

    c = Controller( 1.25, ki, kd )
    p = Buffer( 50, 10  )
    values = []

    for i in range(60):
    # run the simulation
        ts, rs, es, us, ys = closed_loop( c, p, 1000 )
        values.append(numpy.sqrt(numpy.mean(numpy.array(es)**2)))

    currentAvg = sum(values)/len(values)

    if currentAvg < smallestAvg:
        smallestAvg = currentAvg
        val = kd

print val
print smallestAvg

kd = 0

c2 = Controller( 1.25, ki, kd )
p2 = Buffer( 50, 10 )
values2 = []

for i in range(60):
    # run the simulation
    ts, rs, es, us, ys = closed_loop( c2, p2, 1000 )
    values2.append(numpy.sqrt(numpy.mean(numpy.array(es)**2)))

print 'PID RMS avg error', sum(values2)/len(values2)

# generate the smoothed curve using a rolling mean
# (I think the curves in the book use loess)
ys_smooth = pandas.rolling_mean(numpy.array(ys), 20)

# make the plot
'''pyplot.plot(ts, rs, color='green', label='target')
pyplot.plot(ts, ys, color='red', label='queue length')
pyplot.plot(ts, ys_smooth, color='blue', label='trend')
pyplot.show()'''



