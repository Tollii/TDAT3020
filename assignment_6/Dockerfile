FROM archlinux:latest

RUN pacman -Sy

COPY . /app

RUN pacman -S --noconfirm --asdeps make cmake clang

WORKDIR /app/build

RUN CC=clang cmake ..

RUN make

CMD ["./tests/utilitCC=clang cmake ..CC=clang cmake ..y_fuzzer_test.c"]


