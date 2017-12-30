# CacheAndTLB
It contains program to generate files which contains data about memory access time.
I tried many programs, wrote some scripts but a single program which produces all the files required for the plot was very portable ,quick and gave consistent results. 
My experiments produce good results when compared with actual machine parameters. I couldn't find some parameters with accuracy but rest are good.
All the measured Cache and TLB parameters can be found in the myPlotModified.png . It shows plots of wide range of array sizes.
For sufficient accuracy i ran my program on single CPU with giving it he highest priority so as to minimise cache misses occuring due to context switching.
