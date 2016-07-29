/* Hecto -- kilo/10; security restictions on kilo for ops.
 *
 * -----------------------------------------------------------------------
 *
 * Copyright (C) 2016 Anthony O'Brien <humanzee at internet dot dot>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */



#define HECTO_VERSION "0.0.1"


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/stat.h>
#include <fnmatch.h>

#define FILE_MUST_EXIST 1

/* Hecto Exit Codes:
 * 11 -- File not found
 * 12 -- File outside scope */
#define FILE_NOT_EXIST 11
#define FILE_OUTSIDE_SCOPE 12

/* All allowed paths are defined here */
#define NUM_ALLOWED_PATHS 1
char *ALLOWED_PATHS[NUM_ALLOWED_PATHS] = {
    "/etc/nginx/sites-available/*"
};

/* Validate argv[1] from kilo call */
void hecto(char* fpath) {
    int matches = 0;
    char abspath[PATH_MAX];

    realpath(fpath, abspath);

    /* make sure file exists, son! Or bail */
    if (FILE_MUST_EXIST) {
        struct stat buffer;
        if (stat(abspath, &buffer) != 0) {
            fprintf(stderr,"File does not exist: %s\n", abspath);
            exit(FILE_NOT_EXIST);
        }
    }

    /* Check file matches ALLOWED_PATH */
    for (int i = 0; i < NUM_ALLOWED_PATHS; i++) {
        if ((fnmatch(ALLOWED_PATHS[i], abspath, 0)) == 0) {
            matches += 1;
        }
    }

    /* bail if file doesn't match ALLOWED_PATHS */
    if (!(matches)) {
        fprintf(stderr, "File outside scope: %s\n", abspath);
        exit(FILE_OUTSIDE_SCOPE);
    }
}
