#ifndef __SEGMENT_H_
#define __SEGMENT_H_

#include <stdint.h>
#include <vector>


namespace tis {

struct word_dict_t;
struct seg_result_t;

typedef struct token_t{
    const char* str;
    int32_t len;
    int32_t offset;
    int hprop;
    int lprop;
} token_t;

class Segment {
public:
    static int init(const char* path);
    static Segment* create(uint32_t max_token_num);

private:
    static word_dict_t* __worddict;

private:
    Segment();
    virtual ~Segment();

public: 
    int segment(const char* str, int len); 
    void get_basic_tokens(std::vector<token_t>& tokens);
    void get_cat_tokens(std::vector<token_t>& tokens);
    void get_all_unique_tokens(std::vector<token_t>& tokens);

private:
    int _init(uint32_t max_token_num);

    int _max_token_num;
    word_dict_t* _dict;
    seg_result_t* _result;

};

}

#endif
