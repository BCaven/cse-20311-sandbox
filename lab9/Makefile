CMP = gcc
MAIN = symbol
FUNC = symfunc
FUNC2 = gfx
EXEC = runsymbol

$(EXEC): $(FUNC).o $(FUNC2).o $(MAIN).o 
	$(CMP) $(FUNC).o $(FUNC2).o $(MAIN).o -lm -lX11 -o $(EXEC)

$(FUNC).o: $(FUNC).c $(FUNC).h 
	$(CMP) -c $(FUNC).c -o $(FUNC).o 

$(MAIN).o: $(MAIN).c $(FUNC).h
	$(CMP) -c $(MAIN).c -o $(MAIN).o 

clean:
	rm $(EXEC)
