#include "Board.h"
using namespace std;

istream& operator>> (istream &input, Board& board){
	
	string str;
	uint size = 0, raw = 0;
	input >> str;
	size = str.length();
	Board b(size);
	board=b;
	
	while (input){
		
		for (uint j = 0; j < size; j++){
			Coordinate c{raw, j};		
			board[c] = str[j];
		}
		
		input >> str;
		raw++;
	}
	return input;
}

string name(){
	
	int i=0;
	string s;
	bool flag=true;
	
	while(flag){
		
		ifstream ifile("picture"+ to_string(i)+".ppm");
		if(ifile) i++;
		else flag=false;
	}
	return "picture"+ to_string(i)+".ppm";	
}

void Board::makeTable(RGB rgb[] , int numPixel){
	
	for(int i=0; i<numPixel; i++){
		for(int j=1; j<this->size; j++){
			
			rgb[i*numPixel+j*numPixel/this->size].green=255;
			rgb[i*numPixel+j*numPixel/this->size].blue=255;
			rgb[i*numPixel+j*numPixel/this->size].red=255;
			
		}
	}
	for(int i=1; i<this->size; i++){
		for(int j=0; j<numPixel;j++){
			
			rgb[i*numPixel*numPixel/this->size +j].green=255;
			rgb[i*numPixel*numPixel/this->size +j].blue=255;
			rgb[i*numPixel*numPixel/this->size +j].red=255;
		}
	}
}

void Board::drawO(RGB rgb[] ,int row, int col, int numPixel){
	
	int Ycenter= (row+0.5)*numPixel/this->size, Xcenter=(col+0.5)*numPixel/this->size;
	int radius=(numPixel/this->size)/4;
	int Ystart=row*numPixel/this->size, Xstart=col*numPixel/size;
	int Yend=(row+1)*numPixel/this->size, Xend=(col+1)*numPixel/this->size;
	
	for(int i=Ystart; i<Yend; i++){
		for(int j=Xstart; j<Xend; j++){
			
			int length=sqrt((i-Ycenter)*(i-Ycenter)+(j-Xcenter)*(j-Xcenter));
			if(length==radius) rgb[i*numPixel+j].green=255;
		}
	}
}

void Board::drawX(RGB rgb[], int row, int col, int numPixel){
	
	int Ystart=(row+0.25)*numPixel/this->size, Xstart=(col+0.25)*numPixel/this->size;
	int Xend=(col+0.75)*numPixel/this->size;   
	
	for(int i=0; i<0.5*numPixel/this->size; i++){
		rgb[(i+Ystart)*numPixel+Xstart+i-1].blue=255;
		rgb[(i+Ystart)*numPixel+Xstart+i].blue=255;
		rgb[(i+Ystart)*numPixel+Xstart+i+1].blue=255;
	}
	for(int i=0; i<0.5*numPixel/this->size; i++){
		
		rgb[(i+Ystart)*numPixel+Xend-i-1].blue=255;
		rgb[(i+Ystart)*numPixel+Xend-i].blue=255;
		rgb[(i+Ystart)*numPixel+Xend-i+1].blue=255;
	}
}

string Board::draw(int numPixel){
	
	string filename=name();
	ofstream imageFile(filename, ios::out | ios::binary);
	
	imageFile << "P6" << endl << numPixel <<" " << numPixel << endl << 255 << endl;
	RGB rgb[numPixel*numPixel];
	makeTable(rgb, numPixel);
	
	for(int i=0;i<this->size;i++)	{
		for(int j=0;j<this->size;j++)	{
			
			if(board[i][j]=='X')
				drawX(rgb, i, j, numPixel);
			else if(board[i][j]=='O')
				drawO(rgb, i, j, numPixel);
			
		}
	}
	
	imageFile.write(reinterpret_cast<char*>(&rgb), 3 * numPixel * numPixel);
	imageFile.close();
	return filename;
}
