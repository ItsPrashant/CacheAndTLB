#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include <sys/time.h>
#include <sys/resource.h>

/* 
 * 
 * 
 * 
 * 
 * 
 */ 

#define NO_OF_SAMPLES 100000ULL
#define ARRAY_LENGTH 4194304ULL
int arr[ARRAY_LENGTH]={0};

int faltuArray[10000];
typedef unsigned long long ull;
int main()
{
	/*
	if(argc<2)
	{
		perror("Please give Full arguments\n");
		exit(-1);
	}
	*/
	
	ull startingSize;
	
	time_t start,end;
	ull stride;
	ull average_time=0,average_time1=0;
	unsigned long long k=1;
	double strideReadings,strideReadings1,diff;
	int count=0;
	//struct rusage shuru,khtm;
	for(startingSize=32;startingSize<=ARRAY_LENGTH;startingSize*=2)
	{
		char file[50];
		sprintf(file,"%llu",startingSize);
		FILE *fp;
		fp=fopen(file,"w");
		if(fp==NULL)
		{
			perror("Unable to open File");
			exit(1);
		}

		for(stride=1;stride<=startingSize/2;stride*=2)
		{
			average_time=0;
			for(int samp=0;samp<NO_OF_SAMPLES;samp++)
			{
				start=clock();
				//getrusage(RUSAGE_SELF,&shuru);
				for(int i=0;i<startingSize;i+=stride)
				{
					arr[i]=arr[i]*4;
				}
				//average_time+=((ull)(khtm.ru_utime.tv_sec-shuru.ru_utime.tv_sec)*1000000);
				//average_time+=(ull)(khtm.ru_utime.tv_usec-shuru.ru_utime.tv_usec);
				//printf("Elapsed time:%llu\n",((ull)(khtm.ru_utime.tv_sec-shuru.ru_utime.tv_sec)*1000000)+(ull)(khtm.ru_utime.tv_usec-shuru.ru_utime.tv_usec));
				end=clock();
				average_time+=((ull)(end-start));

			}
			
				//getrusage(RUSAGE_SELF,&khtm);
			ull no_of_iteration=(ull)ceil((double)startingSize/(double)stride);
			average_time=(average_time*1000)/NO_OF_SAMPLES;
			//strideReadings[count++]=(average_time*1000000000)/no_of_iteration;		
			strideReadings=(double)(average_time)/no_of_iteration;		
			//fprintf(fp,"Average Time in %llu nano_seconds\n",average_time);
			//fprintf(fp,"Single iteration time (Stride=%llu): %lf nano seconds\n",stride,strideReadings);
			
			average_time1=0;
			for(int samp=0;samp<NO_OF_SAMPLES;samp++)
			{
				start=clock();
				//getrusage(RUSAGE_SELF,&shuru);
				for(int i=0;i<startingSize;i+=stride)
				{
					//k=arr[i]*4;
				}
				//average_time+=((ull)(khtm.ru_utime.tv_sec-shuru.ru_utime.tv_sec)*1000000);
				//average_time+=(ull)(khtm.ru_utime.tv_usec-shuru.ru_utime.tv_usec);
				//printf("Elapsed time:%llu\n",((ull)(khtm.ru_utime.tv_sec-shuru.ru_utime.tv_sec)*1000000)+(ull)(khtm.ru_utime.tv_usec-shuru.ru_utime.tv_usec));
				end=clock();
				average_time1+=((ull)(end-start));

			}
			average_time1=(average_time1*1000)/NO_OF_SAMPLES;
			strideReadings1=(double)(average_time1)/no_of_iteration;		
			
			printf("Avg Time: %llu %llu nano_sec\n",average_time,average_time1);
			printf("Per Iteration (Stride=%llu): %lf %lf nano seconds\n",stride,strideReadings,strideReadings1);
			
			/* Difference between loop with memory and without memory access 
			 */
			
			diff=((double)average_time-(double)average_time1)/no_of_iteration;
			printf("Diff= %lf %llu\n",diff,stride);
			
			if(stride*4>=(1024*1024))
			fprintf(fp,"%lf %lluM\n",100*diff,(stride*4)/(1024*1024));
			else
			if(stride*4>=1024)
			fprintf(fp,"%lf %lluK\n",100*diff,(stride*4)/(1024));
			else
			fprintf(fp,"%lf %llu\n",100*diff,stride*4);
				
			// It has been added just to remove current array elements from cache
			for(int i=0;i<10000;i++)
			{
				faltuArray[i]=faltuArray[i]*2;
			}
			
		}
		
		
		fclose(fp);
	}
}
