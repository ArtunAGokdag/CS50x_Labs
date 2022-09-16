#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
  int grayValue;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // average of rgb values
      grayValue =
          (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) /
          3;

      image[i][j].rgbtBlue = grayValue;
      image[i][j].rgbtRed = grayValue;
      image[i][j].rgbtGreen = grayValue;
    }
  }
  return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
  RGBTRIPLE tmp;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width / 2; j++) {
      // swap mirrored by middle element each row
      tmp = image[i][j];
      image[i][j] = image[i][width - 1 - j];
      image[i][width - 1 - j] = tmp;
    }
  }
  return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
  int red, green, blue;

  // go through each pixel except outer layer
  for (int i = 1; i < height; i++) {
    for (int j = 1; j < width; j++) {

      red = 0;
      green = 0;
      blue = 0;
      // loop surrounding pixels calculate sums of values
      for (int k = i - 1; k <= i + 1; k++) {
        for (int l = j - 1; l <= j + 1; l++) {

          red += image[k][l].rgbtRed;
          green += image[k][l].rgbtGreen;
          blue += image[k][l].rgbtBlue;
        }
      }
      // assign averages  to new pixels
      image[i][j].rgbtRed = red / 9;
      image[i][j].rgbtGreen = green / 9;
      image[i][j].rgbtBlue = blue / 9;
    }
  }
  return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]) {
  // copy image
  RGBTRIPLE temp[height][width];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      temp[i][j] = image[i][j];
    }
  }

  int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

  int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

  // loop all pixels
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {

      int redX = 0;
      int greenX = 0;
      int blueX = 0;
      int redY = 0;
      int greenY = 0;
      int blueY = 0;

      // loop surrounding
      for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {

          if (i - 1 + x < 0 || i - 1 + x > height - 1 || j - 1 + y < 0 ||
              j - 1 + y > width - 1)
            continue;

          // calculate Gx for each color
          redX += image[i - 1 + x][j - 1 + y].rgbtRed * Gx[x][y];
          greenX += image[i - 1 + x][j - 1 + y].rgbtGreen * Gx[x][y];
          blueX += image[i - 1 + x][j - 1 + y].rgbtBlue * Gx[x][y];

          // calculate Gy for each color
          redY += image[i - 1 + x][j - 1 + y].rgbtRed * Gy[x][y];
          greenY += image[i - 1 + x][j - 1 + y].rgbtGreen * Gy[x][y];
          blueY += image[i - 1 + x][j - 1 + y].rgbtBlue * Gy[x][y];
        }
      }

      //calculate sqrt of Gx2 and Gy2
      int red = round(sqrt((redX * redX) + (redY * redY)));
      int green = round(sqrt((greenX * greenX) + (greenY * greenY)));
      int blue = round(sqrt((blueX * blueX) + (blueY * blueY)));

      //cap value  ifexceedes 255
      if(red>255) red = 255;
      if(blue>255) blue = 255;
      if(green>255) green = 255;

      temp[i][j].rgbtRed = red;
      temp[i][j].rgbtGreen = green;
      temp[i][j].rgbtBlue = blue;
    }
  }
  //copy new pixels  into originalimage
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++){
        image[i][j] = temp[i][j];
    }
  }
  return;
}
