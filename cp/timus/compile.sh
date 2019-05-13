g++ -std=gnu++14 -Wall -g -Wextra -Wshadow -Wfloat-equal -fmax-errors=1 -Wconversion -Wshift-overflow=2 -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=signed-integer-overflow -fsanitize=bounds -O2 $1

