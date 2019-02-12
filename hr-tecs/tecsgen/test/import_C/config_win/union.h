union unionA {
	int32_t   no;
	struct { int32_t  no;  int32_t  a; } a;
	struct { int32_t  no;  int32_t  b; } b;
};

struct structAA {
	union unionA a;
};

union unionB {
	int32_t   no;
	union A a;
	struct structAA b;
};
