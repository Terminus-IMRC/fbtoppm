#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

#define width 480
#define height 640

int main()
{
	int i;
	int16_t tmp;
	char *fbimage;
	fbimage=(char*)malloc(sizeof(char)*width*height*2);
	read(STDIN_FILENO, fbimage, width*height*2);
	printf("P3\n%d %d\n255\n", width, height);

	for(i=0; i<width*height*2; i+=2){
		tmp=fbimage[i+1]<<8|fbimage[i];
		printf("%d %d %d ", ((tmp&0xf800)>>8), ((tmp&0x07e0)>>3), (tmp&0x1f)<<3);
		if(i%(width*2)==width*2-2)
			putchar('\n');
	}
}
