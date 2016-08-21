class ProcessingModule {
 public:
 	ProcessingModule() = default;
 	virtual ~ProcessingModule() = default;
	virtual bool process(int value) = 0;
};

typedef ProcessingModule* create_t();
typedef void destroy_t(ProcessingModule*);