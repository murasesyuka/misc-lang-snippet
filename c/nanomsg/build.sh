gcc -pthread pipeline.c -L/usr/local/lib -lnanomsg -o pipeline
gcc -pthread reqrep.c -L/usr/local/lib -lnanomsg -o reqrep
gcc -pthread pair.c -L/usr/local/lib -lnanomsg -o pair
gcc -pthread pubsub.c -L/usr/local/lib -lnanomsg -o pubsub
gcc -pthread survey.c -L/usr/local/lib -lnanomsg -o survey
gcc -pthread bus.c -L/usr/local/lib -lnanomsg -o bus
