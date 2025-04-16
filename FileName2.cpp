//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class CommandBuffer {
//private:
//	char** buffer;
//	int capacity;
//	int size;
//
//	void resize() 
//	{
//		int newCapacity = capacity * 2;
//		char** newBuffer = new char* [newCapacity];
//
//		for (int i = 0; i < size; ++i) {
//			newBuffer[i] = buffer[i];
//		}
//
//		delete[] buffer;
//		buffer = newBuffer;
//		capacity = newCapacity;
//	}
//
//	void shiftLeft() {
//		delete[] buffer[0];
//		for (int i = 1; i < size; ++i) {
//			buffer[i - 1] = buffer[i];
//		}
//		--size;
//	}
//
//public:
//	CommandBuffer() {
//		capacity = 4;
//		size = 0;
//		buffer = new char* [capacity];
//	}
//
//	~CommandBuffer() {
//		for (int i = 0; i < size; ++i) {
//			delete[] buffer[i];
//		}
//		delete[] buffer;
//	}
//
//	void addCommand(const char* command)
//	{
//		if (size == capacity) {
//			resize();
//		}
//
//		if (size == 10) {
//			shiftLeft();
//		}
//
//		buffer[size] = new char[strlen(command) + 1];
//		strcpy_s(buffer[size], strlen(command) + 1, command);
//		++size;
//	}
//
//	void printCommands() const {
//		cout << "\nCurrent Buffer (" << size << " commands):\n";
//		for (int i = 0; i < size; ++i) {
//			cout << "- " << buffer[i] << endl;
//		}
//	}
//};
//
//int main() {
//	CommandBuffer cb;
//
//	cb.addCommand("MOVE 10");
//	cb.addCommand("TURN LEFT");
//	cb.addCommand("MOVE 5");
//	cb.addCommand("TURN RIGHT");
//	cb.addCommand("MOVE 20");
//	cb.addCommand("JUMP");
//	cb.addCommand("TURN LEFT");
//	cb.addCommand("MOVE BACKWARD");
//	cb.addCommand("STOP");
//	cb.addCommand("TURN RIGHT");
//	cb.addCommand("MOVE FORWARD");
//
//	cb.printCommands();
//
//	return 0;
//}
