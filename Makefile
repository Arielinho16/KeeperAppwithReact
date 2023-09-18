listing1.1:
	@mkdir -p build/cap1
	@gcc -o build/cap1/listing1.1  SRC/cap1/listing1.1.c SRC/cap1/listing1.2.cpp SRC/cap1/listing1.3.hpp

listing1.2:
	@mkdir -p build/cap1
	@gcc -o build/cap1/listing1.2  SRC/cap1/listing1.1.c SRC/cap1/listing1.2.cpp SRC/cap1/listing1.3.hpp

listing1.3:
	@mkdir -p build/cap1
	@gcc -o build/cap1/listing1.3  SRC/cap1/listing1.1.c SRC/cap1/listing1.2.cpp SRC/cap1/listing1.3.hpp


listing2.1:
	@mkdir -p build/cap2
	@gcc -o build/cap2/listing2.1  SRC/cap2/listing2.1.c 

listing2.2:
	@mkdir -p build/cap2
	@gcc -o build/cap2/listing2.2  SRC/cap2/listing2.2.c

listing2.3:
	@mkdir -p build/cap2
	@gcc -o build/cap2/listing2.3  SRC/cap2/listing2.3.c

listing2.4:
	@mkdir -p build/cap2
	@gcc -o build/cap2/listing2.4  SRC/cap2/listing2.4.c

listing2.5:
	@mkdir -p build/cap2
	@gcc -o build/cap2/listing2.5  SRC/cap2/listing2.5.c

listing2.6:
	@mkdir -p build/cap2
	@gcc -o build/cap2/listing2.6  SRC/cap2/listing2.6.c











all: 
	@make listing1.1
	@make listing1.2
	@make listing1.3
	@make listing2.1
	@make listing2.2
	@make listing2.3
	@make listing2.4
	@make listing2.5
	@make listing2.6
	@make listing2.9






clean: 
	@rm build -rf

.PHONY: clean all
