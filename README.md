# #include<`ban.h`>

A header file that prevents the use of C functions that are hard to audit or can be easily misused. Based on the [idea of the git project](https://github.com/git/git/blob/master/banned.h).

## Usage
### Load
```bash
curl https://nikeee.github.io/ban.h/ban.h > ban.h
```

### Include
```c
#include "ban.h"
```
