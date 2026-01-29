#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstring> 


struct ScoreEntry {
    char name[20]; 
    int score;
};

class ScoreManager {
private:
    const char* FILE_PATH = "highscores.dat";
    std::vector<ScoreEntry> scores;

public:
    static ScoreManager& Instance() {
        static ScoreManager instance;
        return instance;
    }

    ScoreManager() {
        LoadScores();
    }

    void LoadScores() {
        scores.clear();
        std::ifstream file(FILE_PATH, std::ios::binary);
        if (file.is_open()) {
            ScoreEntry entry;
            while (file.read((char*)&entry, sizeof(ScoreEntry))) {
                scores.push_back(entry);
            }
            file.close();
        }
    }

    void SaveScores() {
        std::ofstream file(FILE_PATH, std::ios::binary | std::ios::trunc);
        if (file.is_open()) {
            for (const auto& entry : scores) {
                file.write((const char*)&entry, sizeof(ScoreEntry));
            }
            file.close();
        }
    }

    bool IsHighScore(int newScore) {
        if (scores.size() < 10) return true;
        return newScore > scores.back().score;
    }

    void AddScore(std::string name, int score) {
        ScoreEntry newEntry;
        newEntry.score = score;

        strncpy_s(newEntry.name, name.c_str(), sizeof(newEntry.name));
        newEntry.name[sizeof(newEntry.name) - 1] = 0; 

        scores.push_back(newEntry);

        std::sort(scores.begin(), scores.end(), [](const ScoreEntry& a, const ScoreEntry& b) {
            return a.score > b.score;
            });

        if (scores.size() > 10) {
            scores.resize(10);
        }

        SaveScores();
    }

    const std::vector<ScoreEntry>& GetScores() const {
        return scores;
    }
};