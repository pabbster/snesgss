struct BassTable : public Bass {
  void initialize(unsigned pass);
  bool assembleBlock(const string &block);

protected:
  struct Prefix {
    string text;
    unsigned size;
  };

  struct Number {
    unsigned bits;
  };

  struct Format {
    enum class Type : unsigned { Static, Absolute, Relative, Repeat } type;
    enum class Match : unsigned { Exact, Strong, Weak } match;
    unsigned data, bits, argument;
    signed displacement;
  };

  struct Opcode {
    vector<Prefix> prefix;
    vector<Number> number;
    vector<Format> format;
    string pattern;
  };

  vector<Opcode> table;
  uint64_t bitval, bitpos;

  unsigned bitLength(string &text) const;
  void writeBits(uint64_t data, unsigned bits);
  bool parseTable(const string &text);
  void assembleTableLHS(Opcode &opcode, const string &text);
  void assembleTableRHS(Opcode &opcode, const string &text);
};
