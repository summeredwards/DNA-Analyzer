// CS1300 Fall 2020
// Author: Summer Edwards
// Recitation: 223 – Siddhant Keshkar
// Project 1 - Problem #7

#include <iostream>
#include <string>

using namespace std;

/*
* This function calculates a similarity score between two DNA sequences
* Parameters: seq1, seq2 -  sequence 1, sequence 2
* Return: simScore - similarity score 
*/

double calcSimScore(string seq1, string seq2){
    double simScore = 0, distance = 0;
    // if the sequence lengths are the same
    if (seq1.length() == seq2.length()){
        // if the lengths are both zero
        if (seq1.length() == 0){
            simScore = 0;
        }
        else{
            // for the length of the sequences
            for (int i=0; i < seq1.length(); i++){
                // check if letters are no the same, if yes add 1 to hamming distance 
                if (seq1[i] != seq2[i]){
                    distance++;
                }
            }
            // calculates simScore
            simScore = (seq1.length() - distance) / seq1.length();
        }  
    }
    // if the sequence lengths are not the same 
    else{
        simScore = 0;
    }
    return simScore;
}

/*
* This function  takes a genome and a sequence and returns
* the highest similarity score found in the genome 
* Parameters: genome, seq -  genome and sequence 
* Return: biggest - highest similarity score in genome 
*/

double findBestSimScore(string genome, string seq){
    double biggest = 0, score = 0;
    // if the sequence length is bigger than the genome length, similarity score = 0
    if (seq.length() > genome.length()){
        biggest = 0;
    }
    else{
        // for as long as the genome length minus the sequence length
        for (int i = 0; i < genome.length() - seq.length() + 1; i ++){
            // calculates similarity score for each genome sub-sequence
            score = calcSimScore(seq, genome.substr(i, seq.length()));
            // checks which similarity score is the highest number
            if (score > biggest){
                biggest = score;
            }
        }
    }
    
    return biggest;
}

/*
* This function takes three genomes and a sequence and
* prints the list of matched genomes
* Parameters: gen1, gen2, gen3, seq -  genome 1, genome 2, genome 3, and sequence 
* Return: N/A
*/

void findMatchedGenome(string gen1, string gen2, string gen3, string seq){
    // if the entered genomes or sequence are emtpy
    if (gen1 == "" || gen2 == "" || gen3 == "" || seq == ""){
        cout << "Genomes or sequence is empty." << endl;
    }
    // if the genome lengths are different 
    else if (gen1.length() != gen2.length() || gen1.length() != gen3.length() || gen2.length() != gen3.length()){
        cout << "Lengths of genomes are different." << endl;
    }
    // otherwise
    else{
        // calculate similarity scores for each entered genome 
        double score1 = findBestSimScore(gen1, seq);
        double score2 = findBestSimScore(gen2, seq);
        double score3 = findBestSimScore(gen3, seq);
        // if genome 1 is greatest
        if (score1 > score2 && score1 > score3){
            cout << "Genome 1 is the best match." << endl;
        }
        // if genome 2 is greatest 
        else if (score2 > score1 && score2 > score3){
            cout << "Genome 2 is the best match." << endl;
        }
        // if genome 3 is greatest 
        else if (score3 > score1 && score3 > score2){
            cout << "Genome 3 is the best match." << endl;
        }
        // if 1 & 2 are greatest 
        else if (score1 == score2 && score1 > score3){
            cout << "Genome 1 is the best match." << endl;
            cout << "Genome 2 is the best match." << endl;
        }
        // if 1 & 3 are greatest 
        else if (score1 == score3 && score1 > score2){
            cout << "Genome 1 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
        // if 2 & 3 are greatest 
        else if (score2 == score3 && score2 > score1){
            cout << "Genome 2 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
        // if they are all the same score 
        else if (score1 == score2 && score1 == score3){
            cout << "Genome 1 is the best match." << endl;
            cout << "Genome 2 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
    }
}

int main (){

    // initialize varibles
    int choice = 0;
    string seq1 = "", seq2 = "", genome = "", seq = "", gen1 = "", gen2 = "", gen3 = "";

    // print menu
    cout << "Select a numerical option: " << endl << "=== menu ===" << endl;
    cout << "1. Find similarity score" << endl << "2. Find the best similarity score" << endl << "3. Analyze the genome sequences" << endl << "4. Quit" << endl;
    // GET choice
    cin >> choice;

    // while choice is not 4
    while (choice != 4){
        switch(choice){
            // if input is 1
            case 1:
                // GET sequence 1, sequence 2
                cout << "Enter sequence 1: " << endl;
                cin >> seq1;
                cout << "Enter sequence 2: " << endl;
                cin >> seq2;

                // print return value of calcSimScore() function
                cout << "Similarity score: " << calcSimScore(seq1, seq2) << endl;

                break;
            // if choice is 2
            case 2:
                // GET genome and sequence
                cout << "Enter genome: " << endl;
                cin >> genome;
                cout << "Enter sequence: " << endl;
                cin >> seq;

                // print return value of findBestSimScore() function
                cout << "Best similarity score: " << findBestSimScore(genome, seq) << endl;

                break;
            // if choice is 3
            case 3:
                // GET genome 1, genome 2, genome 3, and sequence 
                cout << "Enter genome 1: " << endl;
                cin >> gen1;
                cout << "Enter genome 2: " << endl;
                cin >> gen2;
                cout << "Enter genome 3: " << endl;
                cin >> gen3;
                cout << "Enter sequence: " << endl;
                cin >> seq;

                // call findMatchedGenome() function
                findMatchedGenome(gen1, gen2, gen3, seq);

                break;
            // otherwise
            default:
                // print Invalid option.
                cout << "Invalid option." << endl;    
        }
        // print menu again until user chooses 4
        cout << "Select a numerical option: " << endl << "=== menu ===" << endl;
        cout << "1. Find similarity score" << endl << "2. Find the best similarity score" << endl << "3. Analyze the genome sequences" << endl << "4. Quit" << endl;
        cin >> choice;
    }
    
    //if input is 4
    cout << "Good bye!" << endl;

    return 0;
}
