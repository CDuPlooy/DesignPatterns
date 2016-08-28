#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
/*
	Connor Armand du Plooy

	Strategy method:
	Used for encapsulating algorithms ( sort of like every OOP program ever ).

	Participants:
	Context : Uses strategy to use the algorithm.
	Strategy : Interface to the concrete strategies.

	Concrete Strategies : Implements the strategy.

	Strategy implements the entire algorithm.

	It would seem that Context encapsulates everything

	#CMasterRace #CMasterRace #CMasterRace #CMasterRace

	The example I'm using parses a file using either the pure C method or
	the C++ implementation.
*/

class ReaderStrategy{
	public:
		ReaderStrategy(){};
		virtual ~ReaderStrategy(){};
		virtual void execute() = 0;
};


class ReaderContext{
	public:
		ReaderContext(){
			_caller=NULL;
		};
		~ReaderContext(){};
		void useMethod(short method , std::string filename);
		void execute(){
			if(_caller){
				_caller->execute();
			}
		}
	private:
		std::string filename;
		short method;
		ReaderStrategy *_caller;
};


class RawReader : public ReaderStrategy{
	public:
		RawReader(std::string filename){
			this->filename = filename;
		}
		~RawReader(){

		}
	private:
		virtual void execute(){
			std::cout << "RAW READ: " << std::endl;

			fd = open(filename.c_str(),O_RDONLY);

			char *a = new char[250];

			a[read(fd, a, 250)] = 0; //very hacky code , doesn't parse until the end of a file.

			cout << a;

			close(fd);
		}
		int fd;
		std::string filename;
};

class BufferedReader : public ReaderStrategy{
	public:
		BufferedReader(std::string filename){
			std::cout << "BUFFERED READ: " << std::endl;
			fs.open(filename.c_str());
			while(!fs.eof()){
				std::string Buffer;
				getline(fs,Buffer);
				std::cout << Buffer;
			}
			fs.close();
		}
	private:
		virtual void execute(){

		}
		fstream fs;
		std::string filename;
};

void ReaderContext::useMethod(short method , std::string filename){
	this->filename = filename;
	this->method = method;

	if(_caller)
		delete _caller;
	if(method == 1)
		_caller = new RawReader(filename);
	if(method == 2)
		_caller = new BufferedReader(filename);
}
int main(){
	ReaderContext fileReader;
	fileReader.useMethod(1, "lel.c");
	fileReader.execute();

	fileReader.useMethod(2,"lel.c");
	fileReader.execute();

	return 0;
}
