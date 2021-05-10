Content of the task: 
"Compression and decompression of text strings, 
write a solution that will be able to compress "gggghhhhhhzzz" to "g4h6z3"(the numbers correspond to the number of repeated letters) and back."

My comment about the task:
It has not been specified in the content of the task whether the data to be compressed and decompressed will include "1" after individual letters. 
Due to the assumption of performing compression and decompression, i.e. reducing the number of bits of the information set, 
I assumed and coded my program that the data entered for compression does not include a "1" after individual letters. 
Data for decompression is accepted regardless of the selected recording method. 
In case that assumptions would be like "compressed data has to contain "1" after single letters", then my compression code would look like below.

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
        compressed += s_counter;
    }
    cout << "compressed: ";
    for(int k=0; k<compressed.length(); k++) cout << compressed[k];
    cout << endl;
    return compressed;
}