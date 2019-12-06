CC = g++
exe = run_stats

$(exe): run_facts.o state_facts.o
	$(CC) run_facts.o state_facts.o -o $(exe)
run_facts.o: run_facts.cpp
	$(CC) -c run_facts.cpp
state_facts.o: state_facts.cpp
	$(CC) -c state_facts.cpp

clean:
	rm -f *.out *.o $(exe)
