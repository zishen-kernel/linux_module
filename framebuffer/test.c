#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <unistd.h>


int main()
{
    int fd;
    int res;
    unsigned int *fb_buf;
    int buf_len;
    int i;
    struct fb_var_screeninfo screeninfo; 

    fd = open("/dev/fb0", O_RDWR);
    printf("fd %d\n", fd);

    res = ioctl(fd, FBIOGET_VSCREENINFO, &screeninfo); 
    printf("ioctl result: %d\n", res);

    printf("xres: %d, yres: %d\n", screeninfo.xres, screeninfo.yres);

    buf_len = screeninfo.xres * screeninfo.yres * 4;

    fb_buf = mmap(NULL, buf_len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    printf("fb_buf: %p\n", fb_buf);
    printf("size of unsigned int: %d\n", sizeof(unsigned int));


    while(1)
    {
        for(i=0; i<buf_len/4; i++)
        {
            fb_buf[i] = 0xFFFFFF00;
            sleep(1);
        }

        sleep(1.1);

        for(i=0; i<buf_len/4; i++)
        {
            fb_buf[i] = 0xFFFF0000;
        }
        sleep(1.1);
    }
}
