Hecto = Kilo/10
===============

Hecto is Kilo with the brakes on!

Hecto is small text editor derived from [Kilo](https://github.com/antirez/kilo). It is functionally
equivalent to Kilo (it is Kilo!) however it adds some checks to limit what
files may be edited. 

If Kilo is alpha, and this too is alpha, the product of their parts is 
pre-alpha. Or, as Herman Melville puts it:

> Finally: It was stated at the outset, that this system would not be here, 
> and at once, perfected. You cannot but plainly see that I have kept 
> my word. But I now leave my ... System standing thus unfinished, even 
> as the great Cathedral of Cologne was left, with the crane still standing 
> upon the top of the uncompleted tower. For small erections may be finished 
> by their first architects; grand ones, true ones, ever leave the 
> copestone to posterity. God keep me from ever completing anything. 
> This whole book is but a draught – nay, but the draught of a draught. 
> Oh, Time, Strength, Cash, and Patience!

Buyer beware!


Usage
-----

A screencast is available here: https://asciinema.org/a/90r2i9bq8po03nazhqtsifksb

Usage: kilo `<filename>`

Keys:

    CTRL-S: Save
    CTRL-Q: Quit
    CTRL-F: Find string in file (ESC to exit search, arrows to navigate)


Customization
-------------
Currently two restrictions on what files can be edited as permitted.

    1) The location where files are present. These are matched against 
        a pattern (see `fnmatch`). Multiple paths can be specified. These
        can be specified in `hecto.c` in the `ALLOWED_PATHS` array. Be sure
        to update `#define NUM_ALLOWED_PATHS 1` to match the num of paths
        specified.

    2) Whether or not the file must already exists. This can be toggled 
        in `hecto.c` by the `#define FILE_MUST_EXIST 1` statement.


Build
-----
Basic build tools are all that's required. On Ubuntu, `apt-get install 
build-essential` should get you all the tooling you need to build a 
binary.

Build it by running `make`.


Miscellaneous
-------------
You could use hecto to allow all users on a system access to edit files
in the allowed paths by elevating the capabilities of `hecto` using linux
capabilities. For instance, to bypass all ownership permission checks, you 
could set the following on the binary:

```
sudo setcap -v cap_dac_override+ep /usr/local/bin/hecto
```

Note that hecto will still be restricted to editing files as defined by
`FILE_MUST_EXIST` and `ALLOWED_PATHS` options in `hecto.c`. :boom:

Credits
-------
* 99%+ of this comes straight from antirez's [kilo](https://github.com/antirez/kilo) project.
    Much obliged!
