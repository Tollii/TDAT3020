FROM archlinux

COPY . /app

WORKDIR /app/build

RUN pacman -S clang cmake

RUN CC=clang cmake ..

RUN make

RUN ./tests/utilitCC=clang cmake ..CC=clang cmake ..y_fuzzer_test.c


