#!/usr/bin/env bash

time ./executar.sh ./tests/in/pdf1.in ./answ/pdf1.out
time ./executar.sh ./tests/in/pdf2.in ./answ/pdf2.out
time ./executar.sh ./tests/in/1.in    ./answ/1.out
time ./executar.sh ./tests/in/2.in    ./answ/2.out
time ./executar.sh ./tests/in/3.in    ./answ/3.out
time ./executar.sh ./tests/in/4.in    ./answ/4.out
time ./executar.sh ./tests/in/5.in    ./answ/5.out
time ./executar.sh ./tests/in/6.in    ./answ/6.out
time ./executar.sh ./tests/in/7.in    ./answ/7.out
time ./executar.sh ./tests/in/8.in    ./answ/8.out
time ./executar.sh ./tests/in/9.in    ./answ/9.out
time ./executar.sh ./tests/in/10.in   ./answ/10.out

diff ./tests/out/pdf1.out ./answ/pdf1.out
diff ./tests/out/pdf2.out ./answ/pdf2.out
diff ./tests/out/1.out    ./answ/1.out
diff ./tests/out/2.out    ./answ/2.out
diff ./tests/out/3.out    ./answ/3.out
diff ./tests/out/4.out    ./answ/4.out
diff ./tests/out/5.out    ./answ/5.out
diff ./tests/out/6.out    ./answ/6.out
diff ./tests/out/7.out    ./answ/7.out
diff ./tests/out/8.out    ./answ/8.out
diff ./tests/out/9.out    ./answ/9.out
diff ./tests/out/10.out   ./answ/10.out
