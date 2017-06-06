/* Python
def create_fractal(image, width, height, iters):
    pixel_size_x = 3.0 / width
    pixel_size_y = 2.0 / height
    for y in range(height):
        imag = y * pixel_size_y - 1
        yy = y*width
        for x in range(width):
            real = x * pixel_size_x - 2
            color = mandel(real, imag, iters)
            image[yy+x] = color

*/

int mandel(int x, int y, int max_iters, unsigned char * val);

void create_fractal(unsigned char * image, int width, int height, 
                    int iters) {
    float pixel_size_x = 3.0 / width;
    float pixel_size_y = 2.0 / height;
    for (int y=0; y<height; y++) {
        float imag = y * pixel_size_y - 1;
        int yy = y * width;
        for (int x=0; x<width; x++) {
            float real = x * pixel_size_x - 2;
            unsigned char color;
            int ret = mandel(real, imag, iters, &color);
            image[yy + x] = color;
        }
    }
