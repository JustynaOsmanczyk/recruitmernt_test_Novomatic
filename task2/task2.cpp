#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

string compress_data(const string& data){
    string compressed;
    for(int i = 0; i < data.length(); i++){
        int counter = 1; // the number of the same letters
        compressed += data[i];
        while(data[i] == data[i+1]){ //checking if the next letter is the same
            counter++;
            i++;
        }
        string s_counter = to_string(counter); //convert int to string
// not supposed to print "1" after single letters use "if"
        if(s_counter != "1"){
            compressed += s_counter;
        }
    }
    cout << "compressed: ";
    for(int k = 0; k < compressed.length(); k++) cout << compressed[k];
    cout << endl;

    return compressed;
}

string decompress_data(const string& data){
    string decompressed;
    int i = 0;
    while(i < data.length()){
        char letter = data[i];
        i++;
        string s_counter;
        if(data[i] >= '0' && data[i] <= '9'){
            while(data[i] >= '0' && data[i] <= '9'){
                s_counter += data[i];
                i++;
            }
        }
// decompression adapted to write with "1" and without, so both entries can be used
        else{
            s_counter = "1";
        }
        int counter = stoi(s_counter);
        for(int j = 0; j < counter; j++){
            decompressed += letter;
        }
    }

    cout << "decompressed: ";
    for(int k = 0; k < decompressed.length(); k++) cout << decompressed[k];
    cout << endl;

    return decompressed;
}

int main(){
    string data_to_compress;
    string data_to_decompress;
    cout << "to compress: ";
    cin >> data_to_compress;
    cout << "to decompress: ";
    cin >> data_to_decompress;
    compress_data(data_to_compress);
    decompress_data(data_to_decompress);

    return 0;
}
