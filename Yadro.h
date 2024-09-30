//---------------------------------------INSERTION_SORT--------------------------------------------------------
void insertion_sort (int size, int arr[]);
void insertion_copy (int *old_beginning, int *new_beginning, int num_elem_to_copy);


//---------------------------------------SEARCH_FUNCTIONS------------------------------------------------------
int bin_search (int arr[], int size, int required_elem);

//-----------------------------------FILE_PROCESSING_FUNCTIONS-------------------------------------------------
int check_open (FILE** f_ptr, const char *name, const char *mode);

//----------------------------------------TESTING_FUNCTIONS----------------------------------------------------
const int MAX_TEST_SIZE = 40;
const int TEST_NAME_SIZE = 20;

int read_test (int *size, int test_input[MAX_TEST_SIZE], FILE *test_fd, int test_reference[]);
void check_error (int test_num, int error);
void check_test (void);
void check_unittest (const char test_pathname[TEST_NAME_SIZE], const int test_num);

