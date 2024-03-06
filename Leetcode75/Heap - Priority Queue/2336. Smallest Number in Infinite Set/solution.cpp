class SmallestInfiniteSet {
public:
    int v[1001];
    int top = 0;

    // Constructor to initialize the set
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            v[i] = 1;
        }
    }

    // Function to pop the smallest element from the set
    int popSmallest() {
        for (int i = 1; i <= 1000; i++) {
            if (v[i] != 0) {
                v[i] -= 1;
                return i;
            }
        }
        return 0; // Return 0 if the set is empty
    }

    // Function to add an element back to the set
    void addBack(int num) {
        if (v[num] == 0) {
            v[num]++;
        }
    }
};
