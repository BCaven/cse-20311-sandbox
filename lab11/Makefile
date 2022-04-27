CMP = gcc
MAIN = project
FUNC = projfunc
FUNC2 = gfx
EXEC = project

$(EXEC): $(FUNC).o $(FUNC2).o $(MAIN).o 
	$(CMP) $(FUNC).o $(FUNC2).o $(MAIN).o -lm -lX11 -o $(EXEC)

$(FUNC).o: $(FUNC).c $(FUNC).h 
	$(CMP) -c $(FUNC).c -o $(FUNC).o 

$(MAIN).o: $(MAIN).c $(FUNC).h
	$(CMP) -c $(MAIN).c -o $(MAIN).o 

clean:
	rm $(EXEC)
	rm $(FUNC).o
	rm $(MAIN).o