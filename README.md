Lane Snively
# Lab01
For Lab 01:  Process Numbers and Compress Data

Note that zero has a special use as a flag here. What if the input file contained a four-byte zero? Is that a
possibility in this data structure, a BMP image file? What adjustment would you suggest?

Black is represented by a four-byte zero in a BMP image file. This would be problematic for the flag to also be a four-byte 0 because it would be confused as black, or it would get skipped. This problem is easy avoided by using a flag that could never be represented as a color in RGB format: any flag not a four-byte number.
