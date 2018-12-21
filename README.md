# CacheAndTLB
It contains program to generate files which contains data about memory access time.
I tried many programs, wrote some scripts but a single program which produces all the files required for the plot is very portable,quick and gives consistent results.
My experimentally determined parameters are very close to actual machine parameters.
All the measured Cache and TLB parameters can be found in the myPlotModified.png.
For sufficient accuracy, I ran my program on single CPU and escalated its priority so that the number of cache misses due to context switching can be minimized.
Accuracy of my results can be further improved by dedicating one of the CPUs for the experiment and minimising usage of the rest.
Furthermore, if the number of samples or the number of iterations is increased for each stride reading then the results will be more precise as the timer used in experiment has precision of milliseconds and the cache miss are always in nano seconds.

