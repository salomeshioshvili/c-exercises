#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <plplot/plplot.h>

void readBook(const char* fileName, char** contents) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    size_t capacity = 10000;
    size_t size = 0;
    *contents = malloc(capacity);
    
    int c;
    int lastWasSpace = 1;
    while ((c = fgetc(file)) != EOF) {
        if (size >= capacity - 1) {
            capacity *= 2;
            *contents = realloc(*contents, capacity);
        }
        
        if (isalpha(c)) {
            (*contents)[size++] = tolower(c);
            lastWasSpace = 0;
        } else if (!lastWasSpace) {
            (*contents)[size++] = ' ';
            lastWasSpace = 1;
        }
    }
    
    (*contents)[size] = '\0';
    fclose(file);
}

int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void countWords(const char* book, char*** words, int** frequencies, int* nWords) {
    char* bookCopy = strdup(book);
    
    size_t tempCapacity = 50000;
    char** tempWords = malloc(tempCapacity * sizeof(char*));
    size_t wordCount = 0;
    
    char* token = strtok(bookCopy, " ");
    while (token != NULL) {
        if (strlen(token) > 0) {
            if (wordCount >= tempCapacity) {
                tempCapacity *= 2;
                tempWords = realloc(tempWords, tempCapacity * sizeof(char*));
            }
            tempWords[wordCount] = strdup(token);
            wordCount++;
        }
        token = strtok(NULL, " ");
    }
    
    qsort(tempWords, wordCount, sizeof(char*), compareStrings);
    
    *words = malloc(wordCount * sizeof(char*));
    *frequencies = malloc(wordCount * sizeof(int));
    *nWords = 0;
    
    for (size_t i = 0; i < wordCount; i++) {
        if (*nWords == 0 || strcmp(tempWords[i], (*words)[*nWords - 1]) != 0) {
            (*words)[*nWords] = strdup(tempWords[i]);
            (*frequencies)[*nWords] = 1;
            (*nWords)++;
        } else {
            (*frequencies)[*nWords - 1]++;
        }
    }
    
    for (size_t i = 0; i < wordCount; i++) {
        free(tempWords[i]);
    }
    free(tempWords);
    free(bookCopy);
}

void writeResults(const char* fileName, char** words, int* frequencies, int nWords) {
    typedef struct {
        char* word;
        int freq;
    } WordFreq;
    
    WordFreq* pairs = malloc(nWords * sizeof(WordFreq));
    
    for (int i = 0; i < nWords; i++) {
        pairs[i].word = words[i];
        pairs[i].freq = frequencies[i];
    }
    
    for (int i = 0; i < nWords - 1; i++) {
        for (int j = 0; j < nWords - i - 1; j++) {
            if (pairs[j].freq < pairs[j + 1].freq) {
                WordFreq temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
    
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Error opening output file");
        free(pairs);
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < nWords; i++) {
        fprintf(file, "%d %d %s\n", i + 1, pairs[i].freq, pairs[i].word);
    }
    
    fclose(file);
    free(pairs);
}

void plotResults(char** words, int* frequencies, int nWords) {
    typedef struct {
        int freq;
        int index;
    } FreqPair;
    
    FreqPair* pairs = malloc(nWords * sizeof(FreqPair));
    for (int i = 0; i < nWords; i++) {
        pairs[i].freq = frequencies[i];
        pairs[i].index = i;
    }
    
    for (int i = 0; i < nWords - 1; i++) {
        for (int j = 0; j < nWords - i - 1; j++) {
            if (pairs[j].freq < pairs[j + 1].freq) {
                FreqPair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
    
    PLFLT* x = malloc(nWords * sizeof(PLFLT));
    PLFLT* y = malloc(nWords * sizeof(PLFLT));
    
    for (int i = 0; i < nWords; i++) {
        x[i] = log10((PLFLT)(i + 1));
        y[i] = log10((PLFLT)pairs[i].freq);
    }
    
    plsdev("pngcairo");
    plsfnam("zipf_plot.png");
    plscolbg(255, 255, 255);
    plscol0(0, 0, 0, 0);
    plscol0(1, 255, 0, 0);
    plscol0(2, 0, 0, 255);
    plscol0(15, 100, 100, 100);
    
    plinit();
    
    plcol0(15);
    plenv(x[0], x[nWords-1], y[nWords-1], y[0], 0, 10);
    
    plcol0(0);
    pllab("log₁₀(Rank)", "log₁₀(Frequency)", "Zipf's Law - Word Frequency in Moby Dick");
    
    plcol0(2);
    plwidth(3);
    plline(nWords, x, y);
    
    PLFLT xfit[2] = {x[0], x[nWords-1]};
    PLFLT yfit[2];
    PLFLT slope = (y[nWords-1] - y[0]) / (x[nWords-1] - x[0]);
    yfit[0] = y[0];
    yfit[1] = y[0] + slope * (x[nWords-1] - x[0]);
    
    plcol0(1);
    plwidth(2);
    plline(2, xfit, yfit);
    
    plend();
    
    free(x);
    free(y);
    free(pairs);
    
    printf("Plot saved to zipf_plot.png!\n");
    printf("Slope of best fit line: %.3f (ideal Zipf's law = -1.0)\n", slope);
}

void printHapaxLegomena(char** words, int* frequencies, int nWords) {
    int hapaxCount = 0;
    
    for (int i = 0; i < nWords; i++) {
        if (frequencies[i] == 1) {
            hapaxCount++;
        }
    }
    
    printf("\nHapax Legomena (words occurring only once):\n");
    printf("Total count: %d\n", hapaxCount);
    printf("Examples: ");
    
    int examplesShown = 0;
    for (int i = 0; i < nWords && examplesShown < 10; i++) {
        if (frequencies[i] == 1) {
            if (examplesShown > 0) printf(", ");
            printf("%s", words[i]);
            examplesShown++;
        }
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> [--plot]\n", argv[0]);
        fprintf(stderr, "Example: %s pg2701.txt output.dat\n", argv[0]);
        fprintf(stderr, "With plot: %s pg2701.txt output.dat --plot\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char* inputFile = argv[1];
    const char* outputFile = argv[2];
    int shouldPlot = 0;
    
    if (argc == 4 && strcmp(argv[3], "--plot") == 0) {
        shouldPlot = 1;
    }
    
    printf("Reading book from: %s\n", inputFile);
    char* contents = NULL;
    readBook(inputFile, &contents);
    
    printf("Counting words...\n");
    char** words = NULL;
    int* frequencies = NULL;
    int nWords = 0;
    countWords(contents, &words, &frequencies, &nWords);
    
    printf("Found %d unique words\n", nWords);
    
    printHapaxLegomena(words, frequencies, nWords);
    
    printf("\nWriting results to: %s\n", outputFile);
    writeResults(outputFile, words, frequencies, nWords);
    
    if (shouldPlot) {
        printf("\nGenerating plot...\n");
        plotResults(words, frequencies, nWords);
    } else {
        printf("\nUse --plot flag to display graph with PLPlot\n");
        printf("Or plot with: gnuplot -e \"set logscale xy; plot '%s' using 1:2 with lines; pause -1\"\n", outputFile);
    }
    
    for (int i = 0; i < nWords; i++) {
        free(words[i]);
    }
    free(words);
    free(frequencies);
    free(contents);
    
    return EXIT_SUCCESS;
}