#include<iostream>

struct Term{ //triplet
    int row, col, value;
};

void InputSparce(Term matrix[]) {
    std::cout << "Enter total non-zero elements: ";
    std::cin >> matrix[0].value; // value in 0th position = number of non-zero elements

    std::cout << "Enter row, column, and value for each element:\n";
    for (int i = 1; i <= matrix[0].value; i++) {
        std::cin >> matrix[i].row >> matrix[i].col >> matrix[i].value;
    }
}

void displaySparse(Term matrix[]) { //in triplet form
    std::cout << "Row\tCol\tValue\n";
    for (int i = 0; i <= matrix[0].value; i++) {
        std::cout << matrix[i].row << "\t" << matrix[i].col << "\t" << matrix[i].value << "\n";
    }
}

void transposeSparse(Term matrix[], Term transpose[]) {
    transpose[0].row = matrix[0].col;
    transpose[0].col = matrix[0].row;
    transpose[0].value = matrix[0].value;

    int k = 1;
    for (int c = 0; c < matrix[0].col; c++) {
        for (int i = 1; i <= matrix[0].value; i++) {
            if (matrix[i].col == c) {
                transpose[k].row = matrix[i].col;
                transpose[k].col = matrix[i].row;
                transpose[k].value = matrix[i].value;
                k++;
            }
        }
    }
}

void addSparse(Term a[], Term b[], Term sum[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        std::cout << "Matrices can't be added\n";
        return;
    }

    sum[0].row = a[0].row;
    sum[0].col = a[0].col;

    int i = 1, j = 1, k = 1;
    while (i <= a[0].value && j <= b[0].value) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            sum[k++] = a[i++];
        } else if (b[j].row < a[i].row || (b[j].row == a[i].row && b[j].col < a[i].col)) {
            sum[k++] = b[j++];
        } else {
            sum[k].row = a[i].row;
            sum[k].col = a[i].col;
            sum[k].value = a[i].value + b[j].value;
            i++; j++; k++;
        }
    }
    while (i <= a[0].value) sum[k++] = a[i++];
    while (j <= b[0].value) sum[k++] = b[j++];

    sum[0].value = k - 1;
}

void multiplySparse(Term a[], Term b[], Term prod[]) {
    if (a[0].col != b[0].row) {
        std::cout << "Matrices cannot be multiplied\n";
        return;
    }

    Term bT[100];
    transposeSparse(b, bT);

    prod[0].row = a[0].row;
    prod[0].col = b[0].col;
    prod[0].value = 0;

    int k = 1; // index for result

    // Iterate through each row of A
    for (int i = 0; i < a[0].row; i++) {
        // Gather all terms of row i in A
        Term rowA[100];
        int rowCountA = 0;
        for (int x = 1; x <= a[0].value; x++)
            if (a[x].row == i)
                rowA[rowCountA++] = a[x];

        if (rowCountA == 0) continue; // skip empty row

        // Now for each row in bT (i.e., each col in B)
        for (int j = 0; j < bT[0].row; j++) {
            Term rowB[100];
            int rowCountB = 0;
            for (int y = 1; y <= bT[0].value; y++)
                if (bT[y].row == j)
                    rowB[rowCountB++] = bT[y];

            if (rowCountB == 0) continue; // skip empty column

            int p = 0, q = 0, sum = 0;
            while (p < rowCountA && q < rowCountB) {
                if (rowA[p].col == rowB[q].col) {
                    sum += rowA[p].value * rowB[q].value;
                    p++; q++;
                } else if (rowA[p].col < rowB[q].col) {
                    p++;
                } else {
                    q++;
                }
            }

            if (sum != 0) {
                prod[k].row = i;
                prod[k].col = j;
                prod[k].value = sum;
                k++;
            }
        }
    }
    prod[0].value = k - 1;
}

int main(){
    Term A[100], B[100], transposeA[100], sum[100], product[100];

    std::cout<<"-----A-----"<<std::endl;
    std::cout<<"Enter rows and columns for martix A : "<<std::endl;
    std::cin>>A[0].row>>A[0].col;
    InputSparce(A); 
    displaySparse(A);

    std::cout<<"-----B-----"<<std::endl;
    std::cout<<"Enter rows and columns for martix B : "<<std::endl;
    std::cin>>B[0].row>>B[0].col;
    InputSparce(B);
    displaySparse(B);

    std::cout<<"-----Transpose of A-----"<<std::endl;
    transposeSparse(A,transposeA);
    displaySparse(transposeA);

    std::cout<<"-----Addition of A and B-----"<<std::endl;
    addSparse(A,B,sum);
    displaySparse(sum);

    std::cout<<"-----Product of A and B-----"<<std::endl;
    multiplySparse(A,B,product);
    displaySparse(product);
    
    return 0;
}