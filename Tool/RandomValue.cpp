nt RandomValue(int lower, int upper) {
  if (lower > upper) { swap(lower, upper); }
  return rand() % (upper - lower + 1) + lower;
}

double RandomValue(double lower, double upper) {
  if (lower > upper) { swap(lower, upper); }
  return rand() / (double)RAND_MAX * (upper - lower) + lower;
}

template <class T>
vector<T> VectorValue(int size, T value) {
  vector<T> ret(size, value);
  return ret;
}

template <class T>
vector<T> RandomVectorValue(int size, T lower, T upper) {
  vector<T> ret(size);
  for (int i = 0; i < size; i++) {
    ret[i] = RandomValue(lower, upper);
  }
  return ret;
}

template <class T>
vector<T> ArithmeticProgressionValue(int size, T start, T dif, T lower, T upper) {
  assert(size != 0);
  assert(lower <= start && start <= upper);
  vector<T> ret(size);
  ret[0] = start;
  for (int i = 1; i < size; i++) {
    ret[i] = ret[i - 1] + dif;
    assert(lower <= ret[i] && ret[i] <= upper);
  }
  return ret;
}

template <class T>
vector<T> GeometricProgressionValue(int size, T start, T dif, T lower, T upper) {
  assert(size != 0);
  assert(lower <= start && start <= upper);
  vector<T> ret(size);
  ret[0] = start;
  for (int i = 1; i < size; i++) {
    ret[i] = ret[i - 1] * dif;
    assert(lower <= ret[i] && ret[i] <= upper);
  }
  return ret;
}

const string LowerAlphabet = "abcdefghijklmnopqrstuvwxyz";
const string UpperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string Alphabet = LowerAlphabet + UpperAlphabet;
const string NoneZeroDigit = "123456789";
const string Digit = "0123456789";

char RandomChar(const string &usable) {
  const int n = usable.size();
  return usable[RandomValue(0, n - 1)];
}

string RandomString(int lowerSize, int upperSize, const string &usable) {
  const int size = RandomValue(lowerSize, upperSize);
  string ret;
  ret.resize(size);
  for (int i = 0; i < size; i++) {
    ret[i] = RandomChar(usable);
  }
  return ret;
}

vector<string> RandomStringVector(int lowerSize1, int upperSize1, int lowerSize2, int upperSize2, const string &usable) {
  const int size1 = RandomValue(lowerSize1, upperSize1);
  vector<string> ret(size1);
  for (int i = 0; i < size1; i++) {
    ret[i] = RandomString(lowerSize2, upperSize2, usable);
  }
  return ret;
}

template <class T>
void PrintVector(const vector<T> &item) {
  const int n = item.size();
  for (int i = 0; i < n; i++) {
    if (i != 0) { putchar(' '); }
    cout << item[i];
  }
}

void PrintVectorString(const vector<string> &item) {
  const int n = item.size();
  for (int i = 0; i < n; i++) {
    printf("%s", item[i].c_str());
    if (i != n - 1) { putchar(','); }
  }
}

