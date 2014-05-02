all: clean generate install run

clean:
	@if [ -d "build/" ]; then \
		rm -rf build/; \
	fi
	mkdir build/

	@if test -f bin/exercise3-1; then \
		rm bin/exercise3-1; \
	fi

generate:
	cd build/ && cmake ..

install:
	cd build/ && make

run:
	./bin/exercise3-1
