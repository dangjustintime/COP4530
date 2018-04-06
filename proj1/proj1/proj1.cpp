//Justin Dang
//COP4530
//Time to run is about a couple of seconds


#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
#include <utility>
#include <algorithm>

enum SequenceType {CHARACTER, WORD, NUMBER, OTHER};

//function prototype
SequenceType getSequenceType(const std::string & seq);

struct compareSequence {
		bool operator() (const std::pair<std::string, std::pair <std::string, int> > & pair1, const std::pair<std::string, std::pair <std::string, int> > & pair2) const {
			SequenceType type = getSequenceType(pair1.second.first);
			if(pair1.second.second == pair2.second.second) {
				if(type == CHARACTER) {
					return pair1.second.first[1] < pair2.second.first[1];
				}
			}
			return pair1.second.second < pair2.second.second;
		


		}
};

int main() {
	std::map<std::string, std::pair <std::string, int> > charMap;
	std::map<std::string, std::pair <std::string, int> > wordMap;
	std::map<std::string, std::pair <std::string, int> > numberMap;
	std::vector<std::pair <std::string, int> > mostCharVector;
	std::vector<std::pair <std::string, int> > mostWordVector;
	std::vector<std::pair <std::string, int> > mostNumberVector;
	std::string text;
	std::string sequence;
	std::string charSequence;
	char ch;	
	int numChar;
	int numWord;
	int numNum;
	
	while(std::cin.get(ch)){
		text+=ch;
	};
	
	//comvert text string into sequences for maps
	for(auto itr1 = text.begin(); itr1 != text.end(); itr1++) {
		charSequence = *itr1;
		if(charMap.find(charSequence) == charMap.end()) {
			charMap.insert(std::pair<std::string, std::pair<std::string, int> >(charSequence, std::make_pair(charSequence, 1)));
		} else {
			charMap[charSequence].second++;
		}

		if(std::isalnum(*itr1)) {
			SequenceType type;
			auto tempItr = itr1;
			
			//get sequence
			if(std::isdigit(*itr1)) {
				for(auto itr2 = itr1; std::isdigit(*itr2); itr2++) {
					sequence+= *itr2;
					tempItr = itr2;
				}
				if(numberMap.find(sequence) == numberMap.end()) {
					numberMap.insert(std::pair<std::string, std::pair<std::string, int> >(sequence, std::make_pair(sequence, 1)));
				} else {
					numberMap[sequence].second++;
				}
			} else if(std::isalpha(*itr1)) {
				for(auto itr2 = itr1; std::isalpha(*itr2); itr2++) {
					sequence+= *itr2;
					tempItr = itr2;
				}
				//change letters to all lowercase
				for(auto itr = sequence.begin(); itr != sequence.end(); itr++) {
					*itr = std::tolower(*itr);
				}
				if(wordMap.find(sequence) == wordMap.end()) {
					wordMap.insert(std::pair<std::string, std::pair<std::string, int> >(sequence, std::make_pair(sequence, 1)));
				} else {
					wordMap[sequence].second++;	
				}
			}		
			sequence.clear();
			itr1 = tempItr;
		}
	}

	//store map sizes, before you remove them to find max element
	numChar = charMap.size();
	numWord = wordMap.size();
	numNum = numberMap.size();

	auto charItr = charMap.begin();
	auto wordItr = wordMap.begin();
	auto numberItr = numberMap.begin(); 

	for(int i = 0; i < 10; i++) {
		charItr = std::max_element(charMap.begin(), charMap.end(), compareSequence{});
		std::pair<std::string, int> tempPair(charItr->second);
		mostCharVector.push_back(tempPair);
		if(charMap.size() > 1) {
			charMap.erase(charItr);
		} else {
			break;
		}
	}
		
	for(int i = 0; i < 10; i++) {
		wordItr = std::max_element(wordMap.begin(), wordMap.end(), compareSequence{});
		std::pair<std::string, int> tempPair(wordItr->second);
		mostWordVector.push_back(tempPair);
		if(wordMap.size() > 1) {
			wordMap.erase(wordItr);
		} else {
			break;
		}
	}

	for(int i = 0; i < 10; i++) {
		numberItr = std::max_element(numberMap.begin(), numberMap.end(), compareSequence{});
		std::pair<std::string, int> tempPair(numberItr->second);
		mostNumberVector.push_back(tempPair);	
		if(numberMap.size() > 1) {
			numberMap.erase(numberItr);
		} else {
			break;
		}
	}

	std::cout << "\n\nTotal " << numChar << " unique characters, " << mostCharVector.size() << " of the most used characters:" << std::endl;
	for(int i = 0; i != mostCharVector.size(); i++) {
		if(mostCharVector[i].first == "\n") {
			std::cout << "No. " << i << ": \\n" << "\t\t\t\t\t\t" << mostCharVector[i].second << std::endl;
		} else if(mostCharVector[i].first == " ") {
			std::cout << "No. " << i << ": \' '" << "\t\t\t\t\t\t" << mostCharVector[i].second << std::endl;
		} else if(mostCharVector[i].first == "\t") {
			std::cout << "No. " << i << ": \\t " << "\t\t\t\t\t\t" << mostCharVector[i].second << std::endl;
		} else {
			std::cout << "No. " << i << ": " << mostCharVector[i].first  << "\t\t\t\t\t\t" << mostCharVector[i].second << std::endl;
		}
	}
	
	std::cout << "\n\nTotal " << numWord << " unique words, " << mostWordVector.size() << " of the most used words:" << std::endl;
	for(int i = 0; i != mostWordVector.size(); i++) {
		std::cout << "No. " << i << ": " << mostWordVector[i].first << "\t\t\t\t\t\t" << mostWordVector[i].second << std::endl;
	}

	std::cout << "\n\nTotal " << numNum << " unique numbers, " << mostNumberVector.size() << " of the most used numbers:" << std::endl;
	for(int i = 0; i != mostNumberVector.size(); i++) {
		std::cout << "No. " << i << ": " << mostNumberVector[i].first << "\t\t\t\t\t\t" << mostNumberVector[i].second << std::endl;
	}
	return 0;
}

//returns type of sequence a string is
SequenceType getSequenceType(const std::string & seq) {
	SequenceType type;
	if(std::isalpha(seq[0])) {
		for(int i = 0; i < seq.size(); i++) {
			if(std::isalpha(seq[i])) {
				type = WORD;
			} else {
				type = OTHER;
				break;
			}
		}
		if(type == WORD) {
			return type;
		}
	} else if(std::isdigit(seq[0])) {
		for(int i = 0; i < seq.size(); i++) {
			if(std::isdigit(seq[i])) {
				type = NUMBER;
			} else {
				type = OTHER;
				break;
			}
		}
		if(type == NUMBER) {
			return type;
		}
	}
	return type;
}
