#include <bits/stdc++.h>
using namespace std;

int sumfirst = 0, sumbest = 0;

struct Blocks {
    int block_no = 0, block_size = 0, file_no = 0, file_size = 0,
    fragmentation = 0;
};

// First Fit Algorithm
void firstFit(struct Blocks blocks[], int nb, int files[], int nf) {
    for(int i = 0; i < nf; i++) {
        int file_size = files[i];
        for(int j = 0; j < nb; j++) {
            if((blocks[j].block_size >= file_size) && (blocks[j].file_no == 0)) {
                blocks[j].file_no = i + 1;
                blocks[j].file_size = file_size;
                blocks[j].fragmentation = blocks[j].block_size - file_size;
                sumfirst += blocks[j].fragmentation;
                break;
            }
        }
    }
}

// Best Fit Algorithm
void bestFit(struct Blocks blocks[], int nb, int files[], int nf) {
    for(int i = 0; i < nf; i++) {
        int file_size = files[i];
        int minBlock = -1;
        vector<struct Blocks> v;
        for(int j = 0; j < nb; j++) {
            if((blocks[j].block_size >= file_size) && (blocks[j].file_no == 0)) {
                v.push_back(blocks[j]);
                if(minBlock == -1) {
                    minBlock = v[0].block_no;
                } else {
                    if(v[v.size() - 1].block_size < blocks[minBlock - 1].block_size) {
                        minBlock = v[v.size() - 1].block_no;
                    }
                }
            }
        }
        if(minBlock == -1) continue;
        minBlock = minBlock - 1;
        blocks[minBlock].file_no = i + 1;
        blocks[minBlock].file_size = file_size;
        blocks[minBlock].fragmentation = blocks[minBlock].block_size - file_size;
        sumbest += blocks[minBlock].fragmentation;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int nb, nf;
    cin >> nb;
    struct Blocks blocks[nb];
    for (int i = 0; i < nb; i++) {
        cin >> blocks[i].block_size;
        blocks[i].block_no = i+1;
    }

    cin >> nf;
    int files[nf];
    for(int i = 0; i < nf; i++) {
        cin >> files[i];
    }

    firstFit(blocks, nb, files, nf);

    // Printing First Fit Table
    cout << "First Fit:" << endl;
    cout << "BlockNo\tBlockSize\tFileNo\tFileSize\tFragmentation" << endl;
    for (int i = 0; i < nb; i++) {
        cout << blocks[i].block_no << "\t" << blocks[i].block_size << "\t\t" <<
        blocks[i].file_no << "\t\t" << blocks[i].file_size << "\t\t" << blocks[i].fragmentation << endl;
    }

    // Reset blocks for Best Fit
    for (int i = 0; i < nb; i++) {
        blocks[i].file_no = 0;
        blocks[i].file_size = 0;
        blocks[i].fragmentation = 0;
    }


    bestFit(blocks, nb, files, nf);

    // Printing Best Fit Table
    cout << endl << "Best Fit:" << endl;
    cout << "BlockNo\tBlockSize\tFileNo\tFileSize\tFragmentation" << endl;
    for (int i = 0; i < nb; i++) {
        cout << blocks[i].block_no << "\t" <<
        blocks[i].block_size << "\t\t" <<
        blocks[i].file_no << "\t\t" <<
        blocks[i].file_size << "\t\t" <<
        blocks[i].fragmentation << endl;
    }

    cout << endl;
    cout << "Total Fragmentation of First fit: " << sumfirst << endl;
    cout << "Total Fragmentation of Best fit: " << sumbest << endl;
    cout << endl;

    if(sumfirst<sumbest) {
        cout << "So Less fragmentation on First Fit";
    }
    else {
        cout << "So Less fragmentation on Best Fit";
    }
    cout << endl;

    return 0;
}
