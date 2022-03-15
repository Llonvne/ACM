void countingSort(vector<int> & unsort, int K)
{
    vector<int> cont(K, 0);
    for (int i : unsort) {
        ++cont[i];
    }
    for (int i = 1; i < cont.size(); ++i) {
        cont[i] += cont[i - 1];
    }
    vector<int> result(unsort.size());
    for (int i = (int) unsort.size() - 1; i >= 0; --i) {
        // 获得位置
        int & pos = cont[unsort[i]];
        // 放入
        result[pos] = unsort[i];
        // 位置--
        --pos;
    }
    unsort = result;
}