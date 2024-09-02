class UF { 
public:
    vector<int> parents;
    vector<int> sizes;
    UF(int n) {
        parents.resize(n, 0);
        sizes.resize(n, 1);
       
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }

    void un(int child, int parent) {
        int root1 = fd(child);
        int root2 = fd(parent);

        if (root1 == root2) return;

        if (sizes[root1] > sizes[root2]) {
            parents[root2] = root1;
            sizes[root1]++;
        } else {
            parents[root1] = root2;
            sizes[root2]++;
        }
    }

    int fd(int target) {
        while (target != parents[target]) {
            target = parents[target];
        }
        return target;
    }
};
