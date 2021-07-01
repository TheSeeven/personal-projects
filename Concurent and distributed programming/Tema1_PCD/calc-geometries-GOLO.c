#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>

void error()
{
    printf("Usage: \n -t Triangle OR -q Square/Rectangle \n-s (Side for Square/Rectangle, base for Triangle)\n-h (Side for Square/Rectangle height for Triangle)");
    exit(2);
}

void result(double side, double height, double perimeter, double area, char figure)
{
    if (figure == 'q' && height == -1.0)
    {
        printf("Square\n");
        if (area == 0.0)
        {
            area = side * side;
            printf("Area: %f\n", area);
        }
        if (perimeter == 0.0)
        {
            perimeter = 4.0 * side;
            printf("Perimeter: %f\n", perimeter);
        }
    }
    else if (figure == 'q' && height != -1.0)
    {
        printf("Rectangle:\n");
        if (area == 0.0)
        {
            area = side * height;
            printf("Area: %f\n", area);
        }
        if (perimeter == 0.0)
        {
            perimeter = (2.0 * side) + (2.0 * height);
            printf("Perimeter: %f\n", perimeter);
        }
    }
    else if (figure == 't' && height == -1)
    {
        printf("Triangle:\n");
        if (perimeter == 0.0)
        {
            perimeter = 3.0 * side;
            printf("Perimeter: %f\n", perimeter);
        }
    }

    else
    {
        printf("Triangle:\n");
        if (area == 0.0)
        {
            area = side * height / 2.0;
            printf("Area: %f\n", area);
        }
        if (perimeter == 0.0)
        {
            perimeter = 3.0 * side;
            printf("Perimeter: %f\n", perimeter);
        }
    }
}

int main(int argc, char *argv[])
{

    int optionalArguments = 0;
    double area = -1.0, perimeter = -1.0, side = -1.0, height = -1.0;

    static struct option long_options[] = {
        {"triangle", no_argument, 0, 't'},
        {"square", no_argument, 0, 'q'},
        {"area", no_argument, 0, 'a'},
        {"perimeter", no_argument, 0, 'p'},
        {"side", required_argument, 0, 's'},
        {"height", required_argument, 0, 'h'},
        {0, 0, 0, 0}};

    int long_index = 0;
    optionalArguments = getopt_long_only(argc, argv, "tqaps:h:", long_options, &long_index);
    char figure = 0;

    while (optionalArguments != -1)
    {
        switch (optionalArguments)
        {
        case 't':
            if (figure == 0)
                figure = 't';
            else
                error();
            break;
        case 'q':
            if (figure == 0)
                figure = 'q';
            else
                error();
            break;
        case 'a':
            area = 0.0;
            break;
        case 'p':
            perimeter = 0.0;
            break;
        case 's':
            side = atof(optarg);
            break;
        case 'h':
            height = atof(optarg);
            break;
        default:
            break;
        }
        optionalArguments = getopt_long_only(argc, argv, "tqaps:h:", long_options, &long_index);
    }
    result(side, height, perimeter, area, figure);
    return 0;
}