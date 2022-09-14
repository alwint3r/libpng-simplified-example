#include <stdio.h>
#include <png.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    png_image image;
    memset(&image, 0, sizeof(png_image));

    image.version = PNG_IMAGE_VERSION;

    int result = png_image_begin_read_from_file(&image, "reona_unknown.png");
    printf("Read result: %d\r\n", result);

    printf("Width: %d, Height: %d\r\n", image.width, image.height);

    image.format = PNG_FORMAT_RGBA;

    int row_stride = PNG_IMAGE_ROW_STRIDE(image);
    int px_size = PNG_IMAGE_PIXEL_COMPONENT_SIZE(PNG_FORMAT_RGBA);

    int stride_bytes = row_stride * px_size;
    printf("Row stride: %d, pixel size: %d, stride in bytes: %d\r\n", row_stride, px_size, stride_bytes);

    int size = PNG_IMAGE_SIZE(image);
    printf("Size: %d\r\n", size);

    char *buffer = (char *)malloc(size);
    memset(buffer, 0, size);

    result = png_image_finish_read(&image, NULL, buffer, row_stride, NULL);
    printf("Read result: %d\r\n", result);

    png_image w_image;
    memset(&w_image, 0, sizeof(png_image));

    w_image.version = PNG_IMAGE_VERSION;
    w_image.width = image.width;
    w_image.height = image.height;
    w_image.format = image.format;

    png_image_write_to_file(&w_image, "reona_w_unknown.png", 0, buffer, row_stride, NULL);

    png_image_free(&w_image);
    png_image_free(&image);

    free(buffer);

    return 0;
}