//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#ifndef GrayscaleImage_H
#define GrayscaleImage_H

#include <iostream>

class GrayscaleImage {
public:
    /**
     * @brief GrayscaleImage constructs an image including an array to hold pixels
     * @param heightVal height for image
     * @param widthVal width for image
     *
     * Should allocate an array on the heap and initialize all pixels to black (0)
     */
    GrayscaleImage(int heightVal, int widthVal);

    int getWidth() const;
    int getHeight() const;

    uint8_t getPixel(int row, int col) const;
    void setPixel(int row, int col, uint8_t brightness);


    /**
     * @brief Fill the image with the given brightness value
     */
    void fill(uint8_t brightness);


    /**
     * @brief ~GrayscaleImage destructor - cleans up all memory
     */
    ~GrayscaleImage();

    GrayscaleImage(const GrayscaleImage& other);

    /**
     * @brief operator = copy via assignment from another image into this one
     * @param other image to copy from
     * @return this image
     */
    GrayscaleImage& operator=(const GrayscaleImage& other);

    /**
     * @brief operator == checks if this image is identical to other image
     * @param other image to compare with
     * @return true if they have same dimensions and identical pixels
     *          false otherwise
     */
    bool operator==(const GrayscaleImage& other) const;

    /**
     * @brief toString returns string representation of the image
     * @return text version of image
     *
     * Each col should have a \t after it (including last) and each row
     * should end with a \n (including last). A 3 tall, 2 wide image full of pixels with
     * value of 64 would look like:
     * 64  64  64
     * 64  64  64
     * 64  64  64
     *
     */
    std::string toString() const;

    /**
     * @brief addFrame Make a new image that is a copy of this image with a border around it
     * @param padding Number of new pixels to add to each side
     * @param brightness Brightness of the border pixels
     * @return the padded image
     */
    GrayscaleImage addFrame(int padding, uint8_t brightness) const;

    /**
     * @brief crop Make a new image that is a crop out of this imag
     * @param startRow row to start copying pixels from in this image
     * @param startCol col to start copying pixels from in this image
     * @param newHeight height of new image (number of rows to copy)
     * @param newWidth width of new image (number of cols to copy)
     * @return the cropped image
     * @throws out_of_range exception if startRow or startCol is negative or
     *          if the crop would extend past the height or width of this image
     */
    GrayscaleImage crop(int startRow, int startCol, int newHeight, int newWidth) const;

private:
    int width = 0;
    int height = 0;

    uint8_t* pixels;
};


#endif
