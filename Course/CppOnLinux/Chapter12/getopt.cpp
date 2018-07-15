/*******************************************************************************
  > File Name: getopt.cpp
  > Author: Jiang Yong
  > Mail: chiangyung@aliyun.com
  > Created Time: Sat 14 Jul 2018 11:01:11 PM PDT
  > Description:
 ******************************************************************************/

#include <stdlib.h>
#include <getopt.h>

#include <iostream>
using namespace std;

const char *program_name;

void OutputInfo(ostream &os, int exit_code)
{
    os << "Usage: " << program_name << " options [filaname]" << endl;
    os << " -h --help: Display this usage information." << endl;
    os << " -o --output filename: Write output to file." << endl;
    os << " -v --verbose: Print verbose messages." << endl;
    exit(exit_code);
}

int main(int argc, char *argv[])
{
    const char * const short_opts = "ho:v";
    const struct option long_opts[] = {
        {"help", 0, NULL, 'h'},
        {"output", 1, NULL, 'o'},
        {"verbose", 0, NULL, 'v'},
        {NULL, 0, NULL, 0}
    };

    const char *output_filename = NULL;
    int verbose = 0;
    program_name = argv[0];

    int opt = getopt_long(argc, argv, short_opts, long_opts, NULL);

    while (opt != -1) {
        switch (opt) {
            case 'h':
                OutputInfo(cout, 0);
                break;
            case 'o':
                output_filename = optarg;
                break;
            case 'v':
                verbose = 1;
                break;
            case '?':
                OutputInfo(cerr, 1);
            case -1:
                break;
            default:
                abort();
        }
        opt = getopt_long(argc, argv, short_opts, long_opts, NULL);
    }

    return 0;
}
